// ExpWakePushLock 
 
int __fastcall ExpWakePushLock(unsigned int *a1, unsigned int a2)
{
  int v2; // r6
  int result; // r0
  _DWORD *v5; // r4
  _DWORD *v6; // r2
  int v7; // r3
  unsigned int v8; // r2
  int v9; // r5
  _DWORD *v10; // r6
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r1
  _DWORD *v14; // r3
  unsigned int *_18; // [sp+18h] [bp+8h]
  unsigned int varsC; // [sp+1Ch] [bp+Ch]

  _18 = a1;
  v2 = 1;
  varsC = a2;
  while ( 1 )
  {
    if ( (a2 & 1) != 0 )
      return sub_50EC3C();
    result = a2 & 0xFFFFFFF0;
    v5 = *(_DWORD **)((a2 & 0xFFFFFFF0) + 0x14);
    v6 = (_DWORD *)(a2 & 0xFFFFFFF0);
    if ( !v5 )
    {
      do
      {
        v14 = v6;
        v6 = (_DWORD *)v6[4];
        v6[6] = v14;
        v5 = (_DWORD *)v6[5];
      }
      while ( !v5 );
      if ( v6 != (_DWORD *)result )
        *(_DWORD *)((a2 & 0xFFFFFFF0) + 0x14) = v5;
    }
    if ( (v5[8] & 1) != 0 )
    {
      v7 = v5[6];
      if ( v7 )
        break;
    }
    __dmb(0xBu);
    result = 0;
    do
      v8 = __ldrex(a1);
    while ( v8 == a2 && __strex(0, a1) );
    __dmb(0xBu);
    if ( v8 == a2 )
      goto LABEL_11;
    a2 = v8;
  }
  *(_DWORD *)((a2 & 0xFFFFFFF0) + 0x14) = v7;
  v5[6] = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex(a1);
  while ( __strex(v13 & 0xFFFFFFFB, a1) );
  __dmb(0xBu);
  v2 = 0;
LABEL_11:
  v9 = 2;
  if ( v5[6] )
  {
    result = KfRaiseIrql(2);
    v9 = result;
  }
  if ( !v2 )
  {
    if ( v5[9] )
    {
      result = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x7B);
      if ( KiAbEnabled )
        result = KiAbApplyWakeupBoost(result, v5[9], 0);
    }
  }
  do
  {
    v10 = (_DWORD *)v5[6];
    __dmb(0xBu);
    v11 = (unsigned __int8 *)(v5 + 8);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 & 0xFD, v11) );
    __dmb(0xBu);
    if ( !((unsigned __int8)(v12 & 2) >> 1) )
      result = KeSetEvent((int)v5, 0, 0);
    v5 = v10;
  }
  while ( v10 );
  if ( v9 != 2 )
    result = KfLowerIrql(v9);
  return result;
}
