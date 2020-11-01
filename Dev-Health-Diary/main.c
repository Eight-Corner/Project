#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <process.h>

#define  _FILE_   "HealthDiary.dat" // � ��� �����  ���� 

struct data {
   char cName[8]; //��� 
   char cTel[16]; // � 
   char cAddr[32];
};

struct day {
	char cDay[6];    // ��¥
	char cTime[4]; // �ð� 
};

//�Լ� ���� 
void HealthAdd(unsigned, struct data *);//� �߰�
void HealthDel(unsigned, struct data *);//� ���� 
void Show(unsigned, struct data *);//� ��ȸ 
void MemoShow(unsigned, struct data *);//��� ��ȸ 
void Memo(unsigned, struct data *);//��� ���� 

int Cnt_data(unsigned); //���ڵ� �ο����� �����ִ� �Լ�  
 
int main(int argc, char *argv[]) {
    char cBtn;
   int Lec;
   unsigned rsize = sizeof(struct data);//56 byte
   
   struct data *Heal1;   
   struct data *Heal2;
   struct day *day1;
    
    
   while(1){
          
      Lec=Cnt_data(rsize); // � ��� ���� ���ڵ�  
      Lec=Day_data(rsize);  // � ��� ���� ���ڵ�  
  
       Heal1 = (struct data *)malloc(1*sizeof(struct data)); 
      
       Heal2 = (struct data *)malloc(Lec*sizeof(struct data));//���Ͼȿ� �������� ���ڵ带 ���� �޸� Ȯ��
	   //   
      system("cls");
      
      printf("����ü ũ�� : %d\n", rsize);
      printf("������ ���� : %d\n\n", Lec);
      
      if(Lec != 0 ){  
      	printf("--------------------\n");
         printf("|| 1. � �߰� ||\n");
         printf("|| 2. � ���� ||\n");
         printf("|| 3. � ��ȸ ||\n");
         printf("|| 4. ��� ��ȸ ||\n");
         printf("|| 5. ��� ���� ||\n");
         printf("|| 0. ��     �� ||\n");
         printf("\n  ��ȣ     ����  : ");
         scanf("%c", &cBtn);
      } else {  //���� ó���� ���Ͽ� �ƹ��͵� ���� ���� 
         cBtn='1'; 
      }
       if(cBtn == '1'){
          system("cls");
          HealthAdd(rsize, Heal1);
      }else if(cBtn == '2'){
         if(Lec == 0 ){
            printf("�˻��� �����Ͱ� �����ϴ� \n");
            system("pause");
         }else{
            system("cls");
            HealthDel(rsize,Heal2);
         }
      }else if(cBtn=='3'){
         if(Lec == 0) {
            printf("������ �����Ͱ� �����ϴ� \n");
            system("pause");
         }else{
            system("cls");
            Show(rsize, Heal2);
         }
      }else if(cBtn=='4'){
         if(Lec == 0){
            printf("������ �����Ͱ� �����ϴ� \n");
            system("pause");
         }else{
            system("cls");
            MemoShow(rsize, Heal2);
         }
      }else if(cBtn == '5'){
         if(Lec == 0 ){
            printf("��ȸ�� �����Ͱ� �����ϴ� \n");
            system("pause");
         }else{
            system("cls");
            Memo(rsize, Heal2);
         }
         
      }else if(cBtn == '0'){
         break;
      } 
   }
   
      
   return 0;

}

//���ڵ� ���� ���� �ִ� �Լ�  
int Cnt_data(unsigned  rsize){ //56
   int Cnt;
   FILE *fload;//fload��� ������ FILE�� ������ �����̴�. 
   
   fload = fopen(_FILE_, "r");
   if(fload == NULL) {
      Cnt = 0;
   }else{
      fseek(fload, -1, SEEK_END);//fseek(����������, �̵��� ũ��, ������); �����ϸ� 0 �����ϸ� -1�� ��ȯ�� 
    // 
      
      Cnt = (ftell(fload)/rsize)+1;//ftell(����������) ������������ ���� ��ġ�� ��ȯ�Ѵ�. �����ϸ� -1�� ��ȯ�Ѵ�.   
      fclose(fload);
   }
   return Cnt;
}
// � ���� �Լ�  
void HealthAdd(unsigned rsize, struct data *Heal1){
    FILE  *fsave;
    
    fflush(stdin);
    printf("\n  ��� [8�� �̳�] :  ");
    gets(Heal1->cName);
    printf("\n n��Ʈ �Է� [2��] :  ");
    gets(Heal1->cTel);
    printf("\n n ��(sec)�Է� [2��] :  ");
    gets(Heal1->cAddr);
    
    if(strlen(Heal1->cName) < 1 || strlen(Heal1->cTel) < 1 || strlen(Heal1 -> cAddr) < 1){
       printf("������� �ʾҽ��ϴ�. �ٽ� �õ��ϼ���.  \n");
   }else{
     fsave = fopen(_FILE_, "a+");//append �߰�    
     fwrite(Heal1, rsize, 1, fsave);
     fclose(fsave);  
   }
   system("pause");
  }
  
  // � ���� �Լ�   
void HealthDel(unsigned rsize, struct data *Heal2){
      int i, j=0;
   int nNum;
   char cYN;
   int Cnt = Cnt_data(rsize);
   FILE *fsave;//�����  
   FILE *fload;//�б�� 
   
   printf("�� %d���� � �����Ͱ� �ֽ��ϴ� \n", Cnt);
   
   if(Cnt == 1) {
      printf("1���� �����͸� �����մϴ�. \n");
      fflush(stdin);
      printf("��� �����Ͻðڽ��ϱ�?(Y/N)");
      cYN = getchar(); //scanf("%c", &cYN);
      if(cYN == 'Y' || cYN == 'y'){
         _unlink(_FILE_);
    }else{
     printf("��ҵǾ����ϴ�. ") ;    
    }
   } else {
       while(1) {
            printf("���° �����͸� �����Ͻðڽ��ϱ�? ");
            fload = fopen(_FILE_, "r+"); 
  			 fread(Heal2, rsize, Cnt, fload);
   			for(i=0;i<Cnt;i++){ //i=0, 1
     		  //2-1 == 0 2-1 == 1
            printf("\n %d��° ������ \n", i+1);
            printf("�� �� �� : %s\n", (Heal2+i)->cName);
            printf("�� Ʈ �� : %s \n", (Heal2+i)->cTel);
            printf("��    �� : %s \n", (Heal2+i)->cAddr);
 			  }
            scanf("%d", &nNum);
            if(nNum <= Cnt) break;   // 2 <= 3           
     } 
      fload = fopen(_FILE_, "r+");
      fread(Heal2, rsize, Cnt, fload);
      for(i=0;i<Cnt;i++){
         if( i != nNum-1) { // 0 != 1
               if(j==0) fsave = fopen(_FILE_,"w+");
               else fsave = fopen(_FILE_, "a+");
               fwrite(Heal2 + i, rsize, 1, fsave);
               fclose(fsave);
               j++;
         }
      }
         printf("�����Ͻ� ��� �����Ǿ����ϴ�.\n");
         fclose(fload);
         } 
         system("pause");
}
    
 //� ��ȸ �Լ� 
void Show(unsigned rsize, struct data *Heal2){
   
   	int nNum,i;
   FILE *fload;
   int Cnt = Cnt_data(rsize);//������(���ڵ�) ���� ���ִ� �Լ� ȣ��  
   printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n ", Cnt);//ex) 3
   printf("�� ��° �����͸� ��ȸ�Ͻðڽ��ϱ�? ");//ex) 5�� ��ȸ  
   scanf("%d", &nNum);//2
   
   fload = fopen(_FILE_, "r+"); 
   fread(Heal2, rsize, Cnt, fload);
   for(i=0;i<Cnt;i++){ //i=0, 1
       if(nNum-1 == i){ //2-1 == 0 2-1 == 1
            printf("\n %d��° ������ \n", i+1);
            printf("�� �� �� : %s\n", (Heal2+i)->cName);
            printf("�� Ʈ �� : %s \n", (Heal2+i)->cTel);
            printf("��    �� : %s \n", (Heal2+i)->cAddr);
      }
   }
   fclose(fload);
   system("pause");
   
 } 
  //��� ��ȸ �Լ� 
void MemoShow(unsigned rsize, struct data *Heal2){
	int nNum,i;
   FILE *fload;
   int Cnt = Cnt_data(rsize); 
   printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n ", Cnt);
   printf("�� ��° �����͸� ��ȸ�Ͻðڽ��ϱ�? ");
   scanf("%d", &nNum);
   
   fload = fopen(_FILE_, "r+"); 
   fread(Heal2, rsize, Cnt, fload);
   for(i=0;i<Cnt;i++){ //i=0, 1
       if(nNum-1 == i){ //2-1 == 0 2-1 == 1
            printf("\n %d��° ������ \n", i+1);
            printf("�� �� �� : %s\n", (Heal2+i)->cName);
            printf("�� Ʈ �� : %s \n", (Heal2+i)->cTel);
            printf("��    �� : %s \n", (Heal2+i)->cAddr);
      }
   }
   fclose(fload);
   system("pause");
 }
// ��� ���� �Լ� 
void Memo(unsigned rsize, struct data *Heal2){
  int i;
  int Cnt = Cnt_data(rsize);
  FILE *fload;
  
  printf("�� %d���� �����Ͱ� �ֽ��ϴ�. ", Cnt);
  fload = fopen(_FILE_, "r+");
  fread(Heal2, rsize, Cnt, fload);
  for(i=0;i<Cnt; i++){
     printf("\n %d��° ������ \n", i+1);
     printf("��    ¥ : %s\n", (Heal2+i)->cName);
     printf("��    �� : %s \n", (Heal2+i)->cTel);
     printf("�� �� �� : %s \n", (Heal2+i)->cAddr);
  }
  fclose(fload);
  system("pause");
}
  
