#include "pch.h"
#include "CppUnitTest.h"

#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(初期化)
	{
	public:

		TEST_METHOD(リストの初期化)
		{
			list lst;
			initialize_list(&lst);

			Assert::IsNull(lst.header);
			Assert::IsNull(lst.footer);
		}

		TEST_METHOD(ノードの初期化)
		{
			node n;
			initialize_node(&n, 1);

			Assert::IsNull(n.pNext);
			Assert::IsNull(n.pPrev);
			Assert::AreEqual(1, n.data);
		}
	};

	TEST_CLASS(要素の取得)
	{
	public:

		TEST_METHOD(NULLの次はNULL)
		{
			list lst;
			initialize_list(&lst);

			Assert::IsNull(get_next(&lst, NULL));
		}

		TEST_METHOD(NULLの前はNULL)
		{
			list lst;
			initialize_list(&lst);

			Assert::IsNull(get_prev(&lst, NULL));
		}
	};

	TEST_CLASS(追加)
	{
	public:

		TEST_METHOD(一番前に追加（一要素）)
		{
			list lst;
			initialize_list(&lst);

			node n;
			initialize_node(&n, 12);

			push_front(&lst, &n);

			node* p = lst.header;
			Assert::AreEqual((void*)&n, (void*)p);
			Assert::AreEqual(p->data, 12);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n, (void*)p);
			Assert::AreEqual(p->data, 12);
			Assert::IsNull(get_next(&lst, p));
		}

		TEST_METHOD(一番後ろに追加（一要素）)
		{
			list lst;
			initialize_list(&lst);

			node n;
			initialize_node(&n, 123);

			push_back(&lst, &n);

			node* p = lst.header;
			Assert::AreEqual((void*)&n, (void*)p);
			Assert::AreEqual(p->data, 123);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n, (void*)p);
			Assert::AreEqual(p->data, 123);
			Assert::IsNull(get_next(&lst, p));
		}

		TEST_METHOD(一番前に追加（三要素）)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 124);
			initialize_node(&n1, 125);
			initialize_node(&n2, 126);

			push_front(&lst, &n0);
			push_front(&lst, &n1);
			push_front(&lst, &n2);

			node* p = lst.header;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 126);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 125);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 124);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 124);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 125);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 126);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(一番後ろに追加（三要素）)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 134);
			initialize_node(&n1, 135);
			initialize_node(&n2, 136);

			push_back(&lst, &n0);
			push_back(&lst, &n1);
			push_back(&lst, &n2);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 134);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 135);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 136);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 136);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 135);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 134);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(混合して追加（三要素）)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 144);
			initialize_node(&n1, 145);
			initialize_node(&n2, 146);

			push_back(&lst, &n0);
			push_front(&lst, &n1);
			push_back(&lst, &n2);

			node* p = lst.header;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 145);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 144);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 146);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 146);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 144);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 145);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(混合して追加の別順（三要素）)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 154);
			initialize_node(&n1, 155);
			initialize_node(&n2, 156);

			push_front(&lst, &n0);
			push_back(&lst, &n1);
			push_front(&lst, &n2);

			node* p = lst.header;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 156);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 154);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 155);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 155);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 154);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 156);
			Assert::IsNull(get_prev(&lst, p));
		}
	};

	TEST_CLASS(次の要素を削除)
	{
	public:
		TEST_METHOD(二つの要素で二つ目の要素を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1;
			initialize_node(&n0, 1234);
			initialize_node(&n1, 1235);

			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n0);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1234);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1234);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の中央を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1245);
			initialize_node(&n1, 1246);
			initialize_node(&n2, 1247);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, lst.header);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1245);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1247);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1247);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1245);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の末尾を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1255);
			initialize_node(&n1, 1256);
			initialize_node(&n2, 1257);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n1);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1255);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1256);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1256);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1255);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の末尾の後ろを削除しようとする)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1265);
			initialize_node(&n1, 1266);
			initialize_node(&n2, 1267);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n2);

			// 変更がないべき
			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1265);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1266);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1267);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1267);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1266);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1265);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の二つを削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1275);
			initialize_node(&n1, 1276);
			initialize_node(&n2, 1277);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, lst.header);
			remove_next(&lst, lst.header);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1275);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1275);
			Assert::IsNull(get_prev(&lst, p));
		}
	};


	TEST_CLASS(その要素を削除)
	{
	public:

		TEST_METHOD(一つの要素を削除)
		{
			list lst;
			initialize_list(&lst);

			node n;
			initialize_node(&n, 12345);

			push_front(&lst, &n);

			remove_node(&lst, &n);

			// ヘッダーに何もなくなった
			Assert::IsNull(lst.header);
			Assert::IsNull(lst.footer);
		}

		TEST_METHOD(三つの要素の先頭を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 12345);
			initialize_node(&n1, 12346);
			initialize_node(&n2, 12347);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_node(&lst, lst.header);

			node* p = lst.header;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 12346);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 12347);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 12347);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 12346);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の中央を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 12345);
			initialize_node(&n1, 12346);
			initialize_node(&n2, 12347);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_node(&lst, &n1);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 12345);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 12347);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 12347);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 12345);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の末尾を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 12345);
			initialize_node(&n1, 12346);
			initialize_node(&n2, 12347);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_node(&lst, lst.footer);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 12345);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 12346);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 12346);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 12345);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の全てを削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 12345);
			initialize_node(&n1, 12346);
			initialize_node(&n2, 12347);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_node(&lst, lst.footer);
			remove_node(&lst, lst.header);
			remove_node(&lst, &n1);

			Assert::IsNull(lst.header);
			Assert::IsNull(lst.footer);
		}
	};

	TEST_CLASS(前の要素を削除)
	{
	public:
		TEST_METHOD(二つの要素で一つ目の要素を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1;
			initialize_node(&n0, 123456);
			initialize_node(&n1, 123457);

			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_prev(&lst, &n1);

			node* p = lst.header;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123457);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123457);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の中央を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 123466);
			initialize_node(&n1, 123467);
			initialize_node(&n2, 123468);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_prev(&lst, lst.footer);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 123466);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123468);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123468);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 123466);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の先頭を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 123476);
			initialize_node(&n1, 123477);
			initialize_node(&n2, 123478);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_prev(&lst, &n1);

			node* p = lst.header;
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123477);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123478);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123478);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123477);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の先頭の前を削除しようとする)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 123486);
			initialize_node(&n1, 123487);
			initialize_node(&n2, 123488);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_prev(&lst, &n0);

			// 変更がないべき
			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 123486);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123487);
			p = get_next(&lst, p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123488);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123488);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 123487);
			p = get_prev(&lst, p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 123486);
			Assert::IsNull(get_prev(&lst, p));
		}

		TEST_METHOD(三つの要素の二つを削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 123496);
			initialize_node(&n1, 123497);
			initialize_node(&n2, 123498);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_prev(&lst, lst.footer);
			remove_prev(&lst, lst.footer);

			node* p = lst.header;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123498);
			Assert::IsNull(get_next(&lst, p));

			p = lst.footer;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 123498);
			Assert::IsNull(get_prev(&lst, p));
		}
	};
}
