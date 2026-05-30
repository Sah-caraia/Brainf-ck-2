# Brainf-ck-2

Recentemente estava aprendendo sobre criação de linguagens, lexers, parsers e AST, então recriei (ou pelo menos tentei recriar) a linguagem Brainf*ck, porém com adicionais:<br>
- 1°: Mudei o modo de criar loops (exemplos abaixo);
- 2°: A linguagem agora é compilada pra bytecode, que será interpretado pela Brainf*ck Virtual Machine.

## Loops
os loops agora funcionam da seguinte maneira:
```brainfuck
LOOP_NUMBER:
  CODE_BLOCK
;
```

**exemplo:**
```brainfuck
32:
  +
;
.>
```
---
Para compilar o **bfc** (BrainF\*ck Compiler), entre em **`brainfuck_compiler/`** e execute o comando _`make`_. Faça o mesmo para o **bfi** (BrainF\*ck Interpreter), localizado na pasta **`brainfuck_interpreter/`**.

Dentro da pasta **`tests/`** há um exemplo de código. Mova todos os arquivos compilados anteriormente para essa pasta.<br>


## Execução do programa
Para compilar um programa Brainf*ck 2, primeiro use:
```bash
./bfc <BF-CODE-FILE>
```
Isso irá criar o arquivo **exit.bfo**<br>
Após isso, use:
```bash
./bfi exit.bfo
```
isso irá executar o arquivo compilado.

Tirando minhas mudanças, a linguagem continua a mesma. Fiz o favor de manter a sintaxe o mais próximo possível da linguagem original.

Espero que gostem dessa versão. Ainda está bem minimalista, mas eu tentei o meu máximo para criar algo legal.  :)

O código está livre para todos alterarem como quiserem! 🩷
