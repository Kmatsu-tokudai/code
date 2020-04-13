# ソフトウェア実験のサンプルコード集

## 第2回：プログラミング作法 2020.04.28
 
 
### 単語N-gramを作るプログラム 
 
```
 形態素解析器のインストール： 
 sudo apt install mecab 
 
 シェルスクリプトへの実行権限付与： 
 chmod u+x mecab-analyze.sh
 
 形態素解析結果の出力:  
 ./mecab-analyze.sh 
 
 
 コンパイル方法： 
 gcc -o make_bigram make_bigram.c 

 実行方法： 
 chmod u+x make_bigram
 ./make_bigram


```
## 第3回：ライブラリ化 2020.05.12


### 文字列から初期ステータスを計算し、勝ち負けを決定するプログラム

```
ソースコードを関数だけのファイル、共通の変数をまとめたヘッダファイルに分割し、分割コンパイルする。

静的ライブラリと動的ライブラリを作成する。

```

