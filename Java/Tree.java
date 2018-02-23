import java.util.List;

public interface Tree<T> {
	Tree<T> Sum(Tree<T> tree) throws ExceptionHandler ;
	Tree<T> Intersection(Tree<T> tree) throws ExceptionHandler ;
	void insertValues(List<T> list);
	List<Info<T>> sumValues();
	void print(String mess , boolean append);
}
