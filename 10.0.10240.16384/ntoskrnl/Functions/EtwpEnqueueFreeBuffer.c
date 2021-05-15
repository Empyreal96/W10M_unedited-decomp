// EtwpEnqueueFreeBuffer 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall EtwpEnqueueFreeBuffer(int a1, int a2)
{
  int v2; // r5
  int v4; // r8
  unsigned __int64 *v5; // r3
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // r6
  unsigned int v8; // r2
  unsigned int result; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r7
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r3
  int v17; // r4
  int v18; // r3
  int v19; // r3
  __int16 v20; // r3
  unsigned int v21; // r2
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r1
  int v26; // r2
  unsigned __int8 *v27; // r4
  char v28; // r5
  unsigned __int8 *v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // [sp+8h] [bp-20h]

  v2 = 0;
  v4 = a1;
  if ( *(_DWORD *)(a1 + 4) != *(_DWORD *)a2 )
    sub_54CA04();
  *(_DWORD *)(a2 + 44) = 0;
  __dmb(0xBu);
  v5 = (unsigned __int64 *)(a1 + 600);
  do
    v6 = __ldrexd(v5);
  while ( __strexd(v6 + 1, v5) );
  __dmb(0xBu);
  *(_QWORD *)(a2 + 24) = v6 + 1;
  if ( *(_DWORD *)(a1 + 224) != 1 )
  {
    v2 = KfRaiseIrql(15);
    v7 = v4 + 508;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v4 + 508);
    }
    else
    {
      do
        v8 = __ldrex((unsigned int *)v7);
      while ( __strex(1u, (unsigned int *)v7) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v4 + 508));
    }
    goto LABEL_10;
  }
  v7 = a1 + 508;
  if ( KiAbEnabled && (v7 & 0x7FFFFFFC) != 0 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v13 = 0;
    }
    else
    {
      __disable_irq();
      v13 = 1;
    }
    v14 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v13 )
      __enable_irq();
    if ( (v14 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(a1);
      KeBugCheckEx(402, v12, v4 + 508);
    }
    --*(_WORD *)(v12 + 310);
    if ( !*(_BYTE *)(v12 + 484) )
    {
      if ( !*(_BYTE *)(v12 + 810) )
      {
        v17 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          a1 = EtwTraceAutoBoostEntryExhaustion(v12, a1 + 508);
        goto LABEL_61;
      }
      v27 = (unsigned __int8 *)(v12 + 810);
      v28 = *(_BYTE *)(v12 + 810);
      __dmb(0xBu);
      do
        a1 = __ldrex(v27);
      while ( __strex(a1 & ~v28, v27) );
      __dmb(0xBu);
      *(_BYTE *)(v12 + 484) |= v28;
      v2 = 0;
    }
    v15 = *(unsigned __int8 *)(v12 + 484);
    v31 = __clz(__rbit(v15));
    *(_BYTE *)(v12 + 484) = v15 & ~(unsigned __int8)(1 << v31);
    v16 = v12 + 48 * v31;
    v17 = v16 + 488;
    if ( v16 != -488 )
    {
      if ( v7 >= dword_63389C
        && ((v18 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v7 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v18 == 1)
         || v18 == 11)
        && (v25 = *(_DWORD *)(v12 + 116), (v26 = *(_DWORD *)(v25 + 324)) != 0)
        && v25 != PsInitialSystemProcess )
      {
        v19 = *(_DWORD *)(v26 + 8);
      }
      else
      {
        v19 = -1;
      }
      *(_DWORD *)(v17 + 20) = v19;
      *(_DWORD *)(v17 + 16) = v7 & 0x7FFFFFFC;
LABEL_31:
      v20 = *(_WORD *)(v12 + 310) + 1;
      *(_WORD *)(v12 + 310) = v20;
      if ( !v20 && *(_DWORD *)(v12 + 100) != v12 + 100 )
        KiCheckForKernelApcDelivery(a1);
      goto LABEL_34;
    }
LABEL_61:
    v29 = (unsigned __int8 *)(v12 + 81);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 | 0x80, v29) );
    goto LABEL_31;
  }
  v17 = 0;
  do
LABEL_34:
    v21 = __ldrex((unsigned __int8 *)v7);
  while ( __strex(v21 | 1, (unsigned __int8 *)v7) );
  __dmb(0xBu);
  if ( (v21 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v4 + 508), v17, v4 + 508);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
LABEL_10:
  **(_DWORD **)(v4 + 52) = a2 + 32;
  *(_DWORD *)(v4 + 52) = a2 + 32;
  if ( *(_DWORD *)(v4 + 224) == 1 )
  {
    __pld((void *)v7);
    v22 = *(_DWORD *)v7;
    if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
      v23 = v22 - 16;
    else
      v23 = 0;
    if ( (v22 & 2) != 0 )
      goto LABEL_55;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)v7);
    while ( v24 == v22 && __strex(v23, (unsigned int *)v7) );
    if ( v24 != v22 )
LABEL_55:
      ExfReleasePushLock((_DWORD *)v7, v22);
    result = KeAbPostRelease(v7);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v7);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v7 = 0;
    }
    result = KfLowerIrql(v2);
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(v4 + 156);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 + 1, v10) );
  __dmb(0xBu);
  return result;
}
