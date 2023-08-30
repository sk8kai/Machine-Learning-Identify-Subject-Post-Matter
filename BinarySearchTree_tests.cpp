// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"

// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <sstream>
//do we need? V
#include <functional>

using namespace std;


TEST(bst_public_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);

  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_TRUE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);

  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 7);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(5) == 7);
    //CHECK ABOVE FUNC A LOTm this only tests one branch of what it could call 

  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "5 3 7 ");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 5 7 ");
}


TEST(test_height) {
    BinarySearchTree<int> tree;
    
    tree.insert(5);
    tree.insert(7);
    //will the height be 2 here?
    ASSERT_EQUAL(tree.height(), 2);
    tree.insert(6);
    ASSERT_EQUAL(tree.height(), 3);
    tree.insert(8);
    ASSERT_EQUAL(tree.height(), 3);
    tree.insert(4);
    ASSERT_EQUAL(tree.height(), 3);
}

TEST(test_size_and_empty) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    
    //would prob be good if we tested this on the other side, ex
    //8,7,6 going down to make sure it rememebrs everything
    //DO THIS
    
    ASSERT_EQUAL(tree.size(), 3);
    ASSERT_FALSE(tree.empty());
    
    BinarySearchTree<int> tree2;
    ASSERT_TRUE(tree2.empty());  //u originally just had tree here, i think u meant 2
    
    tree2.insert(8);
    tree2.insert(7);
    tree2.insert(5);
    tree2.insert(6);
    
    ASSERT_EQUAL(tree2.size(), 4);
    
    cout << endl;
    cout << tree2.to_string() << endl;
    cout << "we did it!" << endl;
    
    
}

TEST(test_checksortinginv) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    
    ASSERT_TRUE(tree.check_sorting_invariant());
    
}

TEST(find_impl ) {
    BinarySearchTree<int> tree;
    tree.insert(9);
    tree.insert(7);
    tree.insert(3);
    
    ASSERT_TRUE(tree.find(7) != tree.end());
    ASSERT_TRUE(tree.find(3) == tree.begin());
    //id like to test for find(9) here too but idk how
    
    BinarySearchTree<int> tree2;
    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(9);
    ASSERT_TRUE(tree.find(11) == tree.end());
    
}
TEST(insert_impl ) {
    BinarySearchTree<int> tree;
    tree.insert(7);
    tree.insert(9);
    cout << tree << endl;
    BinarySearchTree<int> tree2;
    tree2.insert(11);
    tree2.insert(9);
    cout << tree2 << endl;
}

TEST(check_sorting_invariant_left) {
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    *tree.begin() = 6;
    
    ASSERT_FALSE(tree.check_sorting_invariant());
    
    *tree.begin() = 3;
    ASSERT_TRUE(tree.check_sorting_invariant());
    *(++tree.begin()) = 6;
    ASSERT_FALSE(tree.check_sorting_invariant());
    
    
    *(++tree.begin()) = 4;
}
TEST(check_sorting_invariant_right) {
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(7);
    ASSERT_TRUE(tree.check_sorting_invariant());
    *tree.find(6) = 9;
    ASSERT_FALSE(tree.check_sorting_invariant());
    *tree.find(9) = 6;
    ASSERT_TRUE(tree.check_sorting_invariant());
    *tree.find(7) = 1;
    ASSERT_FALSE(tree.check_sorting_invariant());
    
    //this causes an error
    //find function trys to look to the left but its not there since it was in 7 position
    //*tree.find(1) = 7;
    //ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(min_val_greater_than_test) {
    BinarySearchTree<int> tree;
    int val = 6;
    ASSERT_EQUAL(tree.min_greater_than(val), tree.end());  //not sure how to struc this
    tree.insert(12);
    tree.insert(7);
    tree.insert(33);
    tree.insert(5);
    tree.insert(11);
    tree.insert(6);
    cout << tree << endl;
    ASSERT_EQUAL(*tree.min_greater_than(val), 7);
    val = 33;
    ASSERT_EQUAL(tree.min_greater_than(val), tree.end());
    val = 32;
    ASSERT_EQUAL(*tree.min_greater_than(val), 33);
    
    BinarySearchTree<int> tree2;
    tree2.insert(12);
    ASSERT_EQUAL(*tree2.min_greater_than(6), 12);
    tree2.insert(7);
    ASSERT_EQUAL(*tree2.min_greater_than(6), 7);
    tree2.insert(6);
    ASSERT_EQUAL(*tree2.min_greater_than(6), 7);
    
    
    
}
TEST_MAIN()

