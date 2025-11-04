#include <stdio.h>

// Funções das operações
float soma(float a, float b) {//adicao
    return a + b;
}

float subt(float a, float b) {//subtracao
    return a - b;
}

float mult(float a, float b) {//multiplicacao
    return a * b;
}

float divi(float a, float b) {//divisao
    if (b == 0) {
        printf("Divisao por zero é zero!\n");
        return 0;
    }
    return a / b;
}

float pot(float base, int expo) {//potencia
//Aqui o expo é inteiro. O laço multiplica a base pela quantidade de vezes do expoente. Exemplo: base = 2, expo = 3: +2 × 2 × 2 = 8
    float result = 1;
    int i;//i é a variavel que vou usar pra contar no for
    for (i = 0; i < expo; i++)//loop que repete enquanto i for menor que o expoente
        result *= base;//o resultado = resultado * base
    return result;
}

float porc(float val, float porc) {//porentagem
    return (val * porc) / 100.0;
}

float fato(int n) { // Fatorial
// usado para o seno e o cosseno
    float fat = 1;
    for (int i = 1; i <= n; i++) {//aqui faz com que o valor comece em 1, e o resultado da multiplicação vai descer pro proximo valor e a seja multiplicado por 1 depois por 2, 3, 4 por assim em diante. EX. 1*1=1, 1*2=2, 2*3=6, 6*4=24...
        fat *= i;
    }
    return fat;
}

float seno(float x) {//seno
//Ela soma e subtrai termos: x¹/1! − x³/3! + x⁵/5! − x⁷/7! + …
    float termo, result = 0;
    int sinal = 1, n;
    for (n = 1; n <= 15; n += 2) { //O laço soma 15 termos impares (1, 3, 5, 7...)
        termo = (pot(x, n)) / fato(n);//O cálculo de pot() e fato() é usado pra cada termo.
        result += sinal * termo;
        sinal *= -1; //O sinal alterna entre + e − a cada passo. sinal = sinal * -1
    }
    return result;
}
float coss(float x) {//cosseno
//soma os termos: 1 − x²/2! + x⁴/4! − x⁶/6! + …
    float termo, result = 0;
    int sinal = 1;
    int n; 
    for (n = 0; n <= 14; n += 2) { //Começa com n = 0 porque o primeiro termo é 1 = x⁰/0!) O laço soma 14 termos pares (0, 2, 4, 7...)
        termo = (pot(x, n)) / fato(n);
        result += sinal * termo;
        sinal *= -1;//O sinal alterna entre + e − a cada passo. sinal = sinal * -1
    }
    return result;
}

//Fim das funcoes

int main() { // Programa principal
//Essas variáveis vao guardar os números a, b, o resultado e o estado da calculadora ligado ou desligado.
    float a, b, result = 0;
    char op;
    int ligado = 1;

    printf("===========================\n");
    printf("      CALCULADORA\n");
    printf("===========================\n");

    while (ligado) { // enquanto a calculadora tiver ligada ela irá retornar o menu apos os calculos
        printf("\nMenu de Opcoes:\n");
        printf("[+] Adicao\n");
        printf("[-] Subtracao\n");
        printf("[*] Multiplicacao\n");
        printf("[/] Divisao\n");
        printf("[^] Potencia\n");
        printf("[%c] Porcentagem\n", '%');
        printf("[S] Seno \n");
        printf("[C] Cosseno \n");
        printf("[I] Inicializar\n");
        printf("[D] Desligar\n");
        printf("=====================================\n");

        printf("Selecione a operacao: ");
        scanf(" %c", &op);

        switch (op) {//Cada case vai chamar a funcao escolhida pelo usuario
            case '+':
                printf("Digite dois valores: ");
                scanf("%f %f", &a, &b);
                result = soma(a, b);//puxa a função pre definida
                printf("Resultado = %.2f\n", result);
                break;

            case '-':
                printf("Digite dois valores: ");
                scanf("%f %f", &a, &b);
                result = subt(a, b);
                printf("Resultado = %.2f\n", result);
                break;

            case '*':
                printf("Digite dois valores: ");
                scanf("%f %f", &a, &b);
                result = mult(a, b);
                printf("Resultado = %.2f\n", result);
                break;

            case '/':
                printf("Digite dois valores: ");
                scanf("%f %f", &a, &b);
                result = divi(a, b);
                printf("Resultado = %.2f\n", result);
                break;

            case '^':
                printf("Digite base e expoente (inteiro): ");
                scanf("%f %f", &a, &b);
                result = pot(a, (int)b);
                printf("Resultado = %.2f\n", result);
                break;

            case '%':
                printf("Digite porcentagem deois o valor: "); //aqui pede primeiro o valor porcento depois o valor que você deseja saber o porcento. Exemplo 20% de 100
                scanf("%f %f", &a, &b);
                result = porc(a, b);
                printf("%.2f%% de %.2f = %.2f\n", b, a, result);
                break;

            case 'S'://se o usuario digitar maiusculo ou minusculo a opcao vai funcionar
            case 's':
                printf("Digite o valor de x (em radianos): ");
                scanf("%f", &a);
                result = seno(a);
                printf("sen(%.2f) = %.2f\n", a, result);
                break;

            case 'C'://se o usuario digitar maiusculo ou minusculo a opcao vai funcionar
            case 'c':
                printf("Digite o valor de x (em radianos): ");
                scanf("%f", &a);
                result = coss(a);
                printf("cos(%.2f) = %.2f\n", a, result);
                break;

            case 'I'://se o usuario digitar maiusculo ou minusculo a opcao vai funcionar
            case 'i':
                result = 0;
                printf("Calculadora reiniciada. Visor = 0\n");
                break;

            case 'D'://se o usuario digitar maiusculo ou minusculo a opcao vai funcionar
            case 'd':
                ligado = 0;
                printf("Calculadora desligada.\n");
                break;

            default:
                printf("Operacao invalida!\n");
        }
    }

    return 0;
}
