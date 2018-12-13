//By Monica Moniot
#include "converter.h"

using uint32 = uint32_t;

void convert_all(unsigned size, char* lines[], uint32 nums[]) {
	char** cur_str = lines;
	uint32* cur_num = nums;
	uint32* last_num = nums + size;
	while(true) {
		char* cur_char = *cur_str;
		char n100 = *cur_char;
		cur_char += 1;
		char n10 = *cur_char;
		cur_char += 1;
		char n1 = *cur_char;
		uint32 n = (n1 - '0') + 10*(n10 - '0') + 100*(n100 - '0');
		cur_char += 1;
		char byte = *cur_char;
		if(byte != 0) {
			n = 10*n + (byte - '0');
			cur_char += 1;
			byte = *cur_char;
			if(byte != 0) {
				n = 10*n + (byte - '0');
			}
		}

		*cur_num = n;
		cur_num += 1;
		if(cur_num == last_num) break;//we don't handle the case of an empty array
		cur_str += 1;
	}
}
