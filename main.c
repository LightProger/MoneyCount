#include <stdio.h>

int main(void)
{
    //Переменные
    float owed = 0.0;
    int CentCount;
    int rest = 0;
    int i;

    //Массивы
    int MoneyCount[4] = {0, 0, 0, 0};
    int del[4] = {25, 10, 5, 1};

    printf("Привет! Сколько я должен сдачи?\n");

    //Ввод данных
    scanf("%f", &owed);
    printf("\n");

    if (owed <= 0.0){ printf("Я Вам ничего не должен!\n"); }
    else
    {
        //выясняем общее число центов в сдаче
        owed = owed * 100.0;
        CentCount = (int) owed;

        //считаем
        for(i=0; i<4; i++)
        {
            MoneyCount[i] = CentCount / del[i];
            CentCount = CentCount % del[i];
            rest = rest + MoneyCount[i];
            if (MoneyCount[i]>0)					// добавим печать количества монет
            {
                printf("  %i монет",MoneyCount[i]);
                if (MoneyCount[i]==1)			// с проверкой на окончания
                {
                    printf("а");
                }
                if (MoneyCount[i]>1 && MoneyCount[i]<5)
                {
                    printf("ы");
                }
                printf(" по %i ¢\n", del[i]);
            }
        }

        //выводим результат на экран
        printf("\nВсего в нашей сдаче %i монет", rest);
        if(rest==1){ printf("а"); }
        if(rest>1 && rest<5){ printf("ы"); }
        printf("\n");
    }

    return 0;
}
