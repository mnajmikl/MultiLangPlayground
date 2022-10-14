#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

struct element
{
    int elementnumber;
    char elementsymbol[4];
    char elementname[16];
    double atomicweight1;
    double atomicweight2;
};

static void printelementableheader()
{
	printf("%8s %8s %13s %8s %14s\n", " ", " ", " ", "Lowest", "Highest");
	printf("%8s %8s %13s %8s %13s\n", "Element", "Element", "Element", "Atomic", "Atomic");
	printf("%8s %8s %13s %8s %13s\n\n", "Number", "Symbol", "Name", "Number", "Number");
}

static void printelement(struct element e)
{
	printf("%8d %8s", e.elementnumber, e.elementsymbol);
	printf("%14s", e.elementname);
	printf("%14.8lf", e.atomicweight1);
	printf("%14.8lf\n", e.atomicweight2);
}

static int getelementcount(void)
{
    int count_lines = 1;
    FILE *fp;
    fp = fopen("elements.csv","r");
    int chr = getc(fp);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            ++count_lines;
        }
        chr = getc(fp);
    }
    fclose(fp);
    return count_lines;
}

static void displaynumberofelements(void)
{
    printf("\nThere are currently %d elements in he latest Periodic Table\n",
           getelementcount());
}

static void displayelements(void)
{
    FILE *fp;
    fp = fopen("elements.csv","r");
    struct element displayelement;
	printelementableheader();
    while (!feof(fp))
    {
        fscanf(fp, "%d,%[^,\n],%[^,\n],%lf,%lf\n",
               &displayelement.elementnumber, displayelement.elementsymbol,
               displayelement.elementname, &displayelement.atomicweight1,
               &displayelement.atomicweight2);
		printelement(displayelement);
    }
    fclose(fp);
}

static void searchelementsbynumber(void)
{
    FILE *fp;
    int element_number = 0, found = 0;
    struct element searchelement;
    printf("Enter Element Number to search: ");
    scanf("%d", &element_number);
    fflush(stdin);
    fp = fopen("elements.csv","r");
    while (!feof(fp))
    {
        fscanf(fp, "%d,%[^,\n],%[^,\n],%lf,%lf\n",
               &searchelement.elementnumber, searchelement.elementsymbol,
               searchelement.elementname, &searchelement.atomicweight1,
               &searchelement.atomicweight2);
        if (searchelement.elementnumber == element_number)
        {
            printf("\nElement Number %d has been found\n\n",
                   searchelement.elementnumber);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nElement Number %d Is Not Found\n", element_number);
		return;
    }
	printelementableheader();
	printelement(searchelement);
    fclose(fp);
}

static void searchelementsbysymbol(void)
{
    FILE *fp;
    char element_symbol[4];
    int found = 0;
    struct element searchelement;
    printf("Enter Element Symbol to search: ");
    scanf("%3s", element_symbol);
    fflush(stdin);
    fp = fopen("elements.csv","r");
    while (!feof(fp))
    {
        fscanf(fp, "%d,%[^,\n],%[^,\n],%lf,%lf\n",
               &searchelement.elementnumber, searchelement.elementsymbol,
               searchelement.elementname, &searchelement.atomicweight1,
               &searchelement.atomicweight2);
        if (strcmp(element_symbol, searchelement.elementsymbol) == 0)
        {
            printf("\nElement Symbol %s has been found\n\n", element_symbol);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nElement Symbol %3s Is Not Found\n", element_symbol);
		return;
    }
	printelementableheader();
	printelement(searchelement);
    fclose(fp);
}

static void menu(void)
{
    char choice = '1';
    while (choice != '5')
    {
        printf("\n ____________________________________________________");
        printf("\n|                                                    |");
        printf("\n|               Periodic Element Table               |");
        printf("\n|____________________________________________________|");
        printf("\n\ntSelect One Of The Choices\n");
        printf("\n\t(1) Display All Element");
        printf("\n\t(2) Display Current Total Number of Elements");
        printf("\n\t(3) Search An Element By Number");
        printf("\n\t(4) Search An Element By Symbol (Case Sensitive)");
        printf("\n\t(5) Exit");
        printf("\n\nEnter Your choice here : ");
        scanf(" %c", &choice);
        fflush(stdin);
        switch (choice)
        {
        case '1':
            displayelements();
            break;
        case '2':
            displaynumberofelements();
            break;
        case '3':
            searchelementsbynumber();
            break;
        case '4':
            searchelementsbysymbol();
            break;
        case '5':
            break;
        default:
            printf("Invalid Choice. Please Try Again\n");
            break;
        }
    }
}

int main(void)
{
    menu();
    return 0;
}
