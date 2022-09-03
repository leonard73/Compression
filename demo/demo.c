#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct DATA_STATISTIC_U8_t
{
    uint32_t sample_number;
    uint8_t  data_val;
    uint8_t  parent_val;
    uint8_t  order_id;
    uint8_t  reserved;
}DATA_STATISTIC_U8;
#define TEST_DATA_SIZE (128)
uint8_t input_data[TEST_DATA_SIZE];
void init_data()
{
    #if 1
    for(int i=0;i<TEST_DATA_SIZE;i++)
    {
        input_data[i]=(uint8_t)(i*i*i);
        printf("%3d|",input_data[i]);
    }
    printf("\n");    
    #else
    for(int i=0;i<TEST_DATA_SIZE;i++)
    {
        input_data[i]=(uint8_t)i;
    }
    #endif
}
void log_bits(uint8_t * data_p,int bytes)
{
    #define GET_BIT_OF_BYTE(d,bitN) ((d>>bitN)&0x01)
    for(int i=0;i<bytes;i++)
    {
        for(int j=7;j>=0;j--)
        {
            printf("%1d",GET_BIT_OF_BYTE((*data_p),j));
        }
        printf("|");
        data_p++;
    }
}
int cmpfunc_data_sample (const void * a, const void * b)
{
   return ( (*(DATA_STATISTIC_U8*)b).sample_number - (*(DATA_STATISTIC_U8*)a).sample_number );
}
void getHistogramOfData_u8(DATA_STATISTIC_U8 * data_collect_array,uint8_t * data_p,int bytes)
{
    for(int i=0;i<bytes;i++)
    {
        (data_collect_array[data_p[i]].sample_number)++;
    }
}
void init_data_collect_array(DATA_STATISTIC_U8 * data_collect_array,int nb)
{
    for(int i=0;i<nb;i++)
    {
        data_collect_array[i].sample_number=0;
        data_collect_array[i].order_id=0;
        data_collect_array[i].data_val=(uint8_t)i;
    }
}
void log_data_collect_array(DATA_STATISTIC_U8 * data_collect_array,int nb)
{
    for(int i=0;i<nb;i++)
    {
        printf(" [%3d]: sampleNb: [%d] \n",data_collect_array[i].data_val,data_collect_array[i].sample_number);
    }   
}
int main()
{
    printf("demo compression\n");
    init_data();
    DATA_STATISTIC_U8 data_collect_array[256];
    init_data_collect_array(data_collect_array,256);
    getHistogramOfData_u8(data_collect_array,input_data,TEST_DATA_SIZE);
    qsort(data_collect_array, 256, sizeof(DATA_STATISTIC_U8), cmpfunc_data_sample);
    log_data_collect_array(data_collect_array,256);
    log_bits(input_data,TEST_DATA_SIZE);
    
}