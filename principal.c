#include <stdio.h>
#include "estruturas.h"
#include "disciplinas.h"

int main(int argc, char const *argv[])
{
    escola escola;
    int controle = 0;
    int qtdPessoas = 0;
    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;
    int resultado = 0;
    do
    {
        printf("\nCadastro Escolar------------------\n1 - Sistema de Pessoas.\n2 - Sistema de Disciplinas.\n3 - Sair do Sistema.\n");
        scanf("%i", &controle);
        switch (controle)
        {
        case 1:
            
            break;

        case 2:
            do
            {
                printf("\nSistema de Disciplinas-------------\n1 - Cadastrar disciplina\n2 - Alterar professor de uma disciplina\n3 - Adicionar um aluno a uma disciplina\n4 - Remover aluno de uma disciplina\n5 - Exibir dados de uma disciplina\n6 - Voltar ao menu principal\n");
                scanf("%i", &controle);
                switch (controle)
                {
                case 1:
                    resultado = cadastraDisciplina(escola.pessoas, escola.disciplinas, qtdDisciplinas);
                    if (resultado == 1)
                    {
                        qtdDisciplinas++;
                    }
                    break;

                case 2:
                    alteraDisciplina(escola.pessoas, escola.disciplinas);
                    break;

                case 3:
                    adicionaAluno(escola.disciplinas, escola.pessoas, qtdPessoas, qtdAlunos);
                    break;

                case 4:
                    removeAluno(escola.disciplinas, escola.pessoas, qtdAlunos);
                    break;

                case 5:
                    exibeDisciplina(escola.disciplinas, qtdDisciplinas);
                    break;

                case 6:
                    printf("\nVoltando ao menu.\n");
                    break;

                default:
                    printf("\nComando Invalido.\n");
                    break;
                }
            } while (controle != 6);
            break;

        case 3:
            printf("\nSaindo do Sistema.\n");
            return 0;
            break;

        default:
            printf("\nOpcao Invalida.\n");
            break;
        }
    } while (controle != 3);

    return 0;
}
