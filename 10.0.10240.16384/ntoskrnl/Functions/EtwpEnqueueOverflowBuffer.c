// EtwpEnqueueOverflowBuffer 
 
void __fastcall EtwpEnqueueOverflowBuffer(int a1, int a2)
{
  int v2; // r5
  int v3; // r8
  int v4; // r10
  unsigned int *v5; // r2
  unsigned int v6; // r4
  unsigned int v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r7
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned __int8 *v15; // r4
  char v16; // r5
  char v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r3
  int v20; // r4
  int v21; // r3
  int v22; // r3
  __int16 v23; // r3
  unsigned __int8 *v24; // r3
  unsigned int v25; // r2
  int v26; // r1
  int v27; // r2
  unsigned int v28; // r2
  int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // r2
  unsigned int v32; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  v2 = a2;
  v3 = a1;
  v4 = 0;
  __dmb(0xBu);
  v5 = (unsigned int *)(a2 + 44);
  do
    v6 = __ldrex(v5);
  while ( v6 == 1 && __strex(0, v5) );
  __dmb(0xBu);
  if ( *(_DWORD *)(a1 + 224) == 1 )
  {
    v7 = a1 + 508;
    if ( !KiAbEnabled || (v7 & 0x7FFFFFFC) == 0 )
    {
      v20 = 0;
      do
LABEL_49:
        v28 = __ldrex((unsigned __int8 *)v7);
      while ( __strex(v28 | 1, (unsigned __int8 *)v7) );
      __dmb(0xBu);
      if ( (v28 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 508), v20, v3 + 508);
      if ( v20 )
        *(_BYTE *)(v20 + 14) |= 1u;
      goto LABEL_10;
    }
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v12 = 0;
    }
    else
    {
      __disable_irq();
      v12 = 1;
    }
    v13 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v12 )
      __enable_irq();
    if ( (v13 & 0x10001) != 0 )
    {
      v14 = KeGetCurrentIrql(a1);
      KeBugCheckEx(402, v11, v3 + 508, v14, 0);
    }
    --*(_WORD *)(v11 + 310);
    if ( !*(_BYTE *)(v11 + 484) )
    {
      if ( !*(_BYTE *)(v11 + 810) )
      {
        v20 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          a1 = (int)EtwTraceAutoBoostEntryExhaustion(v11, a1 + 508);
        goto LABEL_42;
      }
      v15 = (unsigned __int8 *)(v11 + 810);
      v16 = *(_BYTE *)(v11 + 810);
      __dmb(0xBu);
      do
        a1 = __ldrex(v15);
      while ( __strex(a1 & ~v16, v15) );
      __dmb(0xBu);
      v17 = *(_BYTE *)(v11 + 484) | v16;
      v2 = a2;
      *(_BYTE *)(v11 + 484) = v17;
    }
    v18 = *(unsigned __int8 *)(v11 + 484);
    v32 = __clz(__rbit(v18));
    *(_BYTE *)(v11 + 484) = v18 & ~(unsigned __int8)(1 << v32);
    v19 = v11 + 48 * v32;
    v20 = v19 + 488;
    if ( v19 != -488 )
    {
      if ( v7 >= dword_63389C
        && ((v21 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v7 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v21 == 1)
         || v21 == 11)
        && (v26 = *(_DWORD *)(v11 + 116), (v27 = *(_DWORD *)(v26 + 324)) != 0)
        && v26 != PsInitialSystemProcess )
      {
        v22 = *(_DWORD *)(v27 + 8);
      }
      else
      {
        v22 = -1;
      }
      *(_DWORD *)(v20 + 20) = v22;
      *(_DWORD *)(v20 + 16) = v7 & 0x7FFFFFFC;
LABEL_37:
      v23 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v23;
      if ( !v23 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(a1);
      goto LABEL_49;
    }
LABEL_42:
    v24 = (unsigned __int8 *)(v11 + 81);
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 | 0x80, v24) );
    goto LABEL_37;
  }
  v4 = KfRaiseIrql(15);
  v7 = v3 + 508;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    sub_50FB8C();
    return;
  }
  do
    v8 = __ldrex((unsigned int *)v7);
  while ( __strex(1u, (unsigned int *)v7) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(v3 + 508));
LABEL_10:
  **(_DWORD **)(v3 + 64) = v2 + 32;
  *(_DWORD *)(v3 + 64) = v2 + 32;
  if ( *(_DWORD *)(v3 + 224) == 1 )
  {
    __pld((void *)v7);
    v29 = *(_DWORD *)v7;
    if ( (*(_DWORD *)v7 & 0xFFFFFFF0) <= 0x10 )
      v30 = 0;
    else
      v30 = v29 - 16;
    if ( (v29 & 2) != 0 )
      goto LABEL_63;
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)v7);
    while ( v31 == v29 && __strex(v30, (unsigned int *)v7) );
    if ( v31 != v29 )
LABEL_63:
      ExfReleasePushLock((_DWORD *)v7, v29);
    KeAbPostRelease(v7);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)v7, vars4);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v7 = 0;
    }
    KfLowerIrql(v4);
  }
  __dmb(0xBu);
  v9 = (unsigned int *)(v3 + 156);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
}
