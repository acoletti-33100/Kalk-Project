import java.lang.Exception;

public class ExceptionHandler extends Exception {
	private String message;

	public ExceptionHandler() { message = "Malformed expression"; } 
	public ExceptionHandler(String message) { this.message =  message; }
	public String what() { return message; }
}
