// CmOpenKey 
 
int __fastcall CmOpenKey(_DWORD *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v5; // r6
  __int64 v8; // r0
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r1
  unsigned __int8 *v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r4
  unsigned int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  _DWORD *v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r2
  unsigned int v23; // r3
  int v24; // r0
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned __int64 v32; // [sp+18h] [bp-C0h] BYREF
  int v33; // [sp+20h] [bp-B8h]
  int v34; // [sp+24h] [bp-B4h] BYREF
  int v35; // [sp+28h] [bp-B0h]
  int v36; // [sp+2Ch] [bp-ACh] BYREF
  int v37; // [sp+30h] [bp-A8h]
  unsigned int v38; // [sp+34h] [bp-A4h]
  int v39; // [sp+38h] [bp-A0h]
  int v40; // [sp+3Ch] [bp-9Ch]
  int v41; // [sp+40h] [bp-98h]
  _DWORD *v42; // [sp+44h] [bp-94h]
  unsigned int v43; // [sp+48h] [bp-90h]
  int v44; // [sp+4Ch] [bp-8Ch]
  unsigned int v45; // [sp+50h] [bp-88h]
  unsigned int v46; // [sp+54h] [bp-84h]
  int v47; // [sp+58h] [bp-80h]
  _DWORD v48[19]; // [sp+5Ch] [bp-7Ch] BYREF
  _DWORD _A8[15]; // [sp+A8h] [bp-30h] BYREF
  unsigned int varg_r1; // [sp+E4h] [bp+Ch]
  int varg_r2; // [sp+E8h] [bp+10h]
  int varg_r3; // [sp+ECh] [bp+14h]

  _A8[14] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v35 = a4;
  varg_r3 = a4;
  v5 = a3;
  v42 = a1;
  v44 = a3;
  v39 = a5;
  v34 = a5;
  v36 = 0;
  v32 = 0i64;
  v47 = 0;
  memset(v48, 0, sizeof(v48));
  v41 = 0;
  _A8[0] = 0;
  _A8[1] = 0;
  _A8[2] = 0;
  _A8[3] = 0;
  v33 = 0;
  v37 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v8) = _A8;
    HIDWORD(v8) = 0x20000;
    EtwGetKernelTraceTimestamp(v8);
  }
  v48[5] = a2 & 0x300;
  v38 = a2 & 0xFFFFFCFF;
  varg_r1 = a2 & 0xFFFFFCFF;
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v10 = CmpShutdownRundown & 0xFFFFFFFE;
  v11 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v12 = (unsigned __int8 *)__ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v12 == (unsigned __int8 *)v10 && __strex(v11, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v12 != (unsigned __int8 *)v10 )
  {
    v12 = (unsigned __int8 *)ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v12 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(0);
      v15 = -1073741431;
      if ( CmpTraceRoutine )
        ((void (__fastcall *)(int, _DWORD *, int))CmpTraceRoutine)(11, _A8, -1073741431);
      return v15;
    }
    v5 = a3;
  }
  if ( (v35 & 0xC) == v35 )
  {
    v40 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( v40 == 1 )
    {
      v20 = a1;
      if ( (unsigned int)a1 >= MmUserProbeAddress )
        v20 = (_DWORD *)MmUserProbeAddress;
      *v20 = 0;
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      v21 = *(unsigned int **)(a3 + 8);
      if ( (unsigned int)v21 >= MmUserProbeAddress )
        v21 = (unsigned int *)MmUserProbeAddress;
      v43 = *v21;
      v45 = v43;
      v22 = v21[1];
      v46 = v22;
      v32 = __PAIR64__(v22, v43);
      if ( (_WORD)v43 )
      {
        if ( (v22 & 1) != 0 )
          ExRaiseDatatypeMisalignment(v12);
        v23 = (unsigned __int16)v43 + v22;
        if ( v23 > MmUserProbeAddress || v23 < v22 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
    }
    else
    {
      v32 = *(_QWORD *)*(_DWORD *)(v5 + 8);
    }
    v24 = *(_DWORD *)(a3 + 4);
    v41 = v24;
    if ( CmpTraceRoutine )
    {
      if ( v24 )
      {
        v25 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
        if ( ObReferenceObjectByHandle(v24, 0, CmKeyObjectType, v25, &v34) >= 0 )
        {
          v33 = *(_DWORD *)(v34 + 4);
          v37 = v33;
          ObfDereferenceObject(v34);
        }
      }
    }
    v48[12] = v39;
    v48[4] = v35;
    v15 = ObOpenObjectByName(a3, CmKeyObjectType, v40);
    if ( v15 >= 0 )
      *a1 = v36;
    if ( CmpTraceRoutine )
      ((void (__fastcall *)(int, _DWORD *, int, _DWORD, int, unsigned __int64 *, int *))CmpTraceRoutine)(
        11,
        _A8,
        v15,
        0,
        v33,
        &v32,
        &v36);
    __pld(&CmpShutdownRundown);
    v26 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v27 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v27 != v26 )
      v26 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v26);
  }
  else
  {
    __pld(&CmpShutdownRundown);
    v16 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v17 != v16 )
      v12 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery((int)v12);
    v15 = -1073741582;
  }
  return v15;
}
