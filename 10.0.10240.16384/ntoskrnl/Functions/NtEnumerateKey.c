// NtEnumerateKey 
 
int __fastcall NtEnumerateKey(int a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6)
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
  _DWORD *v25; // r1
  _DWORD *v26; // r8
  int v27; // r10
  _DWORD *v28; // r2
  _DWORD *v29; // r4
  int v30; // r0
  int v31; // r3
  int v32; // r4
  _DWORD *v33; // r5
  unsigned int v34; // r1
  __int16 v35; // r3
  unsigned int v36; // r1
  unsigned int v37; // r1
  __int16 v38; // r3
  _DWORD *v40; // [sp+10h] [bp-88h] BYREF
  int v41; // [sp+14h] [bp-84h]
  int v42; // [sp+18h] [bp-80h]
  unsigned int v43; // [sp+1Ch] [bp-7Ch]
  int v44; // [sp+20h] [bp-78h] BYREF
  _DWORD *v45; // [sp+24h] [bp-74h] BYREF
  unsigned int v46; // [sp+28h] [bp-70h]
  _DWORD v47[4]; // [sp+30h] [bp-68h] BYREF
  _DWORD *v48; // [sp+40h] [bp-58h] BYREF
  _DWORD v49[8]; // [sp+44h] [bp-54h] BYREF
  _DWORD _68[18]; // [sp+68h] [bp-30h] BYREF

  _68[14] = a1;
  _68[17] = a4;
  v46 = a4;
  _68[16] = a3;
  v42 = a2;
  _68[15] = a2;
  v47[3] = a4;
  v43 = a6;
  v47[2] = a6;
  v48 = 0;
  memset(v49, 0, sizeof(v49));
  _68[0] = 0;
  _68[1] = 0;
  _68[2] = 0;
  _68[3] = 0;
  v9 = 0;
  v41 = 0;
  v44 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v10) = _68;
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
        CmpTraceRoutine(17, _68, -1073741431, a2, 0, 0);
      return v17;
    }
    v9 = 0;
  }
  if ( !a3 || a3 == 1 || a3 == 2 )
  {
    v24 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v17 = ObReferenceObjectByHandle(a1, 8, (int)CmKeyObjectType, v24, (int)&v40, 0);
    v25 = v40;
    v26 = v40;
    v45 = v40;
    if ( v17 >= 0 )
    {
      if ( *v40 != 1803104306 )
      {
        v17 = -1073741816;
        ObfDereferenceObject((int)v40);
        v25 = v26;
      }
      if ( v17 >= 0 )
      {
        if ( CmpTraceRoutine && v25 )
        {
          v41 = v25[1];
          v44 = v41;
        }
        if ( v24 == 1 )
        {
          v27 = a5;
          ProbeForWrite(v46, a5, 4);
          v28 = (_DWORD *)v43;
          if ( v43 >= MmUserProbeAddress )
            v28 = (_DWORD *)MmUserProbeAddress;
          *v28 = *v28;
          v29 = v40;
        }
        else
        {
          v27 = a5;
          v29 = v40;
        }
        v47[1] = v47;
        v47[0] = v47;
        v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v31 = *(__int16 *)(v30 + 0x134);
        *(_WORD *)(v30 + 0x134) = v31 - 1;
        if ( CmpCallBackCount )
        {
          v30 = ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, (int)&CmpCallBackCount, v31 - 1, CmpCallBackCount);
          if ( !v30 )
          {
            v48 = v29;
            v49[0] = v42;
            v49[1] = a3;
            v49[2] = v46;
            v49[3] = v27;
            v49[4] = v43;
            v30 = CmpCallCallBacks(5, &v48, 1, 20, v29, v47);
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
          v40 = 0;
          v32 = CmKeyBodyRemapToVirtualForEnum((int)&v45, &v40);
          v33 = v40;
          v26 = v45;
          if ( v32 >= 0 )
            v32 = CmEnumerateKey(v45, v40, v42, a3, v46, v27, v43);
          if ( v33 )
            ObfDereferenceObject((int)v33);
          v30 = CmPostCallbackNotification(20, v26, v32, &v48, v47);
          v17 = v30;
        }
        v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v35 = *(_WORD *)(v34 + 0x134) + 1;
        *(_WORD *)(v34 + 308) = v35;
        if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
          KiCheckForKernelApcDelivery(v30);
        ObfDereferenceObject((int)v26);
      }
    }
    if ( CmpTraceRoutine )
      CmpTraceRoutine(17, _68, v17, v42, v41, 0);
    __pld(&CmpShutdownRundown);
    v14 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v36 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v36 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v36 != v14 )
      v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v38 = *(_WORD *)(v37 + 0x134) + 1;
    *(_WORD *)(v37 + 308) = v38;
    if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
      goto LABEL_72;
  }
  else
  {
    v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
    if ( CmpTraceRoutine && a1 )
    {
      v19 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
      v14 = ObReferenceObjectByHandle(a1, 0, (int)CmKeyObjectType, v19, (int)&v44, 0);
      if ( v14 < 0 )
      {
        v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
        v9 = 0;
      }
      else
      {
        v41 = *(_DWORD *)(v44 + 4);
        v14 = ObfDereferenceObject(v44);
        v18 = (int (__fastcall *)(int, _DWORD *, int, int, int, _DWORD))CmpTraceRoutine;
        v9 = v41;
      }
    }
    v17 = -1073741811;
    if ( v18 )
      v14 = v18(17, _68, -1073741811, a2, v9, 0);
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
    {
LABEL_72:
      KiCheckForKernelApcDelivery(v14);
      return v17;
    }
  }
  return v17;
}
