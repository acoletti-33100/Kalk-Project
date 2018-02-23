import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public final class RedBlackTree<T> extends BinaryTree<T> {

	public RedBlackTree(RedBlackNode<T> root) {
		super(root);
	}
	public RedBlackNode<T> getRoot()  { return (RedBlackNode<T>)super.getRoot(); }
	private <T> void printRBBinary(RedBlackNode<T> node , PrintWriter out , String path) {
		if(node == null) 
			return;
			if(node.getLeft() != null) 
				out.print(path + "l " + node.getLeft().getInfo() + " " + node.getLeft().getColor());
			if(node.getRight() != null) 
				out.print(" " + path + "r " + node.getRight().getInfo() + " " + node.getRight().getColor());
			if(node.getLeft() != null || node.getRight() != null)
				out.println(); 
			printRBBinary(node.getLeft() , out , path + "l");
			printRBBinary(node.getRight() , out , path + "r");
	}
	public void print(String mess , boolean append) {
		PrintWriter out = null;
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("Use.txt" , append)));
		} catch(IOException ecc) { System.out.println("file not found");System.exit(0); }
		out.println();
		if(mess != null)
			out.println(mess);
		out.println("RedBlackBinary Tree");
		out.println("root : " + getRoot().getInfo() + " " + getRoot().getColor());
		printRBBinary(getRoot(),out,"");
		out.println();
		out.close();
	}

	public RedBlackTree<T> Rotation()throws ExceptionHandler {
		RedBlackNode<T> auxRoot = getRoot();
		if(auxRoot == null || auxRoot.getRight() == null)
			throw new ExceptionHandler("Can't perform rotation on this tree");
		RedBlackNode<T> resultRoot = RotationHelp();
		return (new RedBlackTree<T>(resultRoot));
	}

	protected RedBlackNode<T> RotationHelp() {
		RedBlackNode<T> resultRoot = copyNodeOnly(getRoot());
		RotationRec(resultRoot , getRoot());
		return resultRoot;
	}

	private void RotationRec(RedBlackNode<T> node , RedBlackNode<T> aux) {
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

	private RedBlackNode<T> copyNodeOnly(RedBlackNode<T> node) {
		if(node == null)
			return null;
		return new RedBlackNode<T>(node.getBooleanColor() , node.getVal() , null , null);
	}

	public List<Info<T>> SumBlackNodes() { 
		List<Info<T>> list = new ArrayList<Info<T>>();
		SumIfColor(false,getRoot(),list);	
		return list;
	}

	public List<Info<T>> SumRedNodes() { 
		List<Info<T>> list = new ArrayList<Info<T>>();
		SumIfColor(true,getRoot(),list);	
		return list;
	}

	private void SumIfColor(boolean color , RedBlackNode<T> node , List<Info<T>> list) {
		if(node == null)
			return;
		if(node.getBooleanColor() == color)  
			list.add(node.getVal());
		SumIfColor(color , node.getLeft() , list);
		SumIfColor(color , node.getRight() , list);
	}

private RedBlackNode<T> copyColor(RedBlackNode<T> node) {
    if(node == null)
        return null;
    return new RedBlackNode<T>(node.getBooleanColor() , node.getVal() , copyColor(node.getLeft()) , copyColor(node.getRight()));
}

private RedBlackNode<T> copyBinary(BinaryNode<T> node) {
    if(node == null)
        return null;
    return new RedBlackNode<T>(false , node.getVal() , copyBinary(node.getLeft()) , copyBinary(node.getRight()));
}

    int getRedCount(RedBlackNode<T> node)  {
        if(node == null)
            return 0;
        if(node.hasBlack())
            return getRedCount(node.getLeft()) + getRedCount(node.getRight());
        else
            return 1 + getRedCount(node.getLeft()) + getRedCount(node.getRight());
    }

public RedBlackTree<T> Sum(Tree<T> tree) throws ExceptionHandler {
    RedBlackNode<T> operand = null;
    if(!(tree instanceof RedBlackTree)) {
        if(!(tree instanceof BinaryTree))
            throw new ExceptionHandler("can't sum incompatible trees");
        else {
            operand = copyBinary(super.getRoot());
        }
    }
    else {
        operand = copyColor(((RedBlackTree<T>)tree).getRoot());
    }
    RedBlackNode<T> resultRoot = copyColor(getRoot());
    RedBlackTree<T> resultTree = new RedBlackTree<T>(resultRoot);
    insertRBTBalanced(resultRoot , operand);
    return resultTree;
}


private void insertRBTBalanced(RedBlackNode<T> tmp , RedBlackNode<T> node) {
    while(tmp != null) {
  RedBlackNode<T> l = tmp.getLeft() , r = tmp.getRight();
  if(l == null) {
      tmp.setLeft(node);
      return;
  }
  if(r == null) {
      tmp.setRight(node);
      return;
  }
  if(super.getHeight(l) <= super.getHeight(r))
      tmp = l;
  else
      tmp = r;

    }
}

public RedBlackTree<T> Intersection( Tree<T> tree) throws ExceptionHandler {
    if(!(tree instanceof RedBlackTree)) {
        if(!(tree instanceof BinaryTree))
            throw new ExceptionHandler("can't intersect incompatible trees");
        else {
            BinaryTree<T> binary = super.Intersection(tree);
            return (new RedBlackTree<T>(copyBinary(binary.getRoot())));
        }
    }
    else {
        List<T> list = new ArrayList<T>();
        List<Boolean> colorList = new ArrayList<Boolean>();
        IterateOver(colorList , list , getRoot() , ((RedBlackTree<T>)tree).getRoot());
        return InsertOnIntersectionList(colorList , list);
    }
}


private void IterateOver(List<Boolean> colorList , List<T> list , RedBlackNode<T> iterable , RedBlackNode<T> fixed) {
    if(iterable == null)
        return;
    InsertIfEquals(colorList , list , iterable , fixed);
    IterateOver(colorList , list , iterable.getLeft() , fixed);
    IterateOver(colorList , list , iterable.getRight() , fixed);
}

private void InsertIfEquals(List<Boolean> colorList , List<T> list , RedBlackNode<T> fixed , RedBlackNode<T> iterable) {
    if(iterable == null)
        return;
    if(fixed.getInfo() == iterable.getInfo() && fixed.getBooleanColor() == iterable.getBooleanColor())
         { list.add(fixed.getInfo());colorList.add(fixed.getBooleanColor()); }
    InsertIfEquals(colorList , list , fixed , iterable.getLeft());
    InsertIfEquals(colorList , list , fixed , iterable.getRight());
}

private RedBlackTree<T> InsertOnIntersectionList(List<Boolean> colorList ,  List<T> list) throws ExceptionHandler {
    int dim = list.size();
    int dimC = colorList.size();
    if(dim > 0 && dimC > 0) {
      RedBlackNode<T> Root = new RedBlackNode<T>(colorList.get(0) , new Info<T>(list.get(0)) , null , null);
    for(int i = 1; i < dim && i < dimC; i++) {
        RedBlackNode<T> aux = new RedBlackNode<T>(colorList.get(i) , new Info<T>(list.get(i)) , null , null);
        insertRBTBalanced(Root , aux);
    }
    return (new RedBlackTree<T>(Root));
    }
    else
	    throw new ExceptionHandler("empty Intersection");
}

        public int getBlackHeight(RedBlackNode<T> node)  {
        if(node == null)
            return 0;
        else {
            int countL = getBlackHeight(node.getLeft()) , countR = getBlackHeight(node.getRight());
            if(countL == -1 || countR == -1 || (countL != countR && countL != 0 && countR != 0))
                return -1;
            else {
                int count = 0;
                if(countL <= countR) 
			count = countR;
		else 
			count = countL;
                if(node.hasBlack())
                    return (count + 1);
                else
                    return count;
            }
        }
        }
}
