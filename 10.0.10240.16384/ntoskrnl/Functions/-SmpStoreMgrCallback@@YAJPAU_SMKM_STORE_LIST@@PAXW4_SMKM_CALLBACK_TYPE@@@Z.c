// -SmpStoreMgrCallback@@YAJPAU_SMKM_STORE_LIST@@PAXW4_SMKM_CALLBACK_TYPE@@@Z 
 
int __fastcall SmpStoreMgrCallback(int a1, int a2, int a3)
{
  int v3; // r7
  unsigned int v4; // r2
  int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r0
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  if ( a3 == 2 )
  {
    v3 = ExAllocatePoolWithTag(512, 1528);
    if ( v3 )
    {
      SMKM_STORE<SM_TRAITS>::SmStGetStoreStats();
      v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v4 + 308);
      v5 = KeAbPreAcquire((unsigned int)dword_637048, 0, 0);
      do
        v6 = __ldrex((unsigned __int8 *)dword_637048);
      while ( __strex(v6 | 1, (unsigned __int8 *)dword_637048) );
      __dmb(0xBu);
      if ( (v6 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(dword_637048, v5, (unsigned int)dword_637048);
      if ( v5 )
        *(_BYTE *)(v5 + 14) |= 1u;
      StLcBucketsCombine(&dword_637048[1], (_DWORD *)(v3 + 1464));
      __dmb(0xBu);
      do
        v7 = __ldrex(dword_637048);
      while ( __strex(v7 - 1, dword_637048) );
      if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
        ExfTryToWakePushLock(dword_637048);
      v8 = KeAbPostRelease((unsigned int)dword_637048);
      v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = *(_WORD *)(v9 + 0x134) + 1;
      *(_WORD *)(v9 + 308) = v10;
      if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
        KiCheckForKernelApcDelivery(v8);
      ExFreePoolWithTag(v3);
    }
  }
  return 0;
}
