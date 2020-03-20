#ifndef CPP_LEARN_INPUT_READER_HPP
#define CPP_LEARN_INPUT_READER_HPP

#include <functional>
#include <iosfwd>

namespace cpp_learn {
namespace input_reader {

std::function<int()> istream_reader(std::istream& istream);

}
}

#endif // CPP_LEARN_INPUT_READER_HPP
