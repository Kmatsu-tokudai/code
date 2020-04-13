/*

2020.04.13: Kazuyuki Matsumoto

入力した文字列をもとに主人公の初期ステータスを計算し、
敵と戦うゲーム


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct param{
  int hp; // 体力
  int mp; // 魔力
  int atk; // 攻撃力
  int def; // 防御力
  int lv; // レベル
} PM;



PM toParam(char* txt);

PM battle( PM player, PM enemy );

void printParam( PM pm );

int main(int argc, char** argv)
{

  if ( argc < 3 ){
    printf("第1引数に主人公の名前、第2引数に敵の名前を入力してください！");
    return -1;
  }

  PM pm = toParam(argv[1]);
  printf("-----------------\n%s のステータス\n", argv[1]);
  printParam(pm);
  PM ep = toParam(argv[2]);
  printf("-----------------\n%s のステータス\n", argv[2]);
  printParam(ep);
  pm = battle( pm, ep );
  printf("*****************\n\n%s のバトル後ステータス\n", argv[1]);
  printParam(pm);
  puts("-------------------");
  int res = -1;
  if (pm.hp > 0){ res = 1; }

  if (res > 0){
    printf("[WIN] 主人公「%s」は、敵「%s」に勝利しました！(^v^)V\n", argv[1], argv[2]);
  }else{
    printf("[WIN] 主人公「%s」は、敵「%s」に敗北しました（；；）\n", argv[1], argv[2]);
  }

  return 0;
}

// ステータスを初期化する関数
PM initParam(PM pm)
{
  pm.hp = 10;
  pm.mp = 10;
  pm.atk = 10;
  pm.def = 10;
  pm.lv = 1;
  return pm;
}

// ステータスを表示する関数
void printParam( PM pm )
{
  printf("HP: %d\n", pm.hp );
  printf("MP: %d\n", pm.mp );
  printf("ATK: %d\n", pm.atk );
  printf("DEF: %d\n", pm.def );
  printf("LV: %d\n", pm.lv );

}

// テキスト（文字列）からステータスを計算する関数  
PM toParam(char* txt)
{
  PM pm;
  pm = initParam(pm);
  int i = 0;
  char* p = txt;
	  
  while( *p != '\0' ){
    //printf("%c" , *p);
    i = '0' - *p;
    if ( i % 5 == 0 ){
      pm.hp = pm. hp + (i * i);
    }else if ( i % 5 == 1 ){
      pm.mp = pm.mp + ( i * 2 ) ;
    }else if ( i % 5 == 2 ){
      pm.atk = ( pm.atk ) * (int)100.0 / (i + 1 );
    }else if ( i % 5 == 3 ){
      pm.def = (int)( ( pm.def + i ) / 10.0 );
    }else if ( i % 5 == 4 ){
      pm.lv += 1;
    }
    
    p++;
  }
  return pm;
}


// どちらかのHPが無くなるまで戦う
PM battle( PM player, PM enemy )
{

  while(player.hp > 0 && enemy.hp > 0 ){
    srand((unsigned int)time(NULL));
    int r = rand();
    if (r%5 == 0){
      if (player.hp - enemy.hp > 0 ){ enemy.hp-=1; player.lv += 1; }
      else{ player.hp-=1; enemy.lv += 1; }
    }
    else if(r%5 == 1){
      if (player.mp - enemy.mp > 0 ){ enemy.hp-=2; player.lv += 1; }
      else{ player.hp-=5; enemy.lv += 1; }
    }

    else if(r%5 == 2){
      if (player.atk - enemy.atk > 0 ){ enemy.hp-=1; player.lv += 1; }
      else{ player.hp-=1; enemy.lv += 1; }
    }

    else if(r%5 == 3){
      if (player.def - enemy.def > 0 ){ enemy.hp-=5; player.lv += 1; }
      else{ player.hp-=2; enemy.lv += 1; }
    }
    else if(r%5 == 4){
      if (player.lv - enemy.lv > 0 ){ enemy.hp-=2; }
      else{ player.hp-=2; }
    }
  }

  if (player.hp < 0){ player.hp = 0; }
  return player;

  
}
