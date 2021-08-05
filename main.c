#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linhas 10
#define colunas 20

int x,y,z,u,a,b,num;
char letra[1],matriz[linhas][colunas],matrizz[linhas][colunas];

void preencher_matriz(char matriz[10][20]){
  for(int i=0;i<10;i++){
    for(int j=0;j<20;j++){
      matriz[i][j] = '0';
      matriz[x][y] = 'X';
    }
  }
}

void preencher_matriz2(char matriz[10][20],char matrizz[10][20]){

  srand(time(NULL));
    
  for(int z=0;z<10;z++){
    for(int u=0;u<20;u++){
      matrizz[z][u] = '0';    
      matrizz[x][y] = 'X';
    }
  }
  for(int i=0;i<50;i++){
    a = rand() % 10;
    b = rand() % 20;
    if(matrizz[a][b] == '#' || matrizz[a][b] == 'X'){
      i--;
      continue;
    }
      matrizz[a][b] = '#';
    }
}

void mostrar_matriz(char matriz[10][20]){
  //system("clear");
  for(int i=0; i<10; i++){
    for(int j=0; j<20; j++){
      printf("%c ",matriz[i][j]);
    }
    printf("\n");
  }
}

void mostrar_matriz2(char matrizz[10][20]){
  //system("clear");
  for(int z=0; z<10; z++){
    for(int u=0; u<20; u++){
      printf("%c ",matrizz[z][u]);
    }
    printf("\n");
  }
}

void comando(){

  scanf(" %*c%s%*c%d%*c", &letra[0], &num);
  fflush(stdin);

  if(letra[0] == 'n'){
    //x -= num;
   for(int d=0;d<num;d++){
     a--;
     x--;
     if(matriz[x][y] == '1'){
       a++;
       x++;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       a--;
       x--;
       matrizz[a][b] = 'X';
       matriz[x][y] = 'X';
     }else if(matrizz[x][y] == '#'){
       printf("FAILED\n");
       matriz[x][y] = '#';
       a++;
       x++;
       break;
     }
     if(matriz[x][y] == '#'){
       a++;
       x++;
       printf("FAILED\n");
       break;
     }else{
       a++;
       x++;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       a--;
       x--;
       matrizz[x][y] = 'X';
       matriz[x][y] = 'X';
     }
     if(d == num - 1){
       printf("SUCCESS\n");
     }
     if(letra[0] == '\0'){
       printf("teste");
     }
   }
    //
  }else if(letra[0] == 's'){
    //x += num;
   for(int d=0;d<num;d++){
     a++;
     x++;
     if(matriz[x][y] == '1'){
       a--;
       x--;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       a++;
       x++;
       matrizz[a][b] = 'X';
       matriz[x][y] = 'X';
     }else if(matrizz[x][y] == '#'){
       printf("FAILED\n");
       matriz[x][y] = '#';
       a--;
       x--;
       break;
     }
     if(matriz[x][y] == '#'){
       a--;
       x--;
       printf("FAILED\n");
       break;
     }else{
       a--;
       x--;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       a++;
       x++;
       matrizz[x][y] = 'X';
       matriz[x][y] = 'X';
     }
     if(d == num - 1){
       printf("SUCCESS\n");
     }
   }
    //
  }else if(letra[0] == 'l'){
    //y += num;
    for(int d=0;d<num;d++){
     b++;
     y++;
     if(matriz[x][y] == '1'){
       b--;
       y--;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       b++;
       y++;
       matrizz[a][b] = 'X';
       matriz[x][y] = 'X';
     }else if(matrizz[x][y] == '#'){
       printf("FAILED\n");
       matriz[x][y] = '#';
       b--;
       y--;
       break;
     }
     if(matriz[x][y] == '#'){
       b--;
       y--;
       printf("FAILED\n");
       break;
     }else{
       b--;
       y--;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       b++;
       y++;
       matrizz[x][y] = 'X';
       matriz[x][y] = 'X';
     }
     if(d == num - 1){
       printf("SUCCESS\n");
     }
   }
    //
  }else if(letra[0] == 'o'){
    //y -= num;
    for(int d=0;d<num;d++){
     b--;
     y--;
     if(matriz[x][y] == '1'){
       b++;
       y++;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       b--;
       y--;
       matrizz[a][b] = 'X';
       matriz[x][y] = 'X';
     }else if(matrizz[x][y] == '#'){
       printf("FAILED\n");
       matriz[x][y] = '#';
       b++;
       y++;
       break;
     }
     if(matriz[x][y] == '#'){
       b++;
       y++;
       printf("FAILED\n");
       break;
     }else{
       b++;
       y++;
       matrizz[x][y] = '1';
       matriz[x][y] = '1';
       b--;
       y--;
       matrizz[x][y] = 'X';
       matriz[x][y] = 'X';
     }
     if(d == num - 1){
       printf("SUCCESS\n");
     }
   }
    //
  }else if(letra[0] == '0' && num == 0){
    //system("clear");
  for(int i=0; i<10; i++){
    for(int j=0; j<20; j++){
      printf("%c ",matriz[i][j]);
    }
    printf("\n");
   }
  }
}

int main(void) {
  srand(time(NULL));
  x = rand() % 10;
  y = rand() % 20;

  preencher_matriz(matriz);
  preencher_matriz2(matriz,matrizz);
  printf("Digite o seu comando no seguinte formato: orientação movimentos\n");
  
  while(1){
    comando();
  }
}