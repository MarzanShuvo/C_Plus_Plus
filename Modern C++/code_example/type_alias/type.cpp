# include <array>
# include <memory>

template <class T, int SIZE >
struct Image {
    // Can be used in classes .
    using Ptr = std::unique_ptr <Image <T, SIZE >>;
    std::array <T, SIZE > data;
};

// Can be combined with " template ".
template <int SIZE >
using Imagef = Image <float , SIZE >;

int main () {
    // Can be used in a function for type aliasing .
    using Image3f = Imagef <3>;
    auto image_ptr = Image3f::Ptr(new Image3f );
    return 0;
}