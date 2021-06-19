#include <iostream>
#include <fstream>
#include <vector>

/*
 * Get the sum of all <int> vector members.
 */
int getSum(std::vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

/*
 * Get the index of maximal <int> vector member.
 */
int getIndexOfMax(std::vector<int>& v)
{
    int max_i = 0;
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max_i = i;
            max = v[i];
        }

    }
    return max_i;
}

int main() {
    char *dir = "..\\table_data.txt";
    std::vector<std::string> names;
    std::vector<std::string> surnames;
    std::vector<int> payments;
    std::vector<std::string> dates;

    std::ifstream stream(dir, std::ios::binary);
    if (stream.is_open()) {
        while (!stream.eof()) {
            std::string name;
            std::string surname;
            int payment;
            std::string date;

            stream >> name >> surname >> payment >> date;

            names.push_back(name);
            surnames.push_back(surname);
            payments.push_back(payment);
            dates.push_back(date);
        }
    } else
    {
        std::cout << "Bad file or path.\n";
    }
    stream.close();
    printf("Sum of all payments: %u $\n", getSum(payments));

    int maxValueIndex = getIndexOfMax(payments);
    std::cout << "Maximal payment was paid to: " << names[maxValueIndex] << " ";
    std::cout << surnames[maxValueIndex] << " - ";
    std::cout << payments[maxValueIndex] << " $\n";

    return 0;
}
