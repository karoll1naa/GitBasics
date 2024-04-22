#include "pch.h"
#include "CppUnitTest.h"
#include "../GitBasics/Ansi.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Ansicpp
{
	TEST_CLASS(Ansicpp)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string markdownText = "**This is bold text**";
			string expectedAnsiText = "\033[1mThis is bold text\033[0m";
			Assert::IsTrue(AnsiFormat(markdownText) == expectedAnsiText);
		}

		TEST_METHOD(TestMethod2)
		{
			string markdownText = "_This is italic text_";
			string expectedAnsiText = "\033[3mThis is italic text\033[0m";
			Assert::IsTrue(AnsiFormat(markdownText) == expectedAnsiText);
		}
	};
}
