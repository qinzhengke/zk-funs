#include <cstdio>
#include <cstdint>

struct RingMatrix{

    uint8_t mem[16] = {16,13,14,15,4,1,2,3,8,5,6,7,12,9,10,11};
    int col_s=1, row_s=1;
    uint8_t at(int row, int col){
        int mem_row = (row + row_s) % 4;
        int mem_col = (col + col_s) % 4;
        return mem[mem_row*4+mem_col];
    }

    void move(int drow, int dcol){
        col_s = (col_s - dcol + 4)%4;
        row_s = (row_s - drow + 4)%4;
    }

    void print(){

        printf("=======\n");
        for(int r=0; r<4; r++){
            for(int c=0; c<4; c++){
                printf("%u\t ", at(r,c));
            }
            printf("\n");
        }
    }
};

int main(void){

    RingMatrix rm;

    rm.print();

    rm.move(-1,-1);

    rm.print();


    return 0;

}