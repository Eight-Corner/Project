#include <stdio.h>


typedef struct Health { // � ����ü 
	char hName[20]; // ���
	unsigned int hSet, hTime; // � ��Ʈ�� �ð�
	int day, time; // �����  ��¥�� ��� �ð�
}Health;


void HealthAdd(Health *health_list, char *hName,int *hSet,int *hTime);//� �߰�
void HealthDel(Health *health_list);//� ���� 
void Show(Health *health_list);//� ��ȸ 
void MemoShow(Health *health_day);//��� ��ȸ 
void Memo(Health *health_day, int *day, int *time);//��� ���� 

int main()
{
	int user_choice; // ���� ���ø޴� 
	int num_total_day = 0;  // ���� � ��� �� �� 
	
	Health *health_day;
    Health *health_list;

    printf("������ �ִ� ���� ũ�⸦ ��ŭ ���� �Ͻðڽ��ϱ�?\n");
    scanf_s("%d", &user_choice);
    // ���� ���α׷��� 
    health_list = (Health*)malloc(sizeof(Health) * user_choice);
    


    while (1) {

        printf("--------------------\n");
        printf("|| 1. � �߰� ||\n");
        printf("|| 2. � ���� ||\n");
        printf("|| 3. � ��ȸ ||\n");
        printf("|| 4. ��� ��ȸ ||\n");
        printf("|| 5. ��� ���� ||\n");
        printf("|| 0. ��     �� ||\n");
        printf("\n  ��ȣ     ����  : ");
        scanf("%d", &user_choice);

        if (user_choice == 0) {
            printf("\n�ڡڡڡ����α׷��� �����մϴ١ڡڡڡ�\n");
            break;
        }
    }
}

//� �߰�
void HealthAdd(Health* health_list, char *hName, int *hSet, int *hTime) {
    printf("� �̸� : ");
    scanf_s("%c", health_list[*hName].hName, sizeof(health_list[*hName].hName));
    printf("��Ʈ �� ���� : ");
    scanf_s("%d", health_list[*hSet].hSet, sizeof(health_list[*hSet].hSet));
    printf("�ð�[sec] ���� : ");
    scanf_s("%d", health_list[*hTime].hTime, sizeof(health_list[*hTime].hTime));

    

}
