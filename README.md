# Torre de Hanói

Implementação do clássico jogo **Torre de Hanói**, desenvolvido como projeto final da disciplina de **Estrutura de Dados**.

O projeto simula o jogo no terminal, utilizando estruturas de dados como **pilhas** e **listas encadeadas** para a lógica do jogo e o gerenciamento do histórico de partidas.

## 🎮 Sobre o Jogo

O jogo **Torre de Hanói** é um quebra-cabeça matemático que consiste em mover uma pilha de discos de um pino para outro.

## 🧩 Regras do Jogo

1. Apenas um disco pode ser movido por vez.
2. Um disco só pode ser movido se for o disco do topo de uma das torres.
3. Nenhum disco **maior** pode ser colocado sobre um disco **menor**.
4. Mover todos os discos da torre de origem para outra torre.

## 🧠 Estruturas de Dados Utilizadas

- **Pilhas (Stacks):** representam as torres do jogo.
- **Lista Encadeada:** armazena em memória o histórico das partidas.
- **Arquivo de texto:** registra de forma persistente os dados das partidas jogadas.

## ⚙️ Funcionalidades

- Escolha do número de discos.
- Movimentação manual dos discos entre torres.
- Reinício do jogo a qualquer momento.
- Registro de informações da partida:
  - Nome do jogador
  - Quantidade de discos
  - Número de movimentos
  - Data e hora do término
- Armazenamento do histórico:
  - Em memória (lista encadeada)
  - Em arquivo de texto (`historico.txt`)
- Visualização e busca no histórico por nome ou data.

## 💾 Histórico de Partidas

As partidas são registradas em dois locais:
- **Memória (lista encadeada):** para buscas rápidas durante a execução.
- **Arquivo `historico.txt`:** para persistência dos dados entre execuções.

<br>

--- 

## 💻 Como Executar

1. Compile os arquivos:

```bash
gcc -o torreHanoi src/*.c -Iinclude
```

2. Execute

```bash
./torreHanoi
```

<br>
<br>

--- 

# 📄 Licença

Projeto final da matéria de **Estrutura de Dados**

Engenharia de Software | Universidade Católica de Brasília

> Desenvolvido por:
- João Ricardo Jales Cirino 
- Felipe Lima Duarte

