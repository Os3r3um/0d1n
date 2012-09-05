/*
Author:Antonio Costa aka " Cooler_ "
contact: c00f3r[at]gmail[dot]com
contribuitor: Sergio Renan aka slyfunky

    Copyright (C) 2012 0d1n authors,
    
    This file is part of 0d1n
    
    0d1n is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    0d1n is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.



What this IT ?
this is another Web POST,GET vulnerability scanner

need libcurl to run

$ sudo apt-get install libcurl-dev
$ make
$./0d1n


*/
#include <stdio.h> 
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "spider.h"


void init()
{
 puts(
 CYAN
   "       ~.             ~             \n"                      
   "         01...___|__..10.              \n" 
   "          1010   101   101             \n" 
   "           0101  :Bug  :Sec   `.oo'   \n"
   "           :101  |666  |101  ( (`-'   \n"
   " .---.    1010  ;110  ;010   `.`.     \n"
   "/ .-._)  111-\"\"\"|\"\"\"'-000      `.`.   \n"
   "( (`._) .-.  .-. |.-.  .-.  .-. ) ) \n"
   " \ `---( 1 )( 0 )( 1 )( 1 )( 0 )-' /  \n"
   " `.    `-'  `-'  `-'  `-'  `-'  .'   \n"
   "   `---------------------------'     \n"
 YELLOW
 "Odin simple scanner v 0.6\n"
 LAST
 "-h host to scan\n"
 "-p payload list to inject\n"
 "-f grep list to find on response\n"
 "-c cookie jar file to load\n"
 "-P post method params\n"
 "-o output of result\n"
 "-u custom UserAgent\n"
 YELLOW
 "example:\n./odin -h 'http://site.com/view/1!/product/!/' -p sqli.txt -f response_sqli.txt -o site \n"
 CYAN
 "Coded by Cooler_\n c00f3r[at]gmail[dot]com\n BUGSEC TEAM"
 );
 puts(LAST);
}

int main(int argc, char ** argv)
{
 char c;
 char *pack[7]; 

 if(argc < 9) 
 {
  init();
  return 0;
 }
 
 short y=6;
 while(y)
 {
  pack[y]=NULL;
  y--;
 }

 opterr = 0;

 while((c = getopt(argc, argv, "h:p:f:c:P:o:u:")) != -1)
  switch(c) 
  {
   case 'h':
    pack[0] = optarg;
    break;

   case 'p':
    pack[1]=optarg;
    break;

   case 'f':
    pack[2]=optarg;
    break;

   case 'c':
    pack[3]=optarg;
    break;

   case 'P':
    pack[4]=optarg;
    break;

   case 'o':
    pack[5]=optarg;
    break;
   
   case 'u':
    pack[6]=optarg;

   case '?':
    if(optopt == 'h' || optopt == 'p' || optopt == 'f' || optopt == 'c' || optopt == 'P' || optopt == 'o') 
    {
     init();
     puts(RED);
     fprintf(stderr, "Option -%c requires an argument.\n", optopt); 
     puts(LAST);
     return 0;
    }
  }

 srand(time(NULL));
 
 if(strlen(pack[0]))
  scan((void *)pack);


 return 0;
}