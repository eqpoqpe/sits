#!/bin/bash

declare readonly WORKING_DIR=$(pwd)
declare readonly TEMPLATE_DIR=/tmp

cat <<EOF > $TEMPLATE_DIR/sits.c
#include "$WORKING_DIR/sits.h"
int main()
{
char *ID_0 = "a0c";
char *ID_1 = "a1d";
switch (s_cmp(ID_0, ID_1)) {
case 0:
printf("%s\n", ID_0);
break;
case 1:
printf("%s\n", ID_1);
break;
}
return 0;
}
EOF

gcc -o $TEMPLATE_DIR/sits $TEMPLATE_DIR/sits.c
/tmp/sits && rm $TEMPLATE_DIR/sits.c $TEMPLATE_DIR/sits
