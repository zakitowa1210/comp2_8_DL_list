#pragma once // インクルードガード

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

typedef struct node {
	struct node* pNext;
	struct node* pPrev;
	int data;
}node;

typedef struct list {
	struct node* header;
	struct node* footer;
}list;

void initialize_node(node *p, int val);// ノードを初期化
void initialize_list(list* l);// リストを初期化

void push_front(list* l, node* p);// 先頭にデータを追加
void push_back(list* l, node* p); // 末尾にデータを追加

void remove_node(list* l, node* p); // pのノードを削除
void remove_next(list* l, node* p); // pの次のノードを削除
void remove_prev(list* l, node* p); // pの前のノードを削除

node* get_next(list* l, node* p); // pの次のノードを取得(無ければNULL)
node* get_prev(list* l, node* p); // pの前のノードを取得(無ければNULL)


// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
