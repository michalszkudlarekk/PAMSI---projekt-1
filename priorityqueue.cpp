#include "priorityqueue.hh"
using namespace std;
int main()
{
    try
    {
        queue<data1> queue1; /* Właściwa kolejka */
        queue<data2> mix;    /* "Sztuczna" kolejka stworzona w celu mieszania wiadomości */
        data1 object;        /* Dane obiektu znajdującego się w kolejce */
        data2 object2;
        std::string text, word;
        int i = 0;

        std::cout << "Podaj zdanie, które ma zostać wysłane: " << std::endl;
        std::getline(std::cin, text);
        std::istringstream iss(text);
        text.clear();

        while (iss >> word) /* Pętla działająca do momentu kiedy w zdaniu są słowa (dodaje je do kolejki mieszania ) */
        {
            i++;
            mix.push(i, word);
        }
        std::cout << "Kolejność słów odbierana przez odbiorcę:" << std::endl;
        do /* Pętla do-while wyświętaljąca słowa zgodnie z losowym priorytetem, następnie dodaje je do rzeczywistej kolejki z prawidłowym priorytetem*/
        {
            object2 = mix.pull();
            queue1.push(object2.priority, object2.info); /* Dodawanie poszczególnych obiektów do kolejki ( zasymulowanie ich otrzymywania) */
            std::cout << object2.info;
            if (!mix.checkIfEmpty())
            {
                std::cout << " ";
            }

        } while (!mix.checkIfEmpty());
        std::cout << std::endl
                  << "Zdanie otrzymane po zakończeniu działania programu:"
                  << std::endl;
        do /* Pętla do-while odpowiedzialna za posortowanie i wypisanie otrzymanej odpowiedzi po zakończeniu programu */
        {
            object = queue1.pull();
            std::cout << object.info;
            if (!queue1.checkIfEmpty())
                std::cout << " ";
        } while (!queue1.checkIfEmpty());

        std::cout << std::endl;
    }
    catch (std::logic_error &e)
    {
        std::cout << "Wystapil blad:\n"
                  << e.what() << "\n";
    }
}