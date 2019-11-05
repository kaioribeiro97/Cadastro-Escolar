#include <stdio.h>
#include "estruturas.h"
#include "pessoas.h"
#include "disciplinas.h"
int main()
{
    escola escola;
    int controle = 0;
    int comandopessoa = 0;
    int comandodisc = 0;
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
            do
            {
                printf("\nSistema de Pessoas--------------\n1 - Cadastrar\n2 - Remover\n3 - Exibir todos os dados\n4 - Exibir dados de uma pessoa\n5 - Alterar dados de uma pessoa\n6 - Voltar ao menu principal\n");
                scanf("%i", &comandopessoa);
                switch (comandopessoa)
                {
                case 1:
                    cadastrar(escola.pessoas, &qtdPessoas, &qtdAlunos, &qtdProfessores);
                    break;
                case 2:
                    removerpessoa(escola.pessoas, &qtdPessoas, &qtdDisciplinas, &qtdProfessores, &qtdAlunos, escola.disciplinas);
                    break;
                case 3:
                    exibirdados(escola.pessoas, &qtdPessoas);
                    break;
                case 4:
                    exibe_pessoax(escola.pessoas, &qtdPessoas);
                    break;
                case 5:
                    alterarDados(escola.pessoas, &qtdPessoas);
                    break;

                case 6:
                    printf("\nVoltando ao menu.\n");
                    break;

                default:
                    printf("\nComando Invalido.\n");
                    break;

                }
            } while (comandopessoa != 6);

            break;

        case 2:
            do
            {
                printf("\nSistema de Disciplinas-------------\n1 - Cadastrar disciplina\n2 - Alterar professor de uma disciplina\n3 - Adicionar um aluno a uma disciplina\n4 - Remover aluno de uma disciplina\n5 - Exibir dados de uma disciplina\n6 - Voltar ao menu principal\n");
                scanf("%i", &comandodisc);
                switch (comandodisc)
                {
                case 1:
                    resultado = cadastraDisciplina(escola.pessoas, escola.disciplinas, qtdDisciplinas, qtdPessoas);
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
            } while (comandodisc != 6);
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
