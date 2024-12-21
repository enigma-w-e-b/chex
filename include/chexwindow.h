#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>

class EadWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit EadWindow(QWidget *parent = nullptr);
    ~EadWindow() override;

    private slots:
        void encode();
    void decode();

private:
    QTextEdit *inputTextEdit;
    QTextEdit *outputTextEdit;
    QComboBox *comboBox;
    QPushButton *encodeButton;
    QPushButton *decodeButton;

    static QString toHex(const QString &input);
    static QString fromHex(const QString &input);

    static QString toBinary(const QString &input);
    static QString fromBinary(const QString &input);
    static QString rot13(const QString &input);
    static QString toMorse(const QString &input);
    static QString fromMorse(const QString &input);
    static QString toBase64(const QString &input);
    static QString fromBase64(const QString &input);
    static QString toURLEncode(const QString &input);
    static QString fromURLEncode(const QString &input);
    static QString toHTMLEncode(const QString &input);
    static QString fromHTMLEncode(const QString &input);
};

#endif // MAINWINDOW_H
