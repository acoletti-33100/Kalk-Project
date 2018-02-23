public class Info<T> {
	private T info;	
	
	public Info() {}
	public Info(T val) { info = val; } 
	public T getInfo() { return info; }
	public String addString(Info<T> operand) throws IllegalArgumentException {
		T operandInfo = operand.getInfo();
		if(info != null && operand != null && info instanceof String && operandInfo instanceof String) {
			String x = (String)info;
			String y = (String)operandInfo;
			return new String(x + y);
		}
		else
			throw new IllegalArgumentException("arguments are not strings");
	}
	public Double addDouble(Info<T> operand) throws IllegalArgumentException {
		T operandInfo = operand.getInfo();
		if(info != null && operand != null && info instanceof Double && operandInfo instanceof Double) {
			Double x = (Double)info;
			Double y = (Double)operandInfo;
			return new Double(x + y);
		}
		else
			throw new IllegalArgumentException("arguments are not doubles");
	}
	public Integer addInt(Info<T> operand) throws IllegalArgumentException {
		T operandInfo = operand.getInfo();
		if(info != null && operand != null && info instanceof Integer && operandInfo instanceof Integer) {
			Integer x = (Integer)info;
			Integer y = (Integer)operandInfo;
			return new Integer(x + y);
		}
		else
			throw new IllegalArgumentException("arguments are not integers");
	}
	public void setInfo(T val) { info = val; }
}
