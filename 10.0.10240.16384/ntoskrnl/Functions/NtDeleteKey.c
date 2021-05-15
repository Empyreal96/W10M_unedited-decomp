// NtDeleteKey 
 
int __fastcall NtDeleteKey(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, char a19)
{
  int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r1
  unsigned __int8 *v24; // r0
  int v25; // r1
  int v26; // r8
  _DWORD *v27; // r7
  int v28; // r2
  int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  int v32; // r1
  unsigned int v33; // r0
  unsigned int v34; // r2
  unsigned int v35; // r0
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int v39; // r0
  unsigned int v40; // r1
  unsigned int v41; // r1
  __int16 v42; // r3
  unsigned int v43; // r1
  __int16 v44; // r3
  unsigned int v46; // r1
  __int16 v47; // r3
  int v48; // r1
  unsigned int v49; // r0
  unsigned int v50; // r2
  int v51; // r0
  int v52; // r0
  int v53; // r10
  int v54; // r2
  int v55; // r3
  int v56; // r4
  unsigned int v57; // r4
  unsigned int v58; // r1
  unsigned int v59; // r1
  int v60; // r3
  _DWORD *v61; // [sp+10h] [bp-78h] BYREF
  _DWORD *v62; // [sp+14h] [bp-74h] BYREF
  int v63; // [sp+18h] [bp-70h]
  int v64[2]; // [sp+20h] [bp-68h] BYREF
  int v65; // [sp+28h] [bp-60h]
  int v66; // [sp+2Ch] [bp-5Ch]
  int v67; // [sp+30h] [bp-58h]
  int v68[4]; // [sp+38h] [bp-50h] BYREF
  _DWORD v69[4]; // [sp+48h] [bp-40h] BYREF
  int v70[12]; // [sp+58h] [bp-30h] BYREF

  v66 = 0;
  v62 = 0;
  v68[0] = 0;
  v68[1] = 0;
  v68[2] = 0;
  v68[3] = 0;
  v69[0] = 0;
  v69[1] = 0;
  v69[2] = 0;
  v69[3] = 0;
  v65 = 0;
  v67 = a1;
  if ( !CmpTraceRoutine )
  {
    v20 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v20 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v21 = CmpShutdownRundown & 0xFFFFFFFE;
    v22 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v23 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v23 == v21 && __strex(v22, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v23 != v21 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    {
      v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v47 = *(_WORD *)(v46 + 0x134) + 1;
      *(_WORD *)(v46 + 308) = v47;
      if ( !v47 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
        KiCheckForKernelApcDelivery(0);
      v26 = -1073741431;
      if ( CmpTraceRoutine )
        ((void (__fastcall *)(int, _DWORD *, int))CmpTraceRoutine)(12, v69, -1073741431);
      return v26;
    }
    v63 = 1;
    __mrc(15, 0, 13, 0, 3);
    v24 = (unsigned __int8 *)CmObReferenceObjectByHandle(a1, 0x10000);
    v26 = (int)v24;
    if ( v24 == (unsigned __int8 *)-1073741790
      && CmpVEEnabled
      && (v24 = (unsigned __int8 *)CmpIsSystemEntity(&v62)) == 0 )
    {
      __mrc(15, 0, 13, 0, 3);
      v24 = (unsigned __int8 *)CmObReferenceObjectByHandle(a1, 131097);
      v27 = v61;
      v26 = (int)v24;
      if ( (int)v24 >= 0 )
      {
        v24 = (unsigned __int8 *)CmKeyBodyNeedsVirtualImage(v61);
        if ( !v24 )
        {
          v24 = (unsigned __int8 *)ObfDereferenceObject((int)v61);
          v26 = -1073741790;
        }
      }
      v66 = 1;
    }
    else
    {
      v27 = v61;
    }
    v64[1] = (int)v64;
    v64[0] = (int)v64;
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v28 + 0x134);
    if ( v26 < 0 )
    {
LABEL_45:
      v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v44 = *(_WORD *)(v43 + 0x134) + 1;
      *(_WORD *)(v43 + 308) = v44;
      if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
        v24 = (unsigned __int8 *)KiCheckForKernelApcDelivery((int)v24);
      if ( CmpTraceRoutine )
        v24 = (unsigned __int8 *)((int (__fastcall *)(int, _DWORD *, int, _DWORD, int, _DWORD))CmpTraceRoutine)(
                                   12,
                                   v69,
                                   v26,
                                   0,
                                   v65,
                                   0);
      if ( v63 )
      {
        __pld(&CmpShutdownRundown);
        v57 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v58 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v58 == v57 && __strex(v57 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v58 != v57 )
          v24 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v59 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v60 = (__int16)(*(_WORD *)(v59 + 0x134) + 1);
        *(_WORD *)(v59 + 308) = v60;
        if ( !v60 && *(_DWORD *)(v59 + 100) != v59 + 100 && !*(_WORD *)(v59 + 310) )
          KiCheckForKernelApcDelivery((int)v24);
      }
      return v26;
    }
    if ( CmpCallBackCount )
    {
      if ( !ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v25, v28, CmpCallBackCount) )
      {
        v68[0] = (int)v27;
        v26 = CmpCallCallBacks(0, v68, 1, 15, v27, v64);
        if ( v26 < 0 )
        {
          v24 = (unsigned __int8 *)ObfDereferenceObject((int)v27);
          if ( v26 == -1073740541 )
            v26 = 0;
          goto LABEL_45;
        }
      }
    }
    if ( CmpTraceRoutine && v27 )
      v65 = v27[1];
    v29 = KeAbPreAcquire((unsigned int)&ExpKeyManipLock, 0, 0);
    v30 = v29;
    do
      v31 = __ldrex((unsigned int *)&ExpKeyManipLock);
    while ( !v31 && __strex(0x11u, (unsigned int *)&ExpKeyManipLock) );
    __dmb(0xBu);
    if ( v31 )
      ExfAcquirePushLockSharedEx(&ExpKeyManipLock, v29, (unsigned int)&ExpKeyManipLock);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    if ( ExpControlKey && v27[1] == *(_DWORD *)(ExpControlKey + 4)
      || dword_61A10C && v27[1] == *(_DWORD *)(dword_61A10C + 4) )
    {
      __pld(&ExpKeyManipLock);
      v48 = ExpKeyManipLock;
      if ( (ExpKeyManipLock & 0xFFFFFFF0) <= 0x10 )
        v49 = 0;
      else
        v49 = ExpKeyManipLock - 16;
      if ( (ExpKeyManipLock & 2) != 0 )
        goto LABEL_94;
      __dmb(0xBu);
      do
        v50 = __ldrex((unsigned int *)&ExpKeyManipLock);
      while ( v50 == v48 && __strex(v49, (unsigned int *)&ExpKeyManipLock) );
      if ( v50 != v48 )
LABEL_94:
        ExfReleasePushLock(&ExpKeyManipLock, v48);
      KeAbPostRelease((unsigned int)&ExpKeyManipLock);
      v26 = 0;
      goto LABEL_44;
    }
    __pld(&ExpKeyManipLock);
    v32 = ExpKeyManipLock;
    if ( (ExpKeyManipLock & 0xFFFFFFF0) > 0x10 )
      v33 = ExpKeyManipLock - 16;
    else
      v33 = 0;
    if ( (ExpKeyManipLock & 2) != 0 )
      goto LABEL_54;
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&ExpKeyManipLock);
    while ( v34 == v32 && __strex(v33, (unsigned int *)&ExpKeyManipLock) );
    if ( v34 != v32 )
LABEL_54:
      ExfReleasePushLock(&ExpKeyManipLock, v32);
    v35 = KeAbPostRelease((unsigned int)&ExpKeyManipLock);
    v37 = v27[1];
    if ( (*(_DWORD *)(v37 + 4) & 0x80) != 0 || (v38 = *(_DWORD *)(v37 + 40)) != 0 && (*(_DWORD *)(v38 + 4) & 0x80) != 0 )
    {
      v26 = -1073741790;
LABEL_42:
      if ( v26 >= 0 && (v70[0] & 4) != 0 )
      {
        if ( v27[7] || v27[8] )
        {
          CmpLockRegistry(v35, v36);
          v52 = CmpSearchAddTrans(v27, 0, 0, v27[7], v27[8], 0, &v62);
          v53 = v52;
          if ( v52 >= 0 )
          {
            v54 = v62[11];
            v55 = v62[12];
            v56 = v62[13];
            v70[0] = v62[10];
            v70[1] = v54;
            v70[2] = v55;
            v70[3] = v56;
          }
          CmpUnlockRegistry(v52);
          if ( v53 >= 0 )
            SeDeleteObjectAuditAlarmWithTransaction(v27, v67, v70);
        }
        else
        {
          SeDeleteObjectAuditAlarm(v27, v67);
        }
      }
      goto LABEL_44;
    }
    if ( v66 )
    {
      v51 = CmKeyBodyRemapToVirtual(&v61);
      v27 = v61;
      v26 = v51;
      if ( v51 < 0 )
        goto LABEL_44;
      if ( !CmpVEEnabled || (*(_WORD *)(v61[1] + 106) & 0x100) == 0 )
        v26 = -1073741790;
    }
    if ( v26 >= 0 )
    {
      __pld(&CmpShutdownRundown);
      v39 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v40 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v40 == v39 && __strex(v39 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v40 != v39 )
        v39 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v42 = *(_WORD *)(v41 + 0x134) + 1;
      *(_WORD *)(v41 + 308) = v42;
      if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
        KiCheckForKernelApcDelivery(v39);
      v63 = 0;
      v35 = CmDeleteKey(v27);
      v26 = v35;
      goto LABEL_42;
    }
LABEL_44:
    v26 = CmPostCallbackNotification(15, v27, v26, v68, v64);
    v24 = (unsigned __int8 *)ObfDereferenceObject((int)v27);
    goto LABEL_45;
  }
  return sub_7D2004(
           a1,
           a2,
           a3,
           (int)CmpTraceRoutine,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19);
}
