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
    	default: printf("Opção invalida! Por favor, escolha uma opção valida.\n");
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
    printf("Informe o mês: ");
    scanf("%d", &mes);

    // Previsï¿½es fictï¿½cias para o mï¿½s de maio
    if (mes == 5) {
        if (strcmp(cidade, "Porto_Alegre") == 0) {
            salvar_previsao(cidade, "Chuva moderada");
        } else if (strcmp(cidade, "Caxias_do_Sul") == 0) {
            salvar_previsao(cidade, "Nublado");
        } else if (strcmp(cidade, "Pelotas") == 0) {
            salvar_previsao(cidade, "Ensolarado");
        } else if (strcmp(cidade, "Santa_Maria") == 0) {
            salvar_previsao(cidade, "Tempo instï¿½vel");
        } else {
            printf("Cidade nï¿½o encontrada nas previsï¿½es fictï¿½cias.\n");
        }
    } else {
        printf("Previsï¿½es disponï¿½veis apenas para o mï¿½s de maio.\n");
    }
}

void salvar_previsao(const char *cidade, const char *previsao) {
    FILE *arquivo = fopen("previsao_maio.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "Cidade: %s - Previsï¿½o: %s\n", cidade, previsao);
    fclose(arquivo);
    printf("Previsï¿½o salva com sucesso!\n");
}

void doar_para_vitimas() {
    int opcao;

    printf("\nInformações sobre como doar:\n");
    printf("1. Doar dinheiro\n");
    printf("2. Doar itens\n");
    printf("3. Ser voluntario\n\n");
    printf(">> ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Para doar dinheiro, você pode seguir este tutorial do site do Governo do Estado do Rio Grande do Sul:\nhttps://www.rs.gov.br/carta-de-servicos/servicos?servico=1798\n\n");
            break;
        case 2:
            printf("Para doar itens em Salvador, dirija-se ao seguintes postos de arrecadação:\n\n"
			"Unidades da Polícia Militar\nTodas as unidades da PMBA, operacionais e administrativas funcionarão como pontos de arrecadação da campanha.\nSerão aceitas doações de alimentos não perecíveis integrantes da cesta básica, bem como água mineral, fraldas descartáveis para adultos e crianças, agasalhos, cobertores, mantas e itens de higiene.\n\n"
			"Correios\nA estatal está recebendo e transportando gratuitamente alimentos da cesta básica, material de higiene pessoal, material de limpeza seco, roupas de cama e de banho e ração para pet – sem custo aos doadores.\n\n"
			"CODESAL\nA sede da Defesa Civil de Salvador (CODESAL) na Bonocô está recebendo doações para ajudar as famílias do Rio Grande do Sul pela campanha Ação Salvador Solidária.\nÁgua mineral e produtos de limpeza, como água sanitária e detergente, podem ser entregues na CODESAL das 8h às 16h\n\n");
            break;
        case 3:
            printf("Para ser voluntário, a Coordenadoria Estadual de Proteção e Defesa Civil do Rio Grande do Sul lançou um formulário para voluntários que desejam atuar em tarefas de organização, seleção e triagem das doações de ajuda humanitária. Instituições, empresas e ou grupos interessados no voluntariado também podem preencher o cadastro no link:\nhttps://casamilitar-rs.com.br/voluntariado/.\n\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha uma opção válida.\n\n");
    }
}

void enviar_mensagens_de_apoio() {
    int tipo;

    printf("Escolha o tipo de cidadï¿½o para enviar a mensagem de apoio:\n");
    printf("1. Crianca\n");
    printf("2. Jovem\n");
    printf("3. Adulto\n");
    printf("Escolha uma opï¿½ï¿½o: ");
    scanf("%d", &tipo);

    switch(tipo) {
        case 1:
            printf("Mensagem para Crianca: 'Oi, amiguinho! Fique tranquilo, tudo vai ficar bem. Estamos todos juntos para ajudar!'\n");
            break;
        case 2:
            printf("Mensagem para Jovem: 'Ei, fique firme! Sabemos que ï¿½ difï¿½cil, mas sua forï¿½a faz a diferenï¿½a. Conte conosco!'\n");
            break;
        case 3:
            printf("Mensagem para Adulto: 'Ola, sabemos que esses momentos sï¿½o desafiadores, mas a uniï¿½o faz a forï¿½a. Estamos aqui para apoiar vocï¿½!'\n");
            break;
        default:
            printf("Opcao invalida! Por favor, escolha uma opï¿½ï¿½o vï¿½lida.\n");
    }
}
