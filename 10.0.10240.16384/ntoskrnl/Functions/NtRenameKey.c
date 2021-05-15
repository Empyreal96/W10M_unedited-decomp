// NtRenameKey 
 
int __fastcall NtRenameKey(int a1, int a2)
{
  unsigned int *v2; // r4
  unsigned int v3; // r9
  int v4; // r3
  unsigned int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1
  __int16 v9; // r3
  int result; // r0
  int v11; // r0
  unsigned __int16 *v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned __int8 *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  int v26; // t1
  int v27; // r5
  int v28; // r1
  unsigned int *v29; // r2
  int v30; // r4
  int v31; // r8
  int v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r1
  int v35; // r0
  __int16 v36; // r2
  unsigned int v37; // r1
  __int16 v38; // r3
  unsigned int v39; // r4
  unsigned int v40; // r1
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned __int64 v43; // [sp+8h] [bp-80h] BYREF
  int v44; // [sp+10h] [bp-78h]
  char v45; // [sp+14h] [bp-74h]
  unsigned int v46; // [sp+18h] [bp-70h]
  char v47; // [sp+1Ch] [bp-6Ch]
  char v48; // [sp+1Dh] [bp-6Bh]
  int v49; // [sp+20h] [bp-68h] BYREF
  unsigned __int8 *v50; // [sp+24h] [bp-64h]
  unsigned __int8 *v51; // [sp+28h] [bp-60h]
  int v52; // [sp+2Ch] [bp-5Ch]
  int v53; // [sp+30h] [bp-58h]
  _DWORD v54[2]; // [sp+38h] [bp-50h] BYREF
  int v55; // [sp+40h] [bp-48h] BYREF
  int v56; // [sp+44h] [bp-44h]
  int v57; // [sp+48h] [bp-40h] BYREF
  unsigned __int64 *v58; // [sp+4Ch] [bp-3Ch]
  int v59; // [sp+50h] [bp-38h]
  int v60; // [sp+54h] [bp-34h]
  int v61; // [sp+58h] [bp-30h]
  unsigned int v62; // [sp+60h] [bp-28h]
  unsigned int v63; // [sp+64h] [bp-24h]
  int anonymous20; // [sp+90h] [bp+8h]
  int anonymous21; // [sp+94h] [bp+Ch]

  anonymous21 = a2;
  v2 = (unsigned int *)a2;
  v52 = a1;
  anonymous20 = a1;
  v43 = 0i64;
  v56 = 0;
  v48 = 0;
  v55 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v3 = 0;
  v50 = 0;
  v51 = 0;
  v4 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v5 = CmpShutdownRundown & 0xFFFFFFFE;
  v6 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v7 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v7 != v5 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = *(_WORD *)(v8 + 0x134) + 1;
    *(_WORD *)(v8 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  v53 = 1;
  v47 = 1;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v44 = v11;
  v45 = v11;
  if ( v11 == 1 )
  {
    if ( (unsigned int)v2 >= MmUserProbeAddress )
      v2 = (unsigned int *)MmUserProbeAddress;
    v46 = *v2;
    v62 = v46;
    v63 = v2[1];
    v12 = (unsigned __int16 *)v63;
    v43 = __PAIR64__(v63, v46);
    if ( (_WORD)v46 )
    {
      if ( (v63 & 1) != 0 )
        ExRaiseDatatypeMisalignment(1);
      v13 = (unsigned __int16)v46 + v63;
      if ( v13 > MmUserProbeAddress || v13 < v63 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v12 = (unsigned __int16 *)HIDWORD(v43);
      }
    }
  }
  else
  {
    v14 = *v2;
    v12 = (unsigned __int16 *)v2[1];
    __dmb(0xBu);
    v43 = __PAIR64__((unsigned int)v12, v14);
    v3 = (unsigned int)v51;
    v50 = v51;
    v11 = v44;
  }
  v15 = (unsigned __int16)v43;
  if ( (unsigned __int16)v43 > 0x200u || !(_WORD)v43 || (v43 & 1) != 0 )
  {
    __pld(&CmpShutdownRundown);
    v16 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v17 != v16 )
      v16 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v16);
    result = -1073741811;
    v46 = -1073741811;
    return result;
  }
  if ( v11 == 1 )
  {
    v20 = (unsigned __int8 *)ExAllocatePoolWithQuotaTag(0x208u, (unsigned __int16)v43, 1114524995);
    v3 = (unsigned int)v20;
    v50 = v20;
    v51 = v20;
    if ( !v20 )
    {
      __pld(&CmpShutdownRundown);
      v21 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v22 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v22 == v21 && __strex(v21 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v22 != v21 )
        v20 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = *(_WORD *)(v23 + 0x134) + 1;
      *(_WORD *)(v23 + 308) = v24;
      if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
        KiCheckForKernelApcDelivery((int)v20);
      result = -1073741670;
      v46 = -1073741670;
      return result;
    }
    memmove((int)v20, SHIDWORD(v43), (unsigned __int16)v43);
    v12 = (unsigned __int16 *)v3;
    HIDWORD(v43) = v3;
    v15 = (unsigned __int16)v43;
  }
  v25 = 0;
  if ( v15 )
  {
    while ( 1 )
    {
      v26 = *v12++;
      if ( v26 == 92 )
        break;
      v25 += 2;
      if ( v25 >= v15 )
        goto LABEL_52;
    }
    v27 = -1073741811;
  }
  else
  {
LABEL_52:
    v25 = CmObReferenceObjectByHandle(v52, 131078, (int)CmKeyObjectType, v44, &v49, 0);
    v27 = v25;
    if ( v25 == -1073741790
      && CmpVEEnabled
      && (v25 = CmpIsSystemEntity(&v55, v28, v29, (unsigned __int8)CmpVEEnabled)) == 0 )
    {
      v25 = CmObReferenceObjectByHandle(v52, 131097, (int)CmKeyObjectType, v44, &v49, 0);
      v27 = v25;
      v30 = v49;
      if ( v25 >= 0 )
      {
        v25 = CmKeyBodyNeedsVirtualImage(v49);
        if ( !v25 )
        {
          v25 = ObfDereferenceObject(v30);
          v27 = -1073741790;
        }
      }
      v31 = 1;
    }
    else
    {
      v30 = v49;
      v31 = v56;
    }
    if ( v27 >= 0 )
    {
      v54[1] = v54;
      v54[0] = v54;
      v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v32 + 308);
      if ( CmpCallBackCount )
      {
        v25 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v28, v32, CmpCallBackCount);
        if ( !v25 )
        {
          v57 = v30;
          v58 = &v43;
          v25 = CmpCallCallBacks(4, &v57, 1, 19, v30, v54);
          v27 = v25;
        }
      }
      if ( v27 < 0 )
      {
        if ( v27 == -1073740541 )
          v27 = 0;
      }
      else
      {
        CmpLockRegistryExclusive();
        CmpFlushNotifiesOnKeyBodyList(*(_DWORD *)(v30 + 4));
        if ( (*(_DWORD *)(*(_DWORD *)(v30 + 4) + 4) & 0x180) != 0 )
        {
          v27 = -1073741790;
        }
        else
        {
          if ( v31 )
          {
            v27 = CmKeyBodyReplicateToVirtual(&v49, 131078, &v55);
            v30 = v49;
          }
          if ( v27 >= 0 )
          {
            __pld(&CmpShutdownRundown);
            v33 = CmpShutdownRundown & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v34 = __ldrex((unsigned int *)&CmpShutdownRundown);
            while ( v34 == v33 && __strex(v33 - 2, (unsigned int *)&CmpShutdownRundown) );
            if ( v34 != v33 )
              ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
            v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v36 = *(_WORD *)(v35 + 0x134) + 1;
            *(_WORD *)(v35 + 308) = v36;
            if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
              KiCheckForKernelApcDelivery(v35);
            v53 = 0;
            v27 = CmRenameKey(v30, v43, HIDWORD(v43), v44);
          }
        }
        CmpUnlockRegistry();
        v25 = CmPostCallbackNotification(19, v30, v27);
        v27 = v25;
      }
      v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v38 = *(_WORD *)(v37 + 0x134) + 1;
      *(_WORD *)(v37 + 308) = v38;
      if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
        KiCheckForKernelApcDelivery(v25);
      v25 = ObfDereferenceObject(v30);
    }
    v3 = (unsigned int)v50;
  }
  if ( v3 )
    v25 = ExFreePoolWithTag(v3);
  if ( v53 )
  {
    __pld(&CmpShutdownRundown);
    v39 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v40 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v40 == v39 && __strex(v39 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v40 != v39 )
      v25 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v42 = *(_WORD *)(v41 + 0x134) + 1;
    *(_WORD *)(v41 + 308) = v42;
    if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
      KiCheckForKernelApcDelivery(v25);
  }
  return v27;
}
