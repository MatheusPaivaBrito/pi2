#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Cidade{
    char nome[50];
    int mes;
    int dia;
};

void verificar_previsao_tempo();
void doar_para_vitimas();
void enviar_mensagens_de_apoio();
void salvar_previsao(const char *cidade, const char *previsao);

int main() {
	setlocale(LC_ALL, "Portuguese");
	int op;
	
	do {
	printf("Menu de Monitoramento de Chuvas no Rio Grande do Sul\n1. Verificar a Previsão do tempo\n2. Doar para vítimas das chuvas\n3. Enviar mensagens de apoio\n4. Sair\n\n>> ");
    scanf("%d", &op);	
    
    switch(op){
    	case 1: verificar_previsao_tempo(); break;
    	case 2: doar_para_vitimas(); break; 
    	case 3: enviar_mensagens_de_apoio(); break;
    	case 4:  printf("Saindo...\n"); break;
    	default: printf("Opçãoo invalida! Por favor, escolha uma opção valida.\n");
	}
    } while(op != 4);
}

void verificar_previsao_tempo() {
    char cidade[50];
    int dia, mes;

    printf("Informe o nome da cidade: ");
    scanf("%s", cidade);
    printf("Informe o dia: ");
    scanf("%d", &dia);
    printf("Informe o m�s: ");
    scanf("%d", &mes);

    // Previs�es fict�cias para o m�s de maio
    if (mes == 5) {
        if (strcmp(cidade, "Porto_Alegre") == 0) {
            salvar_previsao(cidade, "Chuva moderada");
        } else if (strcmp(cidade, "Caxias_do_Sul") == 0) {
            salvar_previsao(cidade, "Nublado");
        } else if (strcmp(cidade, "Pelotas") == 0) {
            salvar_previsao(cidade, "Ensolarado");
        } else if (strcmp(cidade, "Santa_Maria") == 0) {
            salvar_previsao(cidade, "Tempo inst�vel");
        } else {
            printf("Cidade n�o encontrada nas previs�es fict�cias.\n");
        }
    } else {
        printf("Previs�es dispon�veis apenas para o m�s de maio.\n");
    }
}

void salvar_previsao(const char *cidade, const char *previsao) {
    FILE *arquivo = fopen("previsao_maio.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "Cidade: %s - Previs�o: %s\n", cidade, previsao);
    fclose(arquivo);
    printf("Previs�o salva com sucesso!\n");
}

void doar_para_vitimas() {
    int opcao;

    printf("Informa��es sobre como doar:\n");
    printf("1. Doar dinheiro\n");
    printf("2. Doar alimentos\n");
    printf("3. Doar roupas e cobertores\n");
    printf("4. Ser volunt�rio\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Para doar dinheiro, voc� pode fazer uma transfer�ncia para a conta do Instituto XYZ - Banco ABC, Ag�ncia 0001, Conta 12345-6.\n");
            break;
        case 2:
            printf("Para doar alimentos, dirija-se ao posto de arrecada��o mais pr�ximo ou entre em contato pelo telefone (51) 1234-5678.\n");
            break;
        case 3:
            printf("Para doar roupas e cobertores, entregue as doa��es na sede da organiza��o ABC na Rua das Flores, 123.\n");
            break;
        case 4:
            printf("Para ser volunt�rio, acesse o site www.voluntariosabc.org.br e fa�a seu cadastro.\n");
            break;
        default:
            printf("Op��o inv�lida! Por favor, escolha uma op��o v�lida.\n");
    }
}

void enviar_mensagens_de_apoio() {
    int tipo;

    printf("Escolha o tipo de cidad�o para enviar a mensagem de apoio:\n");
    printf("1. Crian�a\n");
    printf("2. Jovem\n");
    printf("3. Adulto\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &tipo);

    switch(tipo) {
        case 1:
            printf("Mensagem para Crian�a: 'Oi, amiguinho! Fique tranquilo, tudo vai ficar bem. Estamos todos juntos para ajudar!'\n");
            break;
        case 2:
            printf("Mensagem para Jovem: 'Ei, fique firme! Sabemos que � dif�cil, mas sua for�a faz a diferen�a. Conte conosco!'\n");
            break;
        case 3:
            printf("Mensagem para Adulto: 'Ol�, sabemos que esses momentos s�o desafiadores, mas a uni�o faz a for�a. Estamos aqui para apoiar voc�!'\n");
            break;
        default:
            printf("Op��o inv�lida! Por favor, escolha uma op��o v�lida.\n");
    }
}