![](https://ws4.sinaimg.cn/large/006tNc79gy1g1z9det8jsj304y04x749.jpg)

# Aula Aplicada – Fase 2

Esta atividade tem como objetivo enfatizar os conceitos sobre autômatos finitos determinísticos e não determinísticos estudados até a presente aula. As atividades serão realizadas em forma de competição, em que, o participante 🥇 que finalizar todos os exercícios ou ao término do tempo, o maior número, será premiado com brindes 🎁. Podendo haver brindes até a terceira colocação 🥈🥉! Não esqueçam que além da competição, essa é uma atividade avaliativa e que deve se atentar ao prazo e forma de entrega.

> 👨🏻‍🎓Prof. Benevid Felix Silva

### 1. Lista de exercícios sobre AFD e AFND. 

**Dado as seguintes linguagens sobre os alfabetos $\sum_1=\{0,1\}$ ou $\sum_2=\{a,b\}$:**

1. $L_1$ = {$w$ | $w \in \sum^*$   e $w$ começa por $11$ e termina por $00$}
2. $L_2$ = {$10w$ | $w \in \sum^*$}
3. $L_3$ = {$x01y$ | $x,y \in \{0,1\}^*$}
4. $L_4$ = {$b(ab)^nb$ | $n \ge 0$}
5. $L_5$={ $10^n10$ | $n \ge 0$} 
6. $L_6$= {$0^m1^n$ | m+n é par}
7. $L_7$= {$01^m10(01)^n$ | $n \ge 0$}
8. $L_8$ = {$ab(ab)^nba$ | $n \ge 0$ }
9. $L_9$ = {$ba^nba$ | $n \ge 0$}
10. $L_{10}$ = {$ab^ma^n$ | $m,n \ge 0$}
11. {$w$ | $w$ possui $aaa$ como subpalavra}
12. {$w$ | o sufixo de $w$ é $aa$}
13. {$w$ | $w$ possui número ímpar de $a$ e $b$}
14. {$w$ | $w$ possui número par de $a$ e ímpar de $b$ ou $w$ possui número par de $b$ e ímpar de $a$}
15. {$w$ | o quinto símbolo da direita para a esquerda de w é $a$}

### 2. Atividades

#### Passo 1 - Faça o grafo dos autômatos acima. Caso necessario, converta manualmente os AFNDs para AFDs.

> Obs.: Entregar os grafos e conversões por escrito.

#### Passo 2 - Construa um algoritmo para cada AFD do exercício 1 anterior em Linguagem C.

>  Obs.: Mostre que os algoritmos ACEITAM ou REJEITAM um dado conjunto de palavras sobre os 𝛴.

#### Passo 3 - Trabalho da disciplina - Individual

>  Todos devem entregar até 15/09 os exerícios acima como requisito par obtenção da nota referente ao trabalho principal da disciplina. 
>
> Valor 10 pontos.
>
> As atividades devem ser feitas em manuscrito. Portanto, se deve entregar uma arquivo contento a cópia  das folhas escaneadas.
>
> Enviar para o email: benevid@unemat.br
>
> Título do email: <Nome> Trabalho LFA2019-2



### Exemplos na Linguagem C

#### Algoritmo 1 - Palavras da Linguagem $L=(ba)^n$, $n \ge 1$

```c

#include <stdio.h>
#include <string.h>

/* Função Principal*/
int TAM=0;

void q0(int pos, char w[TAM]);
void q1(int pos, char w[TAM]);
void qFim(char w[TAM]);
void qErro(char w[TAM]);



int main(){

	int size = 0;
	char w[21];

	printf("\n Informe a palavra:");
	scanf("%s",w);

	//Calcular o tamanho da palavra
	while(w[size] !='\0'){
		size++;
	}
	TAM=size;
  // palavra com tamanho 0
  if(TAM <= 0){
    qErro(w);
  }
  
	int pos = 0;
		
	printf("\n TAM: %d", TAM);
	printf("\n Size: %d", size);
	printf("\n Palavra: %s", w);


	q0(pos,w);

	return 0;
}


void q0(int pos, char w[TAM]){
	if(pos<TAM){
		if(w[pos] == 'b'){
			printf("\n q0 lendo %c -> q1", w[pos]);
			q1(++pos,w);
		}else{
			qErro(w);
		}
	}else if(pos == TAM){
		qFim(w);
	}

}

void q1(int pos, char w[TAM]){
	if(pos < TAM){
		if(w[pos] == 'a'){
			printf("\n q1 lendo %c -> q0", w[pos]);
			q0(++pos,w);
		}else{
			qErro(w);
		}
	}else if(pos == TAM){
		qErro(w);
	}
}

void qErro(char w[TAM]){
    printf("\n Palavra %s regeitada pelo automato!\n",w);
}

void qFim(char w[TAM]){
    printf("\n Palavra %s Aceita pelo automato!\n",w);
}
```



#### Algoritmo de Exemplo2

```c

/*Ler as palavras reservadas char, for, float */


#include <stdio.h>
#include <string.h>
#define TAM 100

void qInicio ( char palavra[TAM],int size);
void q0( int contador, char palavra[TAM],int size);
void q1( int contador, char palavra[TAM],int size);
void q2( int contador, char palavra[TAM],int size);
void q3( int contador, char palavra[TAM],int size);
void q4( int contador, char palavra[TAM],int size);
void q5( int contador, char palavra[TAM],int size);
void q6( int contador, char palavra[TAM],int size);
void q7( int contador, char palavra[TAM],int size);
void q8( int contador, char palavra[TAM],int size);
void q9( int contador, char palavra[TAM],int size);
void qFim();
void qErro();

int main(){
	int size = 0;
    char palavra[TAM]; //casos de comprovação: 
    fflush(stdin);
    gets(palavra);
    
    while(palavra[size] != '\0')
    {
    	size++;    	
	}
    
    qInicio(palavra,size);
    
    return 0;
}

void qInicio ( char palavra[TAM],int size ){
    int contador = 0;
    q0( contador, palavra,size );
}

void q0( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'f' ){
           q1( ++contador, palavra,size ); 

        }else if (palavra[contador] == 'c'){
           q8( ++contador, palavra ,size); 

        }else{
            qErro();
        }

    }
}

void q1( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'l' ){
          q2( ++contador, palavra ,size); 

        }else if (palavra[contador] == 'o'){
           q3( ++contador, palavra,size ); 

        }else{
            qErro();
        }

    }
}

void q2( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'o' ) {
        q5 ( ++contador, palavra,size );
        
    } else {
        qErro();
    }
}

void q3( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'r' ) {
        q4 ( ++contador, palavra ,size);
        
    } else {
        qErro();
    }
}

void q4( int contador, char palavra[TAM] ,int size){
	if(contador == size)
	{
		qFim();
	}
    
    else
    {
    	qErro();
	}
    
}

void q5( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'a' ) {
        q6 ( ++contador, palavra ,size);
        
    } else {
        qErro();
    }
}

void q6( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 't' ) {
        q7 ( ++contador, palavra ,size);
        
    } else {
        qErro();
    }
}

void q7( int contador, char palavra[TAM],int size ){
    if(contador == size)
	{
		qFim();
	}
    
    else
    {
    	qErro();
	}
}

void q8( int contador, char palavra[TAM] ,int size){
    if ( contador < TAM ){
        if ( palavra[contador] == 'h' ){
          q9( ++contador, palavra ,size); 

        }else{
            qErro();
        }

    }
}

void q9( int contador, char palavra[TAM] ,int size){
    if ( palavra[contador] == 'a' ) {
        q3 ( ++contador, palavra ,size);
        
    } else {
        qErro();
    }
}


void qErro(){
    printf("Palavra regeitada pelo automata!\n");
}

void qFim(){
    printf("Palavra Aceita pelo automata!\n");
} 
```

