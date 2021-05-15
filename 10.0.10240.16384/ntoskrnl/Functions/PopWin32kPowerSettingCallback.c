// PopWin32kPowerSettingCallback 
 
int __fastcall PopWin32kPowerSettingCallback(int *a1, int *a2, int a3)
{
  int v3; // r3
  int v4; // r4
  int v5; // r5
  int v7; // [sp-4h] [bp-28h]
  int v8; // [sp+0h] [bp-24h]
  int v9; // [sp+4h] [bp-20h]
  int v10; // [sp+8h] [bp-1Ch]
  int v11; // [sp+Ch] [bp-18h]

  if ( a3 != 4 || !a2 )
    return -1073741811;
  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  v7 = *a1;
  v8 = v3;
  v9 = v4;
  v10 = v5;
  v11 = *a2;
  PopBroadcastSessionInfo(a1 + 4);
  return 0;
}
