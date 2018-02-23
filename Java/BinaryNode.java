public class BinaryNode<T> {
	private Info<T> info;
	private BinaryNode<T> left;
	private BinaryNode<T> right; 
	private BinaryNode<T> parent; 

	public BinaryNode(Info<T> info , BinaryNode<T> left , BinaryNode<T> right) {
		this.info = info;
		this.left = left;
		this.right = right;
		parent = null;
		if(left != null)
			left.setParent(this);
		if(right != null)
			right.setParent(this);
	}
	public T getInfo() { return info.getInfo(); }
	public Info<T> getVal() { return new Info<T>(info.getInfo()); }
	public void setInfo(T val) { info.setInfo(val); }
	public BinaryNode<T> getLeft() { return left; }
	public BinaryNode<T> getRight() { return right; }
	public BinaryNode<T> getParent() { return parent; }
	public int getHeight() {
		if(getParent() != null)
			return 1 + getParent().getHeight();
		else 
			return 1;
	}
	public void setChildren(BinaryNode<T> l , BinaryNode<T> r) {
		left = l;
		right = r;
		left.setParent(this);
		right.setParent(this);
	}
	public void setRight(BinaryNode<T> node) { 
		right = node;
		right.setParent(this); 
	}
	public void setLeft(BinaryNode<T> node) { 
		left = node;
		left.setParent(this); 
	}
	public void setParent(BinaryNode<T> node) { parent = node; }
}
