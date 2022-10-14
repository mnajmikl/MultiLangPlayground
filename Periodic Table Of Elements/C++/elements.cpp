#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define ELEMENT_CSV "elements.csv"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

struct element
{
    int elementnumber;
    std::string elementsymbol;
    std::string elementname;
    double atomicweight1;
    double atomicweight2;
    element()
    {
        elementnumber = 0;
        elementsymbol = "";
        elementname = "";
        atomicweight1 = 0.0;
        atomicweight2 = 0.0;
    }
};

void elementheader()
{
    std::cout << std::setw(8) << std::string(8, ' ')
              << std::setw(8) << std::string(8, ' ')
              << std::setw(14) << std::string(14, ' ')
              << std::internal << std::setw(16) << "Lowest"
              << std::setw(16) << "Highest" << std::endl;
    std::cout << std::setw(8) << "Element"
              << std::setw(8) << "Element"
              << std::setw(14) << "Element"
              << std::setw(16) << "Atomic"
              << std::setw(16) << "Atomic" << std::endl;
    std::cout << std::setw(8) << "Number"
              << std::setw(8) << "Symbol"
              << std::setw(14) << "Name"
              << std::setw(16) << "Weight"
              << std::setw(16) << "Weight"
              << std::endl << std::endl;
}
void printelement(element e)
{
    std::cout << std::setw(8) << e.elementnumber
              << std::setw(8) << e.elementsymbol;
    std::cout << std::setw(14) << e.elementname;
    std::cout << std::internal << std::setw(16) << std::fixed
              << std::setprecision(8) << e.atomicweight1;
    std::cout << std::setw(16) << std::fixed
              << std::setprecision(8) << e.atomicweight2 << std::endl;
}

bool readelementscsv(std::ifstream& file)
{
    if (file.is_open())
    {
        file.clear();
    }
    file.open(ELEMENT_CSV, std::ios::in);
    return (file.is_open());
}

bool setelements(std::vector<element>& element_vector)
{
    std::ifstream fp;
    if (!readelementscsv(fp))
    {
        std::cout << "\nCannot open and read element file: " << ELEMENT_CSV
                  << std::endl;
        return false;
    }
    if (!element_vector.empty())
    {
        element_vector.clear();
    }
    while (!fp.eof())
    {
        element e;
        std::string line;
        while (std::getline(fp, line))
        {
            std::istringstream linestream(line);
            std::string item;
            std::getline(linestream, item, ',');
            e.elementnumber = std::stoi(item);
            std::getline(linestream, item, ',');
            e.elementsymbol = item;
            std::getline(linestream, item, ',');
            e.elementname = item;
            std::getline(linestream, item, ',');
            e.atomicweight1 = std::stod(item);
            std::getline(linestream, item);
            e.atomicweight2 = std::stod(item);
            element_vector.push_back(e);
        }
    }
    fp.close();
    return true;
}

int getelementcount(std::vector<element> element_vector)
{
    if (element_vector.empty())
    {
        std::cerr << "\nElements vector is empty\n";
        return 0;
    }
    return element_vector.size();
}

void displaynumberofelements(std::vector<element> element_vector)
{
    std::cout << "\nThere are currently " << getelementcount(element_vector)
              << " elements in he latest Periodic Table\n";
}

void displayelements(std::vector<element> element_vector)
{
    if (getelementcount(element_vector) > 0)
    {
        elementheader();
        for(auto e: element_vector)
        {
            printelement(e);
        }
    }
}

void searchelementsbynumber(std::vector<element> element_vector)
{
    if (getelementcount(element_vector) == 0)
    {
        std::cerr << "There is no elements found from the element list file"
                  << std::endl;
        return;
    }
    int element_number = 0, found = 0;
    std::string str_number;
    std::cout << "Enter Element Number to search: ";
    std::cin.sync();
    std::getline(std::cin, str_number);
    try
    {
        element_number = std::stoi(str_number);
    }
    catch (std::invalid_argument const& ex)
    {
    }
    catch (std::out_of_range const& ex)
    {
    }
    for(auto e: element_vector)
    {
        if (element_number == e.elementnumber)
        {
            std::cout << "\nElement Number " << element_number
                      << " has been found\n" << std::endl;
            elementheader();
            printelement(e);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        std::cout << "\nElement Number " << std::setw(3)
                  << element_number << " Is Not Found\n";
    }
}

void searchelementsbysymbol(std::vector<element> element_vector)
{
    if (getelementcount(element_vector) == 0)
    {
        std::cerr << "There is no elements found from the element list file"
                  << std::endl;
        return;
    }
    int found = 0;
    std::string element_symbol;
    std::cout << "Enter Element Symbol to search: ";
    std::cin.sync();
    std::getline(std::cin, element_symbol);
    for(auto e: element_vector)
    {
        if (element_symbol == e.elementsymbol)
        {
            std::cout << "\nElement Symbol " << element_symbol
                      << " has been found\n" << std::endl;
            elementheader();
            printelement(e);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        std::cout << "\nElement Symbol " << std::setw(3)
                  << element_symbol << " Is Not Found\n";
    }
}

void menu(std::vector<element> element_vector)
{
    char choice = '1';
    while (choice != '5')
    {
        std::cout << "\n __________________________________________________";
        std::cout << "\n|                                                  |";
        std::cout << "\n|               Periodic Element Table             |";
        std::cout << "\n|__________________________________________________|";
        std::cout << "\n\ntSelect One Of The Choices\n";
        std::cout << "\n\t(1) Display All Element";
        std::cout << "\n\t(2) Display Current Total Number of Elements";
        std::cout << "\n\t(3) Search An Element By Number";
        std::cout << "\n\t(4) Search An Element By Symbol (Case Sensitive)";
        std::cout << "\n\t(5) Exit";
        std::cout <<"\n\nEnter Your choice here : ";
        std::cin.sync();
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case '1':
            displayelements(element_vector);
            break;
        case '2':
            displaynumberofelements(element_vector);
            break;
        case '3':
            searchelementsbynumber(element_vector);
            break;
        case '4':
            searchelementsbysymbol(element_vector);
            break;
        case '5':
            break;
        default:
            std::cout << "Invalid Choice. Please Try Again\n";
            break;
        }
    }
}

int main(void)
{
    std::vector<element> elements;
    if (!setelements(elements))
    {
        std::cerr << "\nCannot set the elements vector\n";
        return -1;
    }
    if (getelementcount(elements) == 0)
    {
        std::cerr << "There is no elements found from the element list file"
                  << std::endl;
        return -2;
    }
    menu(elements);
    return 0;
}
