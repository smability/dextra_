#include <stdio.h>
#include <stdlib.h>

/*function definition*/
int genericboard(int N, int M, int k);
int random_number(void);

int main() {
    printf("Balls comming from right-button edge = %d\n", genericboard(10, 10, 70));
	return 0;
}

int random_number(void)
{
return rand() % 3; //random between 0,1,2
}

/*function definition*/
int genericboard(int N, int M, int k){
    
    int b[N][M]; //N=rows, M=columns, board declaration 
    int count;
    int i,j; //matrix indexes
    int rows,columns;
    int right;
    int down;
    int STATE[]={0,1,-1}; //board states
    int randomIndex;
    
    printf("Number of balls %d: \n", k);
    printf("Board size %d x %d: \n", N,M);
    //build a N*M matrix and assign element to every location
    printf("Switch board initial states: \n");
    for (i=0; i<N; i++){//rows
        for(j=0; j<M; j++){//columns
            //randomIndex = random_number();
            //n = 2; //for every iteration n should change between 0,1,2
            b[i][j] = STATE[random_number()];//board STATE
            printf("%d ", b[i][j]);
            if (j==M-1){ //column break
                printf("\n");
            }
        }
    }
    
    /*assign rows and columns value*/
    rows = N;
    columns = M;
    
    /*initial conditions*/
    N = 0;
    M = 0;
    count=0; //ball counter 
    
    /*board algorithm N=x, M=y*/
    while (k>0){
            if(b[N][M] == 1){ //track ball position
            
                right = 1;
                down = 0;
                
                b[N][M] = -1;//change board state
                M++;//move ball to the right
                
                /*right-button edge counter.*/
                if( (M == columns-1) && (N == rows)){ 
                    count++;//ball exit-counter
                }
                /*ball leaving the board*/
                if ((M == columns)||(N == rows)){ 
                    k--;//ball leaves the board
                    M = 0;
                    N = 0;
                }
            }
            else if(b[N][M] == -1) {
            
                right = 0;
                down = 1;
                
                b[N][M] = 1;//change board state
                N++;//move ball downwards
                
                /*right-button edge counter.*/
                if( (M == columns-1) && (N == rows)){
                    count++; //ball exit-counter
                }
                /*ball leaving the board*/
                if ((M == columns)||(N == rows)){
                    k--;
                    M = 0;
                    N = 0;
                }
            }
            else if(b[N][M] == 0)
            { 
                if (right == 1){
                    M++; //continue moving to the right
                }
                else{
                    N++; //continue moving down
                }
                
                /*
                if (down == 1)
                {
                    N++; //continue moving down
                }
                */
                /*right-button edge counter.*/
                if((M == columns-1) && (N == rows)){
                    count++; //count number of balls leaving the board
                }
                /*ball leaving the board*/
                if ((M == columns)||(N == rows)){ 
                    k--;
                    M = 0;
                    N = 0;
                }
            }
            else{
                printf("Invalid satate!\n");
            }
    }
    printf("Switch board final states:\n");
    /*output updated elements of b[][], or new board STATES*/
    for (int k=0; k<rows; k++){ 
        for(int l=0; l<columns; l++){ 
            printf("%d ",b[k][l]); //print elements of b[][]
            if(l==columns-1){
                printf("\n");
            }
        }
    }
    
    return count;
}


