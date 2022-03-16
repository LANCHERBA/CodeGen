void add(string a, string b) {
	int sum_list[10] = {0};
	if (a.size() > b.size()) {
		int lc = a.size() - b.size();
		b = "{}{}".format(r0_t(lc), b);
	}
	else if (a.size() < b.size()) {
		int lc = b.size() - a.size();
		a = "{}{}".format(r0_t(lc), a);
	}
	sum_list = sum_list * a.size();
	string str1(a.begin(), a.end());
	string str2(b.begin(), b.end());
	for (int i = 0, v = 0; i < str1.size(); i++) {
		int v_add = atoi(str2.substr(i, v - 1).c_str()) + atoi(str1.substr(i, v - 1).c_str()) + sum_list[i];
		if (v_add >= 10) {
			int m, va;
			m = v_add;
			va = m;
		}
		else {
			m = v_add;
		}
	}
	cout << setw(10) << v << endl;
}

/*
    Problems:
    1. It creates a fixed length list to score result
    2. What is r0_t that format function? This is a imitation from python code
    3. a.size() is incorrect. Correct format to get size is str.length()
    4. Line 12, 13 does not flip the string. str1() and str2() are not correct to generate new strings.
    5. v should be a number character from "str1" string. Translator misunderstood it.
        Correct one: int v_add = atoi(str2.substr(i, 1).c_str()) + atoi(str1.substr(i, 1).c_str()) + sum_list[i];
    6. Seems our Translator does not understand python function divmod(v_add, 10). Line 17 to 23 make no sense.
    7. Line 25, it makes no sense to output v. It should output int array sum_list.
*/

