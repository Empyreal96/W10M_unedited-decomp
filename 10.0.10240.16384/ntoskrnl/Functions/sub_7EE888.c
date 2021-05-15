// sub_7EE888 
 
int sub_7EE888()
{
  int v0; // r0
  unsigned int v1; // r1
  int v2; // r3
  int v3; // r5
  unsigned int v4; // r2
  char *v5; // r10
  unsigned int *v6; // r4
  int v7; // r5
  unsigned int v8; // r6
  _DWORD *v9; // r8
  int v10; // r9
  unsigned int v11; // r6
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r6
  int v16; // r7
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v20; // [sp+0h] [bp-60h]
  int v21; // [sp+8h] [bp-58h] BYREF
  char v22[76]; // [sp+10h] [bp-50h] BYREF
  int (__fastcall *v23)(_DWORD); // [sp+5Ch] [bp-4h]

  ExpAcquireFastMutexContended((int)v6, v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v6[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6[7] = v8;
  v4 = (v9[3] + v9[2] + v9[1] + *v9) % 0xDu;
  v3 = PnpDeviceClassNotifyList[2 * v4];
  v5 = (char *)&PnpDeviceClassNotifyList[2 * v4];
  if ( (char *)v3 != v5 )
  {
    do
    {
      v20 = v3;
      if ( *(_DWORD *)(v3 + 12) != *(_DWORD *)PsGetServerSiloGlobals(-1) )
        v10 = IopGetSessionIdFromSymbolicName();
      ++*(_WORD *)(v3 + 32);
      v6[1] = 0;
      v11 = v6[7];
      __dmb(0xBu);
      do
        v12 = __ldrex(v6);
      while ( !v12 && __strex(1u, v6) );
      if ( v12 )
        ExpReleaseFastMutexContended(v6, v12);
      KfLowerIrql((unsigned __int8)v11);
      KeAbPostRelease((unsigned int)v6);
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(__int16 *)(v13 + 0x134) - 1;
      *(_WORD *)(v13 + 308) = v14;
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v3 + 40), 1, v13, v14);
      if ( (v10 == -1 || *(_DWORD *)(v3 + 12) == v10)
        && !*(_BYTE *)(v3 + 34)
        && ((_DWORD *)(v3 + 44) == v9 || RtlCompareMemory((unsigned __int8 *)(v3 + 44), (int)v9, 16) == 16) )
      {
        PnpNotifyDriverCallback((_DWORD *)v3, (int)v22, &v21);
      }
      v0 = ExReleaseResourceLite(*(_DWORD *)(v3 + 40));
      v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v2 = (__int16)(*(_WORD *)(v1 + 0x134) + 1);
      *(_WORD *)(v1 + 308) = v2;
      if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
        KiCheckForKernelApcDelivery(v0);
      v15 = KeAbPreAcquire((unsigned int)v6, 0, 0);
      v16 = KfRaiseIrql(1);
      do
        v17 = __ldrex((unsigned __int8 *)v6);
      while ( __strex(v17 & 0xFE, (unsigned __int8 *)v6) );
      __dmb(0xBu);
      if ( (v17 & 1) == 0 )
        ExpAcquireFastMutexContended((int)v6, v15);
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      v6[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v6[7] = v16;
      v3 = *(_DWORD *)v3;
      PnpDereferenceNotify(v20);
    }
    while ( (char *)v3 != v5 );
    v8 = v6[7];
  }
  v6[1] = 0;
  __dmb(0xBu);
  do
    v18 = __ldrex(v6);
  while ( !v18 && __strex(1u, v6) );
  if ( v18 )
    ExpReleaseFastMutexContended(v6, v18);
  KfLowerIrql((unsigned __int8)v8);
  KeAbPostRelease((unsigned int)v6);
  return v23(0);
}
