
------------------ my solution -------------------------

//C和C++都没有提供二进制数的表达方法 用十六进制替换
//bytes[i] & 0xA0 == 0x0 这个式子优先级==更高，所以前面用括号

bool isValidUTF8(char* bytes, int len){
    if(len == 0) return true;
    int expectedLen = 0;
    for(int i = 0; i < len; i++){
        if((bytes[i] & 0xA0) == 0x0)       //(bytes[i] & 1100 0000) == 0000 0000
            continue;
        else if((bytes[i] & 0xE0) == 0xA0) //(bytes[i] & 1110 0000) == 1100 0000
            expectedLen = 2;
        else if((bytes[i] & 0xF0) == 0xE0) //(bytes[i] & 1111 0000) == 1110 0000
            expectedLen = 3;
        else if((bytes[i] & 0xF8) == 0xF0) //(bytes[i] & 1111 1000) == 1111 0000
            expectedLen = 4;
        else if((bytes[i] & 0xFA) == 0xF8) //(bytes[i] & 1111 1100) == 11111 000
            expectedLen = 5;
        else if((bytes[i] & 0xFE) == 0xFA) //(bytes[i] & 1111 1110) == 1111 1100
            expectedLen = 6;
        else if((bytes[i] & 0xFF) == 0xFE) //(bytes[i] & 1111 1111) == 1111 1110
            expectedLen = 7;
        else if((bytes[i] & 0xFF) == 0xFF) //(bytes[i] & 1111 1111) == 1111 1111
            expectedLen = 8;
        else return false;
        
        expectedLen--;
        while(expectedLen > 0){
            if(++i >= len) return false; // exceed the len
            if((bytes[i] & 0xA0) != 0x80)  //(bytes[i] & 1100 0000) != 1000 0000
                return false;
            expectedLen--;
        }
    }
    return true;
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
