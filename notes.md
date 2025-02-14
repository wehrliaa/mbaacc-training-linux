3 opções:
	1. re-escrever o training antigo em C ou C++, adaptando código do training novo v1.6b
	2. ~~fazer um port do training antigo pra Linux, escrito em Python ou C ou C++, fazendo comunicação com o jogo via putaria do wine~~ Não parece ser possível, ou no mínimo, um estresse enorme por motivo nenhum.
	3. ~~consertar o training novo v1.6b~~ Boa sorte lidando com mais de 7000 linhas de código.

1. while loop até o jogo abrir
2. achar o pid do jogo por nome
3. achar o base address do jogo (?)
4. loop principal

Read/WriteProcessMemory parecem funcionar corretamente sem adicionar o base addres do processo ao endereço usado pelas funções, e incorretamente se eu adicionar o base address. hmmmmmm.

deixa, eu tava usando 0063fe9c como endereço da variável no 123456.exe ao invés de 63fe9c.

deixa de novo, eu tinha esquecido de adicionar o base address, logo 0063fe9c e 63fe9c são a mesma coisa (meio óbvio mas eu sou burrinha).
