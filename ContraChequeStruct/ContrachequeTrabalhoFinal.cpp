#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

	struct cad{
	int codigo;
	int qtdFilho;
	char nome[80]; 
	float salarioB;
	int idade;
	char vFilho[5];
	int dataA;
	char mesR[10];

    };
	
	

int main(void){
	
	float cal_Inss(float sb);
	float cal_salario(float sb, int qtdf);
	float imposto_de_renda( float sb );
	cad fun [2]; 

	for(int i= 0; i<10; ++i){
	printf("--------------------FUNCINARIO %i--------------",i+1);
		//perguntas
	printf("\nDigite o Codigo do funcionario :\n");
	scanf("%d",&fun[i].codigo);
	printf("\nDigite o nome do Funcinario :\n");
	scanf("%s",&fun[i].nome);
	printf("\nTem filho menor de 15 anos ou com necessidades especias S/N ? : ");
	scanf("%s",&fun[i].vFilho);
		if (strcmp (fun[i].vFilho, "S") == 0){
			printf("\nQuantos filhos com menos ou igual a 14 anos? : \n");
			scanf("%d",&fun[i].qtdFilho);}
	printf("\nSalario base : ???\n");
	scanf("%f",&fun[i].salarioB);
	printf("\nAno de adimisao ???\n");
	scanf("%i",&fun[i].dataA);
	printf("\nMes de referencia???\n");
	scanf("%s",&fun[i].mesR);

	
	}
	
	void imprima(struct cad fun[]);
	imprima(fun);
	
}



float cal_Inss(float sb){
	float inss;
	if(sb<=1751.81){
		inss = sb*8/100;
	}else if(sb<=2919.72){
		inss = sb*9/100;
	}else if(sb<=5839.45){
		inss = sb*11/100;
	}else
		inss = 652.34;
		
	return inss;
}

float cal_salario(float sb, int qtdf){
	float salarioF;
	if(sb <= 907.77){
		salarioF = 46.54*qtdf;
	}else if((907.78 <=sb) && (sb<=1364.43)){
		salarioF = 32.80*qtdf;
	}else
		salarioF=0;
		
		return salarioF;
	
}
float calc_fgts(float sb){
	float x = sb*8/100;
	return x;
}

float cal_Imposto( float tInss  ){
  float x;
  if(tInss <= 1903.98){
  	x = 0;
  }else if((1903.99 <=tInss)&&(tInss<=2826.65)) {
  	x = (tInss* 7.5/100)- 142.80;
  }else if((2826.66<=tInss )&&(tInss<=3751.05)){
  	x = tInss*15/100- 354.80;
  }else if((3751.06<=tInss )&&(tInss<=4664.68)){
  	x = (tInss*22.5/100) - 636.13;
  }else if(tInss >= 4664.68){
  	x = (tInss*27.5/100) - 869.36;
  }
	return x;
}


void imprima(struct cad fun[]){
		for(int i= 0; i<10; ++i){
	printf("\n--------------------FUNCINARIO %i------------------",i+1);	
	//resposta 
	printf("\n Codigo do funcionario : %d",fun[i].codigo);
	printf("\n Nome do Funcionario : %s",fun[i].nome);
	printf("\n Qtd de Filhos : %d",fun[i].qtdFilho);
	printf("\n Data Adimisao : %.s ",fun[i].dataA);
	printf("\n Mes Referencia : %s ",fun[i].mesR);
	printf("\n Salario base : %.1f ",fun[i].salarioB);
	printf("\n----------------------------------------------------------------");
	
	//Inss
	float valor_Inss = cal_Inss(fun[i].salarioB);
	float valorTotal_Inss = fun[i].salarioB - valor_Inss;
	printf("\n valor do inss :%.2f",valor_Inss);
	printf("\n Valor do salario com Desconto do Inss e : %.2f",valorTotal_Inss);
	
	//salario familia
	printf("\n----------------------------------------------------------------");
	float valor_Familia= cal_salario(fun[i].salarioB, fun[i].qtdFilho);
	float valorTotal_familia = fun[i].salarioB + valor_Familia;
	printf("\n o salario familia e : %.2f",valor_Familia);
	printf("\n Valor do salario com Salario familia : %.2f",valorTotal_familia);
	
	//fgts
	printf("\n----------------------------------------------------------------");
	float valor_Fgts = calc_fgts(fun[i].salarioB);
	float valorTotal_fgts = fun[i].salarioB - valor_Fgts;
	printf("\n o desconto do fgts e : %.2f",valor_Fgts);
	printf("\n Valor do salario com Salario com Fgts descontado : %.2f",valorTotal_fgts);

	//Imposto de renda
	 printf("\n----------------------------------------------------------------");
     float valor_Imposto =cal_Imposto(valorTotal_Inss);
     float valaorTotal_Imposto = fun[i].salarioB-valor_Imposto;
     printf("\n O valor do imposto de renda e : %.2f",valor_Imposto);
     printf("\n Valor do salario com Imposto descontado : %.2f",valaorTotal_Imposto);

	//Desconto
	printf("\n______________________________________________________________________________________________________");
	printf("\n valor Desconto: %.2f ",valor_Inss+valor_Fgts-valor_Imposto);
    printf("\n______________________________________________________________________________________________________");

	//TotalVencimentos
	printf("\n______________________________________________________________________________________________________");
	printf("\n TotalVencimentos: %.2f ",fun[i].salarioB+valor_Familia);
    printf("\n______________________________________________________________________________________________________");

	

	//SalarioLiquido
	printf("\n______________________________________________________________________________________________________");
	printf("\n Salario liquido: %.2f ",fun[i].salarioB+valor_Familia-valor_Inss-valor_Fgts-valor_Imposto);
    printf("\n______________________________________________________________________________________________________");
}
}


