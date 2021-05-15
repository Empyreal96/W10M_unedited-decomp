// KseAddHardwareId 
 
int __fastcall KseAddHardwareId(unsigned __int16 *a1)
{
  unsigned __int8 *v2; // r6
  int v3; // r3
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r3
  int v16; // [sp+0h] [bp-30h] BYREF
  char v17[28]; // [sp+14h] [bp-1Ch] BYREF

  v2 = (unsigned __int8 *)dword_6416FC;
  v3 = dword_6416D4;
  __dmb(0xBu);
  if ( v3 != 2 )
    return sub_7C95FC();
  if ( a1 )
  {
    RtlInitUnicodeString((unsigned int)v17, a1);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire((unsigned int)v2, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v2);
    while ( __strex(v8 | 1, v2) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v2, v6, (unsigned int)v2);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = KsepCacheLookup(v2, &v16);
    if ( !v9 )
    {
      v10 = KsepPoolAllocatePaged(28);
      v9 = v10;
      if ( !v10 || KsepStringDuplicate(v10 + 20, a1) < 0 )
      {
        v11 = -1073741801;
LABEL_15:
        __dmb(0xBu);
        do
          v12 = __ldrex((unsigned int *)v2);
        while ( __strex(v12 - 1, (unsigned int *)v2) );
        if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)v2);
        v13 = KeAbPostRelease((unsigned int)v2);
        v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
        *(_WORD *)(v14 + 308) = v15;
        if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
          KiCheckForKernelApcDelivery(v13);
        if ( v11 < 0 )
        {
          if ( v9 )
          {
            KsepStringFree(v9 + 20);
            KsepPoolFreePaged(v9);
          }
        }
        return v11;
      }
      KsepCacheInsert(v2, v9);
    }
    v11 = 0;
    goto LABEL_15;
  }
  return 0;
}
