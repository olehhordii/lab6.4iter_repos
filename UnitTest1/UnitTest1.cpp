#include "pch.h"
#include "CppUnitTest.h"
#include "../llab6.4_iter/llab6.4_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int a[n] = { 2,-2,3,-5,2 };
			int c = 12;
			int k;
			k = Dob(a, n);
			Assert::AreEqual(k, c);
		
		}
	};
}
