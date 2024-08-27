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

void MultipleMatrixes (const int *data1, const int *data2, int *data_multiple_matrix, size_t sizeY, size_t sizeX)
{

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
    MultipleNumber(k, *data, *data_multiple_number, sizeY, sizeX);
    //Transpose (*data_transpose, *data, sizeX, sizeY);
    SumMatrixes (*data, *data_multiple_number, *data_sum, sizeY, sizeX);

    Print(*data_sum, sizeY, sizeX);



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
