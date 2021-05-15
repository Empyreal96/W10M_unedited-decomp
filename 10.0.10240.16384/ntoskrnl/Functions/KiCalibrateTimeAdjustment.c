// KiCalibrateTimeAdjustment 
 
void *__fastcall KiCalibrateTimeAdjustment(int a1)
{
  int v1; // r8
  unsigned int v2; // r3
  unsigned int v3; // r9
  bool v4; // zf
  char v5; // r3
  void *result; // r0
  int v7; // r10
  __int64 v8; // r4
  __int64 v9; // r0
  int v10; // r2
  int v11; // r3
  __int64 v12; // r0
  __int64 v13; // kr08_8
  int v14; // r7
  int v15; // r7
  unsigned __int64 v16; // kr28_8
  int v17; // r0
  unsigned __int64 v18; // r2
  int v19; // r0
  __int64 v20; // kr30_8
  int v21; // r4
  __int64 v22; // kr38_8
  __int64 *v23; // r0
  int v24; // r1
  int v25; // r2
  char *v26; // r3
  int v27; // r4
  int v28; // [sp+8h] [bp-60h] BYREF
  __int64 v29; // [sp+10h] [bp-58h] BYREF
  unsigned int v30; // [sp+18h] [bp-50h]
  int v31; // [sp+1Ch] [bp-4Ch]
  unsigned int v32; // [sp+20h] [bp-48h]
  __int64 v33; // [sp+28h] [bp-40h] BYREF
  unsigned int v34; // [sp+30h] [bp-38h] BYREF
  unsigned int v35; // [sp+34h] [bp-34h]
  __int64 v36; // [sp+38h] [bp-30h] BYREF
  int v37; // [sp+40h] [bp-28h]
  int v38; // [sp+44h] [bp-24h]

  v1 = a1;
  v31 = a1;
  v2 = (unsigned int)KeGetPcr();
  v3 = (v2 & 0xFFFFF000) + 1408;
  v4 = *(_DWORD *)((v2 & 0xFFFFF000) + 0x594) == *(_DWORD *)(a1 + 4);
  v5 = __get_CPSR();
  if ( v4 )
  {
    if ( (v5 & 0x80) != 0 )
    {
      v7 = 0;
    }
    else
    {
      __disable_irq();
      v7 = 1;
    }
    LODWORD(v12) = KeQueryInterruptTime();
    v13 = *(_QWORD *)(v1 + 8);
    v30 = v13 + v12;
    v14 = (unsigned __int64)(v13 + v12) >> 32;
    LODWORD(v29) = HIDWORD(v13);
    v32 = v13;
    v28 = v14;
    KeQueryPerformanceCounter(&v36, &v34);
    if ( *(_BYTE *)v1 )
    {
      v15 = v34 * v13;
      v16 = v35 * (unsigned __int64)v32
          + v34 * (unsigned __int64)(unsigned int)v29
          + ((v34 * (unsigned __int64)(unsigned int)v13) >> 32);
      HIDWORD(v29) = HIDWORD(v16) + v29 * v35;
      v17 = RtlEnlargedUnsignedDivide(v16, SHIDWORD(v29), v29, (_DWORD *)&v29 + 1);
      HIDWORD(v18) = HIDWORD(v29);
      *(_DWORD *)(v1 + 20) = v17;
      LODWORD(v18) = v15;
      v19 = _rt_udiv64((unsigned int)dword_989680, v18);
      v20 = __PAIR64__(*(_DWORD *)(v1 + 20), v19) + v36;
      v14 = v28;
      *(_DWORD *)(v1 + 16) = v19;
      *(_QWORD *)(v1 + 16) = v20;
    }
    v21 = KeMaximumIncrement;
    RtlExtendedLargeIntegerDivide(&v29, __PAIR64__(v14, v30), KeMaximumIncrement, &v28);
    v22 = *(_QWORD *)(v1 + 8);
    KiTickOffset = v21 - v28;
    MEMORY[0xFFFF93B0] += v22;
    if ( MEMORY[0xFFFF93B4] <= 0 && MEMORY[0xFFFF93B4] < 0 )
      __fastfail(5u);
    v23 = (__int64 *)RtlWriteAcquireTickLock((unsigned __int64 *)0xFFFF9340);
    MEMORY[0xFFFF9010] = v14;
    __dmb(0xBu);
    MEMORY[0xFFFF9008] = v30;
    __dmb(0xBu);
    v24 = HIDWORD(v29);
    MEMORY[0xFFFF900C] = v14;
    dword_690388 = HIDWORD(v29);
    __dmb(0xBu);
    v25 = v29;
    KeTickCount = v29;
    __dmb(0xBu);
    dword_690384 = v24;
    MEMORY[0xFFFF9328] = v24;
    __dmb(0xBu);
    MEMORY[0xFFFF9320] = v25;
    __dmb(0xBu);
    MEMORY[0xFFFF9324] = v24;
    MEMORY[0xFFFF9350] = v36;
    KiInterruptTimeErrorAccumulator = 0i64;
    result = RtlWriteReleaseTickLock(v23);
    __dmb(0xBu);
    *(_DWORD *)(v1 + 28) = 0;
  }
  else
  {
    if ( (v5 & 0x80) != 0 )
      return (void *)sub_6941F0();
    __disable_irq();
    v7 = 1;
    do
      result = (void *)KiPollFreezeExecution();
    while ( *(_DWORD *)(v1 + 28) );
  }
  if ( !KiSerializeTimerExpiration )
  {
    v26 = (char *)(v3 + 4096);
LABEL_24:
    if ( v26 )
    {
      while ( 1 )
      {
        v27 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        __dmb(0xBu);
        if ( v27 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      KeRemoveQueueDpc(v3 + 1944);
      result = (void *)KeInsertQueueDpc(v3 + 1944);
      v1 = v31;
    }
    goto LABEL_8;
  }
  if ( *(_BYTE *)(v3 + 17) )
  {
    v26 = (char *)KiProcessorBlock + 4096;
    goto LABEL_24;
  }
LABEL_8:
  *(_DWORD *)(v3 + 1764) = KeTickCount;
  v8 = *(_QWORD *)(v1 + 8);
  if ( *(_BYTE *)v1 )
  {
    v9 = HalCalibratePerformanceCounter(
           v1 + 24,
           HalCalibratePerformanceCounter,
           *(_DWORD *)(v1 + 16),
           *(_DWORD *)(v1 + 20));
    result = (void *)KeRebaselineInterruptTime(v9, SHIDWORD(v9), v10, v11);
    if ( (dword_682610 & 0x8000) != 0 )
    {
      KeQueryPerformanceCounter(&v36, 0);
      v33 = v36;
      LODWORD(v36) = &v33;
      HIDWORD(v36) = 0;
      v37 = 8;
      v38 = 0;
      result = EtwTraceKernelEvent((int *)&v36, 1, 0x80008000, 4658, 4200450);
    }
  }
  if ( *(_BYTE *)(v3 + 17) )
    result = (void *)KiUpdateSystemTime(v8, HIDWORD(v8), 0, 3);
  if ( v7 )
    __enable_irq();
  return result;
}
