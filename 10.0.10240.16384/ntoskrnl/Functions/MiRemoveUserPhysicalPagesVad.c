// MiRemoveUserPhysicalPagesVad 
 
int __fastcall MiRemoveUserPhysicalPagesVad(int result)
{
  unsigned int v1; // r5
  int v2; // r3
  int v3; // r8
  unsigned int v4; // r4
  int v5; // r9
  int v6; // r2
  int v7; // r1
  unsigned int v8; // r7
  unsigned int v9; // r6
  int v10; // r3
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r2
  __int16 v14; // r3
  char v15[184]; // [sp+8h] [bp-B8h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(v1 + 0x74);
  v3 = *(_DWORD *)(v2 + 328);
  if ( *(_DWORD *)(v2 + 648) )
  {
    v4 = 4 * ((*(_DWORD *)(result + 12) & 0xFFFFF) - 0x10000000);
    v5 = (*(_DWORD *)(result + 16) & 0xFFFFF) - 0x10000000;
    MiInitializeTbFlushList((int)v15, 1, 33);
    --*(_WORD *)(v1 + 310);
    ExAcquireAutoExpandPushLockExclusive(v3 + 4, 0, v6);
    if ( v4 <= 4 * v5 )
    {
      v8 = v4 + 0x40000000;
      v9 = v4 + 1070596096;
      do
      {
        if ( (*(_DWORD *)v4 & 2) != 0 )
        {
          v10 = MmPfnDatabase + 24 * (*(_DWORD *)v4 >> 12);
          __dmb(0xBu);
          v11 = (unsigned int *)(v10 + 4);
          do
            v12 = __ldrex(v11);
          while ( __strex(0, v11) );
          MiInsertTbFlushEntry((int)v15, v4 << 10, 1, 0);
          if ( v8 > 0x3FFFFF )
          {
            *(_DWORD *)v4 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v4 = 0;
            if ( v9 <= 0xFFF )
              MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, v4);
          }
        }
        v4 += 4;
        v8 += 4;
        v9 += 4;
      }
      while ( v4 <= 4 * v5 );
    }
    MiFlushTbList((unsigned int)v15, v7);
    result = ExReleaseAutoExpandPushLockExclusive((int *)(v3 + 4), 0, v13);
    v14 = *(_WORD *)(v1 + 310) + 1;
    *(_WORD *)(v1 + 310) = v14;
    if ( !v14 && *(_DWORD *)(v1 + 100) != v1 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
