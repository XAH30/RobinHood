void test_time(int a)
{
    //a - кол-во элементов
    RobinHoodHashTable<int> hashTable(a);
    // Предварительно заполняем таблицу на 0.7
    for (int i = 0; hashTable.loadFactor() <= 0.7; i++)
        hashTable.insert(i);
    int c = hashTable.getInsertCount();
    srand(a);
    // Тест скорости операции find. a * 0.1 - формальное ограничение количества операций
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i <= a * 0.1; i++)
        hashTable.find(a*10 + i); // unsuccess
        //hashTable.find(a/2 - i); // success
    auto end = chrono::high_resolution_clock::now();
    chrono::microseconds elapsedTime2 = chrono::duration_cast<chrono::microseconds>(end - start);
    int f = hashTable.getFindCount();

    // Тест скорости операции find. a * 0.1 - формальное ограничение количества операций
    start = chrono::high_resolution_clock::now();
    for (int i = 1; i <= a * 0.1; i++)
        //hashTable.find(a * 10 + i); // unsuccess
        hashTable.find(i); // success
    end = chrono::high_resolution_clock::now();
    chrono::microseconds elapsedTime4 = chrono::duration_cast<chrono::microseconds>(end - start);
    int f1 = hashTable.getFindCount();

   // Тест скорости операции insert. a - ограничение количества операций, чтобы не уйти в бесконечный цикл из-за рандомных значений
    start = chrono::high_resolution_clock::now();
    for (int i = 0; hashTable.loadFactor() <= 0.8; i++)
        hashTable.insert(rand() % a);
    end = chrono::high_resolution_clock::now();
    chrono::microseconds elapsedTime3 = chrono::duration_cast<chrono::microseconds>(end - start);
    
    // Тест скорости операции remove. a - ограничение количества операций, чтобы не уйти в бесконечный цикл из-за рандомных значений
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < a && hashTable.loadFactor() >= 0.7; i++)
        hashTable.remove(rand() % a);
    end = chrono::high_resolution_clock::now();
    chrono::microseconds elapsedTime1 = chrono::duration_cast<chrono::microseconds>(end - start);

    // Сохраняем статистику в файл
    ofstream file("statistics_time.txt");
    if (!file)
    {
        cerr << "Error opening file: " << "statistics_time.txt" << endl;
        return;
    }
    cout << "Load Factor: " << hashTable.loadFactor() << endl;
    file << "Load Factor: " << hashTable.loadFactor() << endl;
    cout << "Find unsuccess operations: " << elapsedTime2.count() << " microseconds, operation count " << f << endl;
    file << "Find unsuccess operations: " << elapsedTime2.count() << " microseconds, operation count " << f << endl;
    cout << "Find success operations: " << elapsedTime4.count() << " microseconds, operation count " << f << endl;
    file << "Find success operations: " << elapsedTime4.count() << " microseconds, operation count " << f << endl;
    file.close();
    cout << "Statistics saved to file: " << "statistics_time.txt" << endl;
}