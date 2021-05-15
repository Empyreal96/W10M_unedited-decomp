// IopCleanupFileObjectIosbRange 
 
unsigned int __fastcall IopCleanupFileObjectIosbRange(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r7
  int v6; // r4
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r6
  _DWORD *v11; // r4
  unsigned int v12; // r0
  int v13; // r3
  int v14; // r2
  unsigned __int8 v15; // r4
  unsigned int v16; // r1
  int v18[8]; // [sp+0h] [bp-20h] BYREF

  v18[0] = a2;
  v18[1] = a3;
  v18[2] = a4;
  v5 = 0;
  v18[0] = *(_DWORD *)(a1 + 16);
  ObfDereferenceObjectWithTag(v18[0]);
  *(_DWORD *)(a1 + 16) = 0;
  v6 = KeAbPreAcquire((unsigned int)&IoStatusBlockRangeTableLock, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)&IoStatusBlockRangeTableLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&IoStatusBlockRangeTableLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&IoStatusBlockRangeTableLock, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_631B64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631B7C = v7;
  v10 = RtlLookupElementGenericTableAvl((int)&IoStatusBlockRangeTable, (int)v18);
  v11 = *(_DWORD **)(v10 + 4);
  if ( v11 )
  {
    v9 = *(_DWORD *)(a1 + 8);
    while ( v9 != v11[3] )
    {
      v5 = v11;
      v11 = (_DWORD *)v11[5];
      if ( !v11 )
        goto LABEL_13;
    }
    --*v11;
  }
LABEL_13:
  if ( !*v11 )
  {
    v12 = v11[4];
    if ( v12 )
      MmUnmapLockedPages(v12, v11[3], v9);
    MmUnlockPages(v11[3]);
    IoFreeMdl(v11[3]);
    v13 = v11[5];
    if ( v5 )
      v5[5] = v13;
    else
      *(_DWORD *)(v10 + 4) = v13;
    ExFreePoolWithTag((unsigned int)v11);
    if ( !*(_DWORD *)(v10 + 4) )
      RtlDeleteElementGenericTableAvl((int)&IoStatusBlockRangeTable, (int)v18, v14, 0);
  }
  dword_631B64 = 0;
  v15 = dword_631B7C;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&IoStatusBlockRangeTableLock);
  while ( !v16 && __strex(1u, (unsigned int *)&IoStatusBlockRangeTableLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&IoStatusBlockRangeTableLock, v16);
  KfLowerIrql(v15);
  return KeAbPostRelease((unsigned int)&IoStatusBlockRangeTableLock);
}
