import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class Use {
	public static void main(String[] args) {
		BinaryNode<Integer> Root = new BinaryNode<Integer>(new Info<Integer>(6) , null , null);
		BinaryNode<Integer> Left = new BinaryNode<Integer>(new Info<Integer>(24) , null , null);
		Root.setLeft(Left);
		BinaryTree<Integer> TreeB = new BinaryTree<Integer>(Root);

		RedBlackNode<Integer> R01 = new RedBlackNode<Integer>(false , new Info<Integer>(55) , null , null);
		RedBlackNode<Integer> l01 = new RedBlackNode<Integer>(true , new Info<Integer>(0) , null , null);
		RedBlackNode<Integer> r01 = new RedBlackNode<Integer>(true , new Info<Integer>(17) , null , null);
		RedBlackNode<Integer> ll01 = new RedBlackNode<Integer>(false , new Info<Integer>(32) , null , null);
		RedBlackNode<Integer> rr01 = new RedBlackNode<Integer>(false , new Info<Integer>(0) , null , null);
		RedBlackNode<Integer> rl01 = new RedBlackNode<Integer>(false , new Info<Integer>(7) , null , null);
		R01.setChildren(l01 , r01);
		l01.setLeft(ll01);
		r01.setChildren(rl01,rr01);
		RedBlackTree<Integer> T01 = new RedBlackTree<Integer>(R01);

		RedBlackNode<Integer> R0 = new RedBlackNode<Integer>(false , new Info<Integer>(55) , null , null);
		RedBlackNode<Integer> l0 = new RedBlackNode<Integer>(true , new Info<Integer>(5) , null , null);
		RedBlackNode<Integer> r0 = new RedBlackNode<Integer>(true , new Info<Integer>(17) , null , null);
		RedBlackNode<Integer> ll0 = new RedBlackNode<Integer>(false , new Info<Integer>(32) , null , null);
		RedBlackNode<Integer> rr0 = new RedBlackNode<Integer>(false , new Info<Integer>(6) , null , null);
		RedBlackNode<Integer> rl0 = new RedBlackNode<Integer>(false , new Info<Integer>(7) , null , null);
		R0.setChildren(l0 , r0);
		l0.setLeft(ll0);
		r0.setChildren(rl0,rr0);
		RedBlackTree<Integer> T0 = new RedBlackTree<Integer>(R0);

		BinaryNode<Integer> R = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> l = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> r = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> ll = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> lr = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> rl = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		BinaryNode<Integer> rr = new BinaryNode<Integer>(new Info<Integer>(0) , null , null);
		List<Integer> inputNodes = new ArrayList<Integer>();
		R.setChildren(l,r);
		l.setChildren(ll,lr);
		r.setChildren(rl,rr);
		inputNodes.add(33);
		inputNodes.add(51);
		inputNodes.add(9);
		inputNodes.add(8);
		inputNodes.add(3);
		inputNodes.add(6);
		inputNodes.add(32);

		BinaryTree<Integer> tree = new BinaryTree<Integer>(R);
		tree.insertValues(inputNodes);

		TernaryNode<Integer> t_R = new TernaryNode<Integer>(new Info<Integer>(4) , null , null , null);
		TernaryNode<Integer> t_l = new TernaryNode<Integer>(new Info<Integer>(73) , null , null , null);
		TernaryNode<Integer> t_r = new TernaryNode<Integer>(new Info<Integer>(12) , null , null , null);
		TernaryNode<Integer> t_rm = new TernaryNode<Integer>(new Info<Integer>(112) , null , null , null);
		TernaryNode<Integer> t_m = new TernaryNode<Integer>(new Info<Integer>(113) , null , null , null);
		TernaryNode<Integer> t_rl = new TernaryNode<Integer>(new Info<Integer>(19) , null , null , null);
		TernaryNode<Integer> t_rr = new TernaryNode<Integer>(new Info<Integer>(8) , null , null , null);
		t_R.setChildren(t_l,t_r,t_m);
		t_r.setLeft(t_rl);
		t_r.setRight(t_rr);
		t_r.setMiddle(t_rm);
		TernaryTree<Integer> treeTernary = new TernaryTree<Integer>(t_R);

		TernaryNode<Integer> R3 = new TernaryNode<Integer>(new Info<Integer>(12) , null , null , null);
		TernaryNode<Integer> m3 = new TernaryNode<Integer>(new Info<Integer>(113) , null , null , null);
		TernaryNode<Integer> l3 = new TernaryNode<Integer>(new Info<Integer>(9) , null , null , null);
		TernaryNode<Integer> lm3 = new TernaryNode<Integer>(new Info<Integer>(9) , null , null , null);
		TernaryNode<Integer> r3 = new TernaryNode<Integer>(new Info<Integer>(1) , null , null , null);
		R3.setChildren(l3,r3,m3);
		l3.setMiddle(lm3);
		TernaryTree<Integer> T3 = new TernaryTree<Integer>(R3);

		List<Info<Integer>> list = tree.sumValues();
		List<Info<Integer>> listTernary = treeTernary.sumValues();
		PrintWriter out = null;
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("Use.txt" , true)));
			tree.print("binaryT-1" , false);
			T0.print("RedBlackT-0" , true);
			treeTernary.print("ternaryT-2" , true);
			TreeB.print("binaryT-3" , true);	
			T3.print("ternaryT-4" , true);
			T01.print("RedBlackT-5" , true);
			Tree<Integer> x = T01.Intersection(T0);
			x.print("Intersection T-5 and T-0 : " , true);
			Tree<Integer> SumTernary = treeTernary.Sum(T3);
			Tree<Integer> nuovoTree = tree.Sum(TreeB);
			Info<Integer> tot = new Info<Integer>(0);
			Integer res = new Integer(0);
			for(Info<Integer> tmp : list) {
				res += tot.addInt(tmp); 
			}
			BinaryTree<Integer> rotation = tree.Rotation();
			rotation.print("Rotation on T-1 : " , true);
			out.println();
			out.print("sumValues on T-1 Tree : " + res);
			res = 0;
			tot.setInfo(0);
			out.println();
			List<Info<Integer>> listSBN = T01.SumBlackNodes();
			for(Info<Integer> tmp : listSBN)
				res += tot.addInt(tmp);
			out.print("SumBlackNodes on T-5 Tree : " + res);
			out.println();
			res = 0;
			tot.setInfo(0);
			out.println();
			List<Info<Integer>> listSRN = T01.SumRedNodes();
			for(Info<Integer> tmp : listSRN) {
				res += tot.addInt(tmp); 
			}
			out.print("SumRedNodes on T-5 Tree : " + res);
			out.println();
			out.print("sumValues on T-2 Tree : " + res);
			out.println();
			List<Info<Integer>> listSM = T3.SumMiddle();
			res = 0;
			tot.setInfo(0);
			for(Info<Integer> tmp : listSM)
				res += tot.addInt(tmp);
			out.print("SumMiddle on T-4 Tree : " + res);
			out.println();
			out.println("BlackHeight on T0 : " + T0.getBlackHeight(T0.getRoot())); 
			out.println();
			SumTernary.print("Sum between T-2 and T-4 : " , true);
			out.println();
			nuovoTree.print("Sum between T-1 and T-3 : " , true);
			out.println("try to intersect T-0 and T-1 ....");
			Tree<Integer> IntersectBin = T0.Intersection(tree);
		} catch(IllegalArgumentException ecc) {
			ecc.printStackTrace();
			System.exit(0);
		}
		catch(ExceptionHandler ecc) { out.println(ecc.what()); }
		catch(IOException ecc) { System.out.println("file not found");System.exit(0); }
		out.close();
	}
}
