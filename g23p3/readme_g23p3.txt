Miguel Paradinha 84150
Milton Freitas 84152

- foi criado um Makefile que permite compilar todos os exercicios

1.a)
    - a equação utilizada para obter tt1 a partir de tt0 é a seguinte:
    tt1[i][j] = tt0[i][j] + ((k*ht)/(hx*hx)) * (tt0[i][j+1] - 2 *tt0[i][j] + tt0[i][j-1]) + ((j*ht)/(hy*hy)) * (tt0[i+1][j] - 2*tt0[i][j] + tt0[i-1][j])
    - Reparamos que esta equação de Fourier possui uma derivada em relação ao tempo enquanto que a de Poisson não pelo que temos um termo extra a ter em conta. A equação de Fourier também não tem um termo não homogénio como a carga na equação de Poisson pelo que não se tem de ter em conta aqui.

1.b)
    - como foi aproveitada apenas uma função (create_matrix) do código desenvolvido nos laboratórios não considerámos necessário a inclusão de ficheiros inteiros

1.c)
    No limite deveria ser um plano. 

2.a)
    - a classe vetor encontra-se no ficheiro vector.h e o conjunto de testes no ficheiro test_vector.cpp
    - no overload dos operadores foram seguidas as normas mais aceitadas dentro da comunidade de C++
    - foi utilizada para esta alínea o código escrito durante os laboratórios que implementa uma classe Vector (para vetores de qualquer dimensão)
    - apesar de a compilação ser atrasada pelo facto de o código se encontrar todo no header (em oposição a definir apenas no header e implementar num ficheiro fonte) considerou-se que num projecto desta magnitude o efeito seria insignificante, neste contexto (pois apenas um ficheiro requer cada um dos headers)

2.b)
    - o codigo fonte para este exercício encontra-se em g23p3c2.cpp sendo possível compilar com o comando "make ex2"

2.c)
    - para esta classe foram criados apenas os operadores mais comuns (e que eram necessários para a resolução), de modo a não perder tempo desnessário
    - o codigo fonte para este exercício encontra-se em g23p3c2c.cpp sendo possível compilar com o comando "make ex2c"
