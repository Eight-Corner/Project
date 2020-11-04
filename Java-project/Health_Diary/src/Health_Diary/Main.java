package Health_Diary;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;

class WorkOut {
	Scanner sc = new Scanner(System.in);
	String name; // 운동명 
	int set, cnt,sec; // 운동 세트와 횟수, 시간(초), 초 단위를 이용하여 시 분 초 나오게 할 예정 
	WorkOut(){ // default 
	}
	WorkOut(String name, int set, int cnt,int sec){ // 생성자 
		this.name=name; this.set=set; this.cnt=cnt; this.sec=sec; 
	}
 
	void workoutAdd () { // 운동 추가 함수 
		System.out.println("\n\n운동을 추가하시겠습니까? (Y/N)");
		String y = "y", Y = "Y", n = "n", N = "N"; // 결정 변수
		sc.nextLine(); // 버퍼 방지
		String sel = sc.nextLine(); 
		if (sel.equals(y) || sel.equals(Y)) {
			System.out.println("\n\n 진행합니다. ");
			System.out.println("안내:: 횟수가 아닌 초(sec)단위로 입력하고 싶으시면 "
					+ "\n횟수 입력에서 0을 눌러 진행하십시오. ");
			// 운동 추가 기능 구현
			System.out.print("운동명 입력 : ");
			this.name = sc.nextLine(); // 운동명 
			
			System.out.print("세트 수 입력 : ");
			this.set = sc.nextInt();
			if (this.set <= 0 ) {
				System.out.println("세트 수는 1 이상 입력하셔야 합니다. 다시 입력하세요.");
				return;
			}
			
			System.out.print("횟수 입력 : ");
			this.cnt = sc.nextInt();
			
			if	(this.cnt == 0) {
			System.out.print("초(sec) 입력 : ");
			this.sec = sc.nextInt();
			System.out.println("["+this.name+"] ["+this.set+"세트] ["+this.sec+"sec]가 저장 되었습니다.");
				} else {
				System.out.println("["+this.name+"] ["+this.set+"세트] ["+this.cnt+"개] 가 저장 되었습니다.");
			}
			
		} 
		else if ( sel.equals(n) || sel.equals(N)) {
			System.out.println("이전화면으로 돌아갑니다.");
			return;
		} else {
			int cls = 0;
			for (cls = 0; cls < 15; cls++) {
				System.out.println(); // 화면 클리어 
			} 
			System.out.println("WARNING : : 제대로 다시 입력하세요!!");
		}
	}
	void workoutDel() {
		System.out.println("\n: : WARNING : :\n운동을 삭제하시겠습니까? (Y/N)");
		
	}
	
	void workoutView() {
	if (cnt > 0 || sec <= 0 ) {
	System.out.println("["+this.name+"]이(가) ["+this.set+"세트] ["+this.cnt+"개]");	
		} else if ( sec > 0 || cnt <= 0) {
	System.out.println("["+this.name+"]이(가) ["+this.set+"세트] ["+this.sec+"초]");	
		}
	}
}

class Memo extends WorkOut{ // 기록 클래스 운동을 상속받아 운동 리스트를 호출할 예정
	Scanner sc = new Scanner(System.in);
	int day,time; // 날짜와 운동한 시간이 필요  
	 public Memo() {
		 super();
	}
	void memo() { 
		
		String txt;     // 기록용 변수 선언
		   System.out.print("기록하실 내용을 입력하세요 : ");
			 txt = sc.nextLine(); // 기록을 하기 위한 입력값
		    String fileName = "G://OneDrive - 유원대학교//Windows 10 - Desktop//DiaryMemo.txt" ;
		        try{
		            // BufferedWriter / FileWriter를 조합 사용 (속도 향상)
		            BufferedWriter fw = new BufferedWriter(new FileWriter(fileName, true));
		            fw.write(txt);
		            fw.flush();
		            fw.close();
		        } catch(Exception e){
		            e.printStackTrace();
		        } 
		        System.out.println();
	}
	void memoDel() { // 기록 특정 부분 삭제하는 함수 구현을 하고싶은데 흠흠..
		
	}
	public void memoView() {
	System.out.println("====LIST====");
	System.out.println("["+this.day+"] ["+this.time+"] ["+this.name+"]");
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		
 // 다형성을 이용할 것임
		// 생성자 
		ArrayList<WorkOut> wo = new ArrayList<WorkOut>();
		WorkOut WO = new WorkOut();
		Memo me = new Memo();
		
		//배열 구현
		while ( true ) {

			System.out.println("============메인 메뉴============");
			System.out.print("1.운동 추가 | 2.운동 삭제 | 3.운동 조회 "
							+ "\n4.기록 조회 | 5.기록 저장 | 6.기록 삭제");
			System.out.print("\n 프로그램을 종료하려면 0번");
			System.out.println("\n===============================");
			System.out.print("입력 >  ");
			
			int act = sc.nextInt();
			if ( act == 1 ) {
				WO.workoutAdd();
			} else if ( act == 2 ) {
				WO.workoutDel();
			} else if ( act == 3 ) {
				WO.workoutView(); 
			} else if ( act == 4 ) {
				
			} else if ( act == 5 ) {
				me.memo();
			} else if ( act == 6 ) {
				
			} else if ( act == 0 ) {
				System.out.println("\n\n\n\n\n\n\n\n\n\n"
						+ " ★★프로그램을 종료합니다.★★");
				break;
			} else {
				int cls = 0;
				for (cls = 0; cls < 15; cls++) {
					System.out.println(); // 화면 클리어 
				} 
				System.out.println("WARNING : : 제대로 다시 입력하세요!!");
				for (cls = 0; cls < 5; cls++) {
					System.out.println(); // 화면 클리어 
					}
				continue;
				}
			}
		
	}
}