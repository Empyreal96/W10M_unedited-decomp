// ExReleaseCacheAwarePushLockSharedEx 
 
int __fastcall ExReleaseCacheAwarePushLockSharedEx(int result, int a2, int a3)
{
  char v3; // r4
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r5
  int v7; // r7
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r6
  int v11; // r8
  int v12; // r3
  int v13; // r3
  unsigned __int8 *v14; // r2
  unsigned int v15; // r4

  v3 = a2;
  v4 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_52F3E8(result, a2, a3, a2 & 0xFFFFFFFC);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)result);
  while ( v5 == 17 && __strex(0, (unsigned int *)result) );
  if ( v5 != 17 )
    result = ExfReleasePushLockShared(result, 0);
  if ( (v3 & 2) == 0 )
  {
    v6 = *(_DWORD *)(v4 + 8);
    if ( KiAbEnabled )
    {
      if ( (v6 & 0x7FFFFFFC) != 0 )
      {
        v7 = 0;
        v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v9 = MmIsSessionAddress(v6);
        if ( v9 )
        {
          v9 = MmGetSessionIdEx(*(_DWORD *)(v8 + 116));
          v10 = v9;
        }
        else
        {
          v10 = -1;
        }
        if ( (unsigned int)KeGetCurrentIrql(v9) <= 1 )
        {
          v7 = 1;
          --*(_WORD *)(v8 + 310);
        }
        result = KiAbThreadClearAcquiredLockEntry(v8, v6, v10);
        v11 = result;
        if ( result )
        {
          result = KeAbEntryFree(result, v8);
          v12 = (int)(v11 - v8 - 488) / 48;
          if ( !v7 )
          {
            __dmb(0xBu);
            result = (char)(1 << v12);
            v14 = (unsigned __int8 *)(v8 + 810);
            do
              v15 = __ldrex(v14);
            while ( __strex(v15 | result, v14) );
            __dmb(0xBu);
            return result;
          }
          *(_BYTE *)(v8 + 484) |= 1 << v12;
          goto LABEL_18;
        }
        if ( (*(_DWORD *)(v8 + 80) & 0x8000) == 0 )
          KeBugCheck2(354, v8, v6, v10, 0, 0);
        if ( v7 )
        {
LABEL_18:
          v13 = (__int16)(*(_WORD *)(v8 + 310) + 1);
          *(_WORD *)(v8 + 310) = v13;
          if ( !v13 && *(_DWORD *)(v8 + 100) != v8 + 100 )
            result = KiCheckForKernelApcDelivery(result);
          return result;
        }
      }
    }
  }
  return result;
}
