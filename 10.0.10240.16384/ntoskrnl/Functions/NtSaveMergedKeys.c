// NtSaveMergedKeys 
 
int __fastcall NtSaveMergedKeys(int a1, int a2, int a3)
{
  int v6; // r3
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r5
  unsigned __int8 *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  bool v16; // zf
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r4
  unsigned int v23; // r1
  int v24; // r6
  int v25; // r4
  unsigned int v26; // r1
  __int16 v27; // r3
  int v29; // [sp+8h] [bp-28h] BYREF
  int v30; // [sp+Ch] [bp-24h] BYREF
  int v31[8]; // [sp+10h] [bp-20h] BYREF

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
  v13 = (unsigned __int8 *)CmCheckNoTxContext();
  v12 = (int)v13;
  if ( (int)v13 < 0 )
  {
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v15 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
    v16 = v15 == v14;
LABEL_49:
    if ( !v16 )
      v13 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134) + 1;
    *(_WORD *)(v26 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery((int)v13);
    return v12;
  }
  v17 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v17, (int)&SeBackupPrivilege) )
  {
    if ( v17 == 1 )
    {
      v29 = 0;
      v30 = 0;
      v31[0] = 0;
      v12 = CmConvertHandleToKernelHandle(a1, (int)CmKeyObjectType, 1, 0, &v30);
      if ( v12 >= 0 )
      {
        v12 = CmConvertHandleToKernelHandle(a2, (int)CmKeyObjectType, 1, 0, &v29);
        if ( v12 >= 0 )
        {
          v12 = IoConvertFileHandleToKernelHandle(a3, 1, 2, 0, v31);
          if ( v12 >= 0 )
          {
            v22 = v31[0];
            v12 = ZwSaveMergedKeys();
            if ( v22 )
              ZwClose();
          }
          if ( v29 )
            ZwClose();
        }
        if ( v30 )
          ZwClose();
      }
      __pld(&CmpShutdownRundown);
      v13 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v23 == v13 && __strex((unsigned int)(v13 - 2), (unsigned int *)&CmpShutdownRundown) );
    }
    else
    {
      v12 = CmObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v17, v31, 0);
      if ( v12 >= 0 )
      {
        v12 = CmObReferenceObjectByHandle(a2, 0, (int)CmKeyObjectType, v17, &v30, 0);
        v24 = v31[0];
        if ( v12 >= 0 )
        {
          v25 = v30;
          v12 = CmSaveMergedKeys(*(_DWORD *)(v31[0] + 4), *(_DWORD *)(v30 + 4), a3);
          ObfDereferenceObject(v25);
        }
        ObfDereferenceObject(v24);
      }
      __pld(&CmpShutdownRundown);
      v13 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v23 == v13 && __strex((unsigned int)(v13 - 2), (unsigned int *)&CmpShutdownRundown) );
    }
    v16 = v23 == (_DWORD)v13;
    goto LABEL_49;
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
