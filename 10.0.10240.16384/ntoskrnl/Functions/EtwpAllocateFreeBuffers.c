// EtwpAllocateFreeBuffers 
 
int __fastcall EtwpAllocateFreeBuffers(unsigned int *a1, unsigned int a2)
{
  unsigned int v2; // r9
  int v4; // r10
  unsigned int *v5; // r5
  unsigned int *v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r4
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r6
  unsigned int v15; // r2
  __int64 v16; // r0
  int v17; // r2
  unsigned int v18; // r2
  int v19; // r2
  int v20; // r5
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned int v23; // r7
  int v24; // r2
  int v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r3
  int v28; // r4
  int v29; // r3
  int v30; // r3
  __int16 v31; // r3
  unsigned int v32; // r2
  int v33; // r1
  unsigned int v34; // r0
  unsigned int v35; // r2
  int v36; // r2
  int v37; // r1
  unsigned __int8 *v38; // r4
  char v39; // r5
  unsigned __int8 *v40; // r3
  unsigned int v41; // r2
  unsigned int v42; // r2
  unsigned __int8 v43; // [sp+8h] [bp-38h]
  int v44; // [sp+Ch] [bp-34h]
  int v45; // [sp+10h] [bp-30h]
  int v46; // [sp+14h] [bp-2Ch]
  unsigned int v48; // [sp+1Ch] [bp-24h]

  v2 = a1[1];
  v4 = 0;
  if ( (a1[152] & 0x1000) != 0 )
    v2 = (v2 + 4095) & 0xFFFFF000;
  v45 = 0;
  if ( !a2 )
    goto LABEL_31;
  v5 = a1 + 40;
  v44 = v43;
  while ( 1 )
  {
    v6 = a1 + 43;
    __dmb(0xBu);
    do
    {
      v7 = __ldrex(v5);
      v8 = v7 + 1;
    }
    while ( __strex(v8, v5) );
    __dmb(0xBu);
    if ( v8 > a1[41] )
      break;
    v9 = ExAllocatePoolWithTag(a1[56], v2, 1115124805);
    v46 = v9;
    if ( !v9 )
    {
      __dmb(0xBu);
      do
        v42 = __ldrex(v5);
      while ( __strex(v42 - 1, v5) );
      goto LABEL_33;
    }
    while ( 1 )
    {
      v11 = *v6;
      __dmb(0xBu);
      if ( v11 >= v8 )
        break;
      __dmb(0xBu);
      do
        v10 = __ldrex(v6);
      while ( v10 == v11 && __strex(v8, v6) );
      __dmb(0xBu);
    }
    v12 = EtwpInitializeBufferHeader(a1, v9);
    if ( a1[56] == 1 )
    {
      v13 = (unsigned int)(a1 + 127);
      if ( KiAbEnabled && (v13 & 0x7FFFFFFC) != 0 )
      {
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
          KeGetCurrentIrql(v12);
          KeBugCheckEx(402, v23, a1 + 127);
        }
        --*(_WORD *)(v23 + 310);
        if ( *(_BYTE *)(v23 + 484) )
        {
LABEL_42:
          v26 = *(unsigned __int8 *)(v23 + 484);
          v48 = __clz(__rbit(v26));
          *(_BYTE *)(v23 + 484) = v26 & ~(unsigned __int8)(1 << v48);
          v27 = v23 + 48 * v48;
          v28 = v27 + 488;
          if ( v27 != -488 )
          {
            if ( v13 >= dword_63389C
              && ((v12 = 4092,
                   v29 = *((unsigned __int8 *)&MiState[2423]
                         + ((int)(((v13 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                   v29 == 1)
               || v29 == 11)
              && (v36 = *(_DWORD *)(v23 + 116), (v37 = *(_DWORD *)(v36 + 324)) != 0)
              && v36 != PsInitialSystemProcess )
            {
              v30 = *(_DWORD *)(v37 + 8);
            }
            else
            {
              v30 = -1;
            }
            *(_DWORD *)(v28 + 20) = v30;
            *(_DWORD *)(v28 + 16) = v13 & 0x7FFFFFFC;
            goto LABEL_48;
          }
        }
        else
        {
          if ( *(_BYTE *)(v23 + 810) )
          {
            v38 = (unsigned __int8 *)(v23 + 810);
            v39 = *(_BYTE *)(v23 + 810);
            __dmb(0xBu);
            do
              v12 = __ldrex(v38);
            while ( __strex(v12 & ~v39, v38) );
            __dmb(0xBu);
            *(_BYTE *)(v23 + 484) |= v39;
            v5 = a1 + 40;
            goto LABEL_42;
          }
          v28 = 0;
          if ( (dword_682604 & 0x200) != 0 )
            v12 = EtwTraceAutoBoostEntryExhaustion(v23, a1 + 127);
        }
        v40 = (unsigned __int8 *)(v23 + 81);
        do
          v41 = __ldrex(v40);
        while ( __strex(v41 | 0x80, v40) );
LABEL_48:
        v31 = *(_WORD *)(v23 + 310) + 1;
        *(_WORD *)(v23 + 310) = v31;
        if ( !v31 && *(_DWORD *)(v23 + 100) != v23 + 100 )
          KiCheckForKernelApcDelivery(v12);
      }
      else
      {
        v28 = 0;
      }
      do
        v32 = __ldrex((unsigned __int8 *)v13);
      while ( __strex(v32 | 1, (unsigned __int8 *)v13) );
      __dmb(0xBu);
      if ( (v32 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(a1 + 127, v28, (unsigned int)(a1 + 127));
      if ( v28 )
        *(_BYTE *)(v28 + 14) |= 1u;
      goto LABEL_21;
    }
    v44 = KfRaiseIrql(15);
    v13 = (unsigned int)(a1 + 127);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_54C230();
    do
      v15 = __ldrex((unsigned int *)v13);
    while ( __strex(1u, (unsigned int *)v13) );
    __dmb(0xBu);
    if ( v15 )
      KxWaitForSpinLockAndAcquire(a1 + 127);
LABEL_21:
    LODWORD(v16) = a1 + 18;
    HIDWORD(v16) = a1[19];
    v17 = v46 + 56;
    *(_QWORD *)(v46 + 56) = v16;
    if ( *(unsigned int **)HIDWORD(v16) != a1 + 18 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v16) = v17;
    a1[19] = v17;
    if ( a1[56] == 1 )
    {
      __pld((void *)v13);
      v33 = *(_DWORD *)v13;
      if ( (*(_DWORD *)v13 & 0xFFFFFFF0) > 0x10 )
        v34 = v33 - 16;
      else
        v34 = 0;
      if ( (v33 & 2) != 0 )
        goto LABEL_80;
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)v13);
      while ( v35 == v33 && __strex(v34, (unsigned int *)v13) );
      if ( v35 != v33 )
LABEL_80:
        ExfReleasePushLock((_DWORD *)v13, v33);
      KeAbPostRelease(v13);
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v13);
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v13 = 0;
      }
      KfLowerIrql(v44);
    }
    EtwpEnqueueFreeBuffer(a1, v46);
    ++v4;
    if ( ++v45 >= a2 )
      goto LABEL_31;
  }
  __dmb(0xBu);
  do
    v18 = __ldrex(v5);
  while ( __strex(v18 - 1, v5) );
  __dmb(0xBu);
LABEL_31:
  v19 = a1[56] & 1;
  __dmb(0xBu);
  v20 = a1[1] * v4;
  v21 = (unsigned int *)&dword_61AD64[v19];
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 + v20, v21) );
LABEL_33:
  __dmb(0xBu);
  return v4;
}
