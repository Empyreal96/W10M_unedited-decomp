// NtQueryMultipleValueKey 
 
int __fastcall NtQueryMultipleValueKey(int a1, int a2, unsigned int a3, int a4, int *a5, _DWORD *a6)
{
  unsigned int v6; // r9
  __int64 v8; // r0
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r5
  unsigned __int8 *v16; // r0
  int v17; // r1
  int v18; // r4
  int *v19; // r3
  int v20; // r9
  _DWORD *v21; // r2
  int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  unsigned int v26; // r4
  unsigned int v27; // r1
  unsigned int v28; // r1
  __int16 v29; // r3
  int v31; // [sp+10h] [bp-A0h] BYREF
  int *v32; // [sp+14h] [bp-9Ch]
  int v33; // [sp+18h] [bp-98h] BYREF
  int v34; // [sp+1Ch] [bp-94h]
  int v35; // [sp+20h] [bp-90h]
  int v36; // [sp+24h] [bp-8Ch] BYREF
  int v37; // [sp+28h] [bp-88h]
  int v38; // [sp+2Ch] [bp-84h]
  _DWORD *v39; // [sp+30h] [bp-80h]
  int v40; // [sp+34h] [bp-7Ch]
  unsigned int v41; // [sp+38h] [bp-78h]
  int v42; // [sp+3Ch] [bp-74h] BYREF
  _DWORD v43[4]; // [sp+40h] [bp-70h] BYREF
  int v44; // [sp+50h] [bp-60h]
  int v45; // [sp+54h] [bp-5Ch]
  int v46; // [sp+58h] [bp-58h] BYREF
  _DWORD v47[8]; // [sp+5Ch] [bp-54h] BYREF
  _DWORD _80[18]; // [sp+80h] [bp-30h] BYREF

  _80[14] = a1;
  _80[15] = a2;
  _80[17] = a4;
  v35 = a4;
  v6 = a3;
  v41 = a3;
  _80[16] = a3;
  v38 = a2;
  v45 = a2;
  v43[3] = a4;
  v32 = a5;
  v43[2] = a5;
  v39 = a6;
  v36 = 0;
  v42 = 0;
  v34 = 0;
  v33 = 0;
  v46 = 0;
  memset(v47, 0, sizeof(v47));
  _80[0] = 0;
  _80[1] = 0;
  _80[2] = 0;
  _80[3] = 0;
  v37 = 0;
  v40 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v8) = _80;
    HIDWORD(v8) = 0x20000;
    EtwGetKernelTraceTimestamp(v8);
  }
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v10 = CmpShutdownRundown & 0xFFFFFFFE;
  v11 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v12 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v12 == v10 && __strex(v11, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v12 == v10 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v44 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v16 = (unsigned __int8 *)CmObReferenceObjectByHandle(a1, 1);
    v15 = (int)v16;
    if ( (int)v16 >= 0 )
    {
      v18 = v31;
      if ( CmpTraceRoutine && v31 )
      {
        v37 = *(_DWORD *)(v31 + 4);
        v40 = v37;
      }
      if ( v44 == 1 )
      {
        v19 = v32;
        if ( (unsigned int)v32 >= MmUserProbeAddress )
          v19 = (int *)MmUserProbeAddress;
        v20 = *v19;
        v36 = *v19;
        if ( v41 > 0x10000 )
          RtlRaiseStatus(-1073741670);
        ProbeForWrite(v38, 16 * v41, 4);
        if ( a6 )
        {
          v21 = a6;
          if ( (unsigned int)a6 >= MmUserProbeAddress )
            v21 = (_DWORD *)MmUserProbeAddress;
          *v21 = *v21;
        }
        v16 = (unsigned __int8 *)ProbeForWrite(v35, v20, 4);
        v6 = v41;
      }
      else
      {
        v36 = *v32;
      }
      if ( v15 >= 0 )
      {
        v43[1] = v43;
        v43[0] = v43;
        v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v22 + 308);
        if ( CmpCallBackCount )
        {
          v16 = (unsigned __int8 *)ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v17, v22, CmpCallBackCount);
          if ( !v16 )
          {
            v46 = v18;
            v47[0] = v38;
            v47[1] = v6;
            v47[2] = v35;
            v47[3] = v32;
            v47[4] = a6;
            v16 = (unsigned __int8 *)CmpCallCallBacks(9, &v46, 1, 24, v18, v43);
            v15 = (int)v16;
          }
        }
        if ( v15 < 0 )
        {
          if ( v15 == -1073740541 )
            v15 = 0;
        }
        else
        {
          v23 = CmKeyBodyRemapToVirtualForEnum(&v31, &v33);
          if ( v23 < 0 )
          {
            v34 = v33;
            v18 = v31;
          }
          else
          {
            v34 = v33;
            v18 = v31;
            v23 = CmQueryMultipleValueKey(v31, v33, v38, v6, v35, &v36, &v42);
            v39 = (_DWORD *)v23;
            *v32 = v36;
            if ( a6 )
              *a6 = v42;
          }
          v16 = (unsigned __int8 *)CmPostCallbackNotification(24, v18, v23, &v46, v43);
          v15 = (int)v16;
        }
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = *(_WORD *)(v24 + 0x134) + 1;
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery((int)v16);
      }
      if ( v34 )
        ObfDereferenceObject(v34);
      v16 = (unsigned __int8 *)ObfDereferenceObject(v18);
    }
    if ( CmpTraceRoutine )
      v16 = (unsigned __int8 *)CmpTraceRoutine(19, _80, v15, v6, v37, 0);
    __pld(&CmpShutdownRundown);
    v26 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v27 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v27 != v26 )
      v16 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery((int)v16);
  }
  else
  {
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(0);
    v15 = -1073741431;
    if ( CmpTraceRoutine )
      CmpTraceRoutine(19, _80, -1073741431, v6, 0, 0);
  }
  return v15;
}
