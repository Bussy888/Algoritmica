# BIT o Arbol De Fenwick
Un árbol binario indexado o árbol de Fenwick es una estructura de datos que proporciona métodos eficientes para el cálculo y la manipulación de las cantidades de prefijos de una array de valores. Fue propuesto por Boris Ryabko en 1989 con una modificación posterior publicada por el mismo autor en 1992. Luego volvió a ser conocida como árbol de Fenwik tras la publicación del artículo de Peter Fenwick en 1994.  El Fenwick Tree principalmente resuelve el problema de equilibrar la eficiencia de la suma del prefijo con la eficiencia de modificar un elemento. La eficacia de estas operaciones se presenta como una solución de compromiso, (dado que una mayor eficiencia en el cálculo de la suma del prefijo se consigue precalculando los valores, pero una vez que los valores son precalculados, debe volverse a calcular cada vez que ocurra una modificación). Esto haría O(1) las consultas pero las modificaciones serían O(n). El Fenwick Tree hace ambas operaciones en O(log n), donde n es el tamaño del array.

![BIT](https://prodeportiva.files.wordpress.com/2013/02/abi11.png)
## Ejercicios Relacionados
[Supercomputers](https://open.kattis.com/problems/supercomputer)

## Referencias
[Wikipedia](https://es.wikipedia.org/wiki/%C3%81rbol_binario_indexado)

[Programacion Competitiva Mexico](https://www.youtube.com/watch?v=fPAEZloj2L0)
