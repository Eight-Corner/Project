#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <process.h>

#define  _FILE_   "ADDRBOOK.dat" // ���ϸ� ���� 

//����ü ����  

struct data {
    char cName[8];
    char cTel[16];
    char cAddr[32];
};

//�Լ� ���� 
void SelOne(unsigned, struct data*);//�ڷ� �Է� 
void SelTwo(unsigned, struct data*);//�ڷ� �˻�  
void SelThree(unsigned, struct data*);//�ڷ� ���� 
void SelFour(unsigned, struct data*);//�ڷ� ���� 
void SelFive(unsigned, struct data*);//�ڷ� ��ȸ 

int Cnt_data(unsigned); //���ڵ� �ο����� �����ִ� �Լ�  

int main(int argc, char* argv[]) {
    char cBtn;
    int Lec;
    unsigned rsize = sizeof(struct data);//56 byte

    struct data* Book1;//����ü�� �����ϱ� ���ؼ� �ʿ��� ���� Book1�Դϴ�. �׷��� �̰��� ������ ������ �� ��  
    struct data* Book2;


    while (1) {
        //������ ���� ����, ���Ͽ� ��� �ִ� ���ڵ� ���� ����

        Lec = Cnt_data(rsize); //56
     //   Lec = 10;//�ӽ÷� �ݺ��� ���߰� �ϱ� ���ؼ� ���� �ִ� ������ �� 
        Book1 = (struct data*)malloc(1 * sizeof(struct data));//1�� ���ڵ� ���� �޸� Ȯ�� 
        // ���ڵ� = �ʵ� + �ʵ� + �ʵ� / ���ڵ� = Book1�� ����  
        Book2 = (struct data*)malloc(Lec * sizeof(struct data));//���Ͼȿ� �������� ���ڵ带 ���� �޸� Ȯ��
        //   
        system("cls");//Ŀ��� ���(������ ���) ȭ���� ũ�����ϴ� �Լ�
        printf("����ü ũ�� : %d\n", rsize);
        printf("������ ���� : %d\n\n", Lec);

        if (Lec != 0) { //���Ͽ� �����Ͱ� �̹� �ִ� ���  
            printf("1. �ڷ� �Է� \n");
            printf("2. �ڷ� �˻� \n");
            printf("3. �ڷ� ����  \n");
            printf("4. �ڷ� ���� \n");
            printf("5. �ڷ� ��ȸ \n");
            printf("0. ��     �� \n");
            printf("�����ϼ��� : ");
            scanf("%c", &cBtn);
        }
        else {  //���� ó���� ���Ͽ� �ƹ��͵� ���� ���� 
            cBtn = '1';
        }
        if (cBtn == '1') {
            system("cls");
            SelOne(rsize, Book1);
        }
        else if (cBtn == '2') {
            if (Lec == 0) {
                printf("�˻��� �����Ͱ� �����ϴ� \n");
                system("pause");
            }
            else {
                system("cls");
                SelTwo(rsize, Book2);
            }
        }
        else if (cBtn == '3') {
            if (Lec == 0) {
                printf("������ �����Ͱ� �����ϴ� \n");
                system("pause");
            }
            else {
                system("cls");
                SelThree(rsize, Book2);
            }
        }
        else if (cBtn == '4') {
            if (Lec == 0) {
                printf("������ �����Ͱ� �����ϴ� \n");
                system("pause");
            }
            else {
                system("cls");
                SelFour(rsize, Book2);
            }
        }
        else if (cBtn == '5') {
            if (Lec == 0) {
                printf("��ȸ�� �����Ͱ� �����ϴ� \n");
                system("pause");
            }
            else {
                system("cls");
                SelFive(rsize, Book2);
            }

        }
        else if (cBtn == '0') {
            break;
        }
    }


    return 0;

}

//���ڵ� ���� ���� �ִ� �Լ�  
int Cnt_data(unsigned  rsize) { //56
    int Cnt;
    FILE* fload;//fload��� ������ FILE�� ������ �����̴�. 

    fload = fopen(_FILE_, "r");
    if (fload == NULL) {
        Cnt = 0;
    }
    else {
        fseek(fload, -1, SEEK_END);//fseek(����������, �̵��� ũ��, ������); �����ϸ� 0 �����ϸ� -1�� ��ȯ�� 
      // 

        Cnt = (ftell(fload) / rsize) + 1;//ftell(����������) ������������ ���� ��ġ�� ��ȯ�Ѵ�. �����ϸ� -1�� ��ȯ�Ѵ�.   
        fclose(fload);
    }
    return Cnt;
}

void SelOne(unsigned rsize, struct data* Book1) {
    FILE* fsave;

    fflush(stdin);
    printf("\n ��  ��[8��] : ");
    gets(Book1->cName);
    printf("\n ��ȭ��ȣ[16��] :  ");
    gets(Book1->cTel);
    printf("\n ��   ��[24��] :  ");
    gets(Book1->cAddr);

    if (strlen(Book1->cName) < 1 || strlen(Book1->cTel) < 1 || strlen(Book1->cAddr) < 1) {
        printf("�ƹ��� �Է��� ���� �ּҷϿ� ������� �ʽ��ϴ� \n");
    }
    else {
        fsave = fopen(_FILE_, "a+");//append �߰�    
        fwrite(Book1, rsize, 1, fsave);
        fclose(fsave);
    }
    system("pause");
}//�ڷ� �Է� 

void SelTwo(unsigned rsize, struct data* Book2) {

    int nNum, i;
    FILE* fload;
    int Cnt = Cnt_data(rsize);//������(���ڵ�) ���� ���ִ� �Լ� ȣ��  
    printf("�� %d���� �����Ͱ� �ֽ��ϴ�.\n ", Cnt);//ex) 3
    printf("�� ��° �����͸� ��ȸ�Ͻðڽ��ϱ�? ");//ex) 5�� ��ȸ  
    scanf("%d", &nNum);//2

    fload = fopen(_FILE_, "r+");
    fread(Book2, rsize, Cnt, fload);
    for (i = 0; i < Cnt; i++) { //i=0, 1
        if (nNum - 1 == i) { //2-1 == 0 2-1 == 1
            printf("\n %d��° ������ \n", i + 1);
            printf("��    �� : %s\n", (Book2 + i)->cName);
            printf("��ȭ��ȣ : %s \n", (Book2 + i)->cTel);
            printf("��    �� : %s \n", (Book2 + i)->cAddr);
        }
    }
    fclose(fload);
    system("pause");
}//�ڷ� �˻�  

void SelThree(unsigned rsize, struct data* Book2) {

    int i, temp = 0;
    int Cnt;
    int nNum;
    FILE* fsave;
    FILE* fload;

    Cnt = Cnt_data(rsize);

    printf("�� %d���� �����Ͱ� �ֽ��ϴ�. \n", Cnt);
    printf("�� ��° �����͸� �����Ͻðڽ��ϱ�? ");
    scanf("%d", &nNum);

    fload = fopen(_FILE_, "r+");
    fread(Book2, rsize, Cnt, fload);
    for (i = 0; i < Cnt; i++) {
        if (nNum - 1 == i) {
            printf("\n%d��° ������ \n", i + 1);
            fflush(stdin);
            printf("�� �� : ");
            gets((Book2 + i)->cName);
            printf("��ȭ��ȣ : ");
            gets((Book2 + i)->cTel);
            printf("��   �� : ");
            gets((Book2 + i)->cAddr);
            if (strlen((Book2 + i)->cName) < 1 || strlen((Book2 + i)->cTel) < 1 || strlen((Book2 + i)->cAddr) < 1) {
                temp++;
            }

        }

    }//end for

    if (temp > 0) {
        printf("�ƹ��� �Է��� ���� �ּҷϸ� ���� ���� �ʾҽ��ϴ�.\n");
    }
    else {
        fsave = fopen(_FILE_, "w+");
        fwrite(Book2, rsize * Cnt, 1, fsave);
        fclose(fsave);
    }

    fclose(fload);
    system("pause");

}//�ڷ� ���� 
void SelFour(unsigned rsize, struct data* Book2) {
    int i, j = 0;
    int nNum;
    char cYN;
    int Cnt = Cnt_data(rsize);
    FILE* fsave;//�����  
    FILE* fload;//�б�� 

    printf("�� %d���� �����Ͱ� �ֽ��ϴ� \n", Cnt);

    if (Cnt == 1) {
        printf("1���� �����͸� �����ϹǷ� ������ �Ұ����մϴ� \n");
        fflush(stdin);
        printf("��� �����Ͻðڽ��ϱ�?(Y/N)");
        cYN = getchar(); //scanf("%c", &cYN);
        if (cYN == 'Y' || cYN == 'y') {
            _unlink(_FILE_);
        }
        else {
            printf("��ҵǾ����ϴ�. ");
        }
    }
    else {
        while (1) {
            printf("���° �����͸� �����Ͻðڽ��ϱ�? ");
            scanf("%d", &nNum);
            if (nNum <= Cnt) break;   // 2 <= 3           
        }
        fload = fopen(_FILE_, "r+");
        fread(Book2, rsize, Cnt, fload);
        for (i = 0; i < Cnt; i++) {
            if (i != nNum - 1) { // 0 != 1
                if (j == 0) fsave = fopen(_FILE_, "w+");
                else fsave = fopen(_FILE_, "a+");
                fwrite(Book2 + i, rsize, 1, fsave);
                fclose(fsave);
                j++;
            }
        }

        printf("�����Ͻ� ���ڵ尡 �����Ǿ����ϴ�.\n");
        fclose(fload);

    }

    system("pause");

}//�ڷ� ���� 
void SelFive(unsigned rsize, struct data* Book2) {
    int i;
    int Cnt = Cnt_data(rsize);
    FILE* fload;

    printf("�� %d���� �����Ͱ� �ֽ��ϴ�. ", Cnt);
    fload = fopen(_FILE_, "r+");
    fread(Book2, rsize, Cnt, fload);
    for (i = 0; i < Cnt; i++) {
        printf("\n %d��° ������ \n", i + 1);
        printf("��   �� : %s \n ", (Book2 + i)->cName);
        printf("��ȭ��ȣ: %s \n ", (Book2 + i)->cTel);
        printf("��   �� : %s \n ", (Book2 + i)->cAddr);
    }
    fclose(fload);
    system("pause");
}

//�ڷ� ��ȸ 