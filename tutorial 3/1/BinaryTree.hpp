#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree() {
            numChildren = 0;
        }
        // Copy constructor
        BinaryTree(const BinaryTree<T>& other) {
            value = other.value;
            children = other.children;
            numChildren = other.numChildren;
        }
        // Destruktor
        ~BinaryTree() {}

        // Setter untuk value
        void setValue(const T & v) {
            value = v;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T v) {
            if (numChildren == 2) {
                throw "Tidak bisa memiliki lebih dari dua children\n";
            }
            else {
                children.push_back(BinaryTree<T>());
                numChildren++;
                children.back().setValue(v);
                return children.back();
            }
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& os, BinaryTree<T> t) {
            os << t.value;
            if (t.numChildren > 0) {
                os << "(" << t.children[0] << ")";
            }
            else {
                os << "()";
            }

            if (t.numChildren > 1) {
                os << "(" << t.children[1] << ")";
            }
            else {
                os << "()";
            }
            return os;

        }
};

#endif
