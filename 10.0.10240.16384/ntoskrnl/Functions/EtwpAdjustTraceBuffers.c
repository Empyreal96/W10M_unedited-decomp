// EtwpAdjustTraceBuffers 
 
int EtwpAdjustTraceBuffers()
{
  int v0; // r5
  unsigned int i; // r10
  int v2; // r0
  int v3; // r8
  int result; // r0
  unsigned int v5; // r1
  unsigned int v6; // r1
  int v7; // r2
  unsigned int *v8; // r6
  unsigned int v9; // r2
  __int64 v10; // r2
  int v11; // r7
  int v12; // r1
  int v13; // r2
  __int64 v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r1
  unsigned int v18; // r2
  int v19; // r2
  int v20; // r5
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned int v23; // r7
  int v24; // r2
  int v25; // r3
  unsigned __int8 *v26; // r4
  char v27; // r5
  char v28; // r3
  unsigned int v29; // r2
  unsigned int v30; // r3
  unsigned int v31; // r4
  int v32; // r3
  int v33; // r3
  __int16 v34; // r3
  unsigned __int8 *v35; // r3
  unsigned int v36; // r2
  int v37; // r1
  int v38; // r2
  unsigned int v39; // r2
  unsigned int v40; // r1
  unsigned int v41; // r0
  unsigned int v42; // r2
  int v43; // r0
  unsigned int v44; // r1
  signed int v45; // r1
  int v46; // [sp+8h] [bp-28h]
  unsigned int v47; // [sp+Ch] [bp-24h]

  v0 = 0;
  v46 = 0;
  for ( i = 0; i < 0x40; ++i )
  {
    v2 = EtwpAcquireLoggerContextByLoggerId(i, 0);
    v3 = v2;
    if ( !v2 )
      continue;
    if ( (*(_DWORD *)(v2 + 12) & 0x400) == 0 )
    {
      v6 = *(_DWORD *)(v2 + 156);
      __dmb(0xBu);
      v7 = (*(_DWORD *)(v2 + 12) & 0x10000000) != 0 ? 1 : KeNumberProcessors_0;
      if ( v6 > *(_DWORD *)(v2 + 152) && v6 > 2 * v7 )
      {
        if ( *(_DWORD *)(v2 + 224) != 1 )
        {
          v0 = KfRaiseIrql(15);
          v46 = v0;
          v8 = (unsigned int *)(v3 + 508);
          if ( (dword_682604 & 0x210000) != 0 )
            return sub_5184D0();
          do
            v9 = __ldrex(v8);
          while ( __strex(1u, v8) );
          __dmb(0xBu);
          if ( v9 )
            KxWaitForSpinLockAndAcquire(v3 + 508);
          goto LABEL_21;
        }
        v8 = (unsigned int *)(v2 + 508);
        if ( !KiAbEnabled || ((unsigned int)v8 & 0x7FFFFFFC) == 0 )
        {
          v31 = 0;
          do
LABEL_73:
            v39 = __ldrex((unsigned __int8 *)v8);
          while ( __strex(v39 | 1, (unsigned __int8 *)v8) );
          __dmb(0xBu);
          if ( (v39 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v8, v31, v8);
          if ( v31 )
            *(_BYTE *)(v31 + 14) |= 1u;
LABEL_21:
          v10 = *(_QWORD *)(v3 + 48);
          v11 = 0;
          if ( (_DWORD)v10 != HIDWORD(v10) )
          {
            v12 = *(_DWORD *)v10;
            *(_DWORD *)v10 = **(_DWORD **)v10;
            if ( v12 == *(_DWORD *)(v3 + 52) )
              *(_DWORD *)(v3 + 52) = *(_DWORD *)(v3 + 48);
            v11 = v12 - 32;
            if ( v12 != 32 )
            {
              v13 = v12 + 24;
              v14 = *(_QWORD *)(v12 + 24);
              if ( *(_DWORD *)(v14 + 4) != v11 + 56 || *(_DWORD *)HIDWORD(v14) != v13 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v14) = v14;
              *(_DWORD *)(v14 + 4) = HIDWORD(v14);
            }
          }
          if ( *(_DWORD *)(v3 + 224) == 1 )
          {
            __pld(v8);
            v40 = *v8;
            if ( (*v8 & 0xFFFFFFF0) <= 0x10 )
              v41 = 0;
            else
              v41 = v40 - 16;
            if ( (v40 & 2) != 0 )
              goto LABEL_87;
            __dmb(0xBu);
            do
              v42 = __ldrex(v8);
            while ( v42 == v40 && __strex(v41, v8) );
            if ( v42 != v40 )
LABEL_87:
              ExfReleasePushLock(v8);
            KeAbPostRelease(v8);
          }
          else
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(v8);
            }
            else
            {
              __dmb(0xBu);
              *v8 = 0;
            }
            KfLowerIrql(v0);
          }
          if ( v11 )
          {
            __dmb(0xBu);
            v15 = (unsigned int *)(v3 + 160);
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 - 1, v15) );
            __dmb(0xBu);
            v17 = (unsigned int *)(v3 + 156);
            do
              v18 = __ldrex(v17);
            while ( __strex(v18 - 1, v17) );
            __dmb(0xBu);
            v19 = *(_DWORD *)(v3 + 224) & 1;
            __dmb(0xBu);
            v20 = -*(_DWORD *)(v3 + 4);
            v21 = (unsigned int *)&dword_61AD64[v19];
            do
              v22 = __ldrex(v21);
            while ( __strex(v22 + v20, v21) );
            __dmb(0xBu);
            ExFreePoolWithTag(v11, 0);
            v0 = v46;
          }
          goto LABEL_12;
        }
        v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        if ( (__get_CPSR() & 0x80) != 0 )
        {
          v24 = 0;
        }
        else
        {
          __disable_irq();
          v24 = 1;
        }
        v25 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
        if ( v24 )
          __enable_irq();
        if ( (v25 & 0x10001) != 0 )
        {
          KeGetCurrentIrql(v2);
          KeBugCheckEx(402, v23, v3 + 508);
        }
        --*(_WORD *)(v23 + 310);
        if ( !*(_BYTE *)(v23 + 484) )
        {
          if ( !*(_BYTE *)(v23 + 810) )
          {
            v31 = 0;
            if ( (dword_682604 & 0x200) != 0 )
              v2 = EtwTraceAutoBoostEntryExhaustion(v23, v8);
            goto LABEL_66;
          }
          v26 = (unsigned __int8 *)(v23 + 810);
          v27 = *(_BYTE *)(v23 + 810);
          __dmb(0xBu);
          do
            v2 = __ldrex(v26);
          while ( __strex(v2 & ~v27, v26) );
          __dmb(0xBu);
          v28 = *(_BYTE *)(v23 + 484) | v27;
          v0 = v46;
          *(_BYTE *)(v23 + 484) = v28;
        }
        v29 = *(unsigned __int8 *)(v23 + 484);
        v47 = __clz(__rbit(v29));
        *(_BYTE *)(v23 + 484) = v29 & ~(unsigned __int8)(1 << v47);
        v30 = v23 + 48 * v47;
        v31 = v30 + 488;
        if ( v30 != -488 )
        {
          if ( (unsigned int)v8 >= dword_63389C
            && ((v2 = 4092,
                 v32 = *((unsigned __int8 *)&MiState[2423]
                       + ((int)((((unsigned int)v8 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                 v32 == 1)
             || v32 == 11)
            && (v37 = *(_DWORD *)(v23 + 116), (v38 = *(_DWORD *)(v37 + 324)) != 0)
            && v37 != PsInitialSystemProcess )
          {
            v33 = *(_DWORD *)(v38 + 8);
          }
          else
          {
            v33 = -1;
          }
          *(_DWORD *)(v31 + 20) = v33;
          *(_DWORD *)(v31 + 16) = (unsigned int)v8 & 0x7FFFFFFC;
LABEL_60:
          v34 = *(_WORD *)(v23 + 310) + 1;
          *(_WORD *)(v23 + 310) = v34;
          if ( !v34 && *(_DWORD *)(v23 + 100) != v23 + 100 )
            KiCheckForKernelApcDelivery(v2);
          goto LABEL_73;
        }
LABEL_66:
        v35 = (unsigned __int8 *)(v23 + 81);
        do
          v36 = __ldrex(v35);
        while ( __strex(v36 | 0x80, v35) );
        goto LABEL_60;
      }
    }
LABEL_12:
    EtwpReleaseLoggerContext(v3, 0);
  }
  if ( dword_61ABFC > 2 * dword_61ABF8 * KeNumberProcessors_0 )
  {
    do
    {
      v43 = RtlpInterlockedPopEntrySList(&EtwpStackLookAsideList);
      if ( !v43 )
        break;
      ExFreePoolWithTag(v43, 0);
      __dmb(0xBu);
      do
      {
        v44 = __ldrex((unsigned int *)&dword_61ABFC);
        v45 = v44 - 1;
      }
      while ( __strex(v45, (unsigned int *)&dword_61ABFC) );
      __dmb(0xBu);
    }
    while ( v45 > 2 * dword_61ABF8 * KeNumberProcessors_0 );
  }
  __dmb(0xBu);
  result = 0;
  do
    v5 = __ldrex(&EtwpBufferAdjustmentActive);
  while ( __strex(0, &EtwpBufferAdjustmentActive) );
  __dmb(0xBu);
  return result;
}
