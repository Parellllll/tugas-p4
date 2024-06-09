#include <iostream>
#include <algorithm>

class PersegiPanjang {
private:
    int xmin, ymin, xmax, ymax;

public:
    PersegiPanjang(int xmin, int ymin, int xmax, int ymax) {
        this->xmin = xmin;
        this->ymin = ymin;
        this->xmax = xmax;
        this->ymax = ymax;
    }

    void print() const {
        std::cout << "PersegiPanjang(xmin=" << xmin << ", ymin=" << ymin
                  << ", xmax=" << xmax << ", ymax=" << ymax << ")\n";
    }

    bool operator==(const PersegiPanjang& other) const {
        if ((xmin <= other.xmax && xmax >= other.xmin && ymin <= other.ymax && ymax >= other.ymin)) {
            std::cout << "Persegi Beririsan" << std::endl;
            return true;
        }
        std::cout << "Persegi Tidak Beririsan" << std::endl;
        return false;
    }

    PersegiPanjang operator+(const PersegiPanjang& other) const {
        if (*this == other) {
            int new_xmin = std::min(xmin, other.xmin);
            int new_ymin = std::min(ymin, other.ymin);
            int new_xmax = std::max(xmax, other.xmax);
            int new_ymax = std::max(ymax, other.ymax);
            return PersegiPanjang(new_xmin, new_ymin, new_xmax, new_ymax);
        } else {
            throw std::invalid_argument("Persegi panjang tidak saling beririsan");
        }
    }

    PersegiPanjang operator-(const PersegiPanjang& other) const {
        if (*this == other) {
            int new_xmin = std::max(xmin, other.xmin);
            int new_ymin = std::max(ymin, other.ymin);
            int new_xmax = std::min(xmax, other.xmax);
            int new_ymax = std::min(ymax, other.ymax);
            return PersegiPanjang(new_xmin, new_ymin, new_xmax, new_ymax);
        } else {
            throw std::invalid_argument("Persegi panjang tidak saling beririsan");
        }
    }

    PersegiPanjang& operator++() {
        int new_length = (xmax - xmin) * 2;
        int new_width = (ymax - ymin) * 2;
        int center_x = (xmin + xmax) / 2;
        int center_y = (ymin + ymax) / 2;
        xmin = center_x - new_length / 2;
        xmax = center_x + new_length / 2;
        ymin = center_y - new_width / 2;
        ymax = center_y + new_width / 2;
        return *this;
    }

    PersegiPanjang& operator--() {
        int new_length = (xmax - xmin) / 2;
        int new_width = (ymax - ymin) / 2;
        int center_x = (xmin + xmax) / 2;
        int center_y = (ymin + ymax) / 2;
        xmin = center_x - new_length / 2;
        xmax = center_x + new_length / 2;
        ymin = center_y - new_width / 2;
        ymax = center_y + new_width / 2;
        return *this;
    }

    int operator[](int index) const {
        switch (index) {
            case 0: return xmin;
            case 1: return xmax;
            case 2: return ymin;
            case 3: return ymax;
            default: throw std::out_of_range("Index tidak valid, gunakan 0, 1, 2, atau 3");
        }
    }
};

int main() {
    PersegiPanjang persegiPanjang1(0, 0, 2, 2);
    PersegiPanjang persegiPanjang2(100, 1, 4, 4);

    std::cout << (persegiPanjang2 == persegiPanjang1) << std::endl;

    try {
        PersegiPanjang pp3 = persegiPanjang1 + persegiPanjang2;
        std::cout << "PP1 + PP2: ";
        pp3.print();
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    try {
        PersegiPanjang pp4 = persegiPanjang1 - persegiPanjang2;
        std::cout << "PP1 - PP2: ";
        pp4.print();
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    ++persegiPanjang1;
    std::cout << "PP1 doubled: ";
    persegiPanjang1.print();

    --persegiPanjang1;
    std::cout << "PP1 halved: ";
    persegiPanjang1.print();

    std::cout << "PP1 xmin: " << persegiPanjang1[0] << "\n";
    std::cout << "PP1 xmax: " << persegiPanjang1[1] << "\n";
    std::cout << "PP1 ymin: " << persegiPanjang1[2] << "\n";
    std::cout << "PP1 ymax: " << persegiPanjang1[3] << "\n";

    return 0;
}