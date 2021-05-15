// SepDeleteLogonSessionTrack 
 
int __fastcall SepDeleteLogonSessionTrack(_DWORD *a1, int a2)
{
  int v4; // r4
  int v5; // r5
  unsigned int *v6; // r9
  int v7; // r2
  int v8; // r6
  unsigned int i; // r4
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r0
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3

  v4 = *a1 & 0xF;
  v5 = 0;
  v6 = (unsigned int *)(SepLogonSessions + 4 * v4);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = 7 * (v4 & 3);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v4 & 3), 1, v7, v4 & 3);
  for ( i = *v6; ; i = *(_DWORD *)i )
  {
    if ( !i )
    {
      v10 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v8);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = *(_WORD *)(v11 + 0x134) + 1;
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
        KiCheckForKernelApcDelivery(v10);
      return -1073741729;
    }
    if ( PsEqualCurrentServerSilo(*(_DWORD *)(i + 88)) && *a1 == *(_DWORD *)(i + 4) && a1[1] == *(_DWORD *)(i + 8) )
      break;
    v6 = (unsigned int *)i;
  }
  v14 = *(_DWORD *)(i + 24);
  if ( a2 )
  {
    *(_DWORD *)(i + 24) = v14 | 0x10;
    ObRevokeHandles((_DWORD **)(i + 72));
    v15 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v8);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    return 0;
  }
  if ( (v14 & 8) == 0 && *(_DWORD *)(i + 20) == 1 || !*(_DWORD *)(i + 20) )
  {
    *v6 = *(_DWORD *)i;
    if ( *(_DWORD *)(i + 28) )
    {
      v5 = *(_DWORD *)(i + 28);
      *(_DWORD *)(i + 28) = 0;
    }
    v18 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v8);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
    if ( v5 )
    {
      SepCleanupLUIDDeviceMapDirectory(a1, *(_DWORD *)(i + 88));
      ObfDereferenceDeviceMap(v5, v21, v22, v23);
    }
    v24 = *(_DWORD *)(i + 88);
    if ( v24 )
      PspDereferenceSiloObject(v24);
    v25 = *(_DWORD *)(i + 40);
    if ( v25 )
      ExFreePoolWithTag(v25);
    SepDeleteLogonSessionClaims(i);
    if ( SepTokenSidSharingEnabled )
      SepDeleteLogonSessionSidValues(i);
    ObDestroyHandleRevocationBlock((_DWORD **)(i + 72));
    ExFreePoolWithTag(i);
    SepDeleteSessionLowboxEntries();
    return 0;
  }
  v26 = ExReleaseResourceLite((int)&SepRmDbLock + 8 * v8);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    KiCheckForKernelApcDelivery(v26);
  return -1073741564;
}
