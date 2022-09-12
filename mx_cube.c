void mx_printchar(char c);
void printTopFace1(int n);
void printTopFace2(int n, int *count);
void printBackFace1(int n, int *count);
void printBackFace2(int n, int *count);
void printBottomFace(int n, int *count);

void mx_cube(int n) {
    if (n > 1) {
        int count = 1;
        
        printTopFace1(n);
        printTopFace2(n, &count);
        printBackFace1(n, &count);
        printBackFace2(n, &count);
        printBottomFace(n, &count);
    }
}

void printTopFace1(int n) {
    for (int i = 0; i <= n/2; i++) {
        mx_printchar(' ');
    }
    mx_printchar('+');
    for (int i = 0; i < n*2; i++) {
        mx_printchar('-');
    }
    mx_printchar('+'); 
    mx_printchar('\n');
    
}

void printTopFace2(int n, int *count) {
    for (int j = 0; j < n/2; j++) {
        for (int i = 0; i <= n/2-*count; i++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int i = 0; i < n*2; i++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int i = 0; i < *count-1; i++) {
            mx_printchar(' ');
        }
        mx_printchar('|'); mx_printchar('\n');
        *count += 1;
    }
    mx_printchar('+');
    for (int i = 0; i < n*2; i++) {
        mx_printchar('-');
    }
}

void printBackFace1(int n, int *count) {
    mx_printchar('+');
    for (int i = 0; i < *count-1; i++) {
        mx_printchar(' ');
    }
    mx_printchar('|'); 
    mx_printchar('\n');
    for (int j = 0; j < n-(n/2+1); j++) {
        mx_printchar('|');
        for (int i = 0; i < n*2; i++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        for (int i = 0; i < *count-1; i++) {
            mx_printchar(' ');
        }
        mx_printchar('|'); 
        mx_printchar('\n');
    }
}

void printBackFace2(int n, int *count) {
    mx_printchar('|');
    for (int i = 0; i < n*2; i++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    for (int i = 0; i < *count-1; i++) {
        mx_printchar(' ');
    }
    mx_printchar('+'); 
    mx_printchar('\n'); 
    *count -= 1;
}

void printBottomFace(int n, int *count) {
    for (int j = 0; j < n/2; j++) {
        mx_printchar('|');
        for (int i = 0; i < n*2; i++){
            mx_printchar(' ');
        }
        mx_printchar('|');
        for (int i = 0; i < *count-1; i++){
            mx_printchar(' ');
        }
        mx_printchar('/'); 
        mx_printchar('\n');
        *count -= 1;
    }
    mx_printchar('+');
    for (int i = 0; i < n*2; i++){
        mx_printchar('-');
    }
    mx_printchar('+'); 
    mx_printchar('\n');
}
