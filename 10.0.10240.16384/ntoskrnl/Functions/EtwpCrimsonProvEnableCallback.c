// EtwpCrimsonProvEnableCallback 
 
_DWORD *__fastcall EtwpCrimsonProvEnableCallback(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // r5
  int v12; // r4
  __int64 v13; // kr00_8
  _DWORD *result; // r0
  int v15; // r4
  int v16; // r4
  int v17; // r1
  int v18; // r5
  int *v19; // r6
  unsigned int v20; // r2
  int v21; // t1
  int v22; // r4
  __int64 v23; // kr08_8
  int v24; // r3
  __int64 v25; // kr10_8
  int v26; // [sp+8h] [bp-60h] BYREF
  int v27; // [sp+Ch] [bp-5Ch]
  int v28; // [sp+10h] [bp-58h]
  int v29; // [sp+14h] [bp-54h]
  int v30; // [sp+18h] [bp-50h]
  int v31; // [sp+1Ch] [bp-4Ch]

  v11 = a10;
  KeWaitForSingleObject((unsigned int)&EtwpCrimsonMaskMutex, 0, 0, 0, 0);
  if ( a10 != 1 )
  {
    if ( a10 == 0x2000000 )
    {
      v22 = 0;
      v23 = *(_QWORD *)&EtwpFileProvRegHandle;
      if ( EtwProviderEnabled(EtwpFileProvRegHandle, unk_61A92C, 0, (int)&EtwpFileProvRegHandle, 16i64) )
        v22 = 512;
      if ( EtwProviderEnabled(v23, SHIDWORD(v23), 0, 96, 96i64) )
        v22 |= 0x2000000u;
      if ( EtwProviderEnabled(v23, SHIDWORD(v23), 0, 8096, 8096i64) )
        v22 |= 0x4000000u;
      v24 = 100663808;
    }
    else
    {
      if ( a10 != 536870913 )
      {
        if ( !a2 )
          v11 = 0;
        v26 = a10;
        v27 = v11;
        goto LABEL_40;
      }
      v22 = 0;
      v25 = *(_QWORD *)&EtwpMemoryProvRegHandle;
      if ( EtwProviderEnabled(EtwpMemoryProvRegHandle, unk_61A944, 0, (int)&EtwpMemoryProvRegHandle, 32i64) )
        v22 = 537395200;
      if ( EtwProviderEnabled(v25, SHIDWORD(v25), 0, 64, 64i64) )
        v22 |= 0x20800000u;
      v24 = 545783808;
    }
    v26 = v24;
    v27 = v22;
LABEL_40:
    v18 = 1;
    goto LABEL_17;
  }
  v12 = 0;
  v13 = *(_QWORD *)&EtwpPsProvRegHandle;
  if ( EtwEventEnabled(EtwpPsProvRegHandle, dword_61A934, (int)ProcessStart)
    || EtwEventEnabled(v13, SHIDWORD(v13), (int)EnableProcessTracingCallbacks) )
  {
    v12 = 1;
  }
  if ( EtwEventEnabled(v13, SHIDWORD(v13), (int)ThreadStart) )
    return (_DWORD *)sub_81AC34();
  if ( EtwEventEnabled(v13, SHIDWORD(v13), (int)ImageLoad) )
    v12 |= 4u;
  if ( EtwEventEnabled(v13, SHIDWORD(v13), (int)JobStart) )
    v12 |= 0x80000u;
  v26 = 524295;
  v27 = v12;
  v15 = 0;
  if ( EtwProviderEnabled(v13, SHIDWORD(v13), 0, 384, 384i64) )
    v15 = 536879104;
  v28 = 536879104;
  v29 = v15;
  v16 = 0;
  if ( EtwProviderEnabled(v13, SHIDWORD(v13), 0, 536879104, 512i64) )
    v16 = 1073741826;
  v18 = 3;
  v30 = 1073741826;
  v31 = v16;
  if ( a2 == 2 )
    EtwpPsProvCaptureState(PsProvGuid, v17, a5, a6);
LABEL_17:
  v19 = &v26;
  do
  {
    v20 = v19[1];
    v21 = *v19;
    v19 += 2;
    EtwpGroupMasks[(v20 >> 29) + 64] |= v20 & 0x1FFFFFFF;
    EtwpGroupMasks[((v21 & ~v20) >> 29) + 64] &= ~(v21 & ~v20 & 0x1FFFFFFF);
    --v18;
  }
  while ( v18 );
  KeReleaseMutex((int)&EtwpCrimsonMaskMutex);
  result = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1467446341);
  if ( result )
  {
    result[2] = EtwpUpdateKernelGroupsWork;
    result[3] = result;
    *result = 0;
    result = (_DWORD *)ExQueueWorkItem(result, 1);
  }
  return result;
}
