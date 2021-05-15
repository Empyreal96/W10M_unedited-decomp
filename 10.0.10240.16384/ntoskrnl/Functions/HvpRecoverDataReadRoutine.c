// HvpRecoverDataReadRoutine 
 
int __fastcall HvpRecoverDataReadRoutine(int a1, unsigned int *a2, unsigned int a3, int a4, unsigned int *a5)
{
  int v7; // r5
  int v10; // r4
  unsigned int v11; // r0
  unsigned int v12; // r7
  int v13; // r3
  int v14; // r1
  int v15; // r3
  int v16; // r2
  int v17; // r4
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned int *v21; // [sp+4h] [bp-24h]
  int v22[8]; // [sp+8h] [bp-20h] BYREF

  v21 = a2;
  v22[0] = a3;
  v22[1] = a4;
  v7 = 0;
  if ( a3 + a4 < a3 && a3 + a4 )
    return -1073741811;
  v11 = *a2;
  v12 = 0x10000;
  v13 = *(_DWORD *)(a1 + 68) << 9;
  v14 = v13 - 1;
  v15 = (v13 + a3 + a4 - 1) & ~(v13 - 1);
  v16 = a3 & ~v14;
  v17 = v15 - v16;
  if ( (unsigned int)(v15 - v16) >= 0x10000 )
    v12 = v15 - v16;
  v22[0] = a3 & ~v14;
  if ( !v11 || (a2[1] < v12 ? ExFreePoolWithTag(v11) : (v7 = v11, v12 = a2[1]), *a2 = 0, a2[1] = 0, !v7) )
  {
    v7 = ExAllocatePoolWithTag(1, v17, 1867074883);
    if ( !v7 )
      return -1073741801;
    v12 = v17;
  }
  if ( (*(int (__fastcall **)(int, unsigned int, int *, int, int, unsigned int *))(a1 + 24))(
         a1,
         a2[2],
         v22,
         v7,
         v17,
         v21) )
  {
    *a2 = v7;
    a2[1] = v12;
    v18 = *(_DWORD *)(a1 + 68) << 9;
    if ( !v18 )
      __brkdiv0();
    v19 = a3 % v18 + v7;
    v7 = 0;
    *a5 = v19;
    v10 = 0;
  }
  else
  {
    v10 = -1073741823;
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v10;
}
