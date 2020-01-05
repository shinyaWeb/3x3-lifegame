#include<stdio.h>
#include<unistd.h>

int main(void) {
  int i,j,k,n,m,s,a[5][5],b[5][5];
  k = 1;
  
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++) {
      if((i%4 == 0) || (j%4 == 0)) { 
	a[i][j] = 0;
	b[i][j] = 0;
      }
    }
    if(i%4 != 0) {
      printf("input a numbers of %d row\n",i);
      scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
    }
  }
  
  while(k <= 5) {
    i = 1;
    if(k%2 != 0){
      while(i < 4) {
	printf(" %d %d %d\n",a[i][1],a[i][2],a[i][3]);
	i++;
      }
      sleep(3);
      printf("\n");

      for(i=1; i<4; i++) {
	for(j=1; j<4; j++) {
	  s = 0;
	  for(n=i-1; n<=i+1; n++) {
	    for(m=j-1; m<=j+1; m++) {
	      s+=a[n][m];
	    }
	  }
	  s-=a[i][j];
	  if(a[i][j] == 1) {
	    if((s != 2) && (s != 3)) { 
	      b[i][j] = 0;
	    }
	    else {
	      b[i][j] = 1;
	    }
	  }
	  else {
	    if(s == 3) { 
	      b[i][j] = 1;
	    }
	    else {
	      b[i][j] = 0;
	    }
	  }
	}
      }
      k++;
    }
    else {
     while(i < 4) {
	printf(" %d %d %d\n",b[i][1],b[i][2],b[i][3]);
	i++;
      }
      sleep(3);
      printf("\n");

      for(i=1; i<4; i++) {
	for(j=1; j<4; j++) {
	  s = 0;
	  for(n=i-1; n<=i+1; n++) {
	    for(m=j-1; m<=j+1; m++) {
	      s+=b[n][m];
	    }
	  }
	  s-=b[i][j];
	  if(b[i][j] == 1) {
	    if((s != 2) && (s != 3)) { 
	      a[i][j] = 0;
	    }
	    else {
	      a[i][j] = 1;
	    }
	  }
	  else {
	    if(s == 3) {
	      a[i][j] = 1;
	    }
	    else {
	      a[i][j] = 0;
	    }
	  }
	}
      }
      k++;
    }
  }
  return(0);
}
