#include <iostream>
#include <cctype> // Incluindo a biblioteca <cctype>, que possui a função tolower 

int main(int argc, char** argv) {
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    int fileira = -1, acento = -1;
    char poltrona = ' ';
    char continuaReserva; // Variável para perguntar se o cliente deseja continuar comprando
    int tipoPassagem; // Variável para definir o tipo de passagem
    char confirmarCompra; // Variável para confirmar a aquisição da passagem

    while (true) {
        printf("\nDigite a fileira (1-10): ");
        scanf("%d", &fileira);
        
        if (fileira < 1 or fileira > 10) { //Condição para verificar se a fileira digitada está entre os valores disponíveis 
            printf("\nFileira invalida! Digite uma fileira entre 1 e 10");
            continue;
        }
        
        printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
        scanf(" %c", &poltrona);
        
        poltrona = tolower(poltrona); // Função que serve para tratar letras minúsculas e maiúsculas de forma equivalente
        
        switch (poltrona) {
            case 'a':
                acento = 0;
                break;
            case 'b':
                acento = 1;
                break;
            case 'c':
                acento = 2;
                break;
            case 'd':
                acento = 3;
                break;
            case 'e':
                acento = 4;
                break;
            case 'f':
                acento = 5;
                break;
            default:
                printf("\nPoltrona invalida! Digite outra");
                continue; // Retorna ao início do loop para exigir uma nova entrada
        }
	
        
        if (reserva[fileira - 1][acento] !=  ' ') { // Verifica se o assento já está ocupado
            printf("\nEsse assento ja esta reservado. Escolha outro.\n");
            continue;  // O comando é utilizado para pular para a próxima interação do loop quando o assento estiver reservado
        }
        
        printf("\nTipo de Passagem (1-Executivo, 2-Economico): "); // Pede para o cliente digitar o tipo de passagem
        scanf(" %d", &tipoPassagem);
        
        if (tipoPassagem == 2) { // Tipo de passagem econômica
            if (poltrona == 'a' or poltrona == 'f') {  // A e F são exclusivas para o tipo de passagem Executivo
                printf("As poltronas A e F sao exclusivas para passagem do tipo Executivo! Escolha outra poltrona\n");
    
		        	
		        printf("\nDigite a poltrona [B][C][D][E]: ");
		        scanf(" %c", &poltrona);
		        
			        switch (poltrona) {
			            case 'b':
			                acento = 1;
			                break;
			            case 'c':
			                acento = 2;
			                break;
			            case 'd':
			                acento = 3;
			                break;
			            case 'e':
			                acento = 4;
			                break;
			            default:
			                printf("\nPoltrona invalida! Digite outra");
			                continue; // Retorna ao início do loop para exigir uma nova entrada
			        }	
 			}	
            reserva[fileira - 1][acento] = 'x'; // Marca o assento como reservado
            printf("\nReserva realizada com sucesso!\n");
        } 
		else if (tipoPassagem == 1) { // Tipo de passagem executiva
    		if (poltrona != 'a' and poltrona != 'f') { // Verifica se a poltrona escolhida não é A ou F
        		while (true) {
            	printf("Deseja confirmar a compra desta reserva? (S/N) \n(Recomendo que escolha as poltronas prioritarias (A ou F), pois sao na janela): ");
            	scanf(" %c", &confirmarCompra);
            		if (confirmarCompra == 'n' or confirmarCompra == 'N') {
                		break; // Sai desse loop e retorna ao início do loop principal
            		} 
					else if (confirmarCompra == 's' or confirmarCompra == 'S') {
                		reserva[fileira - 1][acento] = 'x'; // Confirmar a poltrona como reservada
                		printf("\nReserva realizada com sucesso!\n");
                		break; // Sai do loop de confirmação
            		} 
					else {
                		printf("Digite uma resposta valida (S/N)\n"); // Pede ao passageiro para digitar uma resposta válida
            		}
        		}
    		} 
		else { // Se a poltrona é A ou F, faz a reserva sem recomendação
	        reserva[fileira - 1][acento] = 'x'; // Marca a poltrona como reservada
	        printf("\nReserva realizada com sucesso!\n");
   		}
		}


        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
        for (int x = 0; x < 10; x++) {
            if (x < 9) printf("\n\t0%d\t", x + 1);
            else printf("\n\t%d\t", x + 1);
            
            for (int y = 0; y < 6; y++) {
                printf("[%c] ", reserva[x][y]);
                if (y == 2) {
                    printf("\t");
                }
            }
        }
         while (true) {
            printf("\nDeseja comprar mais uma reserva? (S/N): ");
            scanf(" %c", &continuaReserva);
            if (continuaReserva == 'n' or continuaReserva == 'N') {
                printf("\nEncerrando o sistema de reservas...\n");
                return 0;  // Encerra o sistema
            } else if (continuaReserva == 's' or continuaReserva == 'S') {
                break; // Retorna ao início do loop principal
            } else {
                printf("Digite um comando valido (S/N)\n");
            }
        }    
    }
	return 0;
}
