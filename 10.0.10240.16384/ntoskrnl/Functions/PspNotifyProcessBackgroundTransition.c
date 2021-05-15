// PspNotifyProcessBackgroundTransition 
 
int __fastcall PspNotifyProcessBackgroundTransition(int a1, int a2)
{
  unsigned __int8 *v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r5
  unsigned int *v7; // r7
  int v8; // r0
  unsigned int v9; // r2
  int result; // r0
  int v11; // r0
  _DWORD *v12; // r4
  int v13; // r9
  _DWORD *v14; // r6
  unsigned int v15; // r2
  __int16 v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3
  int v19; // r1
  int v20; // r2

  __dmb(0xBu);
  v4 = (unsigned __int8 *)(a1 + 194);
  if ( a2 )
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x10, v4) );
  }
  else
  {
    do
      v17 = __ldrex(v4);
    while ( __strex(v17 & 0xEF, v4) );
  }
  __dmb(0xBu);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned int *)(a1 + 720);
  v8 = KeAbPreAcquire(a1 + 720, 0, 0);
  do
    v9 = __ldrex(v7);
  while ( !v9 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v9 )
    return sub_526388(v8, 17);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v11 = KfRaiseIrql(2);
  v12 = *(_DWORD **)(a1 + 396);
  v13 = v11;
  v14 = (_DWORD *)(a1 + 396);
  while ( v12 != v14 )
  {
    if ( !KeAbThreadAreAllEntriesFree(v12 - 233) )
    {
      v18 = v12[7];
      if ( a2 )
      {
        v19 = (v18 >> 9) & 7;
        v20 = 0;
      }
      else
      {
        v19 = 0;
        v20 = (v18 >> 9) & 7;
      }
      if ( v19 != v20 )
        KeAbProcessBaseIoPriorityChange(v12 - 233, v19, v20);
    }
    v12 = (_DWORD *)*v12;
  }
  KfLowerIrql(v13);
  __dmb(0xBu);
  do
    v15 = __ldrex(v7);
  while ( v15 == 17 && __strex(0, v7) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v7, 0);
  result = KeAbPostRelease(v7);
  v16 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
