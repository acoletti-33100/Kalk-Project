import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class BinaryTree<T> implements Tree<T> {
	private BinaryNode<T> root;

	public BinaryNode<T> getRoot() { return root; }
	public BinaryTree(BinaryNode<T> root) {
		if(root != null)
			this.root = root;
	}
	public int getHeight(BinaryNode<T> node) {
		if(node == null)
			return 0;
		else { return 1 + getHeight(node.getLeft()) + getHeight(node.getRight()); }
	}
	public Tree<T> Sum(Tree<T> tree) throws ExceptionHandler {
		if(tree instanceof BinaryTree) {
			BinaryTree<T> tmp = (BinaryTree<T>)tree;
			BinaryNode<T> res = copy(root);
			insertBalanced(res , copy(tmp.getRoot()));
			return (new BinaryTree<T>(res));
		}
		else
			throw new ExceptionHandler("can't sum incompatible trees");
	}
	private BinaryNode<T> copy(BinaryNode<T> node) {
		                if(node == null)
					return null;
		        return new BinaryNode<T>(node.getVal() , copy(node.getLeft()) , copy(node.getRight()));				            }
	private void insertBalanced(BinaryNode<T> tmp , BinaryNode<T> node) {
	   while(tmp != null) {
		         BinaryNode<T> l = tmp.getLeft() , r = tmp.getRight();
		           if(l == null) {
			               tmp.setLeft(node);
				       return;
				 }
		           if(r == null) {
			            tmp.setRight(node);
				       return;
					    }
		           if(getHeight(l) <= getHeight(r))
			               tmp = l;
			         else
				      tmp = r;
	             }
	         }

	private void IterateOverList(List<T> list , BinaryNode<T> iterable , BinaryNode<T> fixed) {
	if(iterable == null)
		return;
	InsertIfEquals(list , iterable , fixed);
	IterateOverList(list , iterable.getLeft() , fixed);
	IterateOverList(list , iterable.getRight() , fixed); 
}

	private void InsertIfEquals(List<T> list , BinaryNode<T> fixed , BinaryNode<T> iterable) {
	if(iterable == null)
		return;
	if(fixed.getInfo() == iterable.getInfo())
        list.add(fixed.getInfo());
	InsertIfEquals(list , fixed , iterable.getLeft());
	InsertIfEquals(list , fixed , iterable.getRight());
}

        public BinaryTree<T> Intersection(Tree<T> tree) throws ExceptionHandler {
            if(tree instanceof BinaryTree) {
            	BinaryTree<T> tmp = (BinaryTree<T>)tree;
        	List<T> list = new ArrayList<T>();
        	IterateOverList(list , root , tmp.getRoot());
        	return InsertOnIntersectionList(list);
	    }
	    else
                throw new ExceptionHandler("can't intersect incompatible trees");
        }

	private BinaryTree<T> InsertOnIntersectionList(List<T> list) throws ExceptionHandler {
    int dim = list.size();
    if(dim > 0) {
      BinaryNode<T> Root = new BinaryNode<T>(new Info<T>(list.get(0)) , null , null);
    for(int i = 1; i < dim; i++) {
        BinaryNode<T> aux = new BinaryNode<T>(new Info<T>(list.get(i)) , null , null);
        insertBalanced(Root , aux);
    }
    return (new BinaryTree<T>(Root));
    }
    else
	    throw new ExceptionHandler("empty Intersection");
}
	public void insertValues(List<T> list) {
		root.setInfo(list.get(0));
		insertValues(list , list.size() , 1 , root);
	}
	private void insertValues(List<T> list , int listSize , int index , BinaryNode<T> node) {
		if(node == null || index+1 >= listSize)
			return;
		BinaryNode<T> l = node.getLeft();
		BinaryNode<T> r = node.getRight();
		if(l != null && r != null) {
			l.setInfo(list.get(index));
			r.setInfo(list.get(index+1));
			index += 2;
		}
		insertValues(list , listSize , index , l);
		insertValues(list , listSize , index , node.getRight());

	}
	
	private BinaryNode<T> copyNodeOnly(BinaryNode<T> node) {
		if(node == null)
			return null;
		return new BinaryNode<T>(node.getVal() , null , null);
	}

	public BinaryTree<T> Rotation() throws ExceptionHandler {
		if(root == null || root.getRight() == null)
			throw new ExceptionHandler("Can't perform rotation on this tree");
		BinaryNode<T> resultRoot = RotationHelp();
		return (new BinaryTree<T>(resultRoot));
	}

	protected BinaryNode<T> RotationHelp() {
		BinaryNode<T> resultRoot = copyNodeOnly(root);
		RotationRec(resultRoot , root);
		return resultRoot;
	}

	private void RotationRec(BinaryNode<T> node , BinaryNode<T> aux) {
		if(aux == null || node == null)
			return;
		if(aux.getRight() != null) {
			node.setLeft(copyNodeOnly(aux.getRight()));
			RotationRec(node.getLeft() , aux.getRight());
		}
		if(aux.getLeft() != null) {
			node.setRight(copyNodeOnly(aux.getLeft()));
			RotationRec(node.getRight() , aux.getLeft());
		}
	}

	public List<Info<T>> sumValues() { 
		List<Info<T>> list = new ArrayList<Info<T>>();
		Count(root,list);	
		return list;
	}
	protected void Count(BinaryNode<T> node , List<Info<T>> list) {
		if(node != null) { 
			list.add(node.getVal());
			Count(node.getLeft() , list);
			Count(node.getRight() , list);
		}
	}
	private <T> void printBinary(BinaryNode<T> node , PrintWriter out , String path) {
		if(node == null) 
			return;
			if(node.getLeft() != null) 
				out.print(path + "l " + node.getLeft().getInfo());
			if(node.getRight() != null) 
				out.print(" " + path + "r " + node.getRight().getInfo());
			if(node.getLeft() != null || node.getRight() != null)
				out.println(); 
			printBinary(node.getLeft() , out , path + "l");
			printBinary(node.getRight() , out , path + "r");
	}
	public void print(String mess , boolean append) {
		PrintWriter out = null;
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("Use.txt" , append)));
		} catch(IOException ecc) { System.out.println("file not found");System.exit(0); }
		out.println();
		if(mess != null)
			out.println(mess);
		out.println("Binary Tree");
		out.println("root : " + root.getInfo());
		printBinary(root,out,"");
		out.println();
		out.close();
	}
}
