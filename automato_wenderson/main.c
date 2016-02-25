#include <stdio.h>
#include <stdlib.h>

enum estado_i{A};
enum estados_finais{B=1,C=2};
typedef struct nodo nodo;
typedef struct nodo_c nodo_c;
int estado_atual = A;
int transicao[4][2];


struct nodo {
  char n;
};

struct nodo_c {
  char c;
};

int main()
{

    nodo *estados;
    nodo_c *averificacao;
    char *alfabeto;
    int iestados,ialfabeto,i,j,k,iverificao;
    char sestado,salfabeto,st,sverificacao;


    estados = (nodo *) malloc(sizeof(char));

    iestados = 0;
    printf("digite os estados e o alfabeto: \n");
    do{

        scanf(" %c" , &sestado);
        if(sestado == ',' || sestado == ';')
            break;
        iestados = iestados+1;
        estados = (nodo *) realloc(estados,(iestados)*sizeof(nodo));
        estados[(iestados)-1].n = sestado;
    }while(1);

    alfabeto = (char *) malloc(sizeof(char));
    ialfabeto = 0;

    do{
       scanf(" %c" , &salfabeto);
       if(salfabeto == ',' || salfabeto == ';')
          break;
       ialfabeto = ialfabeto + 1;
       alfabeto = (char *) realloc(alfabeto,(ialfabeto)*sizeof(char));
       alfabeto[(ialfabeto)-1] = salfabeto;
    }while(1);


     i = 0;

     printf("\nestados : %d \n", iestados);
     do{
        printf("\n %d = %c \n" , i , estados[i].n);
        i = i+1;
     }while(i<iestados);

     printf("\n %d alfabeto : %s\n",ialfabeto,alfabeto);


     int t1,t2,t3;

     printf("\n transicoes\n");
     do{

       scanf(" %c",&st);
       if(st == '#' || st ==';')
          break;

       switch(st){
           case 'A' : t1 = 0; break;
           case 'B' : t1 = 1; break;
           case 'C' : t1 = 2; break;
           case 'D' : t1 = 3; break;
       }
       while(1){
        scanf(" %c",&st);
        if(st == ';')
            break;

        switch(st){
           case 'A' : t2 = 0; break;
           case 'B' : t2 = 1; break;
           case 'C' : t2 = 2; break;
           case 'D' : t2 = 3; break;
           case '1' : t3 = 1; break;
           case '0' : t3 = 0; break;
       }
       }

       transicao[t1][t3] = t2;
       printf("\n");
     }while(1);

    printf("\nfim das transicoes\n");



    int VerificacoesAlfabeto(char caractera){
         int i,j;
         for(i=0;i<2;i++)
            if(caractera == alfabeto[i])
                break;

         if(i==2)
            return 2;

         for(j=0; j<1; j++)
               estado_atual = transicao[estado_atual][i];
                if( estado_atual == B)
                       return 5;
                else if( estado_atual == C)
                        return 5;
                return 6;
    }
     printf("\npalavras a serem verificadas\n");
     int resultado;
     iverificao = 0;
     char string[100];
     averificacao = (nodo_c *) malloc(sizeof(char));
     do{

        scanf(" %c" , &sverificacao);
        if(sverificacao == ',' || sverificacao == ';')
            break;
        iverificao = iverificao+1;
        averificacao = (nodo_c *) realloc(averificacao,(iverificao)*sizeof(nodo_c));
        averificacao[(iverificao)-1].c = sverificacao;
    }while(1);
    i = 0;
     do{
        resultado = VerificacoesAlfabeto(averificacao[i].c);

        i = i+1;
     }while(i<iverificao);

     i = 0;

     switch(resultado){
       case 2: printf("Erro 02\n"); break;
       case 5: do{string[i] = averificacao[i].c; i++; }while(i < iverificao);  printf("%s  sim\n",string); break;
       case 6: do{string[i] = averificacao[i].c; i++; }while(i < iverificao);  printf("%s  nao\n",string); break;
     }

    return 0;
}
