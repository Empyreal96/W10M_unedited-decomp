// IoCaptureLiveDump 
 
int __fastcall IoCaptureLiveDump(int a1, int a2, int a3, int a4, int a5, int a6, int **a7)
{
  int v7; // r4
  int v8; // r7
  int v9; // r9
  int v10; // r6
  unsigned int v11; // r1
  int *v12; // r5
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r6
  int v17; // r3
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r9
  unsigned int v21; // r1
  unsigned int v22; // r4
  int v23; // r2
  __int64 v24; // r0
  int v25; // r1
  int v26; // r2
  __int64 v27; // r0
  int v28; // r1
  _DWORD *v29; // r3
  _DWORD *v30; // r2
  bool v32; // [sp+8h] [bp-D8h] BYREF
  bool v33; // [sp+9h] [bp-D7h] BYREF
  int v34; // [sp+Ch] [bp-D4h]
  int v35; // [sp+10h] [bp-D0h] BYREF
  int v36; // [sp+18h] [bp-C8h] BYREF
  int v37; // [sp+1Ch] [bp-C4h]
  int v38; // [sp+20h] [bp-C0h] BYREF
  int v39[2]; // [sp+28h] [bp-B8h] BYREF
  int v40; // [sp+30h] [bp-B0h]
  unsigned int v41; // [sp+34h] [bp-ACh]
  int v42; // [sp+38h] [bp-A8h]
  char v43[8]; // [sp+40h] [bp-A0h] BYREF
  int v44; // [sp+48h] [bp-98h]
  int v45; // [sp+4Ch] [bp-94h]
  _DWORD v46[4]; // [sp+50h] [bp-90h] BYREF
  _DWORD v47[8]; // [sp+60h] [bp-80h] BYREF
  int *v48; // [sp+80h] [bp-60h]
  int v49; // [sp+84h] [bp-5Ch]
  int v50; // [sp+88h] [bp-58h]
  int v51; // [sp+8Ch] [bp-54h]
  int *v52; // [sp+90h] [bp-50h]
  int v53; // [sp+94h] [bp-4Ch]
  int v54; // [sp+98h] [bp-48h]
  int v55; // [sp+9Ch] [bp-44h]
  bool *v56; // [sp+A0h] [bp-40h]
  int v57; // [sp+A4h] [bp-3Ch]
  int v58; // [sp+A8h] [bp-38h]
  int v59; // [sp+ACh] [bp-34h]
  int *v60; // [sp+B0h] [bp-30h]
  int v61; // [sp+B4h] [bp-2Ch]
  int v62; // [sp+B8h] [bp-28h]
  int v63; // [sp+BCh] [bp-24h]

  v36 = a4;
  v7 = 0;
  v8 = 0;
  v34 = a6;
  v35 = 0;
  v40 = a3;
  v42 = a2;
  v45 = a1;
  v38 = 0;
  v9 = 0;
  v10 = 0;
  v44 = KeQueryInterruptTime();
  v41 = v11;
  v46[0] = 0;
  v46[1] = 0;
  v46[2] = 0;
  v46[3] = 0;
  v12 = 0;
  IopLiveDumpTraceInterfaceStart();
  if ( a7 )
    *a7 = 0;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(__int16 *)(v13 + 0x134) - 1;
  *(_WORD *)(v13 + 308) = v14;
  v15 = ExAcquireResourceExclusiveLite((int)&IopLiveDumpLock, 0, v13, v14);
  v39[0] = v15;
  if ( v15 != 1 )
  {
    v16 = -1073741267;
    goto LABEL_28;
  }
  if ( (*(_DWORD *)(v34 + 16) & 0x10) != 0 )
  {
    RtlInitUnicodeString((unsigned int)v43, L"\\KernelObjects\\LowNonPagedPoolCondition");
    v9 = IoCreateNotificationEvent((int)v43, &v35);
    RtlInitUnicodeString((unsigned int)v43, L"\\KernelObjects\\LowMemoryCondition");
    v15 = IoCreateNotificationEvent((int)v43, &v38);
    v10 = v15;
    if ( v9 && *(_DWORD *)(v9 + 4) || v15 && *(_DWORD *)(v15 + 4) )
    {
      v16 = -1073741248;
      v7 = v35;
      v8 = v38;
      goto LABEL_24;
    }
    v7 = v35;
    v8 = v38;
  }
  v15 = ExAllocatePoolWithTag(512, 364, 1886217292);
  v12 = (int *)v15;
  if ( !v15 )
  {
    v16 = -1073741670;
LABEL_24:
    if ( v7 )
      v15 = ZwClose();
    if ( v8 )
      v15 = ZwClose();
    goto LABEL_28;
  }
  memset((_BYTE *)v15, 0, 364);
  v12[81] = v9;
  v12[82] = v10;
  IopLiveDumpContext = (int)v12;
  v17 = v45;
  v12[79] = v7;
  v12[80] = v8;
  *v12 = v17;
  v7 = 0;
  v12[1] = v42;
  v8 = 0;
  v12[2] = v40;
  v12[3] = v36;
  v12[4] = a5;
  EtwActivityIdControl(5, v12 + 83);
  EtwActivityIdControl(1, v12 + 87);
  if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
    TlgWrite(&dword_617540, (unsigned __int8 *)dword_4138DC, (int)(v12 + 87), (int)(v12 + 83), 2, v47);
  v15 = IopLiveDumpValidateParameters(v12, v34);
  v16 = v15;
  if ( v15 >= 0 )
  {
    if ( (v12[5] & 8) != 0 && !a7 )
    {
      v16 = -1073741811;
      goto LABEL_28;
    }
    v15 = IopLiveDumpAllocAndInitResources(v12);
    v16 = v15;
    if ( v15 < 0 )
      goto LABEL_28;
    v15 = IopLiveDumpCaptureMemoryPages((int)v12);
    v16 = v15;
    goto LABEL_24;
  }
LABEL_28:
  if ( (*(_DWORD *)(v34 + 16) & 0x10) != 0 && v16 == -1073741248 )
  {
    v15 = IopLiveDumpIsTracingEnabled();
    if ( v15 == 1 )
      v15 = EtwWrite(
              IopLiveDumpEtwRegHandle,
              SHIDWORD(IopLiveDumpEtwRegHandle),
              (int)LIVEDUMP_EVENT_MEMORY_PRESSURE_ABORT,
              0);
  }
  if ( v39[0] )
  {
    IopLiveDumpContext = 0;
    v15 = ExReleaseResourceLite((int)&IopLiveDumpLock);
  }
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v15);
  if ( v16 >= 0 )
  {
    if ( (v12[5] & 8) != 0 )
    {
      v16 = -1073741802;
      *a7 = v12;
    }
    else
    {
      IopLiveDumpTrace();
      v20 = KeQueryInterruptTime();
      v22 = v21;
      v16 = IopLiveDumpWriteDumpFile(v12);
      if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
      {
        v23 = v12[57];
        v39[0] = *(_DWORD *)(v23 + 4000);
        v39[1] = *(_DWORD *)(v23 + 4004);
        LODWORD(v24) = KeQueryInterruptTime();
        v36 = _rt_udiv64(10000i64, v24 - __PAIR64__(v22, v20));
        v37 = v25;
        v48 = v39;
        v49 = 0;
        v50 = 8;
        v51 = 0;
        v52 = &v36;
        v53 = 0;
        v54 = 8;
        v55 = 0;
        TlgWrite(&dword_617540, (unsigned __int8 *)&word_413892 + 1, (int)(v12 + 87), (int)(v12 + 83), 4, v47);
      }
      IopLiveDumpTraceDumpFileWriteEnd((int)v12, 0, v16);
      if ( v16 >= 0 && (v12[12] & 2) != 0 )
        v16 = 261;
    }
  }
  IopLiveDumpTraceInterfaceEnd();
  if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
  {
    v39[0] = v16;
    v26 = *(_DWORD *)(v34 + 16);
    v33 = (v26 & 8) != 0;
    v32 = (v26 & 0x10) != 0;
    LODWORD(v27) = KeQueryInterruptTime();
    v36 = _rt_udiv64(10000i64, v27 - __PAIR64__(v41, v44));
    v37 = v28;
    v48 = v39;
    v49 = 0;
    v50 = 4;
    v51 = 0;
    v52 = (int *)&v33;
    v53 = 0;
    v54 = 1;
    v55 = 0;
    v56 = &v32;
    v57 = 0;
    v58 = 1;
    v59 = 0;
    v60 = &v36;
    v61 = 0;
    v62 = 8;
    v63 = 0;
    if ( v12 )
      v29 = v12 + 83;
    else
      v29 = v46;
    if ( v12 )
      v30 = v12 + 87;
    else
      v30 = v46;
    TlgWrite(&dword_617540, (unsigned __int8 *)dword_41381C, (int)v30, (int)v29, 6, v47);
  }
  if ( v12 )
  {
    if ( (v12[5] & 8) == 0 )
      EtwActivityIdControl(2, v12 + 83);
    if ( v16 != -1073741802 )
    {
      IopLiveDumpReleaseResources(v12);
      ExFreePoolWithTag((unsigned int)v12);
    }
  }
  return v16;
}
