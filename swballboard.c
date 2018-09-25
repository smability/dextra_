#include<stdio.h>
#include <stdlib.h>

int main() {
    /*3x3 dimensional array is the board-switch-ball matrix*/
    int b[3][3] = {{-1,0,-1}, //[0,0] element should be different to 0
                   {1,0,0},
                   {0,0,0}}; //is b[3][3] necesary?? or b[][] is also ok??
    
    int i;//i index of columns
    int j;//j index of rows
    int k;// number of balls entering the board
    int count; //balls exiting the board at the bottom edge

    /*output elements of b[][]*/
    for (int i = 0; i<3; i++){ 
        for(int j=0; j<3; j++){ 
            printf("%d ", b[i][j]); //print all elements of b[][]
            if(j==2){
                printf("\n");
            }
        }
    }
    //b[rows][columns] b[x][y] b[i[j]
    int x = 0;
    int y = 0;
    
    k = 4; //number of balls
    count=0; //count is initialized to zero
     
    /*
    Conditions:
    1.  it is square-shaped;
    2.  it can be in one of three modes: −1, 0 or +1;
    3.  a ball can enter it through the top or the left edge; (inside the board only, see point B)
    4.  a ball can leave it through the bottom or the right edge;
    5.  if the mode is −1, a ball entering the device will leave it through the bottom edge;
    6.  if the mode is +1, a ball entering the device will leave it through the right edge;
    7.  if the mode is 0, a ball entering the device will not change direction;
    8.  after a ball leaves the device, its mode is immediately negated.
    
    A.K balls are rolled through the board one by one. 
    B.Each ball enters the board through the top edge of the top-left ball switch. 
    C.Then it rolls through the board and possibly changes its direction depending on the modes of the switches through which it passes.
    
    Eventually it leaves the board either:
        a.through the bottom edge of one of the switches in the bottom row; or
        b.through the right edge of one of the switches in the rightmost column.
    
    board layout
        in            
       [0][0],[0][1],[0][2]    
       [1][0],[1][2],[1][2]    
       [2][0],[2][1],[2][2] 
                      out
    */
    
    /*all balls enter at [0][0]*/
    while (k>0){
            /*track ball position*/
            if(b[x][y] == 1){
                //change board state
                b[x][y] = -1;
                //move ball to the right
                y++;
                
                //print ball position and STATE
                //printf("ball position b[%d][%d] = %d\n", x,y,b[x][y]);
                
                //right-button edge bottom edge counter
                if( (y == 2) && (x == 2)){ //the ball has exit the board
                    count++;
                    printf("number of balls comming from right-button edge = %d\n", count);
                }
                
                if ((y == 3)||(x == 3)){ 
                    k--;//a ball leaves the board
                    y = 0;
                    x = 0;
                }
            }
            else if(b[x][y] == -1) {
                //change board state
                b[x][y] = 1;
                //move ball to the bottom
                x++;
                //print ball position and STATE
                //printf("ball position b[%d][%d] = %d\n", x,y,b[x][y]);
                //right-button edge bottom edge counter
                if( (y == 2) && (x == 2)){
                    //the ball has exit the board
                    count++;
                    printf("number of balls comming from right-button edge = %d\n", count);
                }
                
                if ((y == 3)||(x == 3)){
                    k--;
                    y = 0;
                    x = 0;
                }
            }
            else if(b[x][y] == 0)
            { 
                //printf("ball is at b[%d][%d] = %d\n",x,y,b[x][y]);
                /*Ask for the previous ball position (donwards case)*/
                if(b[x-1][y]==1){ //-1 previous position is no longer -1 but 1, because STATE was negated at the output of the previous STATE
                    x++;//continue moving downwards
                }
                else if(b[x-1][y]==0){
                    x++;//continue moving downwards
                }
                
                /*Ask for the previous ball position (right case)*/
                if(b[x][y-1]==-1){ //-1 previous position is no longer -1 but 1, because STATE was negated at the output 
                                  // of the previous STATE
                    y++;//continue moving to the right
                }
                else if(b[x][y-1]==0){
                    y++;//continue moving to the right
                }
                
                //right-button edge bottom edge counter
                if((y == 2) && (x == 3)){ //the ball has exit the board
                    count++;
                    printf("number of balls comming from right-button edge = %d\n", count);
                }
                if ((y == 3)||(x == 3)){
                    k--;
                    y = 0;
                    x = 0;
                }
                
                //printf("ball is at b[%d][%d]\n",x,y);
            }
            else{
                printf("Invalid satate!\n");
            }
             
        }
    
    /*output updated elements of b[][]*/
    for (int k = 0; k<3; k++){ 
        for(int l=0; l<3; l++){ 
            printf("%d ", b[k][l]); //print elements of b[][]
            if(l==2){
                printf("\n");
            }
        }
    }
}
