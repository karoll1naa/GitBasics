#include "pch.h"
#include "CppUnitTest.h"
#include "../GitBasics/Html.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestHtml
{
	TEST_CLASS(TestHtml)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			string markdown = "**This is bold text**";
			string expected_html = "<b>This is bold text</b>";
			Assert::IsTrue(MarkdowntoHTML(markdown) == expected_html);
		}
		TEST_METHOD(TestMethod2)
		{
			string markdown = "_This is italic text_";
			string expected_html = "<i>This is italic text</i>";
			Assert::IsTrue(MarkdowntoHTML(markdown) == expected_html);
		};

		TEST_METHOD(TestMethod3)
		{
			string markdown = "```This means that it will be displayed as is```";
			string expected_html = "<pre>This means that it will be displayed as is</pre>";
			Assert::IsTrue(MarkdowntoHTML(markdown) == expected_html);
		};

		TEST_METHOD(TestMethod4)
		{
			string markdown = "`test`";
			string expected_html = "<tt>test</tt>";
			Assert::IsTrue(MarkdowntoHTML(markdown) == expected_html);
		};

	};
}
