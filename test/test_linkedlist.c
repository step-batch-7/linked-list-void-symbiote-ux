#include <assert.h>
#include <stdio.h>
#include<stdio.h>
#include "../linkedlist.h"

void assert_add_to_list(void){
  printf("Add_To_List\n");
  List_ptr list = create_list();
  int *number = malloc(sizeof(Element));

  printf("Should add number when list is empty\n");
  *number = 2;
  assert(add_to_list(list , number));
  assert(list->length == 1);
  assert(*(int *)list->first->element== 2);
  assert(*(int *)list->last->element== 2);
  printf("Passed\n");

  printf("Should add the number when list is not empty\n");
  *number = 3;
  add_to_list(list, number);
  *number = 4;
  add_to_list(list, number);
  *number = 5;
  assert(add_to_list(list, number));
  assert(list->length == 4);
  assert(*(int *)list->last->element == 5);
  printf("Passed\n");
};

void assert_insert_at(void){
  printf("Insert_At\n");
  List_ptr list = create_list();
  printf("Should insert in the  starting when list is empty\n");
  int *num = malloc(sizeof(Element));
  *num = 2;
  assert(insert_at(list, num , 0));
  assert(list->length == 1);
  assert(*(int *)list->first->element == 2);
  assert(*(int *)list->last->element== 2);
  printf("Passed\n");

  printf("Should insert at middle of the list \n");
  *num = 3;
  insert_at(list, num, 1);
  *num = 4;
  insert_at(list, num, 2);
  *num = 5;
  assert(insert_at(list, num, 1)); 
  assert(list->length == 4);
  assert(*(int *)list->first->next->element== 5);
  printf("Passed\n");

  printf("Should insert at last of the list \n");
  *num = 8;
  assert(insert_at(list, num , 4));
  assert(list->length == 5);
  assert(*(int *)list->last->element == 8);
  printf("Passed\n");
  
  printf("Should not insert at invalid position\n");
  *num = 5;
  assert(!insert_at(list, num , 10));
  assert(list->length == 5);
  printf("Passed\n");
}

int main(void){
  assert_insert_at();
  assert_add_to_list();
  return  0;
}