#include <iostream>
#include <vector>

using namespace std;

vector<uint8_t> pack(vector<uint32_t> data) {
    vector<uint8_t> result;
    for (uint32_t value : data) {
        while (value >= 0x80) {
            result.push_back((value & 0x7F) | 0x80);
            value >>= 7;
        }
        result.push_back(value);
    }
    return result;
}

vector<uint32_t> unpack(const vector<uint8_t>& data) {
    vector<uint32_t> result;
    uint32_t value = 0;
    uint32_t shift = 0;
    for (uint8_t byte : data) {
        value |= (byte & 0x7F) << shift;
        shift += 7;
        if ((byte & 0x80) == 0) {
            result.push_back(value);
            value = 0;
            shift = 0;
        }
    }
    return result;
}

int main() {
    vector<uint32_t> original = {1, 2, 3, 128, 255, 300};
    vector<uint8_t> packed = pack(original);
    vector<uint32_t> unpacked = unpack(packed);

    cout << "Original: ";
    for (uint32_t value : original) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Packed: ";
    for (uint8_t byte : packed) {
        cout << (int)byte << " ";
    }
    cout << endl;

    cout << "Unpacked: ";
    for (uint32_t value : unpacked) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
