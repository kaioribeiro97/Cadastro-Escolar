#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Brasileiro
{
    char cpf[12];
    char rg[10];
} brasileiro;

typedef struct Estrangeiro
{
    char passaporte[10];
    char pais_orig[20];
} estrangeiro;

typedef struct PNE
{
    char laudo[10];
} pne;

typedef struct Aluno
{
    int matricula;
} aluno;

typedef struct Professor
{
    char pis[12];
} professor;

typedef struct Cadastro
{
    char nome[15];
    char sobrenome[30];
    int nacionalidade;
    union
    {
        brasileiro brasileiro;
        estrangeiro estrangeiro;
    };
    int tipo;
    union
    {
        aluno aluno;
        professor professor;
    };
    int pnet;
    union
    {
        pne pne;
    };
    int dia;
    int mes;
    int ano;
    int cep;
    char endereco[200];
} cadastros ;

typedef struct Disciplina
{
    int codigo;
    char nome[30];
    int carga;
    cadastros professordisciplina;
    cadastros alunos[10];
    int qtdAlunos;

} disciplina;

typedef struct Escola
{
    cadastros pessoas[60];
    disciplina disciplinas[10];
} escola;

static const struct Cadastro EmptyStruct;

#endif
