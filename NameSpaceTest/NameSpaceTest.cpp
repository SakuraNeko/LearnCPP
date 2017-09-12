#include <iostream>
namespace A1 {
	int a = 10;
}
namespace A2 {
	int a = 20;
}
	using namespace A1;
	using namespace A2;
	cout<<A1::a;
