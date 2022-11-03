El algoritmo de Edmonds-Karp encuentra el flujo máximo en la red de flujo. Es una implementación del método Ford-Fulkerson utilizado para analizar la red de flujo. Edmonds-Karp mejora el tiempo de ejecución de Ford-Fulkerson.


La diferencia entre este algoritmo y el método de Ford-Fulkerson es que el orden de búsqueda se define al encontrar la ruta de aumento. Para encontrar la ruta, usamos una búsqueda en anchura (BFS) aplicando el peso de 1 a cada borde. La ruta encontrada por BFS debe ser la más corta con la capacidad disponible.

![karp](https://i.ytimg.com/vi/L9B0oBQlXQ0/maxresdefault.jpg)

## Ejercicios Relacionados
[Weird Fence UVA - 11262](https://vjudge.net/problem/UVA-11262)

## Referencias
[Wikipedia](https://es.wikipedia.org/wiki/Algoritmo_de_Edmonds-Karp)
[educative.io](https://www.educative.io/answers/what-is-the-edmonds-karp-algorithm)
[Akmal Ahmad](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DL9B0oBQlXQ0&psig=AOvVaw2rz5vo907r6UC7MZxLaUkJ&ust=1667593336312000&source=images&cd=vfe&ved=0CAsQjhxqFwoTCKjHkbjrkvsCFQAAAAAdAAAAABAT)
