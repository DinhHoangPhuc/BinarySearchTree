#include"Queue.h"
#include"asciinode.h"
#include<stdio.h>
#include<conio.h>

void main()
{
	int luachon;
	do
	{
		do
		{
			printf("\n");
			printf("------------------------------MENU------------------------------\n");
			printf("1. Xuat cay nhi phan tim kiem ra man hinh(doc tu file)\n");
			printf("2. Xoa Node co gia tri X ra khoi cay nhi phan tim kiem\n");
			printf("3. Duyet cay theo chieu rong\n");
			printf("4. Duyet cay theo chieu sau\n");
			printf("0. Ket thuc chuong trinh\n");
			printf("Nhap lua chon cua ban: ");
			scanf_s("%d", &luachon);
		} while (luachon < 0);

		switch (luachon)
		{
		case 1:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			print_ascii_tree(bt.root);
			break;
		}

		case 2:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			printf("Cay NPTK hien tai:\n");
			print_ascii_tree(bt.root);
			int x;
			printf("Nhap so can xoa: ");
			scanf("%d", &x);
			if(deleteTNodeX(bt.root, x) == 1)
			{
				printf("Cay NPTK sau khi xoa %d:\n", x);
				print_ascii_tree(bt.root);
			}
			else
				printf("Khong tim thay %d\n", x);
			break;
		}

		case 3:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			print_ascii_tree(bt.root);
			duyetTheoChieuRong(bt.root);
			break;
		}

		case 4:
		{
			BSTree bt;
			initBTree(bt);
			createBSTree(bt.root);
			print_ascii_tree(bt.root);
			duyetTheoChieuSau(bt.root);
			break;
		}

		default:
			break;
		}
	} while (luachon > 0 && luachon <= 4);
}