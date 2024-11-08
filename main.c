#include <stdio.h>
#include <unistd.h>  // Para a fun��o sleep()

int main() {
    int segundos;

    // Solicita que o usu�rio insira o n�mero de segundos
    printf("Digite o n�mero de segundos para a contagem regressiva: ");
    scanf("%d", &segundos);

    // Loop do...while para a contagem regressiva
    do {
        printf("Tempo restante: %d segundos\n", segundos);
        sleep(1);  // Aguarda 1 segundo
        segundos--;
    } while (segundos > 0);

    // Exibe mensagem ao final da contagem regressiva
    printf("Contagem regressiva finalizada!\n");

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>  // Para usar vari�veis booleanas

int main() {
    int numero;
    bool entradaValida;  // Vari�vel para indicar se a entrada � v�lida

    do {
        // Solicita a entrada do usu�rio
        printf("Digite um n�mero inteiro positivo: ");
        scanf("%d", &numero);

        // Verifica se o n�mero � positivo
        entradaValida = (numero > 0);

        // Se a entrada n�o for v�lida, informa o usu�rio
        if (!entradaValida) {
            printf("Entrada inv�lida. Tente novamente.\n");
        }

    } while (!entradaValida);  // Continua o loop enquanto a entrada n�o for v�lida

    // Exibe o n�mero positivo inserido
    printf("Voc� digitou o n�mero positivo: %d\n", numero);

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Digite n�meros inteiros para somar (digite um n�mero negativo para terminar):\n");

    // Loop para solicitar n�meros ao usu�rio
    while (1) {  // Loop infinito que ser� encerrado com um n�mero negativo
        printf("Digite um n�mero: ");
        scanf("%d", &numero);

        // Verifica se o n�mero � negativo
        if (numero < 0) {
            break;  // Encerra o loop se o n�mero for negativo
        }

        // Soma os n�meros positivos
        soma += numero;
    }

    // Exibe a soma total dos n�meros positivos
    printf("A soma total dos n�meros positivos inseridos �: %d\n", soma);

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

int main() {
    char senhaCorreta[] = "Neumann1";  // Define a senha correta
    char senha[100];  // Array para armazenar a senha inserida pelo usu�rio

    do {
        // Solicita ao usu�rio para inserir a senha
        printf("Digite a senha: ");
        fgets(senha, sizeof(senha), stdin);  // L� a senha do usu�rio

        // Remove a nova linha da entrada (se presente)
        senha[strcspn(senha, "\n")] = 0;

    } while (strcmp(senha, senhaCorreta) != 0);  // Compara a senha inserida com a senha correta

    // Se a senha estiver correta, exibe a mensagem
    printf("Senha correta!\n");

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char senha[100];        // Array para armazenar a senha
    char confirmacao[100]; // Array para armazenar a senha de confirma��o
    bool cadastroValido;    // Vari�vel booleana para controlar o fluxo

    do {
        // Solicita que o usu�rio digite a senha
        printf("Digite a senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = 0; // Remove o caractere de nova linha

        // Solicita que o usu�rio digite a senha novamente para confirma��o
        printf("Confirme a senha: ");
        fgets(confirmacao, sizeof(confirmacao), stdin);
        confirmacao[strcspn(confirmacao, "\n")] = 0; // Remove o caractere de nova linha

        // Compara as senhas
        cadastroValido = (strcmp(senha, confirmacao) == 0); // Verifica se as senhas s�o iguais

        if (!cadastroValido) {
            printf("As senhas n�o coincidem. Tente novamente.\n");
        }

    } while (!cadastroValido); // Continua o loop at� que as senhas coincidam

    // Se as senhas forem iguais, exibe a mensagem de sucesso
    printf("Cadastro da senha realizado com sucesso!\n");

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

#define MAX_NOMES 100  // Define o m�ximo de nomes que podem ser cadastrados
#define TAM_NOME 50   // Define o tamanho m�ximo de cada nome

int main() {
    char nomes[MAX_NOMES][TAM_NOME];  // Matriz para armazenar os nomes
    int contador = 0;                  // Contador de nomes cadastrados

    printf("Digite os nomes (pressione Enter para parar):\n");

    // Loop para cadastrar os nomes
    while (contador < MAX_NOMES) {
        printf("Nome %d: ", contador + 1);
        fgets(nomes[contador], sizeof(nomes[contador]), stdin);  // L� o nome do usu�rio
        nomes[contador][strcspn(nomes[contador], "\n")] = 0; // Remove o caractere de nova linha

        // Verifica se a string � vazia
        if (strlen(nomes[contador]) == 0) {
            break;  // Para o loop se o usu�rio pressionar apenas Enter
        }

        contador++;  // Incrementa o contador de nomes
    }

    // Exibe os nomes cadastrados
    printf("\nNomes cadastrados:\n");
    for (int i = 0; i < contador; i++) {
        printf("%s\n", nomes[i]);  // Imprime cada nome
    }

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>

int main() {
    float valorReais;
    const float taxaCambio = 5.25;  // Taxa de c�mbio fixa de 1 USD = 5.25 BRL
    float valorDolares;

    printf("Convers�o de Reais (BRL) para D�lares (USD)\n");

    // Loop para solicitar valores
    do {
        // Solicita ao usu�rio para inserir o valor em reais
        printf("Digite o valor em Reais (0 ou negativo para encerrar): ");
        scanf("%f", &valorReais);

        // Verifica se o valor � positivo
        if (valorReais > 0) {
            // Realiza a convers�o
            valorDolares = valorReais / taxaCambio;
            // Exibe o valor convertido
            printf("Valor em D�lares: USD %.2f\n", valorDolares);
        }

    } while (valorReais > 0);  // Continua at� que o usu�rio digite um valor menor ou igual a 0

    printf("Programa encerrado.\n");
    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()

int main() {
    int numeroGerado, palpite, tentativas = 5;

    // Inicializa a semente para o gerador de n�meros aleat�rios
    srand(time(NULL));

    // Gera um n�mero aleat�rio entre 1 e 50
    numeroGerado = rand() % 50 + 1;

    printf("Adivinhe o n�mero gerado entre 1 e 50. Voc� tem %d tentativas.\n", tentativas);

    // Loop para as tentativas do usu�rio
    while (tentativas > 0) {
        printf("Digite seu palpite: ");
        scanf("%d", &palpite);

        // Verifica se o palpite est� correto
        if (palpite == numeroGerado) {
            printf("Parab�ns! Voc� acertou o n�mero: %d\n", numeroGerado);
            break; // Encerra o loop se o usu�rio acertou
        } else if (palpite < numeroGerado) {
            printf("O n�mero gerado � maior que %d.\n", palpite);
        } else {
            printf("O n�mero gerado � menor que %d.\n", palpite);
        }

        tentativas--; // Decrementa o n�mero de tentativas restantes
        printf("Tentativas restantes: %d\n", tentativas);
    }

    if (tentativas == 0) {
        printf("Voc� perdeu! O n�mero gerado era: %d\n", numeroGerado);
    }

    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

#define MAX_STRING 100  // Tamanho m�ximo da string

int main() {
    char str[MAX_STRING]; // Array para armazenar a string
    int freq[256];       // Array para armazenar a frequ�ncia dos caracteres (256 para incluir todos os caracteres ASCII)

    while (1) {  // Loop infinito que ser� encerrado com uma string vazia
        // Inicializa o array de frequ�ncia
        memset(freq, 0, sizeof(freq)); // Zera o array de frequ�ncia

        // Solicita que o usu�rio insira uma string
        printf("Digite uma string (ou pressione Enter para sair): ");
        fgets(str, sizeof(str), stdin);  // L� a string do usu�rio
        str[strcspn(str, "\n")] = 0; // Remove o caractere de nova linha

        // Verifica se a string est� vazia
        if (strlen(str) == 0) {
            break;  // Encerra o loop se a string for vazia
        }

        // Conta a frequ�ncia de cada caractere
        for (int i = 0; str[i] != '\0'; i++) {
            freq[(unsigned char)str[i]]++;  // Incrementa a contagem do caractere
        }

        // Exibe a contagem de caracteres
        printf("Frequ�ncia de caracteres:\n");
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {  // Exibe apenas os caracteres que aparecem na string
                printf("'%c': %d\n", i, freq[i]);
            }
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}
-------------------------------------------------------------------------
#include <stdio.h>

int main() {
    float valorEmprestimo, taxaJuros, valorFinal;
    int meses;

    printf("Simula��o de Empr�stimo\n");

    while (1) { // Loop infinito que ser� encerrado com um valor de empr�stimo negativo
        // Solicita ao usu�rio o valor do empr�stimo
        printf("Digite o valor do empr�stimo (negativo para sair): ");
        scanf("%f", &valorEmprestimo);

        // Verifica se o valor do empr�stimo � negativo
        if (valorEmprestimo < 0) {
            break; // Encerra o loop se o valor for negativo
        }

        // Solicita a taxa de juros mensal
        printf("Digite a taxa de juros mensal (em porcentagem): ");
        scanf("%f", &taxaJuros);

        // Solicita o n�mero de meses
        printf("Digite o n�mero de meses: ");
        scanf("%d", &meses);

        // Converte a taxa de juros de porcentagem para decimal
        float taxaDecimal = taxaJuros / 100;

        // Exibe o valor final a ser pago ap�s cada m�s
        printf("\nValor do empr�stimo: %.2f\n", valorEmprestimo);
        printf("Taxa de juros: %.2f%%\n", taxaJuros);
        printf("N�mero de meses: %d\n", meses);
        printf("Valor final a ser pago ap�s cada m�s:\n");

        for (int i = 1; i <= meses; i++) {
            valorFinal = valorEmprestimo * (1 + taxaDecimal * i); // Calcula o valor final
            printf("M�s %d: %.2f\n", i, valorFinal);
        }

        printf("\n"); // Nova linha para separa��o entre os casos
    }

    printf("Programa encerrado.\n");
    return 0;
}
