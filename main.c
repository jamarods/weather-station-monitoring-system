    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct DataLeitura{

    int dia;
    int mes;
    int ano;

}DataLeitura;

typedef struct Estacao{

int id;
char nome[40];
char operador[40];
char sensor[20];

int n;
float *leituras;

float media;
float variancia;
float desvioPadrao;

DataLeitura data;

}Estacao;

float mediaComRecursiva(float *leituras, int n){
    if(n == 1) return leituras[0]; //caso base
    return ((leituras[n - 1] + mediaComRecursiva(leituras, n - 1) * (n - 1)) / n); // caso recursivo
}

void calcularVariancia(Estacao *e){
    float soma = 0;
    for(int i = 0; i < e->n; i++){
        soma += pow((e->leituras[i] - e->media), 2);
}
    e->variancia = soma / e->n;
}

void calcularDesvioP(Estacao *e){
    e->desvioPadrao = sqrt(e->variancia);
}

void adicionarEstacao(Estacao *e){
    printf("ID (0-9999): ");
    scanf("%d", &e->id);
        while(e->id < 0 || e->id > 9999){
            printf("Id Invalido. Insira novamente valores entre 0 e 9999\n");
            scanf("%d", &e->id);
}
    printf("Nome da estacao: ");
    scanf("%s", e->nome);
    printf("Operador: ");   
    scanf("%s", e->operador);
    printf("Sensor: ");
    scanf("%s", e->sensor);

    int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("Ano (1900-2100): ");
    scanf("%d", &e->data.ano);
        while(e->data.ano < 1900 || e->data.ano > 2100){
            printf("Insira um ano valido.\n");
            scanf("%d", &e->data.ano);
}
    printf("Mes (1-12): ");              
    scanf("%d", &e->data.mes);
        while(e->data.mes < 1 || e->data.mes > 12){
            printf("Insira um mês valido.\n");
            scanf("%d", &e->data.mes);
}

    if((e->data.ano % 4 == 0 && e->data.ano % 100 != 0) || e->data.ano % 400 == 0){ //Estrutura para identificar anos bissextos e verificar a válidades das datas.
        diasDoMes[2] = 29;
}
    printf("Dia: ");
    scanf("%d", &e->data.dia);
        while(e->data.dia < 1 || e->data.dia > diasDoMes[e->data.mes]){
            printf("Insira um dia valido.\n");
            scanf("%d", &e->data.dia);

}
    printf("Quantidade de leituras: ");
    scanf("%d", &e->n);
        while (e->n < 1 || e->n > 9999){
            printf("Insira um valor valido.\n");
            scanf("%d", &e->n);
}

    e->leituras = (float *) malloc(sizeof(float) * e->n);
        if(e->leituras == NULL){
            printf("Erro de memoria.\n");
            return;
}
    for(int i = 0; i < e->n; i++){
        printf("Leitura %d: ", i + 1);
        scanf("%f", &e->leituras[i]);
}

e->media = mediaComRecursiva(e->leituras, e->n);
calcularVariancia(e);
calcularDesvioP(e);
}

void listarEstacoes(Estacao *estacoes, int total){ //função que percorre e exibe todos os dados das estações
    for(int i = 0; i < total; i++){
        printf("Estacao: %d\n", estacoes[i].id);
        printf("Nome: %s\n", estacoes[i].nome);
        printf("Operador: %s\n", estacoes[i].operador);
        printf("Sensor: %s\n", estacoes[i].sensor);
        printf("Numero de leituras: %d\n", estacoes[i].n);
        printf("Media: %f\n", estacoes[i].media);
        printf("Variancia: %f\n", estacoes[i].variancia);
        printf("Desvio Padrão: %f\n", estacoes[i].desvioPadrao);
        printf("Data: %02d/%02d/%04d\n", estacoes[i].data.dia, estacoes[i].data.mes, estacoes[i].data.ano);
    }
}

void editarEstacoes(Estacao *estacoes, int total){ //função que permite editar os dados das estações
    int id;
    printf("Digite o ID da estacao: ");
    scanf("%d", &id);
    for(int i = 0; i < total; i++){
        if(estacoes[i].id == id){
            printf("Novo nome: ");
            scanf("%s", estacoes[i].nome);
            printf("Operador: ");
            scanf("%s", estacoes[i].operador);
            printf("Sensor: ");
            scanf("%s", estacoes[i].sensor);
            printf("Ano");
            scanf("%d", &estacoes[i].data.ano);
            printf("Mes: ");
            scanf("%d", &estacoes[i].data.mes);
            printf("Dia: ");
            scanf("%d", &estacoes[i].data.dia);
            return;
        }
    }
    printf("Estacao com ID %d nao encontrada.\n", id);
}

void excluirEstacao(Estacao *estacoes, int *total){ //função que permite excluir a estação pelo ID
    int id;
    printf("Digite o ID da estacao: ");
    scanf("%d", &id);
    for(int i = 0; i < *total; i++){
        if(estacoes[i].id == id){
            estacoes[i] = estacoes[*total - 1];
            (*total)--;
            return;
        }
    }
    printf("Estacao com ID %d nao encontrada.\n", id);    
}

void buscarPorOperador(Estacao *estacoes, int total){ //função que permite buscar por um operador
    char operador[40];
    printf("Digite o nome do operador: ");
    scanf("%s", operador);
    int encontrou = 0;
    for(int i = 0; i < total; i++){
        if(strcmp(estacoes[i].operador, operador) == 0){
        printf("Estacao: %d\n", estacoes[i].id);
        printf("Nome: %s\n", estacoes[i].nome);
        printf("Operador: %s\n", estacoes[i].operador);
        printf("Sensor: %s\n", estacoes[i].sensor);
        printf("Número de leituras: %d\n", estacoes[i].n);
        printf("Media: %f\n", estacoes[i].media);
        printf("Variancia: %f\n", estacoes[i].variancia);
        printf("Desvio Padrão: %f\n", estacoes[i].desvioPadrao);
        printf("Data: %02d/%02d/%04d\n", estacoes[i].data.dia, estacoes[i].data.mes, estacoes[i].data.ano);
        encontrou = 1;
        }
    }
    if(encontrou == 0){
    printf("Operador %s nao encontrado.\n", operador);
}   
}

void detectarAnomalias(Estacao *estacoes, int total){
    int id;
    printf("Digite o ID da estação: ");
    scanf("%d", &id);
    for(int i = 0; i < total; i++){
        if(estacoes[i].id == id){
            int encontrou = 0;
            for(int j = 0; j < estacoes[i].n; j++){
                if(fabsf(estacoes[i].leituras[j] - estacoes[i].media) > 2 * estacoes[i].desvioPadrao){
                    printf("Anomalia: %f\n", estacoes[i].leituras[j]);
                    encontrou = 1;
                }
            }
            if(encontrou == 0) printf("Nenhuma anomalia encontrada.\n");
            return;
        }
    }
    printf("Estacao com ID %d nao encontrada.\n", id);
}

void salvarnoCSV(Estacao *estacoes, int total){
FILE *arq = fopen("estacoes.csv", "w");
if(arq == NULL){
    perror("Falha encontrada no arquivo");
    return;
}
fprintf(arq, "ID,Nome,Operador,Sensor,Data,N,Media,Variancia,DesvioPadrao,Leitura\n");
for(int i = 0; i < total; i++){
fprintf(arq, "%d,%s,%s,%s,%02d/%02d/%04d,%d,%.2f,%.2f,%.2f,",
    estacoes[i].id, estacoes[i].nome, estacoes[i].operador, estacoes[i].sensor, estacoes[i].data.dia, estacoes[i].data.mes,
    estacoes[i].data.ano, estacoes[i].n, estacoes[i].media, estacoes[i].variancia, estacoes[i].desvioPadrao);
    for(int j = 0; j < estacoes[i].n; j++){
        fprintf(arq, "%.2f", estacoes[i].leituras[j]);
        if(j < estacoes[i].n - 1) fprintf(arq, ";");
    }
fprintf(arq, "\n");
}
fclose(arq);
}

void carregarCSV(Estacao *estacoes, int *total){
    FILE *arq = fopen("estacoes.csv", "r");
    if(arq == NULL){
        perror("Falha encontrada no arquivo");
        return;
    }
    char linha[2500];
    fgets(linha, sizeof(linha), arq);

    while(fgets(linha, sizeof(linha), arq)){
        Estacao e;
        sscanf(linha, "%d,%39[^,],%39[^,],%19[^,],%d/%d/%d,%d,%f,%f,%f", &e.id, e.nome, e.operador, e.sensor,
        &e.data.dia, &e.data.mes, &e.data.ano,
        &e.n, &e.media, &e.variancia, &e.desvioPadrao);

        e.leituras = (float *) malloc(sizeof(float) * e.n);

        char *ptr = strrchr(linha, ',');
        ptr++;

        for(int j = 0; j < e.n; j++){
            sscanf(ptr, "%f", &e.leituras[j]);
            ptr = strchr(ptr, ';');
            if(ptr) ptr++;
        }
            estacoes[*total] = e;
            (*total)++;
    }
    fclose(arq);
}

int main(void){

Estacao estacoes[1000];
int total = 0;
int opcao;

do{
	printf("||1. Adicionar estacao  ||\n");
	printf("||2. Editar estacao     ||\n");
	printf("||3. Excluir estacao    ||\n");
	printf("||4. Listar estacoes    ||\n");
	printf("||5. Buscar por Operador||\n");
	printf("||6. Detectar anomalias ||\n");
	printf("||7. Salvar CSV         ||\n");
	printf("||8. Carregar CSV       ||\n");
	printf("||0. Sair               ||\n");
    scanf("%d", &opcao);

switch (opcao){
case 1:
    adicionarEstacao(&estacoes[total]);
    total++;
    break;
case 2:
    editarEstacoes(estacoes, total);
    break;
case 3:
    excluirEstacao(estacoes, &total);  // coloquei total com & porque é ponteiro
    break;
case 4:
    listarEstacoes(estacoes, total);
    break;
case 5:
    buscarPorOperador(estacoes, total);
    break;
case 6:
    detectarAnomalias(estacoes, total);
    break;
case 7:
    salvarnoCSV(estacoes, total);
    break;
case 8:
    carregarCSV(estacoes, &total);
    break;
case 0:
        printf("Saindo...\n");
        break;
    default:
        printf("Opcao invalida.\n");
}
} while(opcao != 0);

}
