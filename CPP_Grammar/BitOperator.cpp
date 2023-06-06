#include "pch.h"

/*
	BitFlagTest
*/
#define _TEST_1 0x01 // 00000000 00000000 00000000 00000001
#define _TEST_2 0x02 // 00000000 00000000 00000000 00000010
#define _TEST_3 0x04 // 00000000 00000000 00000000 00000100

int BitFlagTest(const int&& _NewFlag)
{
	return _NewFlag;
}

int main(void)
{
	/*
		Print Binary
	*/
	int var0 = 1;
	int var1 = ~var0;
	int temp{ 0 };

	std::cout << "var0 Binary : " << std::bitset<32>(var0) << std::endl;
	std::cout << "var1 Binary : " << std::bitset<32>(var1) << std::endl;
	std::cout << "var0 Decimal : " << var0 << std::endl;
	std::cout << "var1 Decimal : " << var1 << std::endl;
	std::cout << std::endl;


	/*
		'Shift Operator Test'

		1.
		-1의 Binary는 1111 1111 / 1111 1111 / 1111 1111 / 1111 1111
		<< 연산을 하면 뒤에서 0으로 채워주지만,
		>> 연산시 앞에서 0으로 채우지 않는다.

		2.
		1의 Binary는 0000 0000 / 0000 0000 / 0000 0000 / 0000 0001
		<< 연산을 최대치인 31로 했을 경우 부호 비트까지 움직여 음수의 최대치가 나온다.

	*/
	temp = 1 << 30;
	std::cout << "temp Binary : " << std::bitset<32>(temp) << std::endl;
	std::cout << "temp Decimal : " << temp << std::endl << std::endl;


	std::cout << "BitFlagTest : " << std::bitset<4>(BitFlagTest(_TEST_1 | _TEST_2 | _TEST_3)) << std::endl;

	return 0;
}