/*
 * 练习7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程
 * 序编写一个新版本。
 */

// ./exercise_7_01 < data/book_sales

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::string;

// 定义在练习2.40
struct Sales_data
{
	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};
};

std::istream &read(std::istream &is, Sales_data &sd)
{
	double price = 0.0;
	is >> sd.bookNo >> sd.units_sold >> price;
	sd.revenue = price * sd.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &sd)
{
	double avg_price = 0.0;
	if (sd.units_sold > 0)
		avg_price = sd.revenue / sd.units_sold;
	
	os << sd.bookNo << " "
	   << sd.units_sold << " "
	   << sd.revenue << " "
	   << avg_price;

	return os;
}

int main()
{
	Sales_data total;	// 保存下一条交易记录的变量
	// 读入第一条交易记录，并确保有数据可以处理
	if (read(cin, total)) {
		Sales_data trans;	// 保存和的变量
		// 读入并处理剩余交易记录
		while (read(cin, trans)) {
			// 如果我们仍在处理相同的书
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				print(cout, total) << endl;	// 输出结果
				total = trans;		// 处理下一本书
			}
		}
		print(cout, total) << endl;	// 输出最后一条交易
	}
	else {
		cerr << "No data?!" << endl;
	}

	return 0;
}
