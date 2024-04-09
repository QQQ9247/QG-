#define _CRT_SECURE_NO_WARNINGS
#include "辅助函数.h"
#include "树.h"
vector<int> a;
vector<int> result;
vector<vector<int>> res;
TreeNode* tree = NULL;
TreeNode* p = NULL;
int main()
{
	int n,m;
	char c;
	displaymenu(sel);
	for (;;) {
		if (_kbhit) {
			if (GetAsyncKeyState((VK_UP))) {
				sel = (sel > 1) ? sel - 1 : sel;
				displaymenu(sel);
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				sel = (sel < 12) ? sel + 1 : sel;
				displaymenu(sel);
			}
			c = _getch();
			if (c <= 'z' && c >= 'a') c = c - ('a' - 'A');
			if (c <= 'G' && c >= 'A') {
				sel = c - 'A' + 1;
				displaymenu(sel);
				GoToxy(36, 22);
				printf("command is [%c] 按回车确认!", c);
			}
			else if (c == '\r') {
				if (sel == 12) return 0;
				displaymenu(sel);
				printf("command is [%c]\n", 'A' + sel - 1);
				system("cls");
				switch (sel)
				{
				case 1:
					printf("请输入节点个数：");
					scanf("%d", &n);
					printf("\n请输入%d个节点：", n);
					for (int i = 0; i < n; i++) { cin >> m; a.push_back(m); }
					sort(a.begin(), a.end());
					tree = sortedArrayToBST(a);
					printf("\n构建成功！\n");
					clear();
					break;
				case 2:
					printf("请输入需要插入的节点：");
					scanf("%d", &n);
					tree = insertIntoBST(tree, n);
					clear();
					break;
				case 3:
					printf("请输入需要查找的节点：");
					scanf("%d", &n);
					if (!(p=find(tree, n))) printf("未找到该节点！\n");
					else printf("节点存在！");
					clear();
					break;
				case 4:
					printf("请输入需要删除的节点：");
					scanf("%d", &n);
					tree = deleteNode(tree, n);
					clear();
					break;
				case 5:
					result.clear();
					preorderTraversal2(tree, result);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 6:
					result.clear();
					inorderTraversal12(tree, result);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 7:
					result.clear();
					postorderTraversal2(tree, result);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 8:
					result.clear();
					result = preorderTraversal1(tree);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 9:
					result.clear();
					result = inorderTraversal1(tree);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 10:
					result.clear();
					result = postorderTraversal1(tree);
					printf("结果为：");
					for (int i : result) {
						cout << i << ' ';
					}
					printf("\n");
					clear();
					break;
				case 11:
					res = levelOrder(tree);
					printf("结果为：");
					for (int i = 0; i < res.size(); ++i) {
						for (int j = 0; j < res[i].size(); ++j) {
							cout << res[i][j] << ' ';
						}
					}
					printf("\n");
					clear();
					break;
					/*case 12:

						break;
					case 13:
						clear();
						break;*/
				}
			}
			else if (c == 'Q')
				return 0;
			Sleep(100);
		}
	}
	return 0;
}
