#include "chexwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QByteArray>
#include <QMessageBox>

EadWindow::EadWindow(QWidget *parent)
    : QMainWindow(parent),
      inputTextEdit(new QTextEdit(this)),
      outputTextEdit(new QTextEdit(this)),
      comboBox(new QComboBox(this)),
      encodeButton(new QPushButton("Encode", this)),
      decodeButton(new QPushButton("Decode", this))
{
    resize(800, 600);
    comboBox->addItem("Hex");
    comboBox->addItem("Base64");
    comboBox->addItem("Binary");
    comboBox->addItem("ROT13");
    comboBox->addItem("Morse");
    comboBox->addItem("URL Encode");
    comboBox->addItem("HTML Encode");

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(new QLabel("Input:"));
    mainLayout->addWidget(inputTextEdit);
    mainLayout->addWidget(new QLabel("Output:"));
    mainLayout->addWidget(outputTextEdit);
    mainLayout->addWidget(comboBox);

    auto *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(encodeButton);
    buttonLayout->addWidget(decodeButton);

    mainLayout->addLayout(buttonLayout);

    auto *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(encodeButton, &QPushButton::clicked, this, &EadWindow::encode);
    connect(decodeButton, &QPushButton::clicked, this, &EadWindow::decode);
}

EadWindow::~EadWindow() = default;

void EadWindow::encode() {
    const QString inputText = inputTextEdit->toPlainText();
    QString result;
    const QByteArray byteArray = inputText.toUtf8();

    switch (comboBox->currentIndex()) {
        case 0:
            result = byteArray.toHex();
            break;
        case 1:
            result = byteArray.toBase64();
            break;
        case 2:
            result = toBinary(inputText);
            break;
        case 3:
            result = rot13(inputText);
            break;
        case 4:
            result = toMorse(inputText);
            break;
        case 5:
            result = QString::fromUtf8(byteArray.toPercentEncoding());
            break;
        case 6:
            result = inputText.toHtmlEscaped();
            break;
        default:
            QMessageBox::warning(this, "Error", "Unknown encoding type selected.");
            return;
    }

    outputTextEdit->setPlainText(result);
}

void EadWindow::decode() {
    const QString inputText = inputTextEdit->toPlainText();
    QString result;
    QByteArray byteArray;

    switch (comboBox->currentIndex()) {
        case 0:
            byteArray = QByteArray::fromHex(inputText.toUtf8());
            result = QString::fromUtf8(byteArray);
            break;
        case 1:
            byteArray = QByteArray::fromBase64(inputText.toUtf8());
            result = QString::fromUtf8(byteArray);
            break;
        case 2:
            result = fromBinary(inputText);
            break;
        case 3:
            result = rot13(inputText);
            break;
        case 4:
            result = fromMorse(inputText);
            break;
        case 5:
            byteArray = QByteArray::fromPercentEncoding(inputText.toUtf8());
            result = QString::fromUtf8(byteArray);
            break;
        case 6:
            result = inputText;
            result.replace("&lt;", "<");
            result.replace("&gt;", ">");
            result.replace("&amp;", "&");
            result.replace("&quot;", "\"");
            result.replace("&apos;", "'");
            break;
        default:
            QMessageBox::warning(this, "Error", "Unknown decoding type selected.");
            return;
    }

    outputTextEdit->setPlainText(result);
}

QString EadWindow::toHex(const QString &input) {
    const QByteArray byteArray = input.toUtf8();
    return byteArray.toHex();
}

QString EadWindow::fromHex(const QString &input) {
    const QByteArray byteArray = QByteArray::fromHex(input.toUtf8());
    return QString::fromUtf8(byteArray);
}

QString EadWindow::toBinary(const QString &input) {
    QString binary;
    for (QChar c : input) {
        binary.append(QString("%1 ").arg(c.unicode(), 8, 2, QChar('0')));
    }
    return binary.trimmed();
}

QString EadWindow::fromBinary(const QString &input) {
    QStringList binaryList = input.split(' ', Qt::SkipEmptyParts);
    QString result;
    for (const QString &binary : binaryList) {
        bool ok;
        QChar c(binary.toInt(&ok, 2));
        if (ok) {
            result.append(c);
        } else {
            return "Invalid binary input";
        }
    }
    return result;
}

QString EadWindow::rot13(const QString &input) {
    QString result;
    for (QChar c : input) {
        if (c.isLetter()) {
            QChar base = c.isUpper() ? 'A' : 'a';
            result.append(QChar((c.unicode() - base.unicode() + 13) % 26 + base.unicode()));
        } else {
            result.append(c);
        }
    }
    return result;
}

QString EadWindow::toMorse(const QString &input) {
    static const QHash<QChar, QString> morseCode {
        { 'A', ".-" }, { 'B', "-..." }, { 'C', "-.-." }, { 'D', "-.." }, { 'E', "." },
        { 'F', "..-." }, { 'G', "--." }, { 'H', "...." }, { 'I', ".." }, { 'J', ".---" },
        { 'K', "-.-" }, { 'L', ".-.." }, { 'M', "--" }, { 'N', "-." }, { 'O', "---" },
        { 'P', ".--." }, { 'Q', "--.-" }, { 'R', ".-." }, { 'S', "..." }, { 'T', "-" },
        { 'U', "..-" }, { 'V', "...-" }, { 'W', ".--" }, { 'X', "-..-" }, { 'Y', "-.--" },
        { 'Z', "--.." }, { '1', ".----" }, { '2', "..---" }, { '3', "...--" }, { '4', "....-" },
        { '5', "....." }, { '6', "-...." }, { '7', "--..." }, { '8', "---.." }, { '9', "----." },
        { '0', "-----" }, { ' ', "/" }
    };

    QString morse;
    for (QChar c : input.toUpper()) {
        if (morseCode.contains(c)) {
            morse.append(morseCode.value(c) + " ");
        } else {
            return "Invalid character in input";
        }
    }
    return morse.trimmed();
}

QString EadWindow::fromMorse(const QString &input) {
    static const QHash<QString, QChar> morseCode {
        { ".-", 'A' }, { "-...", 'B' }, { "-.-.", 'C' }, { "-..", 'D' }, { ".", 'E' },
        { "..-.", 'F' }, { "--.", 'G' }, { "....", 'H' }, { "..", 'I' }, { ".---", 'J' },
        { "-.-", 'K' }, { ".-..", 'L' }, { "--", 'M' }, { "-.", 'N' }, { "---", 'O' },
        { ".--.", 'P' }, { "--.-", 'Q' }, { ".-.", 'R' }, { "...", 'S' }, { "-", 'T' },
        { "..-", 'U' }, { "...-", 'V' }, { ".--", 'W' }, { "-..-", 'X' }, { "-.--", 'Y' },
        { "--..", 'Z' }, { ".----", '1' }, { "..---", '2' }, { "...--", '3' }, { "....-", '4' },
        { ".....", '5' }, { "-....", '6' }, { "--...", '7' }, { "---..", '8' }, { "----.", '9' },
        { "-----", '0' }, { "/", ' ' }
    };

    QStringList morseList = input.split(' ', Qt::SkipEmptyParts);
    QString result;
    for (const QString &morse : morseList) {
        if (morseCode.contains(morse)) {
            result.append(morseCode.value(morse));
        } else {
            return "Invalid Morse code in input";
        }
    }
    return result;
}

QString EadWindow::toBase64(const QString &input) {
    const QByteArray byteArray = input.toUtf8();
    return byteArray.toBase64();
}

QString EadWindow::fromBase64(const QString &input) {
    const QByteArray byteArray = QByteArray::fromBase64(input.toUtf8());
    return QString::fromUtf8(byteArray);
}

QString EadWindow::toURLEncode(const QString &input) {
    const QByteArray byteArray = input.toUtf8();
    return QString::fromUtf8(byteArray.toPercentEncoding());
}

QString EadWindow::fromURLEncode(const QString &input) {
    const QByteArray byteArray = QByteArray::fromPercentEncoding(input.toUtf8());
    return QString::fromUtf8(byteArray);
}

QString EadWindow::toHTMLEncode(const QString &input) {
    return input.toHtmlEscaped();
}

QString EadWindow::fromHTMLEncode(const QString &input) {
    QString result = input;
    result.replace("&lt;", "<");
    result.replace("&gt;", ">");
    result.replace("&amp;", "&");
    result.replace("&quot;", "\"");
    result.replace("&apos;", "'");
    return result;
}
