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
void create_left_node_from_parent(TREE_NODE * parent_node,uint8_t curent_val,uint8_t weight)
{
    parent_node->leftChild  = (void*)malloc(sizeof(TREE_NODE));
    ((TREE_NODE*)(parent_node->leftChild))->symbol = curent_val;
}
void create_right_node_from_parent(TREE_NODE * parent_node,uint8_t curent_val,uint8_t weight)
{
    parent_node->rightChild  = (void*)malloc(sizeof(TREE_NODE));
    ((TREE_NODE*)(parent_node->rightChild))->symbol = curent_val;
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
void search_trees_from_top_VLR_noRec(TREE_NODE * top)
{
    TREE_NODE *stack[10];
    int topP=-1;
    stack[++topP] = top;
    while(topP<0 || top>=10)
    {
        if(stack[topP]!=NULL)
        {
            if(stack[topP]->leftChild!=NULL)
            {
                stack[topP+1] = stack[topP]->leftChild;
                topP++;
            }
            if(stack[++topP]!=NULL)
            {
                
            }
        }
        topP--;
    }
    if(top!=NULL)
    {
        printf("node value=%c\n",top->symbol);
        search_trees_from_top_VLR(top->leftChild);
        search_trees_from_top_VLR(top->rightChild);
    }
    return;
}
void free_trees_from_top_VLR(TREE_NODE * top)
{
    if(top!=NULL)
    {
        free(top);
    }
    return;
}
#define TEST_NB (8)
int main()
{
    uint8_t input_array[]={'A','B','C','D','E','F','G'};
    TREE_NODE * top = create_parent_node_from_childs(0,0,input_array[0],0);
    printf("here1\n");
    create_left_node_from_parent(top,input_array[1],0);
    create_right_node_from_parent(top,input_array[2],0);
    create_left_node_from_parent(top->leftChild,input_array[3],0);
    create_right_node_from_parent(top->leftChild,input_array[4],0);
    // create_left_node_from_parent(top->rightChild,input_array[5],0);
    create_right_node_from_parent(top->rightChild,input_array[6],0);
    printf("here\n");
    search_trees_from_top_VLR(top);
    free_trees_from_top_VLR(top);
}