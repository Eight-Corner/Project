package MovieManager2_1;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Movie {
	
	String movieName;
	int movieTime;
	
	private int TicketNumber;
	
	private String userId;
	private int userPassword;

	LinkedList movie = new LinkedList();
	
	public Movie (){}	
	public Movie(String movieName,int movieTime) {this.movieName=movieName;this.movieTime=movieTime;}
	// return = get
	public void setUserPw(int userPassword) { this.userPassword = userPassword; }
	public int getUserPw() { return userPassword; }
	
	public void userLogin() {}
	public void adminLogin() {}
	public void adminMovieAdd() {
		Scanner sc = new Scanner(System.in);
		System.out.println("\n\n\n\t--영화 추가--");
		System.out.print("추가할 영화 제목을 입력하세요 >");
		String nm = sc.next();
		movie.add(nm);
	}
	public void adminMovieEdit() {}
	public void adminMovieDelete() {}
	public void adminMovieShow() {
//		for(Movie show : movie) {System.out.println(show);}
		Iterator movieShow = movie.iterator();
		while(movieShow.hasNext()) {System.out.println(movieShow.next());}
	}
}
