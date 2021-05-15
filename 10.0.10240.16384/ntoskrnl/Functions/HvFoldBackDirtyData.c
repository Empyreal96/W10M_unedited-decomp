// HvFoldBackDirtyData 
 
unsigned int __fastcall HvFoldBackDirtyData(_DWORD *a1)
{
  unsigned int v2; // r7
  unsigned int v3; // r6
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r5
  unsigned int v9; // r6
  unsigned int *v10; // r5
  unsigned int v11; // r1

  if ( a1[470] )
  {
    v2 = a1[469];
    CmpLockRegistry();
    ExAcquireResourceSharedLite(a1[468], 1);
    v3 = a1[467];
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = KeAbPreAcquire(v3, 0, 0);
    v6 = v5;
    do
      v7 = __ldrex((unsigned __int8 *)v3);
    while ( __strex(v7 & 0xFE, (unsigned __int8 *)v3) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      ExpAcquireFastMutexContended(v3, v5);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v8 = 0;
    *(_DWORD *)(v3 + 4) = v4;
    if ( v2 )
    {
      v9 = 8;
      do
      {
        if ( ((*(int *)(a1[470] + 4 * (v8 >> 5)) >> (v8 & 0x1F)) & 1) != 0 )
          HvpMarkDirty((int)a1, v9, 1u);
        ++v8;
        v9 += 512;
      }
      while ( v8 < v2 );
    }
    v10 = (unsigned int *)a1[467];
    v10[1] = 0;
    __dmb(0xBu);
    do
      v11 = __ldrex(v10);
    while ( !v11 && __strex(1u, v10) );
    if ( v11 )
      ExpReleaseFastMutexContended(v10, v11);
    KeAbPostRelease((unsigned int)v10);
    ExReleaseResourceLite(a1[468]);
    CmpUnlockRegistry();
  }
  return HvFreeDirtyData(a1);
}
