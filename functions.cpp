#include <iostream>
#include <vector>

#include "UnionFind.cpp"
#include "LargeInt.cpp"

using namespace std;


/*
   Required for sort_two_arrays
   It uses global variables, so not appropriate for everyday use
   */
vector <int> keys_tmp;
vector <int> values_tmp;
bool compare_key_value(const int& left, const int& right){
	if(values_tmp[left] < values_tmp[right])
		return true;
	if(values_tmp[left] > values_tmp[right])
		return false;
	if(keys_tmp[left] < values_tmp[right])
		return true;
	return false;
	
}

/*
Require: above block
   */
void sort_two_arrays (vector <int> & keys, vector <int> & values){
	if(keys.size() != values.size()){
		throw "Array size does not match!";
		return;
	}

	vector <int> order(keys.size());

	for(int i=0; i<keys.size(); i++)
		order[i] = i;

	keys_tmp = keys;
	values_tmp = values;

	sort(order.begin(), order.end(), compare_key_value);
	
	for(int i=0; i<keys.size(); i++){
		keys[i] = keys_tmp[order[i]];
		values[i] = values_tmp[order[i]];
	}
	
	keys_tmp.clear();
	values_tmp.clear();

}

int julianday (int year, int month, int day){
	if(month<3){
		year--;
		month+=12;
	}

	return year*365 + year/4 - year/100 + year/400 + (int)((double)(month-2) * 30.59) + day - 678912;
}


/*
   Below are for testing this code
   */
#define MOD 1000000007

int main(){
	cout << "MOD = " << MOD << endl;
	cout << "mod_inverse (2, MOD) = " << LargeInt::mod_inverse(2, MOD) << endl;
	cout << "mod_inverse (3, MOD) = " << LargeInt::mod_inverse(3, MOD) << endl;
	cout << "mod_pow (2, 13, MOD) = " << LargeInt::mod_pow(2, 13, MOD) << endl;
	cout << "mod_pow (2, 128, MOD) = " << LargeInt::mod_pow(2, 128, MOD) << endl;
	cout << "mod_nck (5, 2, MOD) = " << LargeInt::mod_nck(5, 2, MOD) << endl;
	cout << "mod_nck (6, 3, MOD) = " << LargeInt::mod_nck(6, 3, MOD) << endl;
	cout << "mod_nck (100, 50, MOD) = " << LargeInt::mod_nck(100, 50, MOD) << endl;

	vector <int> keys, values;

	keys.push_back(1);
	keys.push_back(2);
	keys.push_back(3);
	keys.push_back(4);

	values.push_back(4);
	values.push_back(4);
	values.push_back(1);
	values.push_back(2);

	sort_two_arrays(keys, values);

	for(int i=0; i<keys.size(); i++)
		cout << "sort:\t" << keys[i] << "\t" << values[i] << endl;

	for(int m=1; m<=12; m++)
		cout << "Julian day of 2012/" << m << "/1: " << julianday(2012, m, 1) << endl; 

	UnionFind uf(100);

	uf.combine(1,2);
	uf.combine(2,3);
	uf.combine(0,4);

	cout << uf.sameGroup(1,4) << endl;
	cout << uf.sameGroup(1,3) << endl;
	cout << uf.combine(0,5) << endl;
	cout << uf.combine(0,5) << endl;
	cout << uf.size() << endl;
}

