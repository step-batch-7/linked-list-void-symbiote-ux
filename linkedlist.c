#include<string.h>
#include "linkedlist.h"

Node_ptr create_node(Element element){
  Node_ptr node = malloc(sizeof(Node));
  node->element = malloc(sizeof(Element));
  memcpy(node->element, element, sizeof(Element));
  node->next = NULL;
  return node;
};

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
};

void update_linked_list(Node_ptr p_walk,Node_ptr node,List_ptr list,int position) {
  Node_ptr next_pos = p_walk->next;
  p_walk->next = node;
  node->next = next_pos;
  list->length++;
  if(list->length == position + 1) list->last = node;
};

Node_ptr get_position(List_ptr list, int position) {
  Node_ptr p_walk = list->first;
  int curr_pos = 1;
  while(curr_pos != position) {
    p_walk = p_walk->next;
    curr_pos++;
  }
  return p_walk;
};

Status is_value_present(List_ptr list, Element value, Matcher matcher) {
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    if((*matcher)(p_walk->element, value)) return Success;
    p_walk = p_walk->next;
  }
  return Failure;
};

Status insert_at(List_ptr list, Element element, int position) {
  if(position > list->length || position < 0) return Failure;
  Node_ptr new_node = create_node(element);
  if(list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
    list->length++;
    return Success;
  }
  if(position == 0) {
    Node_ptr prev_first = list->first;
    list->first = new_node;
    new_node->next = prev_first;
    list->length++;
    return Success;
  }      
    Node_ptr p_walk = get_position(list,position);
    update_linked_list(p_walk,new_node,list,position);
    return Success;
};

Status add_unique(List_ptr list, Element value, Matcher matcher){
  if(is_value_present(list, value, matcher)) return Failure;
  return insert_at(list,value,list->length);
};

Status add_to_list(List_ptr list, Element value) {
  return insert_at(list, value, list->length);
};

Status add_to_start(List_ptr list, Element value) {
  return insert_at(list, value, 0);
};

Status is_equal(Element num1, Element num2){
  return *( int *)num1 == *(int *)num2;
};

Element remove_at(List_ptr list, int position){
  if(list->first == NULL || position > list->length || position < 0) return NULL;
  if(position == 0 ) {
    Element removed_element = list->first->element;
    Node_ptr new_first = list->first->next;
    list->first = new_first;
    if(list->length == 1) list->last = NULL;
    list->length--;
    return removed_element;
  }
  Node_ptr p_walk = get_position(list,position);
  Element removed_element = p_walk->next->element;
  if(position + 1 == list->length) {
    list->last = p_walk;
    list->last->next = NULL;
  } else { 
     Node_ptr next_pos = p_walk->next->next;
     free(p_walk->next);
     p_walk->next = next_pos;
  }
  list->length--;
  return removed_element;
};

Element remove_from_start(List_ptr list){
  return remove_at(list,0);
};

Element remove_from_end(List_ptr list){
  return remove_at(list,list->length-1);
};

List_ptr reverse(List_ptr list){
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(new_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return new_list;
};

Element inc_by_one(Element value ){
  int *num = malloc(sizeof(Element));
  *num = *(int *)value + 1;
  return num;
};

List_ptr map(List_ptr list, Mapper mapper){
  Node_ptr p_walk = list->first;
  List_ptr new_list = create_list();
  int pos = 0;
  while ( p_walk != NULL)
  {
    Element value = (*mapper)(p_walk->element);
    insert_at( new_list,value,pos);
    p_walk = p_walk->next;
    pos++;
  }
  return new_list;
};


Status is_even(void *value) {
  return !(*(int *)value % 2);
};

List_ptr filter(List_ptr list, Predicate predicate){
  Node_ptr p_walk = list->first;
  List_ptr  new_list = create_list();
  while ( p_walk != NULL)
  {
    Status is_succeed = (*predicate)(p_walk->element);
    if(is_succeed) add_to_list(new_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return new_list;
};

Element add(Element num1, Element num2){
  int *sum = malloc(sizeof(int));
  *sum = *(int *)num1 + *(int *)num2;
  return sum;
};

Element reduce(List_ptr list,Element context, Reducer reducer ){
  Node_ptr p_walk = list->first;
  while ( p_walk != NULL)
  {
    context = (*reducer)(context, p_walk->element);
    p_walk = p_walk->next;
  }
  return context;
};


void inc_curr( Element value){
  *(int *)value += 1;
};

void forEach(List_ptr list, ElementProcessor processor) {
 Node_ptr p_walk = list->first;
  while ( p_walk != NULL)
  {
    (*processor)( p_walk->element);
    p_walk = p_walk->next;
  }
};

Status clear_list( List_ptr list){
  Node_ptr p_walk = list->first;
  Node_ptr element_to_free = NULL;
  while (p_walk != NULL)
  {
    element_to_free = p_walk;
    p_walk = p_walk->next;
    free(element_to_free);
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
};

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher) {
  Node_ptr p_walk = list->first;
  int position = 0;
  while(p_walk != NULL) {
    Status is_succeed = (*matcher)(p_walk->element, element);
    if(is_succeed) return remove_at(list,position);
    p_walk = p_walk->next;
    position++; 
  }
  return NULL;
};

void display_list(List_ptr list){
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n",*(int *)p_walk->element);
    p_walk = p_walk->next;
  }
};
