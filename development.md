# 開発管理

チケット管理みたいな。番号ふってその説明書くだけです。  
ブランチ名は、「dev-開発No」とし、コミットメッセージの先頭も「dev #開発No」とする。詳しくは[readme.md](readme.md)参照

## 開発内容

### 1

単体テストの環境を整備する。  
参考文献：

- [Visual Studio で C/C++ 用の単体テストを作成する](https://docs.microsoft.com/ja-jp/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019)
- [Microsoft.VisualStudio.TestTools.CppUnitTestFramework API リファレンス](https://docs.microsoft.com/ja-jp/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019)

### 2

フォーマッタが使えないか、検討する。  
→Visual Studioのデフォルトフォーマッタを利用する。また、静的コード解析は行わない。

### 3

階乗を扱うクラス「Factorial」を作成する。  
機能：コンストラクタでn!をmod rで計算しておき、getメソッドなどで即座に利用できる。

### 4

グラフを扱うクラス「Graph」を作成する。

### 5

数rを法とする整数環が利用できるクラス「ModInt」を作成する。  

### 6

素数に関する関数をまとめる。  
ほしい機能：素因数分解、約数の総数を取得

### 7

2d、3dのベクトルの初期化用関数を作成する。

### 8

重み付きグラフ用のクラスを作成する。

### 9

行列演算を行うクラスを作成する。  
ほしい機能

- 和・差・積
- 累乗
- determinant

### 10

累積和を扱うクラスを作成する。  
対象は1D、2D、3Dとする。

### 11

bitsetをbit全探索やbitDPの考えから、使いやすくする。  
ほしい機能

- i番目が0か1か取得する。
- i番目を0,1にする。
- 基本演算not,and,or,xorを実装する。
- 全部選ばれている、全部選ばれていない状態にすぐできる再現する。
- bit全探索のやり方を簡単なwhile又はforループでできるようにする。

### 12

最短経路問題に関するアルゴリズムを実装する。

- Dijkstra
- Warshall-Floyd

### 13

ModIntのバグかもしれない現象があったので調査する。  
現象：[AtCoder Beginner Contest 163 D - Sum of Large Numbers](https://atcoder.jp/contests/abc163/tasks/abc163_d)を解いてるときにバグった。  
ただ、その後ModIntの実装をやめて解いたがうまく動かず、結局別の場所のバグを直して提出しACとなったため、ModIntが悪いかどうか不明。
