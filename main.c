#include <stdio.h>
#include <stdlib.h>

void gameLogo()
{
    printf("**    *  ***  **   **      ****      *     **   **  *****\n");
    printf("* *   *   *   * * * *     **  *     * *    * * * *  *    \n");
    printf("*   * *   *   *  *  *     *    *   *****   *  *  *  ***  \n");
    printf("*    **   *   *     *      ****   *     *  *     *  *****\n\n");
}

void menu(char menuInput)
{
    printf("#########################################################\n");
    printf("Добро пожаловать!\n");
    printf("1 - Выбрать режим игры\n");
    printf("2 - Правила\n");
    printf("3 - Выход\n");
    printf("Введите: ");
    scanf("%c", &menuInput);
    printf("\n");

    if(menuInput == '1'){
        gameModeChoose();
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
    int game = 1;
    int heap = 0, take = 0;
    int heap1 = 3, heap2 = 4, heap3 = 5;
    int counter = 1;

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
                scanf("%d %d", &heap, &take);
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
            printf("неправильно\n");
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
                printf("Фишки кончились.\nПобедил первый игрок!\n");
            }
            if(counter % 2 == 0){
                printf("Фишки кончились.\nПобедил второй игрок!\n");
            }
        }
        
        counter++;
    }
    printf("Старт игры\n");
    return 0;
}

int main()
{
    char menuInput;

    gameLogo();
    menu(menuInput);

    return 0;
}