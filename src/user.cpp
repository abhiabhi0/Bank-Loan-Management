#include "user.h"

void User::add_payment(int lump_sum, int emi_num)
{
	lump_sum_paid += lump_sum;

	//since lump sum will be calculated after current emi
	//so emi_num+1
	lump_payments.push_back({emi_num+1, lump_sum_paid});
}