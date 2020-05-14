#include <assert.h>
#include <stdio.h>
#include<stdio.h>
#include "../linkedlist.h"

void assert_filter(void){
  printf("Filter\n");
  List_ptr list = create_list();
  Predicate predicate = &is_even;
  printf("Should return empty list when list is empty\n");
  List_ptr new_list = filter(list, predicate);
  assert(new_list->length == 0);
  printf("Passed\n");

  printf("should filter the list and give back even number list\n");
  int *number = malloc(sizeof(Element));
  *number = 5;
  add_to_list(list,number);
  *number = 10;
  add_to_list(list,number);
  *number = 15;
  add_to_list(list,number);
  *number = 20;
  add_to_list(list,number);
  new_list = filter(list, predicate);
  assert(new_list->length == 2);
  assert(*(int *)new_list->first->element == 10);
  assert(*(int *)new_list->last->element == 20);
  printf("Passed\n");
};

void assert_map() {
  printf("Map\n");
  Mapper mapper = &inc_by_one;
  List_ptr list = create_list();

  printf("Should return empty list when empty list is given\n");
  List_ptr new_list = map(list, mapper);
  assert(new_list->length == 0);
  printf("Passed\n");

  printf("should return new list after increasing each num by one\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 15;
  add_to_list(list,num);
  new_list = map(list, mapper);
  assert(new_list->length == 3);
  assert(*(int *)new_list->first->element == 6);
  assert(*(int *)new_list->first->next->element == 11);
  assert(*(int *)new_list->last->element == 16);
  printf("Passed\n");
};

void assert_reverse( void ){
  printf("Reverse\n");
  List_ptr list = create_list();
  int *num = malloc(sizeof(Element));
  *num = 1;
  add_to_list(list,num);
  *num = 2;
  add_to_list(list,num);
  *num = 3;
  add_to_list(list,num);
  List_ptr new_list = reverse(list);
  assert(*( int *)new_list->first->element == 3);
  assert(*( int *)new_list->first->next->element == 2);
  assert(*( int *)new_list->last->element == 1);
  printf("Passed\n");
};

void assert_remove_from_start(void) {
  printf("Remove_From_Start\n");
  List_ptr list = create_list();

  printf("Should return null when list is empty\n");
  assert(!remove_from_start(list));
  assert(list->length == 0);
  printf("Passed\n");

  printf("should remove first num from the list\n");
  int *num = malloc(sizeof(Element));
  *num = 2;
  add_to_list(list, num);
  assert(*(int *)remove_from_start(list) == 2);
  assert(list->length == 0);
  assert(list->first == NULL);
  printf("Passed\n");

  printf("should remove first num from list when many nums are present\n");
  *num = 3;
  insert_at(list, num, 0);
  *num = 4;
  insert_at(list, num, 1);
  Element value = remove_from_start(list);
  assert(*(int *)value == 3);
  assert(list->length == 1);
  assert(*(int *)list->last->element== 4);
  assert(*(int *)list->first->element == 4);
  printf("Passed\n");
};

void assert_add_unique(void){
  printf("Add_Unique\n");
  List_ptr list = create_list();
  Matcher matcher = &is_equal;
  int *num = malloc(sizeof(Element));
  *num = 1;
  add_unique(list, num, matcher);
  *num = 2;
  add_unique(list, num, matcher);
  *num = 3;
  add_unique(list, num, matcher);

  printf("Should add num at last when num is not present\n");
  *num = 4;
  assert(add_unique(list, num , matcher));
  assert(list->length == 4);
  assert(*(int *)list->last->element == 4);
  printf("Passed\n");

  printf("Should not add num at last when num is present\n");
  *num = 1;
  assert(!add_unique(list, num, matcher));
  assert(list->length == 4);
  assert(*(int *)list->last->element == 4);
  printf("Passed\n");
};

void assert_add_to_start(void){
  printf("Add_To_Start\n");
  List_ptr list = create_list();
  int *num = malloc(sizeof(Element));

  printf("Should add num to start when list is empty\n");
  *num = 2;
  assert(add_to_start(list , num));
  assert(list->length == 1);
  assert(*(int *)list->first->element == 2);
  assert(*(int *)list->last->element == 2);
  printf("Passed\n");

  printf("Should add the num when list is not empty\n");
  *num = 3;
  add_to_start(list, num);
  *num = 4;
  add_to_start(list, num);
  *num = 5;
  assert(add_to_start(list, num));
  assert(*(int *)list->first->element == 5);
  assert(list->length == 4);
  printf("Passed\n");
};

void assert_add_to_list(void){
  printf("Add_To_List\n");
  List_ptr list = create_list();
  int *num = malloc(sizeof(Element));

  printf("Should add num when list is empty\n");
  *num = 2;
  assert(add_to_list(list , num));
  assert(list->length == 1);
  assert(*(int *)list->first->element== 2);
  assert(*(int *)list->last->element== 2);
  printf("Passed\n");

  printf("Should add the num when list is not empty\n");
  *num = 3;
  add_to_list(list, num);
  *num = 4;
  add_to_list(list, num);
  *num = 5;
  assert(add_to_list(list, num));
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
  assert_add_to_start();
  assert_add_unique();
  assert_remove_from_start();
  assert_reverse();
  assert_map();
  assert_filter();
  return  0;
}