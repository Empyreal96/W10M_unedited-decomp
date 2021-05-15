// ExAcquirePushLockExclusiveEx 
 
int __fastcall ExAcquirePushLockExclusiveEx(int result, int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // lr
  unsigned int v5; // r8
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r4
  int v13; // r3
  int v14; // r3
  __int16 v15; // r3
  unsigned int v16; // r2
  int v17; // r1
  int v18; // r2
  unsigned __int8 *v19; // r4
  char v20; // r5
  unsigned int v21; // r3
  unsigned __int8 *v22; // r3
  unsigned int v23; // r2

  v3 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_50CA70(result, a2, a3, a2 & 0xFFFFFFFC);
  if ( (a2 & 2) != 0 || !KiAbEnabled || (v4 = result & 0x7FFFFFFC, (result & 0x7FFFFFFC) == 0) )
  {
    v12 = 0;
    goto LABEL_22;
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v6 = 0;
  }
  else
  {
    __disable_irq();
    v6 = 1;
  }
  v7 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v6 )
    __enable_irq();
  if ( (v7 & 0x10001) != 0 )
  {
    KeGetCurrentIrql(result);
    KeBugCheckEx(402, v5, v3);
  }
  --*(_WORD *)(v5 + 310);
  if ( !*(_BYTE *)(v5 + 484) )
  {
    if ( !*(_BYTE *)(v5 + 810) )
    {
      v12 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        result = EtwTraceAutoBoostEntryExhaustion(v5, result);
      goto LABEL_39;
    }
    v19 = (unsigned __int8 *)(v5 + 810);
    v20 = *(_BYTE *)(v5 + 810);
    __dmb(0xBu);
    do
      v21 = __ldrex(v19);
    while ( __strex(v21 & ~v20, v19) );
    __dmb(0xBu);
    *(_BYTE *)(v5 + 484) |= v20;
  }
  v8 = *(unsigned __int8 *)(v5 + 484);
  result = 1;
  v9 = __clz(__rbit(v8));
  v10 = v8 & ~(1 << v9);
  v11 = v5 + 48 * v9;
  v12 = v11 + 488;
  *(_BYTE *)(v5 + 484) = v10;
  if ( v11 == -488 )
  {
LABEL_39:
    v22 = (unsigned __int8 *)(v5 + 81);
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 | 0x80, v22) );
    goto LABEL_18;
  }
  if ( v3 >= dword_63389C
    && ((v13 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((v3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v13 == 1)
     || v13 == 11)
    && (v17 = *(_DWORD *)(v5 + 116), (v18 = *(_DWORD *)(v17 + 324)) != 0)
    && v17 != PsInitialSystemProcess )
  {
    v14 = *(_DWORD *)(v18 + 8);
  }
  else
  {
    v14 = -1;
  }
  *(_DWORD *)(v12 + 20) = v14;
  *(_DWORD *)(v12 + 16) = v4;
LABEL_18:
  v15 = *(_WORD *)(v5 + 310) + 1;
  *(_WORD *)(v5 + 310) = v15;
  if ( !v15 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  do
LABEL_22:
    v16 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v16 | 1, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v3, v12, v3);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  return result;
}
