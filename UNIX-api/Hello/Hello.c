/*
 *  Hello.c
 *  
 *
 *  Created by wang yi on 10-3-13.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.h>
//#include <libnet.h>
int main()
{
	printf("Shell say hello!\n");
	//u_char *libnet_host_lookup(u_long in, u_short use_name);
//	u_long i;
//	u_short j;
//	libnet_host_lookup(i, j);
	int x = -8;
	x=x<<1;
	int y = 0, z = 0;
	z = ((y-z)*x)^((y-z)<<31>>31);
	printf("%d",x);
	return 0;
}
