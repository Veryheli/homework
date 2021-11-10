template<class T>
void Bitree<T>::shiftChilds(node<T> *bt)
{
    if(bt == NULL) return;
    node<T> * temp = bt->lchild;
    bt->lchild = bt->rchild;
    bt->rchild = temp;
    shiftChilds(bt->lchild);
    shiftChilds(bt->rchild);
}
