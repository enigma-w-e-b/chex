# Chex - Ferramenta para Codificacao e Decodificacao de Texto

**Creditos:** Ciphers Systems

---

## Introducao

O Chex é uma ferramenta de software livre que permite aos usuarios codificar e decodificar texto usando diferentes algoritmos de cifra. A aplicacao foi desenvolvida pela Ciphers Systems, e é distribuida sob a licenca MIT.
## Caracteristicas

- **Codificacao de Mensagens**: Permite aos usuarios codificar mensagens usando diferentes algoritmos de cifra.
- **Decodificacao de Mensagens**: Decodifque mensagens previamente codificadas com facilidade.

## Instalacão

### Requisitos

- Qt5 (Core, Widgets)
- CMake 3.30 ou superior
- Compilador C++ com suporte a C++17

### Passos para Compilar e Instalar

1. **Clone o Repositório:**
   `
   git clone https://github.com/enigma-w-e-b/chex.git
   cd chex
   `

2. **Configure o Projeto:**
   `
   mkdir build && cd build && cmake ..
   `

3. **Compile o Projeto:**
   `make
   `

4. **Instale o Projeto:**
   `sudo make install
   `

## Uso

### Interface Grafica

Para iniciar o Chex, execute o comando `chex` no terminal ou procure por "Chex" no menu de aplicativos do seu sistema. A interface principal do Chex é composta por uma caixa de texto para inserir a mensagem a ser codificada ou decodificada, um menu suspenso para selecionar o algoritmo de cifra e dois botões para codificar e decodificar a mensagem.
### Linha de Comando (Futuro)

A funcionalidade de linha de comando sera adicionada em versõs futuras para permitrir a codificacao e decodificacao diretamente no terminal.

## Estrutura do Projeto

```
chex/
|-- CMakeLists.txt
|-- chex.desktop.in
|-- ciphers.directory
|-- include/
|   |-- chexwindow.h
|-- resources/
|   |-- ciphers-systems-icon.png
|   |-- chex-icon.svg
|   |-- resources.qrc
|-- src/
|   |-- main.cpp
|   |-- chexwindow.cpp
|-- cmake_uninstall.cmake.in

```

### Arquivos Importantes

- **main.cpp**: Ponto de entrada da aplicaçã.
- **chexwindow.h / chexwindow.cpp**: Implementac:o da janela principal da aplicaçã.
- **resources.qrc**: Arquivo de recursos Qt que inclui ìcones e outros recursos.
- **chex.desktop.in**: Arquivo de desktop para integrac:o com o sistema.
- **ciphers.directory**: Arquivo de diretório para o menu personalizado.
- **cmake_uninstall.cmake.in**: Scripta para desinstalaçã do projeto.

### Contribuiçco

Contribuiçcoes sl-bem-vindas!0 Se você deseja contribuir para o Chex, siga os passos abaixo:

1. **Fork o Repositório**:
   `
   git fork https://github.com/enigma-w-e-b/chex.git
   `

2. **Crie uma Branch:**
   `
   git checkout -b feature/nova-funcionalidade
   `
## Suporte

Para suporte, entre em contato com a Ciphers Systems através do [site oficial](https://ciphers.systems/) ou abra uma issue no [repositório do GitHub](https://github.com/enigma-w-e-b/chex/issues).

## Licenca

Este projeto está licenciado sobre a licencia MIT. Veja o arquivo LICENSE para mais detalhes.
