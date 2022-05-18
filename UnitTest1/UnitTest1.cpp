#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.6/Lab_12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			enqueue(first, last, 5,"test");
			Assert::AreEqual(dequeue(first, last), 5);
		}
	};
}
