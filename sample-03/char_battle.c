/*

2020.04.13: Kazuyuki Matsumoto

入力した文字列をもとに主人公/敵の初期ステータスを計算し、
ランダムな値により勝敗を決めるゲーム

[コンパイル方法]
$ make

[実行方法]
$ ./char_battle [主人公の名前] [敵の名前]


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NMAX 256

typedef struct param{
  int hp; // 体力
  int mp; // 魔力
  int atk; // 攻撃力
  int def; // 防御力
  int lv; // レベル
  char name[NMAX];
} PM;



PM toParam(char* txt);

PM battle( PM player, PM enemy );

void printParam( PM pm );

int main(int argc, char** argv)
{

  if ( argc < 3 ){
    puts("第1引数に主人公の名前、第2引数に敵の名前を入力してください！");
    return -1;
  }

  PM pm = toParam(argv[1]);
  printf("-----------------\n%s のステータス\n", pm.name );
  printParam(pm);
  PM ep = toParam(argv[2]);
  printf("-----------------\n%s のステータス\n", ep.name );
  printParam(ep);
  printf("-------- バトル開始 --------\n");
  pm = battle( pm, ep );
  printf("\n\n*****************\n\n%s のバトル後ステータス\n", pm.name);
  printParam(pm);
  puts("-------------------");
  int res = -1;
  if (pm.hp > 0){ res = 1; }

  if (res > 0){
    printf("[勝利] 主人公「%s」は、敵「%s」に勝利しました！(^v^)V\n", pm.name, ep.name);
  }else{
    printf("[敗北] 主人公「%s」は、敵「%s」に敗北しました（；；）\n", pm.name, ep.name);
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
  strcpy( pm.name, txt );
  int i = 0;
  char* p = txt;
	  
  while( *p != '\0' ){
    //printf("%c" , *p);
    i = '0' - *p;
    if ( i % 10 == 0 ){
      pm.hp = pm.hp + (i%9+1)*10;
    }else if ( i % 10 == 1 ){
      pm.mp = pm.mp + i%8 * 8;
    }else if ( i % 10 == 2 ){
      pm.atk = pm.atk * i%7 * 7;
    }else if ( i % 10 == 3 ){
      pm.def = pm.def + i%6 * 6;
    }else{
      pm.lv += 1;
    }
    p++;
  }
  if (pm.hp > 300){ pm.hp = 300; }
  return pm;
}

void message( int type, char* nm1, char* nm2, int val1, char* nm3, int val2 )
{
  switch (type){
  case 0:
    printf("%s は %s の力で %d のダメージを与えた！ \n", nm1, nm2, val1 );
    break;
  case 1:
    printf("%s は %s に %d のダメージをくらった！ \n", nm1, nm2, val1);
    break;
  case 2:
    printf("%s は 魔法を使い %s に %d のダメージを与えた！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;

  case 3:
    printf("%s は %s の魔法攻撃で %d のダメージをくらった！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;

  case 4:
    printf("%s は %s に 攻撃し、%d のダメージを与えた！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;
      
  case 5:
    printf("%s は %s に 攻撃され、%d のダメージをくらった！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;

  case 6:
    printf("%s は %s の 攻撃を防ぎ、%d のダメージを与えた！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;

  case 7:
    printf("%s は %s の 攻撃を防ぎきれず、%d のダメージをくらった！ \n【%s のレベルが %d 上がった】\n", nm1, nm2, val1, nm3, val2 );
    break;

  case 8:
    printf("%s は体力を %d 消耗した！\n", nm1, val1 );
    break;

  case 9:
    printf("%s は体力を %d 消耗した！\n", nm1, val1 );
    break;
    
  default:
    break;
    
  }
  
}


// どちらかのHPが無くなるまで戦う
PM battle( PM player, PM enemy )
{
  srand((unsigned int)time(NULL));
  int bkhp = player.hp;
  while(player.hp > 0 && enemy.hp > 0 ){
    int r = rand();
    int r2 = rand();
    if (r%5 == 0){
      if (player.hp - enemy.hp > 0 && r2%2 == 0){
	enemy.hp-=1; player.lv += 1;
	message(0, player.name, enemy.name, 1, "NULL", 0);
      }
      else{
	player.hp-=1; enemy.lv += 1;
	message(1, player.name, enemy.name, 1, "NULL", 0);
      }

    }
    else if(r%5 == 1){
      if (player.mp - enemy.mp > 0 && r2%2 == 0){
	enemy.hp-=(r2%10+1)*5; player.lv += 1;
	message(2, player.name, enemy.name, (r2%10+1)*5, player.name, 1 );
      }
      else{
	player.hp-=(r2%10+1)*5; enemy.lv += 1;
	message(3, player.name, enemy.name, (r2%10+1)*5, enemy.name, 1 );
      }
    }

    else if(r%5 == 2){
      if (player.atk - enemy.atk > 0 && r2%2 == 0){
	enemy.hp-=(r2%5+1)*3; player.lv += 1;
	message(4,  player.name, enemy.name, (r2%5+1)*3, player.name, 1 );
      }
      else{
	player.hp-=(r2%5+1)*3; enemy.lv += 1;
	message(5,  player.name, enemy.name, (r2%5+1)*3, enemy.name, 1 );
      }
    }

    else if(r%5 == 3){
      if (player.def - enemy.def > 0 && r2%2 == 0){
	enemy.hp-=(r2%9+1)*2; player.lv += 1;
	message(6, player.name, enemy.name, (r2%9+1)*2, player.name, 1 );
      }
      else{
	player.hp-=(r2%9+1)*2; enemy.lv += 1;
	message(7, player.name, enemy.name, (r2%9+1)*2, enemy.name, 1 );
      }
    }
    else if(r%5 == 4){
      if (player.lv - enemy.lv > 0 && r2%2 == 0){
	enemy.hp-=r2%7+1;
	message(8, enemy.name, "NULL", r2%7+1, "NULL", 0 );
      }
      else{
	player.hp-=r2%7 + 1;
	message(9, player.name, "NULL", r2%7+1, "NULL", 0 );
      }
    }
    puts("-------------------------------------\n");
    bkhp = player.hp;
  }

  if (player.hp < 0){ player.hp = 0; }
  return player;

  
}
