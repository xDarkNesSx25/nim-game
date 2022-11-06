#include <stdio.h>
#include <stdlib.h>

void gameLogo()
{
    printf("**    *  ***  **   **      ****      *     **   **  *****\n");
    printf("* *   *   *   * * * *     **  *     * *    * * * *  *    \n");
    printf("*   * *   *   *  *  *     *    *   *****   *  *  *  ***  \n");
    printf("*    **  ***  *     *      ****   *     *  *     *  *****\n\n");
}

void menu(char menuInput)
{
    menuInput = '1';

    printf("#########################################################\n");
    printf("Добро пожаловать!\n");
    printf("#########################################################\n");
    printf("1 - Выбрать режим игры\n");
    printf("2 - Правила\n");
    printf("3 - Выход\n");
    printf("Введите: ");
    scanf("%c", &menuInput);
    printf("\n");

    if(menuInput == '1'){
        play();
    }
    else if(menuInput == '2'){
        printf("Правила: имеется три кучи фишек. В свой ход игрок может взять любое кол-во фишек(кроме 0)\nиз любой кучи. Побеждает тот, кто возьмёт последние фишки!\n\n");
        _Exit(EXIT_SUCCESS);
    }
    else if(menuInput == '3'){
        _Exit(EXIT_SUCCESS);
    }
    else{
        printf("Некорректный ввод!\n");
        _Exit(EXIT_SUCCESS);
    }
}

int gameModeChoose()
{
    int gameMode = 0, mode = 0;

    printf("1 - Игра вдвоём\n");
    printf("2 - Игра против ИИ\n");
    printf("Введите: ");
    scanf("%d", &gameMode);
    printf("\n");
    if(gameMode == 1){
        mode = 1;
    }
    else if(gameMode == 2){
        mode = 2;
    }
    else{
        printf("Некорректный режим!\n");
        gameModeChoose();
    }

    return mode;
}

int play()
{
    int game = 1, good = 0;
    int heap = 0, take = 0;
    int heap1 = 3, heap2 = 4, heap3 = 5;
    int counter = 1;
    int mode = gameModeChoose();

    if(mode == 1){
        while(game != 0)
        {
            int inGame = 0;
            if(counter % 2 == 1){
                printf("Ходит первый игрок...");
            }
            if(counter % 2 == 0){
                printf("Ходит второй игрок...");
            }
            printf("\n");

            printf("(%d) ", heap1);
            for(int i = 0; i < heap1; i++){
                printf("*");
            }
            printf("\n");
            printf("(%d) ", heap2);
            for(int i = 0; i < heap2; i++){
                printf("*");
            }
            printf("\n");
            printf("(%d) ", heap3);
            for(int i = 0; i < heap3; i++){
                printf("*");
            }
            printf("\n");

            printf("Введите номер кучи: ");
            scanf("%d", &heap);
            printf("Введите количество фишек для взятия: ");
            scanf("%d", &take);
            printf("\n");

            //cant take from empty heap
            while(inGame == 0){
                if((heap == 1 && heap1 == 0) || (heap == 2 && heap2 == 0) || (heap == 3 && heap3 == 0)){
                    printf("Куча пуста!\n");
                    printf("Введите номер кучи: ");
                    scanf("%d", &heap);
                    printf("Введите количество фишек для взятия: ");
                    scanf("%d", &take);
                }
                else{
                    inGame = 1;
                }
            }

            //checking from which heap to take
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
                printf("Ошибка! Выберите существующую кучу!\n\n");
            }

            //checking for a negative number of elements
            if(heap1 < 0){
                heap1 = 0;
            }
            if(heap2 < 0){
                heap2 = 0;
            }
            if(heap3 < 0){
                heap3 = 0;
            }

            //victory conditions
            if(heap1 == 0 && heap2 == 0 && heap3 == 0){
                game = 0;
                if(counter % 2 == 1){
                    printf("\nФишки кончились.\nПобедил первый игрок!\n");
                }
                if(counter % 2 == 0){
                    printf("\nФишки кончились.\nПобедил второй игрок!\n");
                }
            }
            
            counter++;
        }
    }
    else if(mode == 2){
        while(game != 0){
            int inGame = 0;
            if(counter % 2 == 1){
                printf("Ходит игрок...");
            }
            if(counter % 2 == 0){
                printf("Ходит компьютер...");
            }
            printf("\n");

            printf("(%d) ", heap1);
            for(int i = 0; i < heap1; i++){
                printf("*");
            }
            printf("\n");
            printf("(%d) ", heap2);
            for(int i = 0; i < heap2; i++){
                printf("*");
            }
            printf("\n");
            printf("(%d) ", heap3);
            for(int i = 0; i < heap3; i++){
                printf("*");
            }
            printf("\n");

            //player turn
            if(counter % 2 != 0){
                printf("Введите номер кучи: ");
                scanf("%d", &heap);
                printf("Введите количество фишек для взятия: ");
                scanf("%d", &take);
                printf("\n");

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
                    printf("Ошибка! Выберите существующую кучу!\n\n");
                }
            }
            //bot turn
            else{
                if(heap1 > 1 && heap2 > 1 && heap3 > 1){
                    take = heap1 - 1;
                    heap1 -= take;
                    heap = 1;
                }
                else if(heap1 == 1 && heap2 > 1 && heap3 > 1){
                    take = heap2 - 1;
                    heap2 -= take;
                    heap = 2;
                }
                else if(heap1 == 1 && heap2 == 1 && heap3 > 1){
                    take = heap3;
                    heap3 -= take;
                    heap = 3;
                }
                else if(heap1 == 1 && heap2 == 0 && heap3 == 0){
                    take = heap1;
                    heap1 -= take;
                    heap = 1;
                }
                else if(heap2 == 1 && heap1 == 0 && heap3 == 0){
                    take = heap2;
                    heap2 -= take;
                    heap = 2;
                }
                else if(heap1 == 0 && heap2 == 0 && heap3 != 0){
                    take = heap3;
                    heap3 -= take;
                    heap = 3;
                }
                else if(heap1 != 0 && heap2 == 0 && heap3 == 0){
                    take = heap1;
                    heap1 -= take;
                    heap = 1;
                }
                else if(heap1 == 0 && heap2 != 0 && heap3 == 0){
                    take = heap2;
                    heap2 -= take;
                    heap = 2;
                }
                else{
                    good = 0;
                    while(good != 1)
                    {          
                        heap = rand() % 4;
                        if(heap == 1 && heap1 == 0){
                            heap = rand() % 4;
                        }
                        else if(heap == 2 && heap2 == 0){
                            heap = rand() % 4;
                        }
                        else if(heap == 3 && heap3 == 0){
                            heap = rand() % 4;
                        }
                        else{
                            good = 1;
                            if(heap == 1){
                                take = rand() % heap1 + 1;
                                heap1 -= take;
                            }
                            else if(heap == 2){
                                take = rand() % heap2 + 1;
                                heap2 -= take;
                            }
                            else if(heap == 3){
                                take = rand() % heap3 + 1;
                                heap3 -= take;
                            }
                        }
                    }
                }
                printf("Компьютер взял %d фишек из %d кучи.\n\n", take, heap);
            }

            //checking for a negative number of elements
            if(heap1 < 0){
                heap1 = 0;
            }
            if(heap2 < 0){
                heap2 = 0;
            }
            if(heap3 < 0){
                heap3 = 0;
            }

            //victory conditions
            if(heap1 == 0 && heap2 == 0 && heap3 == 0){
                game = 0;
                if(counter % 2 == 1){
                    printf("\nФишки кончились.\nПобедил игрок!\n");
                }
                if(counter % 2 == 0){
                    printf("\nФишки кончились.\nПобедил компьютер!\n");
                }
            }
        
            counter++;
        }
    }

    return 0;
}

int main()
{
    char menuInput;

    gameLogo();
    menu(menuInput);

    return 0;
}