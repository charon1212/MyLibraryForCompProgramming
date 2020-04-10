# MyLibraryForCompProgramming

競技プログラミング用のライブラリ。

## 開発

- 言語  
C++
- IDE  
Visual Studio

## ブランチ運用

個人開発なのでざっくり…

- master  
デフォルトブランチ。動くものを置いとく。
- dev-XX
開発ブランチ。新規クラスの追加・クラスの機能拡張・問題の修正等々。XXの部分は開発Noとし、別ファイルで管理しよう。

## コミットメッセージ

参考：[誰にとってもわかりやすいGitのコミットメッセージを考える](https://www.tam-tam.co.jp/tipsnote/program/post16686.html)

### メッセージテンプレート

以下のテンプレートでコミットメッセージを打つこと。[]内の記述は可変項目で、下の説明に応じてコミットごとに切り替える。

```
dev #[開発No]
[コミット種別]:[概要]

- [詳細1]
- [詳細2]
...
```

- 開発No  
[development.md](./development.md)で管理する開発No。redmineとか使うの面倒なので…  
開発No追加するほどのコミットじゃないときは、1行目を省略。
- コミット種別  
下の表を参照。
- 概要  
概要を記述。50文字以内が目安。
- 詳細
詳細を記述。先頭を「- 」で箇条書きにする。

### コミット種別

いっぺんに同じことコミットしないように…注意しよう。。。俺。。。

| コミット種別 | 内容 |
|:--|:--|
| add | 機能追加 |
| fix | 修正 |
| change | 変更 |
| remove | 削除 |

## ドキュメント

作る気なし。増えてきたら管理しよう。。。
