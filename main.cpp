#include <iostream>
#include <fstream>

int main() {
    const std::string FILE_PATH = "..\\table_data.txt";

    std::string name;
    std::string surname;
    int payment;
    std::string date;

    int maxPayment = 0;
    int sumPayment = 0;
    std::string nameMaxPayment = " ";
    std::string surnameMaxPayment = " ";

    std::ifstream inputStream(FILE_PATH, std::ios::binary);
    if (inputStream.is_open())
    {
        while (!inputStream.eof())
        {
            inputStream >> name >> surname >> payment >> date;
            if (payment > maxPayment)
            {
                maxPayment = payment;
                nameMaxPayment = name;
                surnameMaxPayment = surname;
            }
            sumPayment += payment;
        }
        inputStream.close();
        std::cout << "Max payment is: " << maxPayment << "\n";
        std::cout << "Max payment owner is: " << nameMaxPayment << " " << surnameMaxPayment << "\n";
        std::cout << "Sum of all payments is: " << sumPayment << "\n";
    }
    else
    {
        std::cerr << "File read error. Check path.\n";
    }
    return 0;
}
