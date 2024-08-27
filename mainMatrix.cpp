#include <stdio.h>
#include <math.h>


void Transpose (int *data_transpose, const int *data, size_t sizeX, size_t sizeY)
{

    for (int x = 0; x < sizeX; x++)

        for (int y = 0; y < sizeY; y++)

                *(data_transpose + x * sizeY + y) = *(data + y * sizeX + x);


}

void MultipleNumber (const int k, const int *data, int *data_multiple_number , size_t sizeY, size_t sizeX)
{
    for (size_t y = 0; y < sizeY; y++)

        for (size_t x = 0; x < sizeX; x++)

            *(data_multiple_number + y * sizeX + x) = k * (*(data + y * sizeX + x));


}

void SumMatrixes (const int *data1, const int *data2, int *data_sum, size_t sizeY, size_t sizeX)
{
    for (size_t y = 0; y < sizeY; y++)

        for (size_t x = 0; x < sizeX; x++)

            *(data_sum + y * sizeX + x) = *(data1 + y * sizeX + x) + *(data2 + y * sizeX + x);


}

int ElementOfMultipleMatrixes (int *data1, int *data2, size_t sizeX1, size_t sizeX2)
{
    int element = 0;
    for (int x = 0; x < sizeX1; x++)
    {
        element += ((*(data1 + x)) * (*(data2 + x * sizeX2)));
        printf ("%d * %d ", *(data1 + x), *(data2 + x * sizeX2));
    }
    printf ("%d \n", element);
    return element;

}

void MultipleMatrixes (int *data1, int *data2, int *data_multiple_matrix, size_t sizeY1, size_t sizeX1, size_t sizeY2, size_t sizeX2)
{


    for (size_t y = 0; y < sizeY1; y++)
        for (size_t x = 0; x < sizeX2; x++)
            *(data_multiple_matrix + y * sizeX2 + x) = ElementOfMultipleMatrixes(data1 + y * sizeX1, data2 + x, sizeX1, sizeX2);


}

void Print (const int *data, size_t sizeY, size_t sizeX)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
            printf ("data[%lu][%lu] = %d ", y, x, *(data + y * sizeX + x));
        }
        printf("\n");
    }

}

int FindScore (int first_team, int second_team, int *match_table )
{
    if (second_team < first_team)
    {
        int temp = second_team;
        second_team = first_team;
        first_team = temp;
    }


    int sum = ((first_team - 1) * (first_team)) / 2;
    return *(match_table + sum + second_team);

}

int main ()
{
    //int sizeX = 3, sizeY = 4 ;
    //int **data = {{11, 12, 13}, // not compiled
    int data[4][3]= {
                    {11, 12, 13},
                    {21, 22, 23},
                    {31, 32, 33},
                    {41, 42, 43}
                   };
    size_t sizeY = sizeof(data) / sizeof(*(data));
    size_t sizeX = sizeof(*data) / sizeof(**data);

    int data_transpose [sizeX][sizeY] = {};
    int data_multiple_number [sizeY][sizeX] = {};
    int data_sum [sizeY][sizeX] = {};

    const int k = 2;
    //MultipleNumber(k, *data, *data_multiple_number, sizeY, sizeX);
    //Transpose (*data_transpose, *data, sizeX, sizeY);
    //SumMatrixes (*data, *data_multiple_number, *data_sum, sizeY, sizeX);
    int data1 [2][3] = {{1, 2, 3},
                        {4, 5, 6}
                       };
    int data2 [3][4] = {{1,  2,  3,  4},
                       {5,  6,  7,  8},
                       {9, 10, 11, 12}
                      };

    size_t sizeY1 = 2;
    size_t sizeX1 = 3;
    size_t sizeY2 = 3;
    size_t sizeX2 = 4;
    int data_multiple_matrix [sizeY1][sizeX2] = {};


    int match_table[6] = { 1, 2, 3, 4, 5, 6 };
    printf ("%d", FindScore(3, 0, match_table));


    // Print(*data_multiple_matrix, sizeY1, sizeX2);

    // MultipleMatrixes(*data1, *data2, *data_multiple_matrix, sizeY1, sizeX1, sizeY2, sizeX2);
    //printf ("%d %d %d", **data2 , *(*data2 + 1 * 4 ), *(*data2 + 2 * 4));
    // printf ("%d", ElementOfMultipleMatrixes(*data1, *data2 , sizeX1, sizeX2));

    // print sizeX sizeY
    //printf ("sizeY = %d, sizeX = %d \n", sizeY, sizeX);

    //int x = 2, y = 1; // print [y][x] with sizeof
    //printf ("data [%d][%d] = %d", y, x, *(int *)((size_t)data + (y * sizeX + x) * sizeof(int)));

    // print data[1]
    // printf ("data[1] = { ");
    // for (int x = 0; x < 3; x++)
    //     printf("%d ", *((int *) data + 1 * sizeX + x));
    // printf ("}");

}
