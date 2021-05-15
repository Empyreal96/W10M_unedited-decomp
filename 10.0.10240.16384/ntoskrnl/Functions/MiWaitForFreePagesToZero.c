// MiWaitForFreePagesToZero 
 
int __fastcall MiWaitForFreePagesToZero(int a1, int a2)
{
  int v4; // r6
  int result; // r0
  int v6; // r0
  unsigned int *v7; // r1
  int *v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int v11[2]; // [sp+18h] [bp-68h] BYREF
  int v12[2]; // [sp+20h] [bp-60h] BYREF
  unsigned __int8 v13; // [sp+28h] [bp-58h]

  v11[0] = a1 + 120;
  v4 = a1 + 3232;
  v11[1] = a1 + 3232;
  if ( !KeWaitForMultipleObjects(2, v11, 1) )
    return -1;
  while ( !*(_DWORD *)(a1 + 1280) )
  {
    KeAcquireInStackQueuedSpinLock(a1 + 2944, v12);
    if ( !*(_DWORD *)(a1 + 1280) )
    {
      *(_BYTE *)(a1 + 3248) = 0;
      KeResetEvent(v4);
    }
    if ( (dword_682604 & 0x10000) != 0 )
      JUMPOUT(0x51C952);
    v6 = v12[0];
    if ( !v12[0] )
    {
      v7 = (unsigned int *)v12[1];
      __dmb(0xBu);
      do
        v8 = (int *)__ldrex(v7);
      while ( v8 == v12 && __strex(0, v7) );
      if ( v8 == v12 )
        goto LABEL_15;
      v6 = KxWaitForLockChainValid(v12);
    }
    v12[0] = 0;
    __dmb(0xBu);
    v9 = (unsigned int *)(v6 + 4);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 ^ 1, v9) );
LABEL_15:
    KfLowerIrql(v13);
    if ( !KeWaitForMultipleObjects(2, v11, 1) )
      return -1;
  }
  if ( dword_634C84 )
    JUMPOUT(0x51C92E);
  if ( (unsigned __int16)KeNumberNodes <= 1u )
    result = a2;
  else
    result = sub_51C904();
  return result;
}
