// MiFinishLastForkPageTable 
 
int __fastcall MiFinishLastForkPageTable(int a1, int a2)
{
  int v4; // r4
  int v5; // r8
  unsigned __int8 *v6; // r6
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r2
  int v10; // r1
  int v11; // r6
  int v12; // r7
  int v13; // r3
  int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v18; // [sp+8h] [bp-20h]

  v4 = MmPfnDatabase + 24 * a2;
  v18 = *(_DWORD *)(v4 + 4);
  v5 = KfRaiseIrql(2);
  v6 = (unsigned __int8 *)(v4 + 15);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v7 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v8 = *(_DWORD *)(v4 + 12);
      __dmb(0xBu);
    }
    while ( (v8 & 0x80000000) != 0 );
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
  }
  MiRemoveLockedPageChargeAndDecRef(v4);
  v9 = *(_DWORD *)(v4 + 12);
  v10 = v9 & 0x3FFFFFFF;
  if ( (v9 & 0x3FFFFFFFu) <= 1 )
  {
    v14 = *(_BYTE *)(v4 + 18) & 7;
    if ( v14 != 6 )
      KeBugCheckEx(78, 153, (v4 - MmPfnDatabase) / 24, v14, v10);
    *(_DWORD *)(v4 + 12) = v9 & 0xC0000000 | (v10 - 1) & 0x3FFFFFFF;
    if ( v10 == 1 )
      MiPfnShareCountIsZero(v4, 0);
  }
  else
  {
    v11 = MiMapPageInHyperSpaceWorker(*(_DWORD *)(v4 + 20) & 0xFFFFF, 0, 0x80000000);
    v12 = (*(_DWORD *)(v4 + 4) >> 2) & 0x3FF;
    if ( (*(_DWORD *)(v11 + 4 * v12) & 2) == 0 )
    {
      v13 = (dword_681120 & 0xDED | (a2 << 12) | MiDetermineUserGlobalPteMask(v18 | 0x80000000)) & 0xFFFFFDFF;
      MiArmWritePdeOtherProcess(a1, (_DWORD *)(v11 + 4 * v12), v13 | 0x12, v13);
    }
    MiUnmapPageInHyperSpaceWorker(v11 + 4 * v12, 17, 0x80000000);
  }
  __dmb(0xBu);
  v15 = (unsigned int *)(v4 + 12);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 & 0x7FFFFFFF, v15) );
  return KfLowerIrql(v5);
}
