#include <stdio.h>
int m,n;
int count = 0;// So cach chia
int f = 0; //Tong so keo da chia
unsigned int x[100];//Loi giai

void KiemTraLoiGiai() {
	 int i;
	 if (f == m) {//Keo duoc chia het
	 		count++;
	 		//printf("Cach chia thu :%d\n",count);
			//for (i = 0; i < n;i++) 	printf("Be thu %d nhan so keo:%d\n", i, x[i] );
	 }
	}

void try(int k) {//Thu chia keo cho em be thu k
	int v,vmax;
	
	vmax = m;//m-f; //So keo con lai sau khi da chia f cai keo cho k -1 em be
	for (v = 1; v <= vmax;v++) {
		x[k] = v;
		f = f + v; //So keo da chia sau khi chia v keo cho em be thu k 
		if (k == n-1) KiemTraLoiGiai();
		else try(k+1);
	    f = f - v; //Tra lai so keo ban dau khi da chia keo cho k-1 em be de quay lai thu voi gia tri v khac
	}
}
void main() {
 	int i;
 	for (i = 0; i < 100;i++) x[i] = 0;
	printf("Nhap so em be va so keo:");
 	scanf("%d %d",&n,&m);
 	try (0);
 	printf("SO cach chia:%d\n",count);
 
}