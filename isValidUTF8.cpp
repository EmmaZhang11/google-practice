
------------------ my solution -------------------------
bool isValidUTF8(char* str, int len){
	if(len == 0) return true;
	char first = str[0];
	int one = 0;
	int bit = 8;
	
	while(bit > 0){
		int mask = (1 << bit - 1) - (1 << (bit - 1) - 1);
		if(first & mask) one++;
		else break;
		bit--;
	}
	if(one == 0)
	{
		int mask = (1 << 7 - 1) - (1 << (7 - 1) - 1);
		if(first & mask) return false;
		else return isValidUTF8(str + 1,len - 1);
	}
	int i = 1;
	while( i < one)
		if(i >= len) return false;
		char c = str[i];
		int mask1 = (1 << 8 - 1) - (1 << (8 - 1) - 1); 
		int mask2 = (1 << 7 - 1) - (1 << (7 - 1) - 1); 
		if( !(mask1 & c) || (mask2 & c) )return false;
		i++;
	}

	return isValidUTF8(str + one, len - one);
}

------------- yao solution -------------------
bool isValidUTF8(char* str, int len) {
	for(int i = 0; i < len;) {
		int l = getLen(str[i]);
		i++;
		if(l == 0)
			return false;
		while(--l) {
			if(i >= len)
				return false;
			if(!check(str[i]))
				return false;
			i++;
		}
	}
	return true;
}
int getLen(char c) {
	if(c & 11000000 == 0)
		return 1;
	if(c & 11100000 == 11000000)
		return 2;
	if(c & 11110000 == 11100000)
		return 3;
	if(c & 11111000 == 11110000)
		return 4;
	if(c & 11111100 == 11111000)
		return 5;
	if(c & 11111110 == 11111100)
		return 6;
	if(c & 11111111 == 11111110)
		return 7;
	if(c & 11111111 == 11111111)
		return 8;
	return 0;
}

bool check(char c) {
	return c & 11000000 = 10000000;
}
