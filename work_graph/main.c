#include <stdio.h>
#include <stdlib.h>
typedef struct Path_Node
{
	int seq;
	int Node_value;
	int adjacent_dist;
	int visited;
	struct Path_Node * Nextnode;
	struct Path_Node * next_vertex;
	struct Path_Node * next_path;
}Path_Node;
int main()
{
	/*inicializando as variaveis*/
	struct Path_Node *source = NULL;
	struct Path_Node *current = NULL;
	struct Path_Node *previous = NULL;
	struct Path_Node *temp_node = NULL;
	struct Path_Node *path_head = NULL;
	FILE * fp;
	fp = fopen("grafo","r");
	int count,temp;
	int i=0;
	while(fscanf(fp,"%d ",&temp)!=EOF)
	{
	current=(struct Path_Node*)malloc(sizeof(struct Path_Node));
	current->seq = i;
	if(source == NULL){
	current->Node_value = 0;}
	else if((current->seq) % 9 == (current->seq / 9))
	{current->Node_value = 1000000;}
	current->adjacent_dist=temp;
	current->visited=0;
	current->Nextnode = NULL;
	if(source == NULL){source = current;}
	else{
	previous->Nextnode=current;}
	i++;
	previous=current;
	}
	current = source;
	path_head = source;
	temp_node=path_head;

	while(current != NULL){
	if(current -> adjacent_dist == 0 && (current->seq+1)%9 != 1){
current = current -> Nextnode;}
	else{
	temp_node -> next_path = current;
	temp_node = current;
	temp_node->next_path=NULL;

	current = current->Nextnode;}

	}
	path_head=source;
	current = source;
	temp_node = source;
	while(current!= NULL){
	if(((current->seq)/9)!=(temp_node->seq/9)){printf("\n");}
	printf("%d ",current->seq);
	temp_node = current;
	current=current->next_path;

	}


}

