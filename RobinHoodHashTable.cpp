template <class T>
class RobinHoodHashTable
{
private:
    vector<Hash<T>> table;
    size_t size;
    int collisions;
    int find_count;
    int insert_count;
    int delete_count;
public:
    RobinHoodHashTable(size_t size) : size(size), collisions(0), find_count(0), insert_count(0), delete_count(0)
    {
        if (size == 0)
            throw runtime_error("Wrong size");
        table.vector<Hash<T> >::resize(size);
        for (auto it : table)
            it = Hash<T>();
    }

    // Метод для поиска значения в хеш-таблице
    size_t find(Hash<T> val)
    {
        size_t key = Hash<T>{}(val);
        find_count++; // Увеличиваем счетчик операций поиска
        size_t index = key % size; // �'ычисляем индекс ячейки
        size_t distance = 0; // Расстояние до искомого значения
        while (table[index] != Hash<T>() && Hash<T>{}(table[index]) != key && distance <= size)
        {
            // Продолжаем искать, пока не найдем ячейку с искомым значением или пустую ячейку
            index = (index + 1) % size; // Переходим к следующей ячейке
            distance++;
        }
        if (distance > size)
            return -1;
        return (Hash<T>{}(table[index]) == key) ? index : -1;
    }

    // Метод для вставки значения в хеш-таблицу
    void insert(Hash<T> val)
    {
        size_t key = Hash<T>{}(val);
        insert_count++; // Увеличиваем счетчик операций вставки
        size_t index = key % size; // �'ычисляем индекс ячейки
        size_t distance = 0; // Расстояние до текущей ячейки
        while (table[index] != Hash<T>() && Hash<T>{}(table[index]) != key)
        {
            if (distance > Hash<T>{}(table[index]) - index)
            {
                // Robin Hood: обменять текущее значение с новым, если новое значение имеет меньшее расстояние
                swap(table[index], val);
                distance = Hash<T>{}(table[index]) - index;
            }
            index = (index + 1) % size; // Переходим к следующей ячейке
            distance++;
            collisions++; // Увеличиваем счетчик коллизий
        }
        // Вставляем новое значение в пустую ячейку
        swap(table[index], val);
    }

    // Метод для удаления значения из хеш-таблицы
    void remove(Hash<T> val)
    {
        size_t index = find(val); // Находим индекс ячейки с искомым ключом
        delete_count += index != size_t(-1) ? 1 : 0; // Увеличиваем счетчик операций удаления
        table[index * (index != size_t(-1))] = (index != size_t(-1)) ? Hash<T>() : table[index * (index != size_t(-1))];
    }

    // Метод для вычисления коэффициента заполнения таблицы
    double loadFactor() const
    {
        size_t count = 0;
        for (auto it : table)
            count += int(it != Hash<T>());
        return static_cast<double>(count) / (size - count);
    }

    int getCollisions() const
    {
        return collisions;
    }

    int getFindCount() const
    {
        return find_count;
    }

    int getInsertCount() const
    {
        return insert_count;
    }

    int getDeleteCount() const
    {
        return delete_count;
    }

    size_t getSize() const
    {
        return size;
    }

    // Метод для сохранения статистики в файл
    void save(const string& filename) const
    {
        ofstream file(filename);
        if (!file)
        {
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        file << "Find operations: " << getFindCount() << endl;
        file << "Insert operations: " << getInsertCount() << endl;
        file << "Delete operations: " << getDeleteCount() << endl;
        file << "Collisions: " << getCollisions() << endl;
        file << "Load factor: " << loadFactor() << endl;

        file.close();
        cout << "Statistics saved to file: " << filename << endl;
    }

    void save(const string& filename, char mode = 'a') const
    {
        if (mode == 'a') {
            ofstream file(filename, ios_base::app); // Open the file in append mode
            if (!file)
            {
                cerr << "Error opening file: " << filename << endl;
                return;
            }
            //file << "Collisions: " << getCollisions() << ',' << getSize() << ',' << endl;
            file << getCollisions() << ',' << loadFactor() << endl;
            file.close();
        }
    }
};
