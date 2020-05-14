#include <assert.h>
#include "../linkedlist.h"

void assert_remove_first_occurrence(void){
  printf("Remove_First_Occurrence\n");
  List_ptr list = create_list();
  Matcher matcher = &is_equal;
  int *num = malloc(sizeof(Element));
  *num = 5;
  printf("should give null when list is empty\n");
  assert(!remove_first_occurrence(list, num, matcher));
  assert(list->length== 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("Passed\n");

  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 10;
  printf("should remove first occurrence of the num in list\n");
  assert(*( int *)remove_first_occurrence(list, num, matcher) == 10);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 5);
  assert(*(int *)list->last->element == 10);
  printf("Passed\n");

  *num = 15;
  printf("should give null  when num is not present in the list\n");
  assert(!remove_first_occurrence(list,num,matcher));
  assert(list->length == 2);
  assert(*(int *)list->first->element == 5);
  assert(*(int *)list->last->element == 10);
  printf("Passed\n");
};

void assert_remove_at(void) {
  printf("Remove_At\n");
  List_ptr list = create_list();
  printf("should return null when list is empty\n");
  assert(!remove_at(list,1));
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->length == 0);
  printf("Passed\n");

  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list, num);
  *num = 10;
  add_to_list(list, num);
  *num = 20;
  add_to_list(list, num);
  *num = 30;
  add_to_list(list, num);
  *num = 40;
  add_to_list(list, num);

  printf("should remove the num from the starting of list\n");
  assert(*( int *)remove_at(list,0) == 5);
  assert(list->length == 4);
  assert(*(int *)list->first->element == 10);
  assert(*(int *)list->last->element == 40);
  printf("Passed\n");

  printf("should remove the num from the middle of list\n");
  assert(*(int *)remove_at(list,1) == 20);
  assert(list->length == 3);
  assert(*(int *)list->first->next->element == 30);
  printf("Passed\n");

  printf("should remove the num from last of the list\n");
  assert(*(int *)remove_at(list,2) == 40);
  assert(list->length == 2);
  assert(*(int *)list->last->element == 30);
  printf("Passed\n");

  printf("should give null when invalid position is given\n");
  assert(!remove_at(list,10));
  assert(list->length == 2);
  printf("Passed\n");
};

void assert_remove_from_end(void) {
  printf("Remove_From_End\n");
  List_ptr list = create_list();
  printf("should give null if list is empty\n");
  assert(!remove_from_end(list));
  assert(list->length == 0);
  printf("Passed\n");

  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list, num);
  *num = 10;
  add_to_list(list,num);
  printf("should remove num from last in the list\n");
  assert(remove_from_end(list));
  assert(list->length == 1);
  assert(*(int *)list->first->element == 5);
  assert(*(int *)list->last->element == 5);
  printf("Passed\n");

  printf("should remove num from the when single num is present\n");
  assert(remove_from_end(list));
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->length == 0);
  printf("Passed\n");
};

void assert_clear_list(void){
  printf("Clear_list\n");
  List_ptr list = create_list();
  printf("should clear all the element of the list\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  clear_list(list);
  assert(list->first == NULL);
  assert(list->last == NULL);
  assert(list->length == 0);
  printf("Passed\n");
};

void assert_for_each(void){
  printf("For_Each\n");

  printf("should iterate an empty list\n");
  ElementProcessor processor = &inc_curr;
  List_ptr list = create_list();
  forEach( list ,processor);
  assert(list->length == 0);
  printf("Passed\n");

  list = create_list();
  printf("should increment given list by one\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 15;
  add_to_list(list,num);
  *num = 20;
  add_to_list(list,num);
  forEach( list ,processor);
  assert(*(int *)list->first->element == 6);
  assert(*(int *)list->last->element == 21);
  printf("Passed\n");
};

void assert_reduce(void){
  printf("Reduce\n");
  List_ptr list = create_list();
  Reducer reducer = &add;
  int *init = malloc(sizeof(Element));
  *init = 0;
  printf("should return initial value when list is empty\n");
  Element total = reduce(list,init, reducer);
  assert(*(int *)total == 0);
  int *num = malloc(sizeof(Element));
  *num = 1;
  add_to_list(list,num);
  *num = 2;
  add_to_list(list,num);
  *num = 3;
  add_to_list(list,num);
  *num = 4;
  add_to_list(list,num);
  printf("Passed\n");

  printf("should give sum of nums in the list\n");
  *init = 0;
  total = reduce(list,init, reducer);
  assert(*(int *)total == 10);
  printf("Passed\n");
};

void assert_filter(void){
  printf("Filter\n");
  List_ptr list = create_list();
  Predicate predicate = &is_even;
  printf("Should return empty list when list is empty\n");
  List_ptr result = filter(list, predicate);
  assert(result->length == 0);
  printf("Passed\n");

  printf("should filter the list and give back even num list\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 15;
  add_to_list(list,num);
  *num = 20;
  add_to_list(list,num);
  result = filter(list, predicate);
  assert(result->length == 2);
  assert(*(int *)result->first->element == 10);
  assert(*(int *)result->last->element == 20);
  printf("Passed\n");
};

void assert_map() {
  printf("Map\n");
  Mapper mapper = &inc_by_one;
  List_ptr list = create_list();

  printf("Should return empty list when empty list is given\n");
  List_ptr result = map(list, mapper);
  assert(result->length == 0);
  printf("Passed\n");

  printf("should return new list after increasing each num by one\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  *num = 10;
  add_to_list(list,num);
  *num = 15;
  add_to_list(list,num);
  result = map(list, mapper);
  assert(result->length == 3);
  assert(*(int *)result->first->element == 6);
  assert(*(int *)result->first->next->element == 11);
  assert(*(int *)result->last->element == 16);
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
  List_ptr result = reverse(list);
  assert(*( int *)result->first->element == 3);
  assert(*( int *)result->first->next->element == 2);
  assert(*( int *)result->last->element == 1);
  printf("Passed\n");
};

void assert_remove_from_start(void) {
  printf("Remove_From_Start\n");
  List_ptr list = create_list();

  printf("Should return null when list is empty\n");
  assert(!remove_from_start(list));
  assert(list->length == 0);
  printf("Passed\n");

  printf("should remove first num in a single list\n");
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  assert(*(int *)remove_from_start(list) == 5);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("Passed\n");

  printf("should remove first num from the list\n");
  *num = 2;
  add_to_list(list, num);
  assert(*(int *)remove_from_start(list) == 2);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
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
  assert_reduce();
  assert_for_each();
  assert_clear_list();
  assert_remove_from_end();
  assert_remove_at();
  assert_remove_first_occurrence();
  return  0;
}