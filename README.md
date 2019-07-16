# CG2019.1
## 1° Trabalho prático da disciplina introdução à computação gráfica
## Professor: Christian Azambuja Pagot
## Aluno: Renan Paiva Oliveira Costa

# Atividade
  Nesta primeira atividade os alunos deverão implementar algoritmos para a rasterização de pontos e linhas. 
Triângulos deverão ser desenhados através da rasterização das linhas que compõem suas arestas.
  A rasterização destas primitivas será feita através da escrita direta na memória. Como os sistemas 
  operacionais atuais protegem a memória quanto ao acesso direto, os alunos deverão utilizar um framework, 
  fornecido pelo professor, que simula o acesso à memória de vídeo. 
  
## Funções implementadas:
• **putPixel**: Função que rasteriza um ponto na memória de vídeo, recebendo como parâmetros a posição do pixel na tela (x,y) e sua cor (RGBA).
 
• **drawLine**: Função que rasteriza uma linha na tela, recebendo como parâmetros os seus vértices (inicial e final, representados respectivamente pelas tuplas (x,y) e (x1,y1)), e as cores (no formato RGBA) de cada vértice. As cores dos pixels ao longo da linha rasterizada devem ser obtidas através da interpolação linear das cores dos vértices.
O algoritmo de rasterização implementado baseado no algoritmo de Bresenham.
    O Algorítimo de Bresenham utiliza a equação geral da reta para decidir qual ponto no eixo y deve ser pintado.
    
 ```  
if(dx > dy) {
x += pX;
p += dy;

if(p >= dx) 
{
y += pY;
p -= dx;
}
            } 
else {
y += pY;
p += dx;

if(p >= dy) 
{
x += pX;
p -= dy;
}
     }
```

• **drawTriangle**: Função que desenha as arestas de um triângulo na tela, recebendo como parâmetros as posições dos três vértices (x,y), (x1,y1) e (x2,y2) 
bem como as cores (RGBA) de cada um dos vértices.

A interpolação das cores dos pontos é feita automaticamente pelas funções ao chamar a função mixColors que utiliza a 
porcentagem da posição do ponto na reta para determinar a mistura das cores dos pontos inicial e final.

## Execução do Programa

  Deve-se escolher qual função usar especificamente descomentando no código os trechos necessários. A execução usa um sistema simples de entrada
  de dados pelo terminal durante a execução para receber as cordenadas e cores para serem utilizadas nas funções
  
  • **putPixel**: Recebe a coordenada do ponto no formato **x y** e a cor no formato **r g b a**
    Exemplo: 50 50 255 0 0 255
  
  • **drawLine**: Recebe as coordenadas dos pontos no formato **x y x1 y1** e as cores **r g b a r1 g1 b1 a1**
    Exemplo: 50 50 40 200 255 0 0 255 0 255 0 255
    
  • **drawTriangle**: Recebe as coordenadas dos pontos no formato **x y x1 y1 x2 y2** e as cores **r g b a r1 g1 b1 a1 r2 g2 b2 a2**
    Exemplo: 50 50 100 200 100 50 255 0 0 255 0 255 0 255 0 0 255 255

### Considerações finais e dificuldades
O Algorítimo de Bresenham é bem interessante de ser implementado, mas sua parte mais complicada de implementar foi a definição dos quadrantes para o funcionamento do mesmo. O programa deixa margem para otimizações de desempenho com um estudo mais aprofundado, pois para a rasterização de muitas linhas em alta resolução pode consumir mais poder computacional do que o realmente necessário.

# **Referências Bibliográficas**
- Notas de Aula do Prof. Christian
- [Rasterização em C/C++ (Algorítmo de Bresenham)](https://bitunico.wordpress.com/2012/12/16/rasterizacao-em-cc-algoritmo-de-bresenham/)
- [The Bresenham Line-Drawing Algorithm](https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html)
- [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
