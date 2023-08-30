#include <iostream>
#include <bitset>

class IDSystem {
private:
    static const int MAX_IDS = 429496729; // Total available IDs 4294967296
    std::bitset<MAX_IDS> availableIDs;

public:
    IDSystem() {
        availableIDs.set(); // Initialize all IDs as available
    }

    int getID() {
        for (int i = 0; i < MAX_IDS; ++i) {
            if (availableIDs[i]) {
                availableIDs.reset(i);
                return i;
            }
        }
        return -1; // No available ID
    }

    bool deleteID(int id) {
        if (id >= 0 && id < MAX_IDS && !availableIDs[id]) {
            availableIDs.set(id);
            return true; // ID successfully deleted
        }
        return false; // Invalid ID or already deleted
    }
};
IDSystem idSystem;

int main() {


    int id1 = idSystem.getID();
    if (id1 != -1) {
        std::cout << "Got ID: " << id1 << std::endl;
    }

    int id2 = idSystem.getID();
    if (id2 != -1) {
        std::cout << "Got ID: " << id2 << std::endl;
    }

    if (idSystem.deleteID(id1)) {
        std::cout << "Deleted ID: " << id1 << std::endl;
    }

    int id3 = idSystem.getID();
    if (id3 != -1) {
        std::cout << "Got ID: " << id3 << std::endl;
    } else {
        std::cout << "No available IDs." << std::endl;
    }

    return 0;
}
