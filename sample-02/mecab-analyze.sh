#!/bin/bash

sentences="前期は，レポート作成技術を学んだ後，\
	Makefileの作成法，ライブラリ化，ユーザインターフェイス，\
	デバッグツールの使用法等，プログラミング手法の基礎的課題に\
	個人単位で取り組む．その後，個人でゲーム開発を行う．\
	後期は，ネットワークプログラミング，統合・モジュール化手法を\
	個人単位で取り組む.その後，企画立案ならびにプレゼンテーション技術を学んだ後，\
	メタな課題(例えば，GUIを用いたネットワークプログラミングによる対戦型ゲームの作成)に対して，\
	グループ単位で企画，立案，ソフトウェア開発を行い，最終的にコンテストを行う．"

output=./wakati.txt
echo $sentences | mecab -Owakati | sed -e 's/  */\n/g' > $output




