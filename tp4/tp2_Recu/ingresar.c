int pedirNumero(char mensaje[])
{
    int retorno;
    char num[10];

    printf("%s",mensaje);
    scanf("%s",&num);

    for (int i = 0; i < strlen(num); i++)
    {
        while(!isdigit(num[i]) )
        {
            printf("Error. %s",mensaje);
            scanf("%s",&num);
        }
        break;
    }

    retorno = atoi(num);

    return retorno;
}
