package MovieManager2_4;

public class AccountManager {
	
	private String id,pw,name,gender,birth,email,tel,brand;
	
	public String getId() {return id;}
	public void setId(String id) {this.id = id;}
	public String getPw() {return pw;}
	public void setPw(String pw) {this.pw = pw;}
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public String getGender() {return gender;}
	public void setGender(String gender) {this.gender = gender;}
	public String getBirth() {return birth;}
	public void setBirth(String birth) {this.birth = birth;}
	public String getEmail() {return email;}
	public void setEmail(String email) {this.email = email;}
	public String getTel() {return tel;}
	public void setTel(String tel) {this.tel = tel;}
	public String getBrand() {return brand;}
	public void setBrand(String brand) {this.brand=brand;}
	
	public String toString() {
		String str = String.format("아이디:%s\n이름:%s\n성별:%s\n생일:%s"
				+ "\n이메일:%s\n[%s]연락처:%s\n",id,name,gender,birth,email,brand,tel);
		return str;
	}


}
