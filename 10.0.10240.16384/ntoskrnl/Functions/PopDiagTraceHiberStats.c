// PopDiagTraceHiberStats 
 
int PopDiagTraceHiberStats()
{
  int v0; // r7
  int v1; // r8
  _QWORD *v2; // r3
  int v3; // r0
  int v4; // r1
  int v5; // r9
  __int64 v6; // r2
  __int64 v7; // r2
  __int64 v8; // r2
  __int16 **v9; // r8
  char *v10; // r4
  char *v11; // r5
  int v12; // r9
  __int64 *v13; // r3
  _DWORD *v14; // r2
  __int64 v15; // r0
  __int64 v16; // r0
  int v17; // r9
  int v18; // r3
  int v19; // r5
  __int64 v20; // r8
  __int64 v21; // r0
  __int64 v22; // r0
  __int64 v23; // r0
  __int64 v24; // r0
  __int64 v25; // r0
  __int64 v26; // r0
  __int64 v27; // r2
  unsigned int v28; // r1
  unsigned int v29; // r2
  unsigned int v30; // r0
  signed __int64 v31; // kr20_8
  __int64 v32; // kr28_8
  int v34; // [sp+8h] [bp-4B8h] BYREF
  char v35[8]; // [sp+10h] [bp-4B0h] BYREF
  __int64 v36; // [sp+18h] [bp-4A8h]
  int v37; // [sp+20h] [bp-4A0h]
  int v38[4]; // [sp+28h] [bp-498h] BYREF
  char v39; // [sp+38h] [bp-488h] BYREF
  char v40; // [sp+1B0h] [bp-310h] BYREF

  if ( PopOpenPowerKey((int)&v34) >= 0 )
    v0 = v34;
  else
    v0 = 0;
  *(_QWORD *)&qword_61F070 = PopCaptureTimeOnProcZero();
  v1 = qword_61F070;
  if ( KeNumberProcessors_0 )
    v2 = KiProcessorBlock;
  else
    v2 = 0;
  v3 = _rt_udiv64(1000000i64, v2[121]);
  v5 = v4;
  v34 = v4;
  v36 = 1000i64 * (unsigned int)v3;
  *(_QWORD *)&dword_61F090 = HvlQueryHypervisorTscAdjustment();
  qword_61F068 -= *(_QWORD *)&dword_61F090;
  qword_61EFF8 = qword_61F068 - qword_61F000;
  qword_61F078 -= qword_61F088 + *(_QWORD *)&dword_61F090;
  qword_61F098 -= qword_61F088 + *(_QWORD *)&dword_61F090;
  qword_61F070 = v1 - (qword_61F088 + dword_61F090);
  MEMORY[0x61F074] = v1 - (qword_61F088 + dword_61F090);
  LODWORD(v6) = &PopHiberInfo;
  qword_61F0A0 -= qword_61F088 + *(_QWORD *)&dword_61F090;
  dword_61F16C = dword_61EED4;
  HIDWORD(v6) = dword_61EF18;
  dword_61F168 = dword_61EF18;
  dword_61F118 = PopQpcTimeInMs(&dword_61EF68, &dword_61EF70, v6);
  dword_61EFE0 = PopQpcTimeInMs(&dword_61EF48, &dword_61EFE0, v7);
  dword_61EFE4 = 0;
  LODWORD(v8) = v36;
  HIDWORD(v8) = HIDWORD(v36) + 1000 * v5;
  PopComputeDerivedHiberStats((int)&qword_61EFA0, v8, v38);
  v9 = &PopHiberLogInfo;
  v10 = &v39;
  v11 = &v40;
  v37 = 47;
  do
  {
    v12 = (int)v9[2];
    if ( (v12 & 0x40000000) != 0 )
      v13 = (__int64 *)v38;
    else
      v13 = &qword_61EFA0;
    v14 = (_DWORD *)((char *)v13 + (_DWORD)v9[1]);
    *(_DWORD *)v10 = *v14;
    if ( (v12 & 2) != 0 )
      *((_DWORD *)v10 + 1) = v14[1];
    else
      *((_DWORD *)v10 + 1) = 0;
    if ( v12 < 0 )
    {
      HIDWORD(v15) = HIDWORD(v36) + 1000 * v34;
      LODWORD(v15) = v36;
      if ( !__PAIR64__(HIDWORD(v15), v36) )
        __brkdiv0();
      LODWORD(v16) = _rt_udiv64(v15, *(_QWORD *)v10);
      *(_QWORD *)v10 = v16;
    }
    if ( (v12 & 0x20) != 0 )
      v17 = 8;
    else
      v17 = 4;
    if ( v0 )
    {
      RtlInitUnicodeString((unsigned int)v35, (unsigned __int16 *)*v9);
      ZwSetValueKey();
    }
    v18 = v37;
    *(_DWORD *)v11 = v10;
    *((_DWORD *)v11 + 1) = 0;
    *((_DWORD *)v11 + 2) = v17;
    *((_DWORD *)v11 + 3) = 0;
    v11 += 16;
    v10 += 8;
    v37 = v18 - 1;
    v9 += 3;
  }
  while ( v18 != 1 );
  v19 = v34;
  v20 = v36;
  HIDWORD(v21) = HIDWORD(v36) + 1000 * v34;
  LODWORD(v21) = v36;
  if ( !__PAIR64__(HIDWORD(v21), v36) )
    __brkdiv0();
  LODWORD(v22) = _rt_udiv64(v21, qword_61F0E0);
  qword_61F0E0 = v22;
  HIDWORD(v23) = HIDWORD(v20) + 1000 * v19;
  LODWORD(v23) = v20;
  if ( !__PAIR64__(HIDWORD(v23), v20) )
    __brkdiv0();
  LODWORD(v24) = _rt_udiv64(v23, qword_61EFA8);
  qword_61EFA8 = v24;
  HIDWORD(v25) = HIDWORD(v20) + 1000 * v19;
  LODWORD(v25) = v20;
  if ( !__PAIR64__(HIDWORD(v25), v20) )
    __brkdiv0();
  LODWORD(v26) = _rt_udiv64(v25, *(unsigned __int64 *)&qword_61F070);
  qword_61F170 = v26 - (unsigned int)dword_61EFE8 - (unsigned int)dword_61EFF0;
  if ( v0 )
  {
    RtlInitUnicodeString((unsigned int)v35, L"KernelResumeIoCpuTime");
    ZwSetValueKey();
    RtlInitUnicodeString((unsigned int)v35, L"HiberIoCpuTime");
    ZwSetValueKey();
    LODWORD(v27) = qword_61F108;
    if ( qword_61F108 )
    {
      HIDWORD(v27) = HIDWORD(qword_61F108) | qword_61F108;
      dword_61EEB8 += PopQpcTimeInMs(&dword_61EF58, &dword_61F110, v27);
      RtlInitUnicodeString((unsigned int)v35, L"HybridBootAnimationTime");
      ZwSetValueKey();
    }
    v28 = MEMORY[0xFFFF9004];
    while ( 1 )
    {
      v29 = MEMORY[0xFFFF9324];
      __dmb(0xBu);
      v30 = MEMORY[0xFFFF9320];
      __dmb(0xBu);
      if ( v29 == MEMORY[0xFFFF9328] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v31 = v30 * (unsigned __int64)v28;
    dword_61F178 = (v31 >> 24) + ((v29 * v28) << 8);
    dword_61F17C = (((unsigned __int64)v31 >> 24) + ((v29 * (unsigned __int64)v28) << 8)) >> 32;
    RtlInitUnicodeString((unsigned int)v35, L"ResumeCompleteTimestamp");
    ZwSetValueKey();
    LODWORD(v26) = ZwClose();
  }
  if ( PopDiagHandleRegistered )
  {
    v32 = *(_QWORD *)&PopDiagHandle;
    LODWORD(v26) = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_HIBER_STATS);
    if ( (_DWORD)v26 )
      LODWORD(v26) = EtwWrite(v32, SHIDWORD(v32), (int)POP_ETW_EVENT_HIBER_STATS, 0);
  }
  return v26;
}
