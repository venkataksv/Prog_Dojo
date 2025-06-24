#include <gtest/gtest.h>
#include <sstream>
#include "Stack.h"

class StreamRedirector {
public:
    StreamRedirector(std::ostream& stream, std::stringstream& buffer)
        : originalStream(stream), oldBuffer(stream.rdbuf(buffer.rdbuf())) {}

    ~StreamRedirector() {
        originalStream.rdbuf(oldBuffer);
    }

private:
    std::ostream& originalStream;
    std::streambuf* oldBuffer;
};

TEST(StackTest, IsEmptyInitially)
{
    Stack<int> s;
    ASSERT_EQ(s.size(), 0);
    ASSERT_TRUE(s.isEmpty());
}

TEST(StackTest, CheckStackOverflow)
{

    Stack<int> s;
    std::stringstream cerrBuffer;

    StreamRedirector redirect(std::cerr, cerrBuffer);

    for(int i=0;i<STACK_SIZE;i++)
    {
        s.push(i);
    }

    s.push(1000);
    ASSERT_EQ(cerrBuffer.str(),"Error: Stack overflow\n");
}