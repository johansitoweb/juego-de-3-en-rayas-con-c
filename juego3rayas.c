#include <stdio.h>  

char board[3][3]; // Tablero de juego  

// Función para inicializar el tablero  
void inicializar_tablero() {  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 3; j++) {  
            board[i][j] = ' '; // Rellenar el tablero con espacios  
        }  
    }  
}  

// Función para mostrar el tablero  
void mostrar_tablero() {  
    printf("\n");  
    for (int i = 0; i < 3; i++) {  
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);  
        if (i < 2) {  
            printf("---|---|---\n");  
        }  
    }  
    printf("\n");  
}  

// Función para comprobar si hay un ganador  
int comprobar_ganador() {  
    // Comprobar filas y columnas  
    for (int i = 0; i < 3; i++) {  
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||  
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {  
            return 1; // Hay un ganador  
        }  
    }  

    // Comprobar diagonales  
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||  
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {  
        return 1; // Hay un ganador  
    }  

    // Comprobar si hay un empate  
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (board[i][j] == ' ') return 0; // Aún hay movimientos disponibles  

    return 2; // Empate  
}  

// Función principal  
int main() {  
    int fila, columna, resultado;  
    char jugador = 'X';  

    inicializar_tablero();  

    do {  
        mostrar_tablero();  
        printf("Jugador %c, ingresa fila (0-2) y columna (0-2): ", jugador);  
        scanf("%d %d", &fila, &columna);  

        // Verificar si la posición es válida  
        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && board[fila][columna] == ' ') {  
            board[fila][columna] = jugador; // Marcar el tablero  
            resultado = comprobar_ganador(); // Comprobar el resultado  
            if (resultado == 1) {  
                mostrar_tablero();  
                printf("¡Jugador %c ha ganado!\n", jugador);  
                break;  
            } else if (resultado == 2) {  
                mostrar_tablero();  
                printf("¡Es un empate!\n");  
                break;  
            }  
            jugador = (jugador == 'X') ? 'O' : 'X'; // Cambiar de jugador  
        } else {  
            printf("Movimiento inválido, intenta de nuevo.\n");  
        }  
    } while (1);  

    return 0;  
}