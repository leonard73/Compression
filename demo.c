#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct TREE_NODE_t
{
    void * leftChild;
    void * rightChild;
    uint8_t symbol;
    uint8_t layerID;
    uint8_t code;
    uint8_t weight;
}TREE_NODE;
TREE_NODE* create_left_node_from_parent(TREE_NODE * parent_node,uint8_t curent_val,uint8_t weight)
{
    parent_node->leftChild  = (void*)malloc(sizeof(TREE_NODE));
    ((TREE_NODE*)(parent_node->leftChild))->symbol = curent_val;
    return parent_node->leftChild;
}
TREE_NODE* create_right_node_from_parent(TREE_NODE * parent_node,uint8_t curent_val,uint8_t weight)
{
    parent_node->rightChild  = (void*)malloc(sizeof(TREE_NODE));
    ((TREE_NODE*)(parent_node->rightChild))->symbol = curent_val;
    return parent_node->rightChild;
}
TREE_NODE* create_parent_node_from_childs(TREE_NODE * leftChild,TREE_NODE * rightChild,uint8_t curent_val,uint8_t weight)
{
    TREE_NODE * newNode = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    newNode->leftChild = (void *)leftChild;
    newNode->rightChild= (void *)rightChild;
    newNode->symbol      = curent_val;
    return newNode;
}
void search_trees_from_top_VLR(TREE_NODE * top)
{
    if(top!=NULL)
    {
        printf("node value=%c\n",top->symbol);
        search_trees_from_top_VLR(top->leftChild);
        search_trees_from_top_VLR(top->rightChild);
    }
    return;
}
#define TEST_NB (8)
int main()
{
    uint8_t input_array[]={'A','B','C','D','E','F','G'};
    TREE_NODE * node_array[TEST_NB];
    node_array[0]  = create_parent_node_from_childs(0,0,input_array[0],0);
    printf("here1\n");
    node_array[1]  = create_left_node_from_parent(node_array[0],input_array[1],0);
    node_array[2]  = create_right_node_from_parent(node_array[0],input_array[2],0);
    node_array[3]  = create_left_node_from_parent(node_array[1],input_array[3],0);
    node_array[4]  = create_right_node_from_parent(node_array[1],input_array[4],0);
    node_array[5]  = create_left_node_from_parent(node_array[2],input_array[5],0);
    node_array[6]  = create_right_node_from_parent(node_array[2],input_array[6],0);
    printf("here\n");
    search_trees_from_top_VLR(node_array[0]);
    for(int i=0;i<7;i++)
    {
        free(node_array[i]);
    }
}