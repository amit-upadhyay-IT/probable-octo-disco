class TreeNode
{
	public int data;
	public TreeNode left;
	public TreeNode right;
	
	public TreeNode(int data)
	{
		this.data = data;
		left = right = null;
	}

}

class BinaryTree
{
	public TreeNode insert(TreeNode root, int data)
	{
		// case 1, when tree is empty
		if (root == null)
			root = new TreeNode(data);
		// case 2, data is small
		else if (data < root.data)
			root.left = insert(root.left, data);
		// case 3, data is more
		else if (data > root.data)
			root.right = insert(root.right, data);
		return root;
	}
	
	public void inorder(TreeNode root)
	{
		if (root != null)
		{
			inorder(root.left);
			System.out.printf("%d ",root.data);
			inorder(root.right);
		}
	}
	
	public int getLevel(TreeNode root, int key, int level)
	{
		if (root != null)
		{
			if (root.data == key)
				return level;
			int ll = getLevel(root.left, key, level+1);
			if (ll != -1)
				return ll;
			return getLevel(root.right, key, level+1);
		}
		else // root == null
			return -1;
	}
}

public class ProblemTen {

	public static void main(String[] args) {
		
		TreeNode root = null;
		int level = 1;
		
		BinaryTree bt = new BinaryTree();
		root = bt.insert(root, 50);
		root = bt.insert(root, 40);
		root = bt.insert(root, 60);
		root = bt.insert(root, 55);
		root = bt.insert(root, 45);
		root = bt.insert(root, 150);
		
		//bt.inorder(root);
		
		int keyLevel = bt.getLevel(root, 55, level);
		
		System.out.println(keyLevel);
		

	}

}

