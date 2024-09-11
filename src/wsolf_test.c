#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "wsolf.h"


int main(void){
    int res = read_wsolf("data/wsolf.txt");
    printf("%d\n",res);
}
