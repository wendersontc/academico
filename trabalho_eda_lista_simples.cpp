#include<stdlib.h>
#include<stdio.h>

// Registro para um lista simplesmente encadeada
typedef struct L {
int matricula;
float media;
struct L *prox;
}LISTA;

int buscar_valor(int N, LISTA *L){
     
     LISTA *aux = L;
     int cont = 0;
     
     while(aux != NULL){
          if(aux->matricula == N){                   
               cont++;
          }
          aux = aux->prox;
     }
     return cont;
}

  
int obter_tamanho(LISTA *L){
   int cont = 0;
   if(L == NULL){
      printf("\nLISTA VAZIA");
      return cont;
   }else{
      while(L != NULL){
         L = L->prox;
         cont++;
      }
     return cont;    
   }
}

void insere_inicio(int n, float media , LISTA **L){
     LISTA *aux,*novo;
     aux = *L;
     novo = (LISTA*)malloc(sizeof(LISTA)); 
     novo->matricula = n;
     novo->media = media;
     novo->prox = *L;
     *L = novo;
}

bool remove_elemento(int N, LISTA **L){
    LISTA *aux,*ant,*prox;
    bool achou = false;
    
    ant = NULL;
    aux = *L;
      while(aux != NULL && achou == false){
         if(aux->matricula == N){
           prox = aux;
           aux = aux->prox;
            if(ant == NULL) *L = aux;
            else ant->prox = aux;
            free(prox);
            prox = NULL;
            achou = true;
         }else{
           ant = aux;
           aux = aux->prox;
         }
      }
      
    return achou;
}

void imprime(LISTA *L){
    LISTA *aux;
    aux = L;
       if(L == NULL){
         printf("LISTA VAZIA");
       }else{
         
         while(aux != NULL){
           printf("matricula %d\n",aux->matricula);
		   printf("media %.2f\n",aux->media);        
           aux = aux->prox;
         }
         
       }
}

int main(){
   //LISTA f;
   //f = NULL;  
    
   LISTA *p;
   p = NULL;
   
  
   
   //insere_inicio(101,6,&p);
   //insere_inicio(212,5,&p);
   //insere_inicio(312,5,&p);
   //insere_inicio(4121,8.9,&p);
   //insere_inicio(412,9.9,&p);
   
  int op=-1;
  int matricula=0;
  float nota;
   do{
   	 
   	 printf("Menu:\n1_insere matricula\n2_Pesquisa por matricula\n3_Remover\n4_Imprimi\n0_Sair:\n:");
       scanf("%d",&op);
       
       switch (op)
            {
              case 1:
                    {	
                       printf("Digite a matricula:");
                       scanf("%d",&matricula);
                       printf("Digite o nome:");
                       scanf("%f",&nota);	
                       insere_inicio(matricula,nota,&p);
                      break;
                    }
 
              case 2:
                    {
                      
                      break;
                    }
              case 3:
                {
                  printf("Digite a matricula:");
                  scanf("%d",&matricula);	
                  remove_elemento(matricula,&p);
                  printf("removido com sucesso");
                  imprime(p); 
                   break;
                }            
              case 4:
                    {
                      imprime(p);
                      break;
                    }
              case 0:
                    {
                      op = 0;
                      return 0;
                      break;
                    }
            }
   } while(op != 0);
   

   //printf("valor buscado %d \n",buscar_valor(3,p));
 
  //imprime(concatena(p,d));
   //imprime(interseccao(p,d));
   //insere_meio(1,5,&p);
    
   //insere_ordenada(9,&p);
   //insere_ordenada(2,&p);
   //insere_ordenada(6,&p);
   //insere_ordenada(8,&p);
   
   //insere_inicio(4,&d);
   //insere_inicio(3,&d);
   //insere_inicio(2,&d);
   //insere_inicio(1,&d);
   
   //concatena(p,d);
   //concatena(p,d);
   
   //printf("%d\n",remove_elemento(1,&p));
   
   //inserir_ultimo(1,f);
  
   
   //inserir_ultimo(24,&f);
   
   //insere_inicio(1,&p);
   //insere_inicio(2,&p); 
   //insere_inicio(13,&p);
   
   //insere_meio(1,4,&p);
   
   
   //imprime(p);
   //imprime_par(p);
   //printf("item :%d\n",p->valor);


system("pause");
}

