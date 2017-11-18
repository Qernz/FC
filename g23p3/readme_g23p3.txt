Miguel Paradinha 84150
Milton Freitas 84152

- foi criado um Makefile que permite compilar todos os exercicios 

1.a)
    - a equação utilizada para obter tt1 a partir de tt0 é a seguinte:
    tt1[i][j] = tt0[i][j] + ((k*ht)/(hx*hx)) * (tt0[i][j+1] - 2 *tt0[i][j] + tt0[i][j-1]) + ((j*ht)/(hy*hy)) * (tt0[i+1][j] - 2*tt0[i][j] + tt0[i-1][j])
    - <COMENTARIO SOBRE A POISSON/LAPLACE>

1.b)
    - como foi aproveitada apenas uma função (create_matrix) do código desenvolvido nos laboratórios não considerámos necessário a inclusão de ficheiros inteiros

2.a)
    METER AQUELE COMENTARIO DO .H DO VECTOR AQUI EM VEZ DE LA, e em portugues
