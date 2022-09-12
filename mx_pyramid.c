void mx_printchar(char c);
void printFrontFace(int n, int *countOut, int *countIn);
void printBackFace(int *count, int IncreaseOrDecrease);
void printLine(int *count);

void mx_pyramid(int n) {
    if (n > 1 && n % 2 == 0) {
        int countOutLeft = 1;
        int countOutRight = 1;
        int countIn = 0;
        
        printFrontFace(n, &countOutLeft, &countIn);
        mx_printchar('\n');
        for (int i = 0; i < n/2-1; i++) {
            printFrontFace(n, &countOutLeft, &countIn);
            printBackFace(&countOutRight, 1);
        }
        for (int i = 0; i < n/2-1; i++) {
            printFrontFace(n, &countOutLeft, &countIn);
            printBackFace(&countOutRight, 2);
        }
        printLine(&countIn);
    }
}

void printFrontFace(int n, int *countOut, int *countIn) {
    for (int i = 0; i < n-*countOut; i++) {
        mx_printchar(' ');
    }
        mx_printchar('/');
        for (int i = 0; i < *countIn; i++) {
        mx_printchar(' ');
    }
        mx_printchar('\\');
        *countOut += 1;
        *countIn += 2;
}

void printBackFace(int *count, int IncreaseOrDecrease) {
    if (IncreaseOrDecrease == 1) {
        for (int i = 0; i < *count; i++) {
            mx_printchar(' ');
        }
        mx_printchar('\\'); 
        mx_printchar('\n');
        *count += 1;
    }
    else if (IncreaseOrDecrease == 2) {
        for (int i = 0; i < *count-1; i++) {
            mx_printchar(' ');
        }
        mx_printchar('|'); 
        mx_printchar('\n');
        *count -= 1;
    }
}

void printLine(int *count) {
    mx_printchar('/');
    for (int i = 0; i < *count; i++) {
        mx_printchar('_');
    }
    mx_printchar('\\'); 
    mx_printchar('|'); 
    mx_printchar('\n');
}
