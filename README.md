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

# Termos e Responsabilidades

## Introdução

As ferramentas desenvolvidas pela Ciphers Systems são projetadas para ajudar os usuários a aprender sobre criptografia e segurança da informação. Estas ferramentas são fornecidas gratuitamente e devem ser utilizadas de forma responsável e ética.

## Uso Permitido

Os usuários das ferramentas da Ciphers Systems devem utilizar esses recursos apenas para:

1. **Educação:**
   - Aprender sobre criptografia e segurança da informação.
   - Realizar estudos acadêmicos e projetos educacionais.

2. **Desenvolvimento de Habilidades:**
   - Melhorar as habilidades técnicas em criptografia e segurança.
   - Praticar a implementação de algoritmos criptográficos de maneira ética.
   - Aprender a identificar e corrigir vulnerabilidades de segurança.
   - Desenvolver habilidades práticas em testes de penetração.
   - Aprender a proteger sistemas e dados contra ameaças cibernéticas.
   - Aprender a usar ferramentas de segurança e criptografia de forma responsável.
   - Aprender a proteger a privacidade e a segurança dos dados pessoais.

## Responsabilidade do Usuário

1. **Uso Ético:**
   - Os usuários são responsáveis por garantir que suas atividades estejam em conformidade com todas as leis e regulamentos aplicáveis.
   - É estritamente proibido utilizar as ferramentas para qualquer atividade ilegal, incluindo, mas não se limitando a, invasão de sistemas, roubo de dados ou qualquer outra forma de cibercrime.

2. **Consequências do Uso Indevido:**
   - A Ciphers Systems não se responsabiliza por qualquer ato ilegal ou antiético realizado pelos usuários das ferramentas.
   - Os usuários assumem total responsabilidade por suas ações e concordam em indenizar a Ciphers Systems por qualquer dano resultante do uso indevido das ferramentas.

## Isenção de Responsabilidade

1. **Limitação de Responsabilidade:**
   - As ferramentas são fornecidas "como estão", sem garantias de qualquer tipo, expressas ou implícitas.
   - A Ciphers Systems não garante que as ferramentas estejam livres de erros ou falhas, ou que o uso das ferramentas atenderá às expectativas dos usuários.

2. **Isenção de Responsabilidade:**
   - Em nenhuma circunstância a Ciphers Systems será responsável por qualquer dano indireto, incidental, especial, consequente ou punitivo decorrente do uso ou da incapacidade de usar as ferramentas.

## Aceitação dos Termos

Ao utilizar as ferramentas da Ciphers Systems, os usuários concordam com os termos e responsabilidades descritos neste documento. Se você não concorda com qualquer parte destes termos, não utilize as ferramentas.

## Atualizações dos Termos

A Ciphers Systems reserva-se o direito de atualizar estes termos a qualquer momento. Quaisquer alterações serão publicadas nesta página e entrarão em vigor imediatamente após a publicação.

---

Se você tiver alguma dúvida sobre esses termos, por favor, entre em contato conosco através do [site oficial](https://ciphers.systems).

**Última atualização:** 21 De Dezembro De 2024
