import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class TernaryTree<T> implements Tree<T> {
	private TernaryNode<T> root;

	public TernaryTree(TernaryNode<T> root) {
		if(root != null)
			this.root = root;
	}
	public TernaryNode<T> getRoot() { return root; }
	public void insertValues(List<T> list) {
		root.setInfo(list.get(0));
		insertValues(list , list.size() , 1 , root);
	}
	private void insertValues(List<T> list , int listSize , int index , TernaryNode<T> node) {
		if(node == null || index+2 >= listSize)
			return;
		TernaryNode<T> l = node.getLeft();
		TernaryNode<T> r = node.getRight();
		TernaryNode<T> m = node.getMiddle();
		if(l != null && r != null && m!= null) {
			l.setInfo(list.get(index));
			r.setInfo(list.get(index+1));
			m.setInfo(list.get(index+2));
			index += 3;
		}
		insertValues(list , listSize , index , l);
		insertValues(list , listSize , index , node.getRight());
		insertValues(list , listSize , index , node.getMiddle());

	}
	public List<Info<T>> sumValues() { 
		List<Info<T>> list = new ArrayList<Info<T>>();
		Count(root,list);	
		return list;
	}
	private void Count(TernaryNode<T> node , List<Info<T>> list) {
		if(node != null) { 
			list.add(node.getVal());
			Count(node.getLeft() , list);
			Count(node.getRight() , list);
			Count(node.getMiddle() , list);
		}
	}
	public TernaryTree<T> Sum(Tree<T> tree) throws ExceptionHandler {
            if(tree instanceof TernaryTree) {
		TernaryTree<T> tmp = (TernaryTree<T>)tree;
            	TernaryNode<T> resultRoot = copy(root);
        	insertBalanced(resultRoot , copy(tmp.getRoot()));
            	return (new TernaryTree<T>(resultRoot));
	    
	    }
	    else
                throw new ExceptionHandler("can't sum incompatible trees");
	}

        private TernaryNode<T> copy(TernaryNode<T> node) {
            if(node == null)
                return null;
            return new TernaryNode<T>(node.getVal() , copy(node.getLeft()) , copy(node.getRight()) , copy(node.getMiddle()));
        }

private void IterateOverList(List<T> list , TernaryNode<T> iterable , TernaryNode<T> fixed) {
    if(iterable == null)
        return;
    InsertIfEquals(list , iterable , fixed);
    IterateOverList(list , iterable.getLeft() , fixed);
    IterateOverList(list , iterable.getRight() , fixed);
    IterateOverList(list , iterable.getMiddle() , fixed);
}

private void InsertIfEquals(List<T> list , TernaryNode<T> fixed , TernaryNode<T> iterable) {
    if(iterable == null)
        return;
    if(fixed.getInfo() == iterable.getInfo())
        list.add(fixed.getInfo());
    InsertIfEquals(list , fixed , iterable.getLeft());
    InsertIfEquals(list , fixed , iterable.getRight());
    InsertIfEquals(list , fixed , iterable.getMiddle());
}

private TernaryTree<T> InsertOnIntersectionList(List<T> list) throws ExceptionHandler {
    int dim = list.size();
    if(dim > 0) {
      TernaryNode<T> Root = new TernaryNode<T>(new Info<T>(list.get(0)) , null , null , null);
    for(int i = 1; i < dim; i++) {
        TernaryNode<T> aux = new TernaryNode<T>(new Info<T>(list.get(i)) , null , null , null);
        insertBalanced(Root , aux);
    }
    return (new TernaryTree<T>(Root));
    }
    else
	    throw new ExceptionHandler("empty Intersection");
}

	public List<Info<T>> SumMiddle() {
		List<Info<T>> list = new ArrayList<Info<T>>();
		helpSumMiddle(list , root);
		return list;
	}

      private void insertBalanced(TernaryNode<T> tmp , TernaryNode<T> node) {
          while(tmp != null) {
        TernaryNode<T> l = tmp.getLeft() , r = tmp.getRight() , m = tmp.getMiddle();
        if(l == null) {
            tmp.setLeft(node);
            return;
        }
        if(r == null) {
            tmp.setRight(node);
            return;
        }
        if(m == null) {
            tmp.setMiddle(node);
            return;
        }
        int heightL = getHeight(l) , heightR = getHeight(r) ,heightM = getHeight(m) , tmpH = -1;
        if(heightL < heightR) {
            tmp = l;
            tmpH = heightL;
        }
        else {
            tmp = r;
            tmpH = heightR;
        }
        if(tmpH > heightM)
            tmp = m;
          }
      }

        public TernaryTree<T> Intersection(Tree<T> tree) throws ExceptionHandler {
            if(tree instanceof TernaryTree) {
            	TernaryTree<T> tmp = (TernaryTree<T>)tree;
        	List<T> list = new ArrayList<T>();
        	IterateOverList(list , root , tmp.getRoot());
        	return InsertOnIntersectionList(list);
	    }
	    else
                throw new ExceptionHandler("can't intersect incompatible trees");
        }

 public int getHeight(TernaryNode<T> node) {
          if(node == null) { return 0; }
          else { return 1 + getHeight(node.getLeft()) + getHeight(node.getRight()) + getHeight(node.getMiddle()); }
      }
	private void helpSumMiddle(List<Info<T>> list , TernaryNode<T> node) {
		if(node == null)
			return;
		TernaryNode<T> aux = node.getMiddle();
		if(aux != null)
			list.add(aux.getVal());
		helpSumMiddle(list , node.getLeft());
		helpSumMiddle(list , node.getRight());
		helpSumMiddle(list , node.getMiddle());
	}
	private <T> void printTernary(TernaryNode<T> node , PrintWriter out , String path) {
		if(node == null) 
			return;
			if(node.getLeft() != null) 
				out.print(path + "l " + node.getLeft().getInfo());
			if(node.getRight() != null) 
				out.print(" " + path + "r " + node.getRight().getInfo());
			if(node.getMiddle() != null) 
				out.print(" " + path + "m " + node.getMiddle().getInfo());
			if(node.getLeft() != null || node.getRight() != null || node.getMiddle() != null)
				out.println();
			printTernary(node.getLeft() , out , path + "l");
			printTernary(node.getRight() , out , path + "r");
			printTernary(node.getMiddle() , out , path + "m");
	}
	public void print(String mess , boolean append) {
		PrintWriter out = null;
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("Use.txt" , append)));
		} catch(IOException ecc) { System.out.println("file not found");System.exit(0); }
		out.println();
		if(mess != null)
			out.println(mess);
		out.println("Ternary Tree");
		out.println("root : " + root.getInfo());
		printTernary(root,out,"");
		out.println();
		out.close();
	}
}
