/**
 * @BelongsProject: Others
 * @Author: yuan wang
 * @CreateTime: 2023-08-07  17:36
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * 将src座上的n个盘子，以mid座为中转，移动到dest座
 * @param n
 * @param src
 * @param mid
 * @param dest
 */
void Hanoi(int n, char src, char mid, char dest) {
    if (n == 1) {
        //到了最后一个盘子，只需将其直接从src移动到dest即可
        cout << src << "->" << dest << endl;
        //递归中止，由于是void，直接写一个return即可
        return;
    }
    //先将n-1个盘子从src移动到mid
    Hanoi(n - 1, src, dest, mid);
    //再将一个盘子从src移动到dest
    cout << src << "->" << dest << endl;
    //最后将n-1个盘子从mid移动到dest
    Hanoi(n - 1, mid, src, dest);
    return;
}

/**
 * @description: 汉罗塔问题
 * @author: yuan wang
 * @date: 2023/08/07 17:36
 * @param: null
 * @return: null
 */
int main() {
    int n;
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
