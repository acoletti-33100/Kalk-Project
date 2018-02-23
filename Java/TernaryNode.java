public class TernaryNode<T> {
	private Info<T> info;
	private TernaryNode<T> left;
	private TernaryNode<T> right;
	private TernaryNode<T> middle;
	private TernaryNode<T> parent;

	public TernaryNode(Info<T> info , TernaryNode<T> left ,
			TernaryNode<T> right ,
			TernaryNode<T> middle) {
		this.info = info;
		this.left = left;
		this.right = right;
		this.middle = middle;
		parent = null;
		if(left != null)
			left.setParent(this);
		if(right != null)
			right.setParent(this);
		if(middle != null)
			middle.setParent(this);
	}
	public T getInfo() { return info.getInfo(); }
	public Info<T> getVal() { return new Info<T>(info.getInfo()); }
	public void setInfo(T val) { info.setInfo(val); }
	public TernaryNode<T> getLeft() { return left; }
	public TernaryNode<T> getRight() { return right; }
	public TernaryNode<T> getMiddle() { return middle; }
	public TernaryNode<T> getParent() { return parent; }
	public int getHeight() {
		if(getParent() != null)
			return 1 + getParent().getHeight();
		else 
			return 1;
	}
	public void setChildren(TernaryNode<T> l , TernaryNode<T> r , TernaryNode<T> m) {
		left = l;
		right = r;
		middle = m;
		left.setParent(this);
		right.setParent(this);
		middle.setParent(this);
	}
	public void setRight(TernaryNode<T> node) { 
		right = node;
		right.setParent(this); 
	}
	public void setLeft(TernaryNode<T> node) { 
		left = node;
		left.setParent(this);
	}
	public void setMiddle(TernaryNode<T> node) { 
		middle = node;
		middle.setParent(this);
	}
	public void setParent(TernaryNode<T> node) { parent = node; }
}
