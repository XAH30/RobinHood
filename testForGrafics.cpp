void test_for_graphics(double fact, int razmer)
{
    RobinHoodHashTable<int> hashTable(razmer);
    srand(razmer);
    int a = fact*razmer;
    for (int i = 0; i < a; i++)
    {
        int n = rand() % razmer;
        hashTable.insert(n);
    }
    hashTable.save("statistics_for_graphics.csv", 'a');
}