package dynamic_beat_16;

import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.ImageIcon;

public class Note extends Thread {

	private Image noteBasicImage = new ImageIcon(Main.class.getResource("../images/noteBasic.png")).getImage();
	private int x, y = 580 - (1000 / Main.SLEEP_TIME * Main.NOTE_SPEED) * Main.REACH_TIME;
	private String noteType;
	private boolean proceeded = true;
	
	public String getNoteType() {
		return noteType;
	}
	
	public boolean isProceeded() {
		return proceeded;

	}

	public void close() {
		proceeded = false;
	}

	public Note(String noteType) {
		if(noteType.equals("A")) {
			x = 228;
		} else if (noteType.equals("S")) {
			x = 332;
		} else if (noteType.equals("D")) {
			x = 436;
		} else if (noteType.equals("Space")) {
			x = 540;
		} else if (noteType.equals("1")) {
			x = 744;
		} else if (noteType.equals("2")) {
			x = 848;
		} else if (noteType.equals("3")) {
			x = 952;
		}
		this.noteType = noteType;
	}

	public void screenDraw(Graphics2D g) {
		if(noteType.equals("Space")) {
			g.drawImage(noteBasicImage, x, y, null);
			g.drawImage(noteBasicImage, x + 100, y, null);
		}
		else {
			g.drawImage(noteBasicImage, x, y, null);

		}
	}

	public void drop() {
		y += Main.NOTE_SPEED;
		if(y > 620) {
			System.out.println("Miss");
			close();
		}
	}

	@Override
	public void run() {
		try {
			while(true) {
				drop();
				if(proceeded) {
					Thread.sleep(Main.SLEEP_TIME);
				}else {
					interrupt();
					break;
				}
			}
		}catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
	
	public String judge() {
		if( y >= 613) {
			System.out.println("Late");
			close();
			return "Late";
		} else if ( y >= 600) {
			System.out.println("Good");
			close();
			return "Good";
		} else if ( y >= 587) {
			System.out.println("Great");
			close();
			return "Great";
		} else if ( y >= 573) {
			System.out.println("Perfect");
			close();
			return "Perfect";
		} else if ( y >= 565) {
			System.out.println("Great");
			close();
			return "Great";
		} else if ( y >= 550) {
			System.out.println("Good");
			close();
			return "Good";
		} else if ( y >= 535) {
			System.out.println("Early");
			close();
			return "Early";
		}
		return "None"; // 판정이 없음 
	}
	
	public int getY() {
		return y;
	}
	
}
