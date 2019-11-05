#include <stdio.h>
#include "estruturas.h"

void cadastrar(cadastros pessoa[], int *qtda, int *qtda_al, int *qtda_prof)
{
    char dia[3];
    char mes[3];
    char ano[5];
    if(*qtda_al >=50 || *qtda_prof >=10)
    {
        printf("Limite maximo de pessoas alcancadas, encerrando cadastro... \n");
        return;
    }
    pessoa[*qtda].nacionalidade=3;
    pessoa[*qtda].dia=32;
    pessoa[*qtda].mes=13;
    pessoa[*qtda].pnet=3;
    pessoa[*qtda].cep=1;
    pessoa[*qtda].tipo=3;
    char aux1[20];
    getchar();
    scanf("%[^;]s",pessoa[*qtda].nome);
    getchar();
    scanf("%[^;]s",pessoa[*qtda].sobrenome);
    getchar();
    while(pessoa[*qtda].nacionalidade < 0 || pessoa[*qtda].nacionalidade > 1)
    {
        scanf("%d;", &pessoa[*qtda].nacionalidade);
        if(pessoa[*qtda].nacionalidade<0 || pessoa[*qtda].nacionalidade>1)
        {
            printf("nacionalidade invalida, Digite novamente:\n");
        }
        if(pessoa[*qtda].nacionalidade==0)
        {
            scanf("%[^;]s", pessoa[*qtda].brasileiro.cpf);
            getchar();
            if(strlen(pessoa[*qtda].brasileiro.cpf)<11 || strlen(pessoa[*qtda].brasileiro.cpf)>11)
            {
                printf("CPF invalido! Digite novamente:\n");
            }
            scanf("%[^;]s", pessoa[*qtda].brasileiro.rg);
            getchar();
            if(strlen(pessoa[*qtda].brasileiro.rg)<9 || strlen(pessoa[*qtda].brasileiro.rg)>9)
            {
                printf("RG invalido! Digite novamente:\n");
            }
        }
        if(pessoa[*qtda].nacionalidade==1)
        {
            scanf("%[^;]s", pessoa[*qtda].estrangeiro.passaporte);
            getchar();
            scanf("%[^;]s", &pessoa[*qtda].estrangeiro.pais_orig);
            getchar();
        }
    }
    while(pessoa[*qtda].mes>12 || pessoa[*qtda].dia>31)
    {
        scanf("%[^/]s", dia);
        getchar();
        scanf("%[^/]s", mes);
        getchar();
        scanf("%[^;]s", ano);
        getchar();
        pessoa[*qtda].dia = atoi(dia);
        pessoa[*qtda].mes = atoi(mes);
        pessoa[*qtda].ano = atoi(ano);
        if(pessoa[*qtda].dia>31)
        {
            printf("Dia invalido, digite novamente.\n");
        }
        if(pessoa[*qtda].mes>12)
        {
            printf("Mes invalido, digite novamente.\n");
        }
        if(pessoa[*qtda].ano>9999)
        {
            printf("Ano invalido, digite novamente.\n");
        }
    }
    scanf("%d;", &pessoa[*qtda].pnet);
    if(pessoa[*qtda].pnet==1)
    {
        scanf("%[^;]s", pessoa[*qtda].pne.laudo);
        getchar();
    }
    if(pessoa[*qtda].pnet>1 || pessoa[*qtda].pnet<0)
    {
        printf("pne invalido! Digite novamente:");
    }
    while(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999)
    {
        scanf("%d;", &pessoa[*qtda].cep);
        if(pessoa[*qtda].cep<10000000 || pessoa[*qtda].cep>99999999)
        {
            printf("CEP invalido! Digite novamente:\n");
        }
    }
    scanf("%[^;]s", pessoa[*qtda].endereco);
    getchar();
    while(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
    {
        scanf("%d;", &pessoa[*qtda].tipo);
        if(pessoa[*qtda].tipo < 0 || pessoa[*qtda].tipo > 1)
        {
            printf("tipo de pessoa inválido! Digite novamente:\n");
        }
        if(pessoa[*qtda].tipo==1)
        {
            (*qtda_prof)++;
            scanf("%[^\n]s", pessoa[*qtda].professor.pis);
            getchar();
            if(strlen(pessoa[*qtda].professor.pis)<11 || strlen(pessoa[*qtda].professor.pis)>11)
            {
                printf("pis invalido! Digite novamente:");
                scanf("%[^\n]s", pessoa[*qtda].professor.pis);
                getchar();
            }
        }
        if(pessoa[*qtda].tipo==0)
        {
            pessoa[*qtda].aluno.matricula=19000+*qtda_al;
            (*qtda_al)++;
        }
    }
    (*qtda)++;
}

void removerpessoa(cadastros pessoa[], int *qtda, int *qtda_disc, int *qtda_al, int *qtda_prof, disciplina disciplinas[])
{
    char aux[11];
    long int aux2;
    int tipo;
    int i;
    int pos=0;
    printf("Se a pessoa que deseja remover for um aluno, digite 0, caso seja um professor, digite 1:");
    scanf("%d", &tipo);
    getchar();
    if(tipo==1)
    {
        printf("Digite o pis do professor:");
        scanf("%s", aux);
        getchar();
        for(i = 0 ; i < *qtda_disc; i++)
        {
            if(atoi(aux)==atoi(disciplinas[i].professordisciplina.professor.pis))
            {
                printf("Professor encontrado em uma disciplina, impossivel remover!\n");
                return;
            }
        }
        for(i = 0 ; i < *qtda; i++)
        {
            if(atoi(aux)==atoi(pessoa[i].professor.pis))
            {
                printf("Professor encontrado!\n");
                pos = i;
                (*qtda)--;
                (*qtda_prof)--;
                for(i = pos; i < *qtda; i++)
                {
                    pessoa[i] = pessoa[i+1];
                }
            }
            else
            {
                pos = -1;
            }
        }
        if(pos == -1)
        {
            printf("Pessoa nao cadastrada!\n");
            return;
        }
        printf("A pessoa da posicao %d foi deletada\n",pos);
    }

    if(tipo==0)
    {

        printf("Digite a matricula do aluno:");
        scanf("%ld", &aux2);
        getchar();
        for(i = 0 ; i < *qtda_disc; i++)
        {
            for(int j=0 ; j < disciplinas[i].qtdAlunos ; j++)
            {
                if(aux2==disciplinas[i].alunos[j].aluno.matricula)
                {
                    printf("Aluno encontrado em uma disciplina, impossivel remover!\n");
                    return;
                }
            }
        }
        for(i = 0 ; i < *qtda; i++)
        {
            if(aux2==pessoa[i].aluno.matricula)
            {
                printf("Aluno encontrado!\n");
                pos = i;
                (*qtda)--;
                (*qtda_al)--;
                for(i = pos; i < *qtda; i++)
                {
                    pessoa[i] = pessoa[i+1];
                }
            }
            else
            {
                pos = -1;
            }
        }
        if(pos == -1)
        {
            printf("Pessoa nao cadastrada!\n");
            return;
        }
        printf("A pessoa da posicao %d foi deletada\n",pos);
    }
}


void exibirdados(cadastros pessoa[], int *qtda)
{
    printf("Exibindo dados \n");
    for(int i = 0; i < *qtda; i++)
    {
        printf("//////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        printf("Pessoa %d:\n", i);
        printf("Nome: %s\n",pessoa[i].nome);
        printf("Sobrenome: %s \n",pessoa[i].sobrenome);
        printf("Data de nascimento: %d/",pessoa[i].dia);
        printf("%d/",pessoa[i].mes);
        printf("%d\n",pessoa[i].ano);
        if(pessoa[i].nacionalidade==0)
        {
            printf("Brasileiro\n");
            printf("CPF: %s\n", pessoa[i].brasileiro.cpf);
            printf("RG: %s\n", pessoa[i].brasileiro.rg);
        }
        if(pessoa[i].nacionalidade==1)
        {
            printf("Pais de origem: %s\n", pessoa[i].estrangeiro.pais_orig);
            printf("Numero do passaporte: %s\n", pessoa[i].estrangeiro.passaporte);
        }
        if(pessoa[i].pnet==1)
        {
            printf("Codigo do laudo medico: %s\n", pessoa[i].pne.laudo);

        }
        printf("CEP: %d\n", pessoa[i].cep);
        printf("Endereco: %s\n", pessoa[i].endereco);
        if(pessoa[i].tipo==0)
        {
            printf("Matricula: %d\n\n", pessoa[i].aluno.matricula);
        }
        if(pessoa[i].tipo==1)
        {
            printf("PIS: %s\n\n", pessoa[i].professor.pis);
        }
    }
}

void alterarDados(cadastros pessoa[], int *qtda)
{
    int tipo;
    long int matricula;
    char pis[11];
    int achou;
    int controle;
    int id_pessoa;
    int pnet ;
    char laudo[30];
    int cep;
    char endereco[200];

    printf("\nDigite 0 para Aluno ou 1 para Professor:");
    scanf("%d", &tipo);
    if (tipo == 0)
    {
        printf("\nDigite a matricula: \n");
        scanf("%ld",&matricula);
        for (int i = 0; i <= *qtda; i++)
        {
            if (pessoa[i].aluno.matricula == matricula)
            {
                achou = 1;
                id_pessoa = i;
                break;
            }
        }
        if (achou == 1)
        {
            printf("\n1 - Portador de Necessidades especiais?\n2 - Codigo do laudo medico\n3 - CEP\n4 - Endereco\n");
            scanf("%i", &controle);
            switch (controle)
            {
            case 1:
                printf("\nPNE 1 para sim, 0 para não:\n");
                scanf("%i", &pnet);
                if (pnet == 1 || pnet == 0)
                {
                    if (pessoa[id_pessoa].pnet != pnet)
                    {
                        if (pnet == 1)
                        {
                            pessoa[id_pessoa].pnet = 1;
                            printf("\nDigite o laudo: \n");
                            scanf("%s", pessoa[id_pessoa].pne.laudo);
                        }
                        else if(pnet == 0)
                        {
                            pessoa[id_pessoa].pnet = 0;
                            //strcpy(pessoa[id_pessoa].pne.laudo, NULL);
                        }
                    }
                    else
                    {
                        printf("\nStatus ja presente no sistema.\n");
                    }
                }
                else
                {
                    printf("\nValor Invalido.\n");
                }
                break;

            case 2:
                if (pessoa[id_pessoa].pnet == 1)
                {
                    printf("\nDigite o novo laudo: \n");
                    scanf("%s", laudo);
                    strcpy(pessoa[id_pessoa].pne.laudo, laudo);
                }
                else
                {
                    printf("\nO aluno nao eh PNE.");
                }
                break;

            case 3:
                printf("\nDigite o novo CEP\n");
                scanf("%i", &cep);
                pessoa[id_pessoa].cep = cep;
                break;

            case 4:
                printf("\nDigite o novo endereco\n");
                getchar();
                scanf("%[^\n]s", endereco);
                strcpy(pessoa[id_pessoa].endereco, endereco);
                break;
            default:
                printf("Comando invalido \n");
                break;
            }
        }
        else if(achou != 1)
        {
            printf("\nAluno nao encontrado.\n");
            return;
        }
    }
    if (tipo == 1)
    {
        printf("Digite o Pis do professor: \n");
        scanf("%s", pis);
        for (int i = 0; i <= *qtda; i++)
        {
            if(atoi(pis)==atoi(pessoa[i].professor.pis))
            {
                achou = 1;
                id_pessoa = i;
                break;
            }
        }
        if (achou == 1 )
        {
            printf("\n1 - Portador de Necessidades especiais?\n2 - Codigo do laudo medico\n3 - CEP\n4 - Endereco\n");
            scanf("%i", &controle);
            switch (controle)
            {
            case 1:
                printf("\nPNE?\n");
                scanf("%i", &pnet);
                if (pnet == 1 || pnet == 0)
                {
                    if (pessoa[id_pessoa].pnet != pnet)
                    {
                        if (pnet == 1)
                        {
                            pessoa[id_pessoa].pnet = 1;
                            printf("\nDigite o laudo: \n");
                            scanf("%s", pessoa[id_pessoa].pne.laudo);
                        }
                        else if(pnet == 0)
                        {
                            pessoa[id_pessoa].pnet = 0;
                            //strcpy(pessoa[id_pessoa].pne.laudo, NULL);
                        }
                    }
                    else
                    {
                        printf("\nStatus ja presente no sistema.\n");
                    }
                }
                else
                {
                    printf("\nValor Invalido.\n");
                }
                break;

            case 2:
                if (pessoa[id_pessoa].pnet == 1)
                {
                    printf("\nDigite o novo laudo: \n");
                    scanf("%s", laudo);
                    strcpy(pessoa[id_pessoa].pne.laudo, laudo);
                }
                else
                {
                    printf("\nO Professor nao eh PNE.");
                }
                break;

            case 3:
                printf("\nDigite o novo CEP\n");
                scanf("%i", &cep);
                pessoa[id_pessoa].cep = cep;
                break;

            case 4:
                printf("Digite o novo endereco\n");
                getchar();
                scanf("%[^\n]s", endereco);
                strcpy(pessoa[id_pessoa].endereco, endereco);
                break;
            default:
                printf("Comando invalido \n");
                break;
            }
        }
        else if(achou != 1)
        {
            printf("Professor nao encontrado.\n");
            return;
        }
    }
}


void exibe_pessoax(cadastros pessoa[], int *qtda)
{
    int pos=-1;
    char aux[11];
    long int aux2;
    int tipo;
    int i;
    printf("Se a pessoa que deseja exibir for um aluno, digite 0, caso seja um professor, digite 1:");
    scanf("%d", &tipo);
    getchar();
    if(tipo==1)
    {

        printf("Digite o pis do professor:");
        scanf("%s", aux);
        getchar();
        for(i = 0 ; i < *qtda; i++)
        {
            if(atoi(aux)==atoi(pessoa[i].professor.pis))
            {
                printf("professor encontrado!\n");
                pos = i;
            }
        }
    }

    if(tipo==0)
    {

        printf("Digite a matricula do aluno:");
        scanf("%ld", &aux2);
        getchar();
        for(i = 0 ; i < *qtda; i++)
        {
            if(aux2==pessoa[i].aluno.matricula)
            {
                printf("Aluno encontrado!\n");
                pos = i;
            }
        }
    }

    if(pos==-1)
    {
        printf("Pessoa nao encontrada!");
        return;
    }
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("Exibindo dados da pessoa %d:\n", pos);

    printf("Nome: %s\n",pessoa[pos].nome);
    printf("Sobrenome: %s \n",pessoa[pos].sobrenome);
    printf("Data de nascimento: %d/",pessoa[pos].dia);
    printf("%d/",pessoa[pos].mes);
    printf("%d\n",pessoa[pos].ano);
    if(pessoa[pos].nacionalidade==0)
    {
        printf("Brasileiro\n");
        printf("CPF: %s\n", pessoa[pos].brasileiro.cpf);
        printf("RG: %s\n", pessoa[pos].brasileiro.rg);
    }
    if(pessoa[pos].nacionalidade==1)
    {
        printf("Pais de origem: %s\n", pessoa[pos].estrangeiro.pais_orig);
        printf("Numero do passaporte: %s\n", pessoa[pos].estrangeiro.passaporte);
    }
    if(pessoa[pos].pnet==1)
    {
        printf("Codigo do laudo medico: %s\n", pessoa[pos].pne.laudo);

    }
    printf("CEP: %d\n", pessoa[pos].cep);
    printf("Endereco: %s\n", pessoa[pos].endereco);
    if(pessoa[pos].tipo==0)
    {
        printf("Matricula: %d\n\n", pessoa[pos].aluno.matricula);
    }
    if(pessoa[pos].tipo==1)
    {
        printf("PIS: %s\n\n", pessoa[pos].professor.pis);
    }
}

int cadastraDisciplina(cadastros *Pessoas, disciplina *Disciplinas, int qtdDisciplinas)
{
    char pis[11];
    int codigo = 0;
    char nome[30];
    int carga = 0;
    int achou = 0;
    int idprofessor = 0;
    if (qtdDisciplinas < 10)
    {
        printf("\nDigite o codigo, o nome, a carga horaria e o PIS do professor da materia (codigo;nome;carga.pis): \n");
        scanf("%i;%[^;];%i;%s", &codigo, nome, &carga, pis);
        printf("%s\n", nome);
        printf("%i\n", codigo);
        printf("%i\n", carga);
        printf("%s\n", pis);
        printf("%s\n", Pessoas[qtdDisciplinas].professor.pis);

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
    char pis[11];
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
                printf("%i", Disciplinas[id_disciplina].qtdAlunos);
                Disciplinas[id_disciplina].alunos[id_aluno] = Aluno;
                Disciplinas[id_disciplina].qtdAlunos++;
                printf("%i", Disciplinas[id_disciplina].alunos[qtdAlunos].aluno.matricula);
                printf("%i", Disciplinas[id_disciplina].qtdAlunos);
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
        printf("\nAlunos da Disciplina: ");
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
