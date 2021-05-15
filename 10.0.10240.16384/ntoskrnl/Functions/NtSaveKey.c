// NtSaveKey 
 
int __fastcall NtSaveKey(int a1, int a2)
{
  int v4; // r3
  unsigned int v5; // r5
  unsigned int v6; // r2
  unsigned int v7; // r4
  unsigned int v8; // r1
  __int16 v9; // r3
  int v10; // r5
  unsigned __int8 *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  bool v14; // zf
  int v15; // r4
  int v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r4
  unsigned int v21; // r1
  _BYTE *v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r4
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r1
  __int16 v30; // r3
  int v32[2]; // [sp+8h] [bp-40h] BYREF
  int v33[2]; // [sp+10h] [bp-38h] BYREF
  int v34; // [sp+18h] [bp-30h] BYREF
  _DWORD v35[11]; // [sp+1Ch] [bp-2Ch] BYREF

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
  v11 = (unsigned __int8 *)CmCheckNoTxContext();
  v10 = (int)v11;
  if ( (int)v11 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v12 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v13 == v12 && __strex(v12 - 2, (unsigned int *)&CmpShutdownRundown) );
    v14 = v13 == v12;
LABEL_55:
    if ( !v14 )
      v11 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v30 = *(_WORD *)(v29 + 0x134) + 1;
    *(_WORD *)(v29 + 308) = v30;
    if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
      KiCheckForKernelApcDelivery((int)v11);
    return v10;
  }
  v15 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v15, (int)&SeBackupPrivilege) )
  {
    if ( v15 == 1 )
    {
      v32[0] = 0;
      v33[0] = 0;
      v10 = CmConvertHandleToKernelHandle(a1, (int)CmKeyObjectType, 1, 0, v32);
      if ( v10 >= 0 )
      {
        v10 = IoConvertFileHandleToKernelHandle(a2, 1, 2, 0, v33);
        if ( v10 >= 0 )
        {
          v20 = v33[0];
          v10 = ZwSaveKey();
          if ( v20 )
            ZwClose();
        }
        if ( v32[0] )
          ZwClose();
      }
      __pld(&CmpShutdownRundown);
      v11 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v21 == v11 && __strex((unsigned int)(v11 - 2), (unsigned int *)&CmpShutdownRundown) );
    }
    else
    {
      v10 = CmObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v15, v33, 0);
      if ( v10 >= 0 )
      {
        v34 = 0;
        v22 = memset(v35, 0, 20);
        v32[1] = (int)v32;
        v32[0] = (int)v32;
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v24 + 308);
        v25 = v33[0];
        if ( CmpCallBackCount )
        {
          v22 = (_BYTE *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v23, v24, CmpCallBackCount);
          if ( !v22 )
          {
            v35[0] = a2;
            v35[1] = 1;
            v34 = v25;
            v22 = (_BYTE *)CmpCallCallBacks(43, &v34, 1, 44, 0, v32);
            v10 = (int)v22;
          }
        }
        if ( v10 < 0 )
        {
          if ( v10 == -1073740541 )
            v10 = 0;
        }
        else
        {
          v26 = CmSaveKey(*(_DWORD *)(v25 + 4), a2, 3);
          v22 = (_BYTE *)CmPostCallbackNotification(44, v25, v26);
          v10 = (int)v22;
        }
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x134) + 1;
        *(_WORD *)(v27 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
          KiCheckForKernelApcDelivery((int)v22);
        ObfDereferenceObject(v25);
      }
      __pld(&CmpShutdownRundown);
      v11 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v21 == v11 && __strex((unsigned int)(v11 - 2), (unsigned int *)&CmpShutdownRundown) );
    }
    v14 = v21 == (_DWORD)v11;
    goto LABEL_55;
  }
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
  return -1073741727;
}
