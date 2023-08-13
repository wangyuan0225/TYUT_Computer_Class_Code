/**
 * @BelongsProject: Bailian09B_force_B
 * @Author: yuan wang
 * @CreateTime: 2023-08-13  11:41
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>
using namespace std;
char oriLights[5];
char lights[5];
char result[5];

/**
 * 取字符 c 的第 i 个比特
 * @param c 字符 c
 * @param i 第 i 位
 * @return 字符 c 的第 i 个比特
 */
int GetBit(char c, int i){
    return (c >> i) & 1;
}

/**
 * 设置字符 c 的第 i 个比特为 v
 * @param c 字符 c
 * @param i 第 i 位
 * @param v 需要设置的0/1
 */
void SetBit(char & c, int i, int v) {
    if (v) {
        c |= (1 << i);
    } else {
        c &= ~(1 << i);
    }
}

/**
 * 反转 c 的第 i 位比特
 * @param c
 * @param i
 */
void FlipBit(char & c, int i) {
    c ^= (1 << i);
}

/**
 * 输出结果
 * @param t
 * @param result
 */
void OutputResult(int t, char result[]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << GetBit(result[i], j);
            if (j < 5) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/**
 * @description: 熄灯问题
 * @author: yuan wang
 * @date: 2023/08/13 11:41
 * @param: null
 * @return: null
 */
int main() {
    int T = 1;
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                int s;
                cin >> s;
                SetBit(oriLights[i], j, s);
            }
        }
        for (int n = 0; n < 64; ++n) {
            //第0行的开关状态，进循环后依次存储每一行开关状态
            int switchs = n;
            //将最开始灯的状态赋值给lights，类似于重置为最初
            memcpy(lights, oriLights, sizeof(oriLights));
            for (int i = 0; i < 5; ++i) {
                //第一次进入的时候存第0行的开关状态，即n，后续进入存取每一行开关状态
                result[i] = switchs;
                //让第i行的每一个开关起作用
                for (int j = 0; j < 6; ++j) {
                    //先针对同行处理，如果开关为1才进行处理
                    if (GetBit(switchs, j)) {
                        //先对自身进行反转
                        FlipBit(lights[i], j);
                        //再对同一行左右进行处理
                        if (j > 0) {
                            FlipBit(lights[i], j - 1);
                        }
                        if (j < 5) {
                            FlipBit(lights[i], j + 1);
                        }
                    }
                }
                //对下一行的处理，上一行不用处理，可以用异或语句简便处理
                if (i < 4) {
                    lights[i + 1] ^= switchs;
                }
                //由此可以确定下一行的开关状态
                switchs = lights[i];
            }
            //上述语句可以确保前四行灯光都熄灭，只需看第五行灯光是否全灭即可
            if (lights[4] == 0) {
                OutputResult(t, result);
                break;
            }
        }
    }
    return 0;
}
