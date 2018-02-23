public final class RedBlackNode<T> extends BinaryNode<T> {
	private boolean color = false;
	
	public RedBlackNode(boolean color , Info<T> info , RedBlackNode<T> left , RedBlackNode<T> right) {
		super(info , left , right);
		this.color = color;
	}
	public boolean hasBlack() { return color ^ true; }
	public boolean getBooleanColor() { return color; }
	public String getColor() {
		if(color)
			return "Red";
		return "Black";
	}
	public RedBlackNode<T> getParent() { return (RedBlackNode<T>)super.getParent(); }
	public RedBlackNode<T> getRight() { return (RedBlackNode<T>)super.getRight(); }
	public RedBlackNode<T> getLeft() { return (RedBlackNode<T>)super.getLeft(); }
	public void setColor(boolean col) { color = col; }
}
