# Atividade 1 - Desenvolvimento para Internet das Coisas (IoT)

Este repositório contém o código-fonte e a configuração da **Atividade 1** realizada na disciplina de **Desenvolvimento para Internet das Coisas** do curso de **Tecnologia em Análise e Desenvolvimento de Sistemas (TADS)**.

O projeto consiste em uma aplicação prática utilizando a plataforma ESP32 para leitura de sensores e interação com atuadores e display LCD.

## 📝 Descrição do Projeto

O objetivo principal desta atividade é consolidar os conhecimentos básicos de IoT, incluindo a manipulação de entradas/saídas digitais e analógicas, comunicação I2C e integração com simuladores (Wokwi).

O projeto realiza a leitura de um sensor de luminosidade (LDR), utiliza um botão para interação e um display LCD I2C para exibição de informações, além de controlar um LED externo.

## 🚀 Funcionalidades

- **Inicialização:** Exibe uma barra de progresso no LCD ao ligar.
- **Interação por Botão:** Detecta o pressionamento de um botão para ações no display.
- **Leitura de Sensor:** Realiza a leitura analógica de um LDR e exibe o valor em tempo real no LCD.
- **Controle de Atuador:** Acionamento de um LED (GPIO 23).

## 🛠️ Hardware Utilizado (Simulado)

- **Microcontrolador:** ESP32 (DOIT DevKit V1)
- **Display:** LCD 16x2 com módulo I2C (Endereço 0x27)
- **Sensor:** LDR (Ligado à porta analógica 34)
- **Botão:** Push-button (Ligado à porta 25 com INPUT_PULLUP)
- **LED:** LED Vermelho/Verde (Ligado à porta 23)

## 💻 Tecnologias e Ferramentas

- [PlatformIO](https://platformio.org/) - Ecossistema para desenvolvimento IoT.
- [Arduino Framework](https://www.arduino.cc/) - Framework para programação do ESP32.
- [Wokwi](https://wokwi.com/) - Simulador de eletrônica online.
- Biblioteca `LiquidCrystal_I2C` para controle do display.

[Veja como usar PlatformIO e Wokwi no VSCode](https://youtu.be/SJNPFvk--_o)

## 📅 Histórico de Desenvolvimento

- **Início:** 17 de Abril de 2026
- **Última Atualização:** 24 de Abril de 2026 (Aulas práticas da disciplina)

## ⚙️ Como Executar

1.  Certifique-se de ter o **VS Code** com a extensão **PlatformIO** instalada.
2.  Clone este repositório.
3.  Abra a pasta do projeto no VS Code.
4.  O PlatformIO baixará automaticamente as dependências (LiquidCrystal_I2C).
5.  Para simular, utilize o arquivo `wokwi.toml` com a extensão do Wokwi no VS Code ou carregue o `diagram.json` no site oficial do Wokwi.

---
Projeto desenvolvido para fins acadêmicos.
