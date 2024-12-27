#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <queue>  // Встроенная библиотека для очереди

#define MAX_NODES 10  // Определите количество вершин графа

// Функция для генерации случайной матрицы смежности для неориентированного графа
void generateAdjacencyMatrix(int matrix[MAX_NODES][MAX_NODES], int numNodes) {
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        for (int j = i; j < numNodes; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = matrix[j][i] = rand() % 2;  // Случайное значение 0 или 1
            }
        }
    }
}

// Функция для вывода матрицы смежности на экран
void printAdjacencyMatrix(int matrix[MAX_NODES][MAX_NODES], int numNodes) {
    printf("Матрица смежности:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Реализация обхода в ширину (BFS) для графа с использованием очереди из библиотеки queue
void bfs(int matrix[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    bool visited[MAX_NODES] = {false};
    std::queue<int> q;  // Создаем очередь
    visited[startNode] = true;
    q.push(startNode);  // Добавляем стартовую вершину в очередь

    printf("Обход в ширину начиная с вершины %d: ", startNode);
    while (!q.empty()) {
        int currentNode = q.front();  // Получаем элемент из начала очереди
        q.pop();  // Удаляем элемент из очереди
        printf("%d ", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (matrix[currentNode][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);  // Добавляем новую вершину в очередь
            }
        }
    }
    printf("\n");
}

// Основная функция
int main() {
    int numNodes = MAX_NODES;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    
    // Генерация и вывод матрицы смежности
    generateAdjacencyMatrix(adjacencyMatrix, numNodes);
    printAdjacencyMatrix(adjacencyMatrix, numNodes);
    
    // Выполнение обхода в ширину
    bfs(adjacencyMatrix, numNodes, 0);
    
    return 0;
}