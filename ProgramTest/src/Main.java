
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt;
		int num[];
		int korEng[][];
		int sum[];
		int rank[];
		int[] notJoin;
		do {
			System.out.print("�ο����� �Է��ϼ���. 1~10�� >");
			cnt = sc.nextInt();
			if ( cnt == 0 ) {
				cnt = 5; // default �ʱ��ο� ��
			}
		} while (cnt < 1 || cnt > 10);
		// �޸� �Ҵ�
		num = new int[cnt];
		korEng = new int[cnt][3];
		sum = new int[cnt];
		 notJoin = new int[cnt]; // �ἮȽ��
		rank = new int[cnt]; 
		int total[] = new int[6];
		int avg[] = new int[6];
		char ox[] = new char [cnt];
		char[] grade1 = new char [cnt]; // ����
		String[] title = { "����", "����", "����" };
		// ����� ������ �޴� (for������ �������)

		while(true) {
			System.out.println("�޴� �Է� ");
			System.out.println("1. ���� �Է��ϱ� / 2. ��ü ���� ��� / 3. ���б� ����� / 4. ���� ");
			int act = sc.nextInt();
			if(act == 1) {
				for (int i = 0; i < cnt; i++) {
					System.out.print("��ȣ �Է� >");
					num[i] = sc.nextInt();
					for (int j = 0; j < 3; j++) { // ����� ��� �Է� �� ���̱� ������ 2�� �ݺ�
						System.out.print(title[j] + " ���� �Է� :");
						korEng[i][j] = sc.nextInt();
						
						sum[i] += korEng[i][j]; // �������
						total[0] += korEng[i][0]; // ���� �հ�
						total[1] += korEng[i][1]; //���� �հ�
						total[2] += korEng[i][2]; // ���� �հ�
						total[4] += sum[i]; // ��� �հ�
						total[5] += sum[i]/cnt; // ��� ��� �հ�
						avg[0] = total[0]/cnt; // ����
						avg[1] = total[1]/cnt; // ����
						avg[2] = total[2]/cnt; // ����
						avg[4] = total[4]/cnt; // �հ� ���
						avg[5] = total[5]/cnt; // ��ü ���
						if(sum[i] >= 250) {
							ox[i] = 'O';
							grade1[i] = 'A';
						} else if (sum[i] <= 249){
							ox[i] = 'X';
							grade1[i] = 'B';
						} else if (sum[i] < 200){
							ox[i] = 'X';
							grade1[i] = 'C';
						} else if (sum[i] < 150 ) {
							ox[i] = 'X';
							grade1[i] = 'F';
						}
						
					}
				}
				for(int i = 0; i < cnt; i ++ ) {
					System.out.print(i+1+"��°�� �л��� �Ἦ Ƚ�� �Է� >");
					for(int j = 0; j < 1; j++) {
						notJoin[i] = sc.nextInt();
						total[3] += notJoin[i];
					}
				}
				for (int i = 0; i < cnt; i++) {
					rank[i] = 1; // ��ũ�� 1�� �ʱ�ȭ ���ѳ��� �ؿ��� ������ �� ���� ������ ��ũ�� ++
				}
				// �������
				for (int i = 0; i < cnt - 1; i++) { 
					for (int j = i + 1; j < cnt; j++) { // �ڽ� ������ �ε����� ���ϱ� ���� �ʱ��
						if (sum[i] > sum[j]) { 
							rank[j]++; 
						} else if (sum[i] < sum[j]) { 
							rank[i]++;
						}
					}
				}
			}
			else if ( act == 2 ) {
				System.out.println("Show All");
				System.out.println("�й�\t����\t����\t����\t�ἮȽ��\t  �հ�\t���\t����\t����\t���бݿ���");
				for (int i = 0; i < cnt; i++) {
					System.out.print(num[i]+"\t"); //
					for (int j = 0; j < 3; j++) {
						System.out.printf("%5d\t",korEng[i][j]);
					}
					System.out.printf("%5d\t",notJoin[i]);
					System.out.printf("%5d\t%d\t%5d\t", sum[i], sum[i] / 2, rank[i]);
					System.out.printf("%c\t%c",grade1[i],ox[i]);
					System.out.println();
				}
				System.out.print("\n�հ�: ");
				for (int i = 0; i < total.length; i++) {
				System.out.print(" \t  "+total[i]);
				}
				System.out.print("\n���: ");
				for(int i = 0; i < avg.length; i++) {
					System.out.print("  \t  "+avg[i]);
				}
				System.out.println();
			}
			else if ( act == 3 ) {
				for(int i = 0; i < cnt; i ++ ) {
					if(grade1[i] == 'A') {
						System.out.println("���б� ����� : "+num[i]);
					}
				}
			}
		

			
			if(act == 4) {
				System.out.println("���� �Ϸ� �����ϴ�.");
				break;
			}
		}
	}

}
