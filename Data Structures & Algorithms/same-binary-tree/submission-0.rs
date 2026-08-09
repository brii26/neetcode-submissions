// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//     pub val: i32,
//     pub left: Option<Rc<RefCell<TreeNode>>>,
//     pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         TreeNode {
//             val,
//             left: None,
//             right: None,
//         }
//     }
// }

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if p.is_none() && q.is_none(){
            return true;
        } 

        if p.is_none() || q.is_none() {
            return false;
        }

        let p = p.unwrap();
        let q = q.unwrap();
        let p_borrow = p.borrow();
        let q_borrow = q.borrow();

        if p_borrow.val != q_borrow.val {
            return false
        }

        Self::is_same_tree(p_borrow.right.clone(),q_borrow.right.clone()) && 
        Self::is_same_tree(p_borrow.left.clone(),q_borrow.left.clone())
    }
}
