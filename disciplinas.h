#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

int cadastraDisciplina(cadastros *Pessoas, disciplina *Disciplinas, int qtdDisciplinas, int qtdPessoas);

void alteraDisciplina(cadastros *Pessoas, disciplina *Disciplinas);

void adicionaAluno(disciplina *Disciplinas, cadastros *Pessoas, int qtdPessoas, int qtdAlunos);

void removeAluno(disciplina *Disciplinas, cadastros *Pessoas, int qtdAlunos);

void exibeDisciplina(disciplina *Disciplinas, int qtdDisciplinas);