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

Status add_to_list( List_ptr list, Element value) {
  return insert_at(list, value, list->length);
};

Status add_to_start( List_ptr list, Element value) {
  return insert_at(list, value, 0);
};

void display_list(List_ptr list){
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n",*(int *)p_walk->element);
    p_walk = p_walk->next;
  }
};
