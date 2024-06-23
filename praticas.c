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
	printf("Menu de Monitoramento de Chuvas no Rio Grande do Sul\n1. Verificar a Previs�o do tempo\n2. Doar para v�timas das chuvas\n3. Enviar mensagens de apoio\n4. Sair\n\n>> ");
    scanf("%d", &op);	
    
    switch(op){
    	case 1: verificar_previsao_tempo(); break;
    	case 2: doar_para_vitimas(); break; 
    	case 3: enviar_mensagens_de_apoio(); break;
    	case 4:  printf("Saindo...\n"); break;
    	default: printf("Op��o invalida! Por favor, escolha uma op��o valida.\n");
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

    printf("\nInforma��es sobre como doar:\n");
    printf("1. Doar dinheiro\n");
    printf("2. Doar itens\n");
    printf("3. Ser voluntario\n\n");
    printf(">> ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Para doar dinheiro, voc� pode seguir este tutorial do site do Governo do Estado do Rio Grande do Sul:\nhttps://www.rs.gov.br/carta-de-servicos/servicos?servico=1798\n\n");
            break;
        case 2:
            printf("Para doar itens em Salvador, dirija-se ao seguintes postos de arrecada��o:\n\n"
			"Unidades da Pol�cia Militar\nTodas as unidades da PMBA, operacionais e administrativas funcionar�o como pontos de arrecada��o da campanha.\nSer�o aceitas doa��es de alimentos n�o perec�veis integrantes da cesta b�sica, bem como �gua mineral, fraldas descart�veis para adultos e crian�as, agasalhos, cobertores, mantas e itens de higiene.\n\n"
			"Correios\nA estatal est� recebendo e transportando gratuitamente alimentos da cesta b�sica, material de higiene pessoal, material de limpeza seco, roupas de cama e de banho e ra��o para pet � sem custo aos doadores.\n\n"
			"CODESAL\nA sede da Defesa Civil de Salvador (CODESAL) na Bonoc� est� recebendo doa��es para ajudar as fam�lias do Rio Grande do Sul pela campanha A��o Salvador Solid�ria.\n�gua mineral e produtos de limpeza, como �gua sanit�ria e detergente, podem ser entregues na CODESAL das 8h �s 16h\n\n");
            break;
        case 3:
            printf("Para ser volunt�rio, a Coordenadoria Estadual de Prote��o e Defesa Civil do Rio Grande do Sul lan�ou um formul�rio para volunt�rios que desejam atuar em tarefas de organiza��o, sele��o e triagem das doa��es de ajuda humanit�ria. Institui��es, empresas e ou grupos interessados no voluntariado tamb�m podem preencher o cadastro no link:\nhttps://casamilitar-rs.com.br/voluntariado/.\n\n");
            break;
        default:
            printf("Op��o inv�lida! Por favor, escolha uma op��o v�lida.\n\n");
    }
}

void enviar_mensagens_de_apoio() {
    int tipo;

    printf("Escolha o tipo de cidad�o para enviar a mensagem de apoio:\n");
    printf("1. Crianca\n");
    printf("2. Jovem\n");
    printf("3. Adulto\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &tipo);

    switch(tipo) {
        case 1:
            printf("Mensagem para Crianca: 'Oi, amiguinho! Fique tranquilo, tudo vai ficar bem. Estamos todos juntos para ajudar!'\n");
            break;
        case 2:
            printf("Mensagem para Jovem: 'Ei, fique firme! Sabemos que � dif�cil, mas sua for�a faz a diferen�a. Conte conosco!'\n");
            break;
        case 3:
            printf("Mensagem para Adulto: 'Ola, sabemos que esses momentos s�o desafiadores, mas a uni�o faz a for�a. Estamos aqui para apoiar voc�!'\n");
            break;
        default:
            printf("Opcao invalida! Por favor, escolha uma op��o v�lida.\n");
    }
}
