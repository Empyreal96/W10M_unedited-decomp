// NtEnumerateValueKey 
 
int __fastcall NtEnumerateValueKey(int a1, int a2, int a3, unsigned int a4, int a5, int a6)
{
  int v9; // lr
  __int64 v10; // r0
  int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v17; // r5
  int (__fastcall *v18)(int, _DWORD *, int, int, int, _DWORD); // r4
  char v19; // r3
  unsigned int v20; // r4
  unsigned int v21; // r1
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r4
  int v25; // r8
  int v26; // r6
  unsigned int v27; // r1
  _DWORD *v28; // r2
  unsigned int v29; // r10
  int v30; // r0
  int v31; // r3
  int v32; // r5
  int v33; // r4
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int v37; // r1
  unsigned int v38; // r1
  __int16 v39; // r3
  unsigned int v41; // [sp+18h] [bp-88h] BYREF
  int v42; // [sp+1Ch] [bp-84h] BYREF
  int v43; // [sp+20h] [bp-80h]
  int v44; // [sp+24h] [bp-7Ch]
  unsigned int v45; // [sp+28h] [bp-78h]
  int v46; // [sp+2Ch] [bp-74h]
  int v47[2]; // [sp+30h] [bp-70h] BYREF
  _DWORD v48[4]; // [sp+38h] [bp-68h] BYREF
  int v49; // [sp+48h] [bp-58h] BYREF
  _DWORD v50[8]; // [sp+4Ch] [bp-54h] BYREF
  _DWORD _70[18]; // [sp+70h] [bp-30h] BYREF

  _70[14] = a1;
  _70[17] = a4;
  v41 = a4;
  v46 = a3;
  _70[16] = a3;
  v44 = a2;
  _70[15] = a2;
  v48[2] = a4;
  v45 = a6;
  v47[1] = a6;
  v49 = 0;
  memset(v50, 0, sizeof(v50));
  _70[0] = 0;
  _70[1] = 0;
  _70[2] = 0;
  _70[3] = 0;
  v9 = 0;
  v43 = 0;
  v47[0] = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v10) = _70;
    HIDWORD(v10) = 0x20000;
    EtwGetKernelTraceTimestamp(v10);
    v9 = 0;
  }
  v11 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v11 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v12 = CmpShutdownRundown & 0xFFFFFFFE;
  v13 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v14 == v12 && __strex(v13, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v14 != v12 )
  {
    v14 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v14 )
    {
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(_WORD *)(v15 + 0x134) + 1;
      *(_WORD *)(v15 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
        KiCheckForKernelApcDelivery(0);
      v17 = -1073741431;
      if ( CmpTraceRoutine )
        CmpTraceRoutine(18, _70, -1073741431, a2, 0, 0);
      return v17;
    }
    v9 = 0;
  }
  if ( !a3 || a3 == 1 || a3 == 2 )
  {
    v24 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v17 = CmObReferenceObjectByHandle(a1, 1);
    if ( v17 < 0 )
      goto LABEL_69;
    v25 = v42;
    if ( CmpTraceRoutine && v42 )
    {
      v43 = *(_DWORD *)(v42 + 4);
      v47[0] = v43;
    }
    if ( v24 != 1 )
    {
      v26 = a5;
      v29 = v41;
LABEL_50:
      v48[1] = v48;
      v48[0] = v48;
      v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v31 = *(__int16 *)(v30 + 0x134);
      *(_WORD *)(v30 + 0x134) = v31 - 1;
      if ( CmpCallBackCount )
      {
        v30 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, (int)&CmpCallBackCount, v31 - 1, CmpCallBackCount);
        if ( !v30 )
        {
          v49 = v25;
          v50[0] = v44;
          v50[1] = v46;
          v50[2] = v29;
          v50[3] = v26;
          v50[4] = v45;
          v30 = CmpCallCallBacks(6, &v49, 1, 21, v25, v48);
          v17 = v30;
        }
      }
      if ( v17 < 0 )
      {
        if ( v17 == -1073740541 )
          v17 = 0;
      }
      else
      {
        v41 = 0;
        v32 = CmKeyBodyRemapToVirtualForEnum((int)&v42, &v41);
        v33 = v41;
        v25 = v42;
        if ( v32 >= 0 )
        {
          if ( v41 )
            v34 = CmEnumerateValueKeyFromMergedView(v42, v41, 0, v44, v46, v29, v26, v45, 0);
          else
            v34 = CmEnumerateValueKey(v42, v44, v46, v29, v26, v45);
          v32 = v34;
        }
        if ( v33 )
          ObfDereferenceObject(v33);
        v30 = CmPostCallbackNotification(21, v25, v32, &v49, v48);
        v17 = v30;
      }
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v36 = *(_WORD *)(v35 + 0x134) + 1;
      *(_WORD *)(v35 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
        KiCheckForKernelApcDelivery(v30);
      ObfDereferenceObject(v25);
LABEL_69:
      if ( CmpTraceRoutine )
        CmpTraceRoutine(18, _70, v17, v44, v43, 0);
      __pld(&CmpShutdownRundown);
      v14 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v37 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v37 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v37 != v14 )
        v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v39 = *(_WORD *)(v38 + 0x134) + 1;
      *(_WORD *)(v38 + 308) = v39;
      if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
        goto LABEL_79;
      return v17;
    }
    v26 = a5;
    if ( a5 )
    {
      if ( (v41 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v41);
      v27 = MmUserProbeAddress;
      if ( v41 + a5 <= MmUserProbeAddress && v41 + a5 >= v41 )
        goto LABEL_46;
      *(_BYTE *)MmUserProbeAddress = 0;
    }
    v27 = MmUserProbeAddress;
LABEL_46:
    v28 = (_DWORD *)v45;
    if ( v45 >= v27 )
      v28 = (_DWORD *)v27;
    *v28 = *v28;
    v29 = v41;
    goto LABEL_50;
  }
  v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
  if ( CmpTraceRoutine && a1 )
  {
    v19 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v14 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v19, (int)v47, 0);
    if ( v14 < 0 )
    {
      v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
      v9 = 0;
    }
    else
    {
      v43 = *(_DWORD *)(v47[0] + 4);
      v14 = ObfDereferenceObject(v47[0]);
      v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
      v9 = v43;
    }
  }
  v17 = -1073741811;
  if ( v18 )
    v14 = v18(18, _70, -1073741811, a2, v9, 0);
  __pld(&CmpShutdownRundown);
  v20 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v21 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v21 != v20 )
    v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = (__int16)(*(_WORD *)(v22 + 0x134) + 1);
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
LABEL_79:
    KiCheckForKernelApcDelivery(v14);
  return v17;
}
