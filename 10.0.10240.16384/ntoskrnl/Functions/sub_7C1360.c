// sub_7C1360 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7C1360(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  BOOL v13; // r8
  int v14; // r3
  int v15; // r7
  _DWORD *v16; // r1
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  int v21; // r7
  int v22; // r7
  int v23; // r8
  _DWORD *v24; // r9
  GUID *v25; // r10
  int v26; // r4
  int v27; // r5
  unsigned int v28; // r2
  unsigned __int8 v29; // r4
  unsigned int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  int v36; // r4
  int v37; // r7
  unsigned int v38; // r2
  int v39; // r10
  int v40; // r4
  int v41; // r8
  unsigned int v42; // r2
  int v43; // r4
  int v44; // r8
  unsigned __int8 v45; // r9
  unsigned int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r4
  int v53; // r9
  unsigned int v54; // r2
  int v55; // r5
  unsigned __int8 v56; // r4
  unsigned int v57; // r1
  int v58; // [sp-3Ch] [bp-3Ch]
  int i; // [sp-38h] [bp-38h]
  int v60; // [sp-30h] [bp-30h]
  int v61; // [sp-2Ch] [bp-2Ch] BYREF
  int v62; // [sp-28h] [bp-28h]
  _DWORD *v63; // [sp-24h] [bp-24h]
  _DWORD v64[5]; // [sp-1Ch] [bp-1Ch] BYREF
  int v65; // [sp-8h] [bp-8h]

  v26 = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
  v27 = KfRaiseIrql(1);
  do
    v28 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
  while ( __strex(v28 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
  __dmb(0xBu);
  if ( (v28 & v23) == 0 )
    ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v26);
  if ( v26 )
    *(_BYTE *)(v26 + 14) |= v23;
  dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630D3C = v27;
  v13 = v25 == &GUID_TARGET_DEVICE_REMOVE_CANCELLED
     || RtlCompareMemory((unsigned __int8 *)v25, (int)&GUID_TARGET_DEVICE_REMOVE_CANCELLED, 16) == 16;
  if ( v13 )
    v55 = *(_DWORD *)(v22 + 324);
  else
    v55 = *(_DWORD *)(v22 + 320);
  v14 = v22 + 320;
  for ( i = v22 + 320; ; v14 = i )
  {
    if ( v55 == v14 )
      goto LABEL_63;
    v62 = v55;
    if ( *(_DWORD *)(v55 + 12) == *(_DWORD *)PsGetServerSiloGlobals(-1) )
    {
      v15 = v60;
    }
    else
    {
      v15 = IopGetSessionIdFromPDO(v58);
      v60 = v15;
    }
    ++*(_WORD *)(v55 + 32);
    dword_630D24 = 0;
    v29 = dword_630D3C;
    __dmb(0xBu);
    do
      v30 = __ldrex((unsigned int *)&PnpTargetDeviceNotifyLock);
    while ( !v30 && __strex(1u, (unsigned int *)&PnpTargetDeviceNotifyLock) );
    if ( v30 )
      ExpReleaseFastMutexContended((unsigned int *)&PnpTargetDeviceNotifyLock, v30);
    KfLowerIrql(v29);
    KeAbPostRelease((unsigned int)&PnpTargetDeviceNotifyLock);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = *(__int16 *)(v31 + 0x134) - 1;
    *(_WORD *)(v31 + 308) = v32;
    ExAcquireResourceExclusiveLite(*(_DWORD *)(v55 + 40), 1, v31, v32);
    if ( (v15 == -1 || *(_DWORD *)(v55 + 12) == v15) && !*(_BYTE *)(v55 + 34) )
    {
      if ( v24 )
      {
        v24[5] = *(_DWORD *)(v55 + 44);
        v16 = v24;
      }
      else
      {
        v65 = *(_DWORD *)(v55 + 44);
        v16 = v64;
      }
      v17 = PnpNotifyDriverCallback((_DWORD *)v55, (int)v16, &v61);
      v18 = ExReleaseResourceLite(*(_DWORD *)(v55 + 40));
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(v18);
      if ( v17 < 0 )
      {
        v21 = 0;
        v61 = 0;
      }
      else
      {
        v21 = v61;
      }
      if ( v21 < 0
        && (v25 == &GUID_TARGET_DEVICE_QUERY_REMOVE
         || RtlCompareMemory((unsigned __int8 *)v25, (int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16) == 16) )
      {
        if ( v63 )
          *v63 = *(_DWORD *)(v55 + 28);
        v64[1] = -885374969;
        v64[2] = 298862320;
        v64[3] = 1610649520;
        v64[4] = 1057297303;
        v39 = v55;
        v40 = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
        v41 = KfRaiseIrql(1);
        do
          v42 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
        while ( __strex(v42 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
        __dmb(0xBu);
        if ( (v42 & 1) == 0 )
          ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v40);
        if ( v40 )
          *(_BYTE *)(v40 + 14) |= 1u;
        dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        dword_630D3C = v41;
        do
        {
          v43 = -1;
          v44 = v55;
          if ( *(_DWORD *)(v55 + 12) != *(_DWORD *)PsGetServerSiloGlobals(-1) )
            v43 = IopGetSessionIdFromPDO(v58);
          ++*(_WORD *)(v55 + 32);
          dword_630D24 = 0;
          v45 = dword_630D3C;
          __dmb(0xBu);
          do
            v46 = __ldrex((unsigned int *)&PnpTargetDeviceNotifyLock);
          while ( !v46 && __strex(1u, (unsigned int *)&PnpTargetDeviceNotifyLock) );
          if ( v46 )
            ExpReleaseFastMutexContended((unsigned int *)&PnpTargetDeviceNotifyLock, v46);
          KfLowerIrql(v45);
          KeAbPostRelease((unsigned int)&PnpTargetDeviceNotifyLock);
          v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v48 = *(__int16 *)(v47 + 0x134) - 1;
          *(_WORD *)(v47 + 308) = v48;
          ExAcquireResourceExclusiveLite(*(_DWORD *)(v55 + 40), 1, v47, v48);
          if ( (v43 == -1 || *(_DWORD *)(v55 + 12) == v43) && !*(_BYTE *)(v55 + 34) )
          {
            v65 = *(_DWORD *)(v55 + 44);
            PnpNotifyDriverCallback((_DWORD *)v55, (int)v64, 0);
          }
          v49 = ExReleaseResourceLite(*(_DWORD *)(v55 + 40));
          v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v51 = *(_WORD *)(v50 + 0x134) + 1;
          *(_WORD *)(v50 + 308) = v51;
          if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
            KiCheckForKernelApcDelivery(v49);
          v52 = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
          v53 = KfRaiseIrql(1);
          do
            v54 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
          while ( __strex(v54 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
          __dmb(0xBu);
          if ( (v54 & 1) == 0 )
            ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v52);
          if ( v52 )
            *(_BYTE *)(v52 + 14) |= 1u;
          dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          dword_630D3C = v53;
          v55 = *(_DWORD *)(v55 + 4);
          PnpDereferenceNotify(v44);
          if ( v44 == v39 )
            PnpDereferenceNotify(v39);
        }
        while ( v55 != i );
LABEL_63:
        dword_630D24 = 0;
        v56 = dword_630D3C;
        __dmb(0xBu);
        do
          v57 = __ldrex((unsigned int *)&PnpTargetDeviceNotifyLock);
        while ( !v57 && __strex(1u, (unsigned int *)&PnpTargetDeviceNotifyLock) );
        if ( v57 )
          ExpReleaseFastMutexContended((unsigned int *)&PnpTargetDeviceNotifyLock, v57);
        KfLowerIrql(v56);
        KeAbPostRelease((unsigned int)&PnpTargetDeviceNotifyLock);
        ObfDereferenceObject(v58);
        __asm { POP.W           {R4-R11,PC} }
      }
    }
    else
    {
      v33 = ExReleaseResourceLite(*(_DWORD *)(v55 + 40));
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v35 = *(_WORD *)(v34 + 0x134) + 1;
      *(_WORD *)(v34 + 308) = v35;
      if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
        KiCheckForKernelApcDelivery(v33);
    }
    v36 = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
    v37 = KfRaiseIrql(1);
    do
      v38 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
    while ( __strex(v38 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
    __dmb(0xBu);
    if ( (v38 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v36);
    if ( v36 )
      *(_BYTE *)(v36 + 14) |= 1u;
    dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_630D3C = v37;
    if ( v13 )
      v55 = *(_DWORD *)(v55 + 4);
    else
      v55 = *(_DWORD *)v55;
    PnpDereferenceNotify(v62);
  }
}
