# LixeiraInteligente
Repositório para o trabalho desenvolvido na disciplina de PIC1

## Conteúdo
- [Conteúdo](#conteúdo)
- [Resumo](#resumo)
- [Descrição](#descrição)
- [Componentes/Materiais](#componentes)
- [Resultado](#resultado)
- [Autores](#autores)

## Resumo

A ideia do projeto foi utilizar os sensores ultrassônicos para agregar comodidade e informação para as lixeiras que temos hoje em dia. A ideia não é novidade tendo em vista que é possivel encontrar no mercado produtos que possuem a mesma funcionalidade.

## Descrição

O projeto abre e fecha a tampa utilizando um sensor ultrassônico e um micro servo motor, além de também informar se a lixeira está cheia ou não, tudo isso controlado pelo arduino. 

Para a lixeira decidir se deve realizar uma ação, seja ela de abrir ou de fechar a tampa, ela precisa de duas verificações, a primeira verifica se o usuario quer realizar uma ação, para isso é necessario que exista algum movimento a menos de 5 cm do sensor, se existir, ela verifica qual é o estado atual da tampa, ou seja, fechada ou aberta, e se ela estiver fechada a lixeira entende que o usuario quer na verdade abrir a tampa, mas se a tampa estiver aberta ela entende que o usuario quer na verdade fechar a tampa, depois disso em ambos os casos ela realiza a ação utilizando o servo motor. Agora para avisar que a lixeira está lotada ela acende um led vermelho que avisa caso o lixo esteja a menos de 10 cm da tampa.

## Componentes/Materiais

- Arduino Uno
- 2x Sensor Ultrassônico HC-SR04
- Micro Servo Motor 9g SG90
- LED de cor vermelha
- Lixeira de plástico
- Tampa de papelão
- Fundo falso de papelão
- Jumpers
- Fonte de alimentação 9v 1a

## Resultado

Vídeo com o resultado -> [Link](https://youtube.com/)

## Autores

- Anderson -> [@juniorcamisa10](https://github.com/juniorcamisa10)
- Lucas -> [@LucasPBrioschi](https://github.com/LucasPBrioschi)
- Wilkis Gabriel -> [@](https://github.com/)
- Yuri -> [@YuriVictoria](https://github.com/YuriVictoria)
