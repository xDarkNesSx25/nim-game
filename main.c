#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ку, правила\n");

    int game = 1;
    int heap = 0, take = 0;
    int heap1 = 3, heap2 = 4, heap3 = 5;
    int counter = 1;
    while(game != 0)
    {
        int ladno = 0;
        if(counter % 2 == 1){
            printf("Ходит первый игрок: ");
        }
        if(counter % 2 == 0){
            printf("Ходит второй игрок: ");
        }
        printf("%d %d %d\n", heap1, heap2, heap3);
        printf("Откуда брать и сколько\n");
        scanf("%d %d", &heap, &take);
        while(ladno == 0){
            if((heap == 1 && heap1 == 0) || (heap == 2 && heap2 == 0) || (heap == 3 && heap3 == 0)){
                printf("Куча пуста!\n");
                scanf("%d %d", &heap, &take);
            }
            else{
                ladno = 1;
            }
        }

        if(heap == 1){
            if(heap1 != 0){
                heap1 -= take;
            }
        }
        else if(heap == 2){
            if(heap2 != 0){
                heap2 -= take;
            }
        }
        else if(heap == 3){
            if(heap3 != 0){
                heap3 -= take;
            }
        }
        else{
            printf("неправильно\n");
        }

        if(heap1 < 0){
            heap1 = 0;
        }
        if(heap2 < 0){
            heap2 = 0;
        }
        if(heap3 < 0){
            heap3 = 0;
        }

        if(heap1 == 0 && heap2 == 0 && heap3 == 0){
            game = 0;
            if(counter % 2 == 1){
                printf("Фишки кончились.\nПобедил первый игрок!\n");
            }
            if(counter % 2 == 0){
                printf("Фишки кончились.\nПобедил второй игрок!\n");
            }
        }
        
        counter++;
    }
}