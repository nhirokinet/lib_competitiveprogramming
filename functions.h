/*
   Required for sort_two_arrays
   It uses global variables, so not appropriate for everyday use
   */
std::vector <int> keys_tmp;
std::vector <int> values_tmp;

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
Require: compare_key_value, key_tmp, values_tmp
   */
void sort_two_arrays (std::vector <int> & keys, std::vector <int> & values){
	if(keys.size() != values.size()){
		throw "Array size does not match!";
		return;
	}

	std::vector <int> order(keys.size());

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

