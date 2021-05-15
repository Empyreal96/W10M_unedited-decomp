// NtRestoreKey 
 
int __fastcall NtRestoreKey(int a1, int a2, int a3)
{
  int v6; // r3
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  bool v17; // zf
  int v18; // r4
  int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r4
  unsigned int v24; // r1
  int v25; // r4
  _BYTE *v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r0
  unsigned int v30; // r1
  unsigned int v31; // r1
  __int16 v32; // r3
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r1
  __int16 v37; // r3
  int v39; // [sp+8h] [bp-48h] BYREF
  int v40[2]; // [sp+10h] [bp-40h] BYREF
  int v41; // [sp+18h] [bp-38h] BYREF
  _DWORD v42[5]; // [sp+1Ch] [bp-34h] BYREF

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
  v13 = 1;
  v14 = CmCheckNoTxContext();
  v12 = v14;
  if ( v14 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v15 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v16 == v15 && __strex(v15 - 2, (unsigned int *)&CmpShutdownRundown) );
    v17 = v16 == v15;
    goto LABEL_66;
  }
  v18 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v18, (int)&SeRestorePrivilege) )
  {
    __pld(&CmpShutdownRundown);
    v19 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v20 == v19 && __strex(v19 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v20 != v19 )
      v19 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(v19);
    return -1073741727;
  }
  if ( v18 == 1 )
  {
    v39 = 0;
    v40[0] = 0;
    v12 = CmConvertHandleToKernelHandle(a1, (int)CmKeyObjectType, 1, 0, &v39);
    if ( v12 >= 0 )
    {
      v12 = IoConvertFileHandleToKernelHandle(a2, 1, 1, 0, v40);
      if ( v12 >= 0 )
      {
        v23 = v40[0];
        v12 = ZwRestoreKey();
        if ( v23 )
          ZwClose();
      }
      if ( v39 )
        ZwClose();
    }
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v24 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
    goto LABEL_65;
  }
  v12 = CmObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v18, v40, 0);
  if ( v12 < 0 )
    goto LABEL_62;
  v25 = v40[0];
  if ( (*(_DWORD *)(*(_DWORD *)(v40[0] + 4) + 4) & 0x80) != 0 )
  {
    v12 = -1073741790;
  }
  else
  {
    v41 = 0;
    v26 = memset(v42, 0, sizeof(v42));
    v40[1] = (int)v40;
    v40[0] = (int)v40;
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v28 + 308);
    if ( CmpCallBackCount )
    {
      v26 = (_BYTE *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v27, v28, CmpCallBackCount);
      if ( !v26 )
      {
        v41 = v25;
        v42[0] = a2;
        v42[1] = a3;
        v26 = (_BYTE *)CmpCallCallBacks(41, &v41, 1, 42, 0, v40);
        v12 = (int)v26;
      }
    }
    if ( v12 < 0 )
    {
      if ( v12 == -1073740541 )
        v12 = 0;
    }
    else
    {
      __pld(&CmpShutdownRundown);
      v29 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v30 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v30 == v29 && __strex(v29 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v30 != v29 )
        v29 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v32 = *(_WORD *)(v31 + 0x134) + 1;
      *(_WORD *)(v31 + 308) = v32;
      if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
        KiCheckForKernelApcDelivery(v29);
      v13 = 0;
      v33 = CmRestoreKey(v25, a2, a3);
      v26 = (_BYTE *)CmPostCallbackNotification(42, v25, v33);
      v12 = (int)v26;
    }
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v35 = *(_WORD *)(v34 + 0x134) + 1;
    *(_WORD *)(v34 + 308) = v35;
    if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
      KiCheckForKernelApcDelivery((int)v26);
  }
  ObfDereferenceObject(v25);
  if ( v13 )
  {
LABEL_62:
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v24 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
LABEL_65:
    v17 = v24 == v14;
LABEL_66:
    if ( !v17 )
      v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v37 = *(_WORD *)(v36 + 0x134) + 1;
    *(_WORD *)(v36 + 308) = v37;
    if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  return v12;
}
