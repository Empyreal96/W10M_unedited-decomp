// NtReplaceKey 
 
int __fastcall NtReplaceKey(int *a1, int a2, int *a3)
{
  int v6; // r3
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r5
  int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  bool v16; // zf
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r1
  int v27; // r4
  _BYTE *v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int v37; // r1
  __int16 v38; // r3
  int v40[2]; // [sp+8h] [bp-50h] BYREF
  unsigned __int16 v41; // [sp+10h] [bp-48h] BYREF
  unsigned int v42; // [sp+14h] [bp-44h]
  unsigned __int16 v43; // [sp+18h] [bp-40h] BYREF
  unsigned int v44; // [sp+1Ch] [bp-3Ch]
  int v45; // [sp+20h] [bp-38h] BYREF
  _DWORD v46[5]; // [sp+24h] [bp-34h] BYREF

  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 != v7 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  v13 = CmCheckNoTxContext();
  v12 = v13;
  if ( v13 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v15 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
    v16 = v15 == v14;
    goto LABEL_61;
  }
  v17 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v17, (int)&SeRestorePrivilege) )
  {
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v22 + 308);
    v23 = CmpNameFromAttributes(a1, v17, &v41);
    v12 = v23;
    if ( v23 >= 0 )
    {
      v12 = CmpNameFromAttributes(a3, v17, &v43);
      if ( v12 >= 0 )
      {
        v12 = CmObReferenceObjectByHandle(a2, 0, (int)CmKeyObjectType, v17, v40, 0);
        if ( v12 >= 0 )
        {
          v27 = v40[0];
          if ( (*(_DWORD *)(*(_DWORD *)(v40[0] + 4) + 4) & 0x80) != 0 )
          {
            v12 = -1073741790;
          }
          else
          {
            v45 = 0;
            v28 = memset(v46, 0, sizeof(v46));
            v40[1] = (int)v40;
            v40[0] = (int)v40;
            v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v30 + 308);
            if ( CmpCallBackCount )
            {
              v28 = (_BYTE *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v29, v30, CmpCallBackCount);
              if ( !v28 )
              {
                v45 = v27;
                v46[0] = &v43;
                v46[1] = &v41;
                v28 = (_BYTE *)CmpCallCallBacks(45, &v45, 1, 46, 0, v40);
                v12 = (int)v28;
              }
            }
            if ( v12 < 0 )
            {
              if ( v12 == -1073740541 )
                v12 = 0;
            }
            else
            {
              v31 = CmReplaceKey(*(_DWORD *)(*(_DWORD *)(v27 + 4) + 20), *(_DWORD *)(v27 + 4), &v41, &v43);
              v28 = (_BYTE *)CmPostCallbackNotification(46, v27, v31);
              v12 = (int)v28;
            }
            v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v33 = *(_WORD *)(v32 + 0x134) + 1;
            *(_WORD *)(v32 + 308) = v33;
            if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
              KiCheckForKernelApcDelivery((int)v28);
          }
          ObfDereferenceObject(v27);
        }
        ExFreePoolWithTag(v44);
        v34 = ExFreePoolWithTag(v42);
        v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v36 = *(_WORD *)(v35 + 0x134) + 1;
        *(_WORD *)(v35 + 308) = v36;
        if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
          KiCheckForKernelApcDelivery(v34);
        __pld(&CmpShutdownRundown);
        v13 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v26 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
        goto LABEL_60;
      }
      v23 = ExFreePoolWithTag(v42);
    }
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    __pld(&CmpShutdownRundown);
    v13 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v26 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_60:
    v16 = v26 == v13;
LABEL_61:
    if ( !v16 )
      v13 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v38 = *(_WORD *)(v37 + 0x134) + 1;
    *(_WORD *)(v37 + 308) = v38;
    if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
      KiCheckForKernelApcDelivery(v13);
    return v12;
  }
  __pld(&CmpShutdownRundown);
  v18 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v19 == v18 && __strex(v18 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v19 != v18 )
    v18 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return -1073741727;
}
