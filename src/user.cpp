#include "user.h"

void User::add_payment(double lump_sum, int emi_num)
{
	lump_sum_paid += lump_sum;

	//since lump sum will be calculated after current emi
	//so emi_num+1
	emi_num += 1;
	lump_emis.push_back(emi_num);
	emi_lump_map.insert({emi_num, lump_sum_paid});
}

double User::get_total_amount()
{
	return total_amt;
}


double User::get_emi_amount()
{
	return emi_amt;
}

void User::set_emi_amount(double amt)
{
	emi_amt = amt;
}

double User::get_total_emis()
{
	return total_emis;
}

double User::lump_amt_paid(int emi_num)
{
	//returns the lump amount till emi_num

	//if lump_payments is empty
	if (lump_emis.empty()) return 0;

	//if emi_num is less than first emi for which lump amount was paid
	//then lump amount paid for this emi is 0 
	if (emi_num < lump_emis[0]) return 0;

	//if emi_num is greater than last emi for which lump amount was paid
	//then lump amount paid for this emi is total lump sum paid.

	if (emi_num > lump_emis[lump_emis.size()-1]) return lump_sum_paid;


	int l = lump_emis[0];
	int r = lump_emis[lump_emis.size()-1];
	int nearest_lump_emi = l; //emi number which is equal to emi_num or least smallest than emi_num

	while (l < r)
	{
		int mid = (l+r)/2;

		if (mid == emi_num)
		{
			nearest_lump_emi = mid;
			break;
		}
		else if (mid > emi_num)
		{
			r = mid-1;
		}
		else  
		{
			nearest_lump_emi = mid;
			l = mid+1;
		}
	}
	return emi_lump_map[nearest_lump_emi];
}