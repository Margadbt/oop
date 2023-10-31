#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class employee
{
private:
    int number;
    int age;
    int hourSal;
    char *name;
    char *position;
    float hour;
    float extraHour;
    float calcZah();
    static int count;

public:
    employee();
    employee(int n, char name[], int a, int ho, char position[], float h);
    ~employee();
    void getData();
    void showData();
    float calcSal();
    bool addHour(float);
    void lineData();

    static void showCount();

    int get_number() const { return number; }
    int get_age() const { return age; }
    int get_hourSal() const { return hourSal; }
    const char *get_name() const { return name; }
    const char *get_position() const { return position; }
    float get_hour() const { return hour; }

    void set_number(int n) { number = n; }
    void get_age(int n) { age = n; }
    void get_hourSal(int n) { hourSal = n; }
    void set_name(const char *n) { strcpy(name, n); }
    void set_position(const char *p) { strcpy(position, p); }
    void set_hour(float h) { hour = h; }
};

int employee::count = 0;

void employee::showCount()
{
    cout << "Niit Ajilchdiin too: " << count << endl;
}

employee::employee()
{
    number = 0;
    age = 20;
    hourSal = 6500;
    name = new char[1];
    strcpy(name, "");
    position = new char[9];
    strcpy(position, "Ajilchin");
    hour = 0.0;
    extraHour = 0.0;

    count++;
}

employee::employee(int n, char name[], int a, int ho, char position[], float h)
{
    number = n;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    age = a;
    hourSal = ho;
    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
    hour = h;
    extraHour = 0.0;

    count++;
}

employee::~employee()
{
    delete [] name;
    delete [] position;
}

void employee::getData()
{
    delete [] name;
    delete [] position;
    char n[20], p[20];

    cout << "1. Dugaar: ";
    cin >> number;
    cout << "2. Ner: ";
    cin >> n;
    cout << "3. Nas: ";
    cin >> age;
    cout << "4. Alban Tushaal: ";
    cin >> p;
    cout << "5. Tsagiin huls(Tugrug): ";
    cin >> hourSal;
    cout << "6. Ajillasan Tsag: ";
    cin >> hour;

    name = new char[strlen(n)+1];
    strcpy(name, n);
    position = new char[strlen(p) +1];
    strcpy(position, p);
}

void employee::showData()
{
    cout << "Dugaar: " << number << endl;
    cout << "Ner: " << name << endl;
    cout << "Nas: " << age << endl;
    cout << "Alban tushaal: " << position << endl;
    cout << "Ajillasan tsag: " << hour << endl;
}

float employee::calcZah()
{
    float sal;
    sal = ((hour + extraHour) * hourSal);
    return sal;
}

float employee::calcSal()
{
    float sal;
    if (strcmp(position, "Zahiral") != 0 && strcmp(position, "zahiral") != 0)
    {
        sal = (hour + extraHour) * hourSal;
    }
    else
    {
        sal = calcZah();
    }
    return sal;
}

bool employee::addHour(float h)
{
    if (h <= 24)
    {
        extraHour = h;
        return 1;
    }
    else
    {
        return 0;
    }
}

void employee::lineData()
{
    cout << left << setfill(' ') << setw(8) << number;
    cout << left << setfill(' ') << setw(20) << name;
    cout << left << setfill(' ') << setw(8) << age;
    cout << left << setfill(' ') << setw(15) << position;
    cout << left << setfill(' ') << setw(10) << hour;
    cout << left << setfill(' ') << setw(20) << extraHour;
}

void sort(employee *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j].calcSal() < arr[j + 1].calcSal())
            {
                employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool idCheck(employee *a, int len, int id)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i].get_number() == id)
        {
            return true;
        }
    }
    return false;
}

void registerEmp(employee *a, int len)
{
    bool idFlag = true;
    while (idFlag)
    {
        (a + len)->getData(); // Use pointer arithmetic without creating a new object
        if (!idCheck(a, len, (a + len)->get_number()))
        {
            idFlag = false;
        }
        else
        {
            cout << "Id davhtslaa, shine Id oruulna uu:" << endl;
        }
    }
}


void tablePrint(employee *emp, int n)
{
    int sumSal = 0;
    char l = '-';
    cout << left << setfill(' ') << setw(8) << "Dugaar";
    cout << left << setfill(' ') << setw(20) << "Ner";
    cout << left << setfill(' ') << setw(8) << "Nas";
    cout << left << setfill(' ') << setw(15) << "Ajliin bair";
    cout << left << setfill(' ') << setw(10) << "Tsag";
    cout << left << setfill(' ') << setw(20) << "Nemelt Tsag";
    cout << left << setfill(' ') << setw(12) << "Tsalin";
    cout << endl;
    for (int i = 0; i < 89; i++)
    {
        cout << l;
    }
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        emp[i].lineData();
        cout << left << setfill(' ') << setw(12) << emp[i].calcSal();
        cout << endl;
        sumSal += emp[i].calcSal();
    }
    cout << "Niit Tsalin: " << sumSal << endl
         << endl
         << endl;
    sumSal = 0;
}

int main()
{
    int n;
    cout << "Ajilchdiin toog oruulna uu: ";
    cin >> n;
    employee emp[n];
    for (int i = 0; i < n; i++)
    {
        registerEmp(&emp[0], i);
        float AddedHour;
        cout << "Nemelt Ajillasan tsag: ";
        cin >> AddedHour;
        while (emp[i].addHour(AddedHour) == 0)
        {
            cout << "24-uus heterlee dahij oruulna uu: ";
            cin >> AddedHour;
        }
        cout << endl;
    }

    cout << "Ajiltnuudiin Medeelel:\n";
    tablePrint(&emp[0], n);

    sort(&emp[0], n);

    cout << "Sortlson:\n";
    tablePrint(&emp[0], n);

    employee::showCount();

    return 0;
}
