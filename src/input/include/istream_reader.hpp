#ifndef CPP_LEARN_INPUT_ISTREAM_READER_HPP
#define CPP_LEARN_INPUT_ISTREAM_READER_HPP

#include <functional>
#include <iosfwd>

namespace cpp_learn {
namespace input {

std::function<int()> istream_reader(std::istream& istream);

}
}

#endif // CPP_LEARN_INPUT_ISTREAM_READER_HPP
