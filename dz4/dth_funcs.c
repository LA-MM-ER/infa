int hex_to_dec(char input_hex[]) {
    int result = 0, decimal;

    for (int i = 0; input_hex[i] != '\0'; i++) {

        if (input_hex[i] >= '0' && input_hex[i] <= '9') { 
            decimal = input_hex[i] - '0';
        } 
        else if (input_hex[i] >= 'A' && input_hex[i] <= 'F') { 
            decimal = input_hex[i] - 'A' + 10;
        } 
        else if (input_hex[i] >= 'a' && input_hex[i] <= 'f') { 
            decimal = input_hex[i] - 'a' + 10;
        } 
        else return -1; 
        
        result = result * 16 + decimal;
    }
    
    return result;
}

int odd_bit_ctr(int input) {
    int b = 1, ctr = 0;
    while (b <= input) {
        if ((input & b) != 0)
            ctr++;
        b<<=2;
    }
    return ctr;
}