#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *num = malloc(sizeof(Element));
  *num = 5;
  add_to_list(list,num);
  display_list(list);
  remove_from_start(list);
  display_list(list);
  return 0;
}
