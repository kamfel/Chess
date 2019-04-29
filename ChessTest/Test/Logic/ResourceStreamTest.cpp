#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic/ResourceStream.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(ResourceStreamTest)
	{
	public:

		TEST_METHOD(LoadResourceById_InvalidArgsShouldBeFalse)
		{
			unsigned id = 0;
			const char* type = "TYPE";

			ResourceStream rs;

			Assert::IsFalse(rs.LoadResourceById(id, type));
		}

		TEST_METHOD(LoadResourceById_InvalidArgsShouldBeFalse)
		{
			unsigned id = 0;
			const char* type = "TYPE";

			ResourceStream rs;

			Assert::IsFalse(rs.LoadResourceById(id, type));
		}
	};
}