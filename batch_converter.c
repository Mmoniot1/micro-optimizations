//By Monica Moniot
#include "converter.h"

using uint32 = uint32_t;

void convert_all(unsigned size, char* lines[], uint32 nums[]) {
	char** cur_str = lines;
	uint32* cur_num = nums;
	uint32* last_num = nums + size;
	while(true) {
		char* cur_char = *cur_str;
		char byte = *cur_char;
		uint32 n = (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
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
		if(cur_num == last_num) break;
		cur_str += 1;

		cur_char = *cur_str;
		byte = *cur_char;
		n = (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
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
		if(cur_num == last_num) break;
		cur_str += 1;

		cur_char = *cur_str;
		byte = *cur_char;
		n = (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
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
		if(cur_num == last_num) break;
		cur_str += 1;

		cur_char = *cur_str;
		byte = *cur_char;
		n = (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
		n = 10*n + (byte - '0');
		cur_char += 1;
		byte = *cur_char;
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
		if(cur_num == last_num) break;
		cur_str += 1;
	}
}
