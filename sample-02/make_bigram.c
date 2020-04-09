////////////////////////////////////////////
//
//  形態素解析の結果を読み込み、
//  単語n-gram (bi-gram)を作成するプログラム
//
//  2020.03.31: Kazuyuki Matsumoto
//
// 以下の課題１，２について，Latex形式でレポート作成し，作成したC言語のソースファイルと
// レポートのtexソースファイルおよびPDFファイルを .tar.gz 形式で圧縮し，
// 「cから始まるアカウント番号.tar.gz」という名前で，Manaba上から本日の課題の場所に提出すること．
//  （ 自分のアカウント番号が c123456789 というアカウント名の場合，
//     c123456789.tar.gz というファイル名とする．）
//
// 課題１：プログラミング作法を身につけることで，今後の開発において
//         どのようなメリットがあるのかを500字以上1000字以内で記述せよ．
//
//
// 課題２：以下の基本課題(1)-(3)，余裕があれば発展課題(1)にも取り組むこと．
//
//   今日の講義資料に出てきた作法を意識してプログラミングすること．
//   (どこをどのように意識したのかをレポート内およびソースコード内のコメントに記述してください)
//
//  make_bigram.c は，日本語形態素解析結果を読み込んで，bi-gramを作成して
//  bigram.txt というファイル名で出力するプログラムです．
//  [準備]
//      $ chmod u+x mecab_analyze.sh
//      $ ./mecab_analyze.sh
//  [コンパイル方法]
//      $ gcc -o make_bigram make_bigram.c
//  [実行方法]
//      $ ./make_bigram
//
//
//   基本(1) 句読点「，」や「．」を含むbi-gramを出力しないように改良せよ．
//   基本(2) (1)の改良したプログラムを用いて，自分で書いた課題１の文章を
//           形態素解析した結果を用いてbi-gramを作成してみよ．
//   基本(3) tri-gram を作成できるように改良し，(2)と同じ文章についてtri-gramを作成せよ．
//   発展(1) 基本(3)で作成したプログラムについて，重複するtri-gramを出力しないようにし，
//           それぞれのtri-gramの出現頻度も一緒に出力できるように改良せよ．
//
////////////////////////////////////////////

//
// このソースコードは必要最低限のコメントのみ入れています．
// 適宜，ほかの人が読んでもわかりやすいようにコメントを入れるようにしてください．
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256 // 1単語(形態素)のバイト長

int main(void)
{
  char fname[] = "wakati.txt"; // 読み込むファイル名
  char ofname[] = "bigram.txt"; // bi-gramを出力するファイル名
  char str[N], bef[N];
  bef[0] = '\0';
  
  FILE* fp = fopen(fname, "r"); // 入力ファイルを開く．失敗するとNULLを返す．
  if ( fp == NULL ) {
    printf("%s file not open!\n", fname);
    return -1;
  }

  FILE* ofp = fopen(ofname, "w");
  if ( ofp == NULL ) {
    printf("%s file not open!\n", ofname );
    return -1;
  }


  while( fgets( str, N, fp ) != NULL ){
    str[strlen(str)-1] = '\0';
    if ( strcmp(str,"") == 0) break;
    if ( strcmp(bef,"") != 0 && str != NULL ){
      fprintf( ofp, "%s%s\n",  bef, str );
    }
    strcpy( bef, str );
  }
  
  fclose(fp); // ファイルを閉じる
  fclose(ofp);

}		

