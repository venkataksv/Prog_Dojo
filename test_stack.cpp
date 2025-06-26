#include <gtest/gtest.h>
#include <sstream>
#include "Stack.h"

/**
 * Stream redirector class to read a console stream buffer and 
 * redirect into ostream buffer instead of redirecting it to "<<" operator
 */
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

    // Fails the test if return is False
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

    // emulating a stack overflow case 
    s.push(1000);

    // Fails the test if Assertion is not validated
    ASSERT_EQ(cerrBuffer.str(),"Error: Stack overflow\n");
}

// We don't need to declare the main function here if we are going to link this
// cpp file with GTest::gtest_main lib