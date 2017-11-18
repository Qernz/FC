Miguel Paradinha 84150
Milton Freitas 84152


1)a)
Equação pedida:
tt1[i][j] = tt0[i][j] + ((k*ht)/(hx*hx)) * (tt0[i][j+1] - 2 *tt0[i][j] + tt0[i][j-1]) + ((k*ht)/(hy*hy)) * (tt0[i+1][j] - 2 *tt0[i][j] + tt0[i-1][j])

A equação de Poisson apenas possuí derivadas em função do espaço, enquanto que  
a equação de Fourier possuí tanto derivadas no espaço como no tempo. Assim haverá 
um termo adicional a ter em conta. Outra diferença é que esta equação de Fourier aqui
tomada é homogénea enquanto que a equação de Poisson tinha de ter em conta a 
carga.