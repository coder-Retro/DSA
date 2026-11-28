#include<iostream>
#include"hashmap.h"
using namespace std;

int main() {
    cout << boolalpha;
    HashMap<string> hp(10);

    cout << "--- Fresh map ---\n";
    cout << "empty: " << (bool)hp.empty() << ", size: " << hp.size() << ", buckets: " << hp.buckets() << "\n";
    hp.printMap();

    cout << "\n--- insert (3015 and 3005 collide in bucket 5) ---\n";
    cout << "insert 3015: " << hp.insert(3015, "Kaido") << "\n";
    cout << "insert 3005: " << hp.insert(3005, "Luffy") << "\n";
    cout << "insert 1001: " << hp.insert(1001, "Shanks") << "\n";
    cout << "insert 3015 again (duplicate): " << hp.insert(3015, "Zoro") << "\n";
    cout << "size: " << hp.size() << "\n";
    hp.printMap();

    cout << "\n--- contains ---\n";
    cout << "contains 3015: " << hp.contains(3015) << "\n";
    cout << "contains 3005: " << hp.contains(3005) << "\n";
    cout << "contains 9999: " << hp.contains(9999) << "\n";

    cout << "\n--- erase ---\n";
    cout << "erase 3015: " << hp.erase(3015) << "\n";
    cout << "erase 3015 again: " << hp.erase(3015) << "\n";
    cout << "erase 9999 (missing): " << hp.erase(9999) << "\n";
    cout << "size: " << hp.size() << "\n";
    hp.printMap();

    cout << "\n--- operator[] ---\n";
    hp[3005] = "Sanji";            // update existing
    hp[3019] = "Brook";            // create new
    cout << "hp[3005] = " << hp[3005] << "\n";
    cout << "hp[3019] = " << hp[3019] << "\n";
    hp[3019] += " Chopper";           // modify through reference
    cout << "hp[3019] after += : " << hp[3019] << "\n";
    string blank = hp[4444];       // accessing a missing key creates an empty entry
    cout << "hp[4444] = \"" << blank << "\" (created), contains: " << hp.contains(4444) << "\n";
    cout << "size: " << hp.size() << "\n";
    hp.printMap();

    cout << "\n--- clear ---\n";
    hp.clear();
    cout << "empty: " << (bool)hp.empty() << ", size: " << hp.size() << "\n";
    hp.printMap();

    cout << "\n--- reuse after clear ---\n";
    hp.insert(7, "Robin");
    hp.printMap();

    // rehash() is private, so it is never called directly. insert() and operator[]
    // call it automatically when adding one more key would push size past 75% of buckets.
    cout << "\n--- rehash (automatic growth) ---\n";
    HashMap<string> crew(4);
    string names[] = {"Luffy", "Kaido", "Shanks", "Zoro", "Sanji", "Brook", "Chopper", "Robin"};
    cout << "start: size: " << crew.size() << ", buckets: " << crew.buckets() << "\n";
    for(int i = 0; i < 8; i++) {
        size_t before = crew.buckets();
        crew.insert(i + 1, names[i]);
        cout << "insert " << i + 1 << " (" << names[i] << "): size: " << crew.size() << ", buckets: " << crew.buckets();
        if(crew.buckets() != before) cout << "   <-- rehash: " << before << " -> " << crew.buckets();
        cout << "\n";
    }
    crew.printMap();

    cout << "\nall keys still found after rehash: ";
    bool ok = true;
    for(int i = 1; i <= 8; i++) if(!crew.contains(i)) ok = false;
    cout << ok << ", crew[5] = " << crew[5] << ", size: " << crew.size() << "\n";

    cout << "\n--- rehash through operator[] ---\n";
    HashMap<string> bounty(2);
    cout << "start: buckets: " << bounty.buckets() << "\n";
    for(int i = 1; i <= 6; i++) {
        size_t before = bounty.buckets();
        bounty[i * 100] = "bounty " + to_string(i);
        cout << "bounty[" << i * 100 << "]: size: " << bounty.size() << ", buckets: " << bounty.buckets();
        if(bounty.buckets() != before) cout << "   <-- rehash: " << before << " -> " << bounty.buckets();
        cout << "\n";
    }

    return 0;
}