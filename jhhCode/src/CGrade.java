

public class CGrade extends WirelessClass{
	//시간당 단가
		int unitPrice = 104;//시간당 단가
		int basePrice=15000;
		String gradeCode="C";
		int discountRate= discountRateMethod(basePrice);//할인요금
		// TODO Auto-generated constructor stub
		String[] custName = new String[10];//고객명
		int[]  useTime = new int[10];//사용시간
		int[] communicationFee = new int[10];//이번달통신요금
		
	    //입력되는 인원수
	    static int cnt=0;
		public void input(String cN, int uT) {
			custName[cnt] = cN;
	        useTime[cnt] = uT;
	        communicationFee[cnt]= communicationFeeMethod(unitPrice, useTime[cnt],basePrice, discountRate );
	        cnt++;
		}
		public void output() {
			for(int i=0;i<cnt; i++) {
				System.out.print(custName[i]+"\t");
				System.out.print(gradeCode+"\t");
				System.out.print( unitPrice+"\t");
				System.out.print( basePrice+"\t");
				System.out.print( useTime[i]+"\t");
				System.out.print( discountRate+"\t");
				System.out.print( communicationFee[i]);
				System.out.println();
			}
			
			
		}
}