#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

int cadastraDisciplina(cadastros *Pessoas, disciplina *Disciplinas, int qtdDisciplinas)
{
    char pis[12];
    int codigo = 0;
    char nome[30];
    int carga = 0;
    int achou = 0;
    int idprofessor = 0;
    if (qtdDisciplinas < 10)
    {
        printf("\nDigite o codigo, o nome, a carga horaria e o PIS do professor da materia (codigo;nome;carga.pis): \n");
        scanf("%i;%[^;];%i;%s", &codigo, nome, &carga, pis);

        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1; i++)
        {
            if (atoi(Pessoas[i].professor.pis) == atoi(pis))
            {
                achou = 1;
                idprofessor = i;
                break;
            }
        }
        if (achou == 1)
        {
            Disciplinas[qtdDisciplinas].codigo = codigo;
            strcpy(Disciplinas[qtdDisciplinas].nome, nome);
            Disciplinas[qtdDisciplinas].carga = carga;
            Disciplinas[qtdDisciplinas].professordisciplina = Pessoas[idprofessor];
            Disciplinas[qtdDisciplinas].qtdAlunos = 0;
            printf("\nMateria Cadastrada!\n");
            return 1;
        }
        else
        {
            printf("\nProfessor nao encontrado.\n");
            return 0;
        }
    }
    else
    {
        printf("\nNumero maximo de disciplinas atingido.\nNao e possivel inserir mais disciplinas.\n");
        return 0;
    }
};

void alteraDisciplina(cadastros *Pessoas, disciplina *Disciplinas)
{
    int codigo = 0;
    char pis[12];
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_professor = 0;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
    {
        if (Disciplinas[i].codigo == codigo)
        {
            achou = 1;
            id_disciplina = i;
            break;
        }
    }
    if (achou == 1)
    {
        printf("\nDigite o pis do novo professor da Disciplina: \n");
        scanf("%11s", pis);
        for (int i = 0; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1; i++)
        {
            if (atoi(Pessoas[i].professor.pis) == atoi(pis))
            {
                achou2 = 1;
                id_professor = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            Disciplinas[id_disciplina].professordisciplina = Pessoas[id_professor];
            printf("\nProfessor da disciplina alterado.\n");
            return;
        }
        else
        {
            printf("\nProfessor nao encontrado.\n");
            return;
        }
    }
    else
    {
        printf("\nCodigo de disciplina invalido.\n");
        return;
    }
};

void adicionaAluno(disciplina *Disciplinas, cadastros *Pessoas, int qtdPessoas, int qtdAlunos)
{
    int codigo = 0;
    int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int existe = 0;
    int id_disciplina = 0;
    int id_aluno = 0;
    cadastros Aluno;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
    {
        if (Disciplinas[i].codigo == codigo)
        {
            achou = 1;
            id_disciplina = i;
            break;
        }
    }
    if (achou == 1)
    {
        printf("\nDigite a matricula do aluno que deseja adicionar a materia: \n");
        scanf("%i", &matricula);
        for (int i = 0; i <= qtdPessoas; i++)
        {
            if (Pessoas[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                Aluno = Pessoas[i];
                break;
            }
        }
        if (achou2 == 1)
        {
            for (int i = 0; i <= qtdPessoas; i++)
            {
                if (Disciplinas[id_disciplina].alunos[i].aluno.matricula == matricula)
                {
                    existe = 1;
                    break;
                }
            }

            if (existe == 0)
            {
                id_aluno = Disciplinas[id_disciplina].qtdAlunos;
                Disciplinas[id_disciplina].alunos[id_aluno] = Aluno;
                Disciplinas[id_disciplina].qtdAlunos++;
                printf("\nAluno cadastrado com sucesso.\n");
                return;
            }
            else
            {
                printf("\nAluno já cadastrado.\n");
                return;
            }
        }
        else
        {
            printf("\nMatricula nao encontrada.\n");
            return;
        }
    }
    else
    {
        printf("\nDisciplina nao existe.\n");
        return;
    }
};

void removeAluno(disciplina *Disciplinas, cadastros *Pessoas, int qtdAlunos)
{
    int codigo = 0;
    int matricula = 0;
    int achou = 0;
    int achou2 = 0;
    int id_disciplina = 0;
    int id_aluno = 0;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i <= (sizeof(Disciplinas) / sizeof(Disciplinas[0])) + 1; i++)
    {
        if (Disciplinas[i].codigo == codigo)
        {
            achou = 1;
            id_disciplina = i;
            break;
        }
    }
    if (achou == 1)
    {
        printf("\nDigite a matricula do aluno a ser removido: \n");
        scanf("%i", &matricula);
        for (int i = 0; i < qtdAlunos + 2; i++)
        {
            if (Disciplinas[id_disciplina].alunos[i].aluno.matricula == matricula)
            {
                achou2 = 1;
                id_aluno = i;
                break;
            }
        }
        if (achou2 == 1)
        {
            for (int i = id_aluno; i <= (sizeof(Pessoas) / sizeof(Pessoas[0])) + 2; i++)
            {
                if (i < (sizeof(Pessoas) / sizeof(Pessoas[0])) + 1)
                {
                    Disciplinas[id_disciplina].alunos[i] = Disciplinas[id_disciplina].alunos[i + 1];
                }
                else
                {
                    Disciplinas[id_disciplina].alunos[i] = EmptyStruct;
                }
            }
            printf("\nAluno removido com sucesso.\n");
            return;
        }
        else
        {
            printf("\nMatricula nao encontrada.\n");
            return;
        }
    }
    else
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }
};

void exibeDisciplina(disciplina *Disciplinas, int qtdDisciplinas)
{
    int codigo = 0;
    int achou = 0;
    int id_disciplina = 0;
    printf("\nDigite o codigo da disciplina: \n");
    scanf("%i", &codigo);
    for (int i = 0; i < qtdDisciplinas + 1; i++)
    {
        if (Disciplinas[i].codigo == codigo)
        {
            achou = 1;
            id_disciplina = i;
            break;
        }
    }
    if (achou == 1)
    {
        printf("\nCodigo da Disciplina: ");
        printf("%i\n", Disciplinas[id_disciplina].codigo);
        printf("\nNome da Disciplina: ");
        printf("%s\n", Disciplinas[id_disciplina].nome);
        printf("\nProfessor da Disciplina: ");
        printf("%s ", Disciplinas[id_disciplina].professordisciplina.nome);
        printf("%s\n", Disciplinas[id_disciplina].professordisciplina.sobrenome);
        printf("\nAlunos da Disciplina: \n");
        for (int i = 0; i < Disciplinas[id_disciplina].qtdAlunos; i++)
        {
            printf("%i ", Disciplinas[id_disciplina].alunos[i].aluno.matricula);
            printf("%s\n", Disciplinas[id_disciplina].alunos[i].nome);
        }
        return;
    }
    else
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }
};