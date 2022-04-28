#include "priorityqueue.hh"

int main()
{
    try
    {
        queue<data1> queue1;
        queue<data2> queue2;
        data1 object;
        data2 object2;
        std::string text, word;
        int i = 0;

        std::cout << "Podaj zdanie, które ma zostać wysłane: " << std::endl;
        std::getline(std::cin, text);
        std::istringstream iss(text);

        text.clear();
        while (iss >> word)
        {
            i++;
            queue2.add(i, word);
        }
        std::cout << "Kolejność słów odbierana przez odbiorcę:" << std::endl;
        do
        {
            object2 = queue2.removeSmallest();
            queue1.add(object2.priority, object2.info);
            std::cout << object2.info;
            if (!queue2.checkIfEmpty())
            {
                std::cout << " ";
            }

        } while (!queue2.checkIfEmpty());
        std::cout << std::endl
                  << "Zdanie otrzymane po zakończeniu działania programu:"
                  << std::endl;
        do
        {
            object = queue1.removeSmallest();
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