// CmpIsCmRm 
 
int __fastcall CmpIsCmRm(_DWORD *a1)
{
  int v2; // r7
  unsigned int v3; // r2
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v18[6]; // [sp+0h] [bp-18h] BYREF

  v18[0] = 0;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = KeAbPreAcquire((unsigned int)&CmpRmListLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&CmpRmListLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&CmpRmListLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpRmListLock, v5);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_631FA4 = v4;
  while ( 1 )
  {
    v8 = CmListGetNextElement(&CmpRmListHead, v18, 0);
    if ( !v8 )
      break;
    if ( (_DWORD *)v8 == a1 )
    {
      if ( a1[6] && a1[7] && a1[4] && a1[5] )
        v2 = 1;
      dword_631FA4 = 0;
      __dmb(0xBu);
      do
        v9 = __ldrex((unsigned int *)&CmpRmListLock);
      while ( !v9 && __strex(1u, (unsigned int *)&CmpRmListLock) );
      if ( v9 )
        ExpReleaseFastMutexContended((unsigned int *)&CmpRmListLock, v9);
      v10 = KeAbPostRelease((unsigned int)&CmpRmListLock);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = *(_WORD *)(v11 + 0x134) + 1;
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
        KiCheckForKernelApcDelivery(v10);
      return v2;
    }
  }
  dword_631FA4 = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpRmListLock);
  while ( !v13 && __strex(1u, (unsigned int *)&CmpRmListLock) );
  if ( v13 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpRmListLock, v13);
  v14 = KeAbPostRelease((unsigned int)&CmpRmListLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return 0;
}
