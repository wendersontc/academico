
public class Simetricos implements Comparable<Simetricos>{
	
	public Integer A;
	public Integer B;
	
	public Integer getA() {
		return A;
	}
	public void setA(Integer a) {
		A = a;
	}
	public Integer getB() {
		return B;
	}
	public void setB(Integer b) {
		B = b;
	}
	@Override
	public int compareTo(Simetricos o) {
		if(o.getA() != getA())
			return Integer.compare(o.getA(), getA());
		return Integer.compare(o.getB(), getB());
	}

}
