// NtSaveKeyEx 
 
int __fastcall NtSaveKeyEx(int a1, int a2, int a3)
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
  int v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r4
  unsigned int v27; // r1
  _BYTE *v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r4
  int v32; // r0
  int v33; // r2
  unsigned int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r1
  __int16 v37; // r3
  int v39[2]; // [sp+8h] [bp-48h] BYREF
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
LABEL_73:
    if ( !v16 )
      v13 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v37 = *(_WORD *)(v36 + 0x134) + 1;
    *(_WORD *)(v36 + 308) = v37;
    if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
      KiCheckForKernelApcDelivery((int)v13);
    return v12;
  }
  v17 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v17, (int)&SeBackupPrivilege) )
  {
    if ( a3 == 1 || a3 == 2 || a3 == 4 )
    {
      if ( v17 == 1 )
      {
        v39[0] = 0;
        v40[0] = 0;
        v12 = CmConvertHandleToKernelHandle(a1, (int)CmKeyObjectType, 1, 0, v39);
        if ( v12 >= 0 )
        {
          v12 = IoConvertFileHandleToKernelHandle(a2, 1, 2, 0, v40);
          if ( v12 >= 0 )
          {
            v26 = v40[0];
            v12 = ZwSaveKeyEx();
            if ( v26 )
              ZwClose();
          }
          if ( v39[0] )
            ZwClose();
        }
        __pld(&CmpShutdownRundown);
        v13 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( (unsigned __int8 *)v27 == v13 && __strex((unsigned int)(v13 - 2), (unsigned int *)&CmpShutdownRundown) );
      }
      else
      {
        v12 = CmObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v17, v40, 0);
        if ( v12 >= 0 )
        {
          v41 = 0;
          v28 = memset(v42, 0, sizeof(v42));
          v39[1] = (int)v39;
          v39[0] = (int)v39;
          v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v30 + 308);
          v31 = v40[0];
          if ( CmpCallBackCount )
          {
            v28 = (_BYTE *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v29, v30, CmpCallBackCount);
            if ( !v28 )
            {
              v41 = v31;
              v42[0] = a2;
              v42[1] = a3;
              v28 = (_BYTE *)CmpCallCallBacks(43, &v41, 1, 44, 0, v39);
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
            if ( a3 == 4 )
            {
              v32 = CmDumpKey(*(_DWORD *)(v31 + 4), a2);
            }
            else
            {
              v33 = 3;
              if ( a3 == 2 )
                v33 = 5;
              v32 = CmSaveKey(*(_DWORD *)(v31 + 4), a2, v33);
            }
            v28 = (_BYTE *)CmPostCallbackNotification(44, v31, v32);
            v12 = (int)v28;
          }
          v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v35 = *(_WORD *)(v34 + 0x134) + 1;
          *(_WORD *)(v34 + 308) = v35;
          if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
            KiCheckForKernelApcDelivery((int)v28);
          ObfDereferenceObject(v31);
        }
        __pld(&CmpShutdownRundown);
        v13 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( (unsigned __int8 *)v27 == v13 && __strex((unsigned int)(v13 - 2), (unsigned int *)&CmpShutdownRundown) );
      }
      v16 = v27 == (_DWORD)v13;
      goto LABEL_73;
    }
    __pld(&CmpShutdownRundown);
    v22 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v23 == v22 && __strex(v22 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v23 != v22 )
      v22 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v22);
    v12 = -1073741811;
  }
  else
  {
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
    v12 = -1073741727;
  }
  return v12;
}
