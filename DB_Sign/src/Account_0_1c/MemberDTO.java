package Account_0_1c;


//Data (data transfer object)  데이터 전송 이동 객체, db처리하는데이용함 
public class MemberDTO {
	
	private String id;
	private String pw;
	private String name;
	private String tel;
	private String addr;
	private String birth;
	private String job;
	private String gender; 
	private String email;
	private String intro;
	public String getIntro() {
		return intro;
	}
	public void setIntro(String intro) {
		this.intro = intro;
	}
	// 흠...
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getPw() {
		return pw;
	}
	public void setPw(String pw) {
		this.pw = pw;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getTel() {
		return tel;
	}
	public void setTel(String tel) {
		this.tel = tel;
	}
	public String getAddr() {
		return addr;
	}
	public void setAddr(String addr) {
		this.addr = addr;
	}
	public String getBirth() {
		return birth;
	}
	public void setBirth(String birth) {
		this.birth = birth;
	}
	public String getJob() {
		return job;
	}
	public void setJob(String job) {
		this.job = job;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	
// DTO 객체 확인
	@Override
	public String toString() {
		return "Member [id = "+id+", pwd = "+pw+", name = "+name+", tel = "+tel
				+", addr = "+addr+", birth = "+birth+", job = "+job+", gender = "
				+gender+", email = "+email+", intro = "+intro+"]";
	}
	
	
}
