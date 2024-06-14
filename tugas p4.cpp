#include <iostream> // Mengimpor library iostream untuk input dan output
#include <algorithm> // Mengimpor library algorithm untuk fungsi min dan max

// Mendefinisikan kelas PersegiPanjang
class PersegiPanjang {
private:
    int xmin, ymin, xmax, ymax; // Variabel private untuk menyimpan koordinat persegi panjang

public:
    // Konstruktor untuk menginisialisasi koordinat persegi panjang
    PersegiPanjang(int xmin, int ymin, int xmax, int ymax) {
        this->xmin = xmin;
        this->ymin = ymin;
        this->xmax = xmax;
        this->ymax = ymax;
    }

    // Fungsi untuk mencetak informasi persegi panjang
    void print() const {
        std::cout << "PersegiPanjang(xmin=" << xmin << ", ymin=" << ymin
                  << ", xmax=" << xmax << ", ymax=" << ymax << ")\n";
    }

    // Operator overloading untuk mengecek apakah dua persegi panjang beririsan
    bool operator==(const PersegiPanjang& other) const {
        if ((xmin <= other.xmax && xmax >= other.xmin && ymin <= other.ymax && ymax >= other.ymin)) {
            std::cout << "Persegi Beririsan" << std::endl;
            return true;
        }
        std::cout << "Persegi Tidak Beririsan" << std::endl;
        return false;
    }

    // Operator overloading untuk menambahkan dua persegi panjang yang beririsan
    PersegiPanjang operator+(const PersegiPanjang& other) const {
        if (*this == other) { // Mengecek apakah dua persegi panjang beririsan
            int new_xmin = std::min(xmin, other.xmin); // Menentukan xmin yang baru
            int new_ymin = std::min(ymin, other.ymin); // Menentukan ymin yang baru
            int new_xmax = std::max(xmax, other.xmax); // Menentukan xmax yang baru
            int new_ymax = std::max(ymax, other.ymax); // Menentukan ymax yang baru
            return PersegiPanjang(new_xmin, new_ymin, new_xmax, new_ymax); // Mengembalikan persegi panjang baru hasil penjumlahan
        } else {
            throw std::invalid_argument("Persegi panjang tidak saling beririsan"); // Melempar pengecualian jika tidak beririsan
        }
    }

    // Operator overloading untuk mengurangi dua persegi panjang yang beririsan
    PersegiPanjang operator-(const PersegiPanjang& other) const {
        if (*this == other) { // Mengecek apakah dua persegi panjang beririsan
            int new_xmin = std::max(xmin, other.xmin); // Menentukan xmin yang baru
            int new_ymin = std::max(ymin, other.ymin); // Menentukan ymin yang baru
            int new_xmax = std::min(xmax, other.xmax); // Menentukan xmax yang baru
            int new_ymax = std::min(ymax, other.ymax); // Menentukan ymax yang baru
            return PersegiPanjang(new_xmin, new_ymin, new_xmax, new_ymax); // Mengembalikan persegi panjang baru hasil pengurangan
        } else {
            throw std::invalid_argument("Persegi panjang tidak saling beririsan"); // Melempar pengecualian jika tidak beririsan
        }
    }

    // Operator overloading untuk memperbesar ukuran persegi panjang dua kali lipat
    PersegiPanjang& operator++() {
        int new_length = (xmax - xmin) * 2; // Menentukan panjang baru
        int new_width = (ymax - ymin) * 2; // Menentukan lebar baru
        int center_x = (xmin + xmax) / 2; // Menentukan pusat x
        int center_y = (ymin + ymax) / 2; // Menentukan pusat y
        xmin = center_x - new_length / 2; // Menghitung xmin baru
        xmax = center_x + new_length / 2; // Menghitung xmax baru
        ymin = center_y - new_width / 2; // Menghitung ymin baru
        ymax = center_y + new_width / 2; // Menghitung ymax baru
        return *this; // Mengembalikan objek yang telah diperbesar
    }

    // Operator overloading untuk memperkecil ukuran persegi panjang menjadi setengah
    PersegiPanjang& operator--() {
        int new_length = (xmax - xmin) / 2; // Menentukan panjang baru
        int new_width = (ymax - ymin) / 2; // Menentukan lebar baru
        int center_x = (xmin + xmax) / 2; // Menentukan pusat x
        int center_y = (ymin + ymax) / 2; // Menentukan pusat y
        xmin = center_x - new_length / 2; // Menghitung xmin baru
        xmax = center_x + new_length / 2; // Menghitung xmax baru
        ymin = center_y - new_width / 2; // Menghitung ymin baru
        ymax = center_y + new_width / 2; // Menghitung ymax baru
        return *this; // Mengembalikan objek yang telah diperkecil
    }

    // Operator overloading untuk mengakses koordinat persegi panjang dengan indeks
    int operator[](int index) const {
        switch (index) {
            case 0: return xmin; // Mengembalikan xmin jika indeks 0
            case 1: return xmax; // Mengembalikan xmax jika indeks 1
            case 2: return ymin; // Mengembalikan ymin jika indeks 2
            case 3: return ymax; // Mengembalikan ymax jika indeks 3
            default: throw std::out_of_range("Index tidak valid, gunakan 0, 1, 2, atau 3"); // Melempar pengecualian jika indeks tidak valid
        }
    }
};

int main() {
    PersegiPanjang persegiPanjang1(0, 0, 2, 2); // Membuat objek PersegiPanjang dengan koordinat (0, 0, 2, 2)
    PersegiPanjang persegiPanjang2(100, 1, 4, 4); // Membuat objek PersegiPanjang dengan koordinat (1, 1, 4, 4)

    std::cout << (persegiPanjang2 == persegiPanjang1) << std::endl; // Mengecek apakah persegiPanjang1 dan persegiPanjang2 beririsan dan mencetak hasilnya

    try {
        PersegiPanjang pp3 = persegiPanjang1 + persegiPanjang2; // Mencoba menambahkan persegiPanjang1 dan persegiPanjang2
        std::cout << "PP1 + PP2: ";
        pp3.print(); // Mencetak hasil penjumlahan jika berhasil
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n"; // Mencetak pesan kesalahan jika tidak beririsan
    }

    try {
        PersegiPanjang pp4 = persegiPanjang1 - persegiPanjang2; // Mencoba mengurangi persegiPanjang1 dan persegiPanjang2
        std::cout << "PP1 - PP2: ";
        pp4.print(); // Mencetak hasil pengurangan jika berhasil
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n"; // Mencetak pesan kesalahan jika tidak beririsan
    }

    ++persegiPanjang1; // Memperbesar ukuran persegiPanjang1 dua kali lipat
    std::cout << "PP1 doubled: ";
    persegiPanjang1.print(); // Mencetak persegiPanjang1 yang sudah diperbesar

    --persegiPanjang1; // Memperkecil ukuran persegiPanjang1 menjadi setengah
    std::cout << "PP1 halved: ";
    persegiPanjang1.print(); // Mencetak persegiPanjang1 yang sudah diperkecil

    // Mengakses dan mencetak nilai xmin, xmax, ymin, dan ymax dari persegiPanjang1
    std::cout << "PP1 xmin: " << persegiPanjang1[0] << "\n";
    std::cout << "PP1 xmax: " << persegiPanjang1[1] << "\n";
    std::cout << "PP1 ymin: " << persegiPanjang1[2] << "\n";
    std::cout << "PP1 ymax: " << persegiPanjang1[3] << "\n";

    return 0; // Mengakhiri program
}
