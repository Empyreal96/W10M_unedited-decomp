// ExAcquirePushLockSharedEx 
 
int __fastcall ExAcquirePushLockSharedEx(int result, int a2, int a3)
{
  unsigned int v3; // r7
  int v4; // r8
  unsigned int v5; // r6
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r4
  int v13; // r3
  __int16 v14; // r3
  unsigned int v15; // r2
  unsigned __int8 *v16; // r4
  char v17; // r5
  unsigned int v18; // r0
  unsigned __int8 *v19; // r3
  unsigned int v20; // r2

  v3 = result;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_50EAA4(result, a2, a3, a2 & 0xFFFFFFFC);
  if ( (a2 & 2) != 0 || !KiAbEnabled || (v4 = result & 0x7FFFFFFC, (result & 0x7FFFFFFC) == 0) )
  {
    v12 = 0;
    goto LABEL_21;
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
      goto LABEL_36;
    }
    v16 = (unsigned __int8 *)(v5 + 810);
    v17 = *(_BYTE *)(v5 + 810);
    __dmb(0xBu);
    do
      v18 = __ldrex(v16);
    while ( __strex(v18 & ~v17, v16) );
    __dmb(0xBu);
    *(_BYTE *)(v5 + 484) |= v17;
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
LABEL_36:
    v19 = (unsigned __int8 *)(v5 + 81);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x80, v19) );
    goto LABEL_18;
  }
  if ( v3 >= dword_63389C
    && ((v13 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((v3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v13 == 1)
     || v13 == 11) )
  {
    result = MmGetSessionIdEx(*(_DWORD *)(v5 + 116));
  }
  else
  {
    result = -1;
  }
  *(_DWORD *)(v12 + 20) = result;
  *(_DWORD *)(v12 + 16) = v4;
LABEL_18:
  v14 = *(_WORD *)(v5 + 310) + 1;
  *(_WORD *)(v5 + 310) = v14;
  if ( !v14 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  do
LABEL_21:
    v15 = __ldrex((unsigned int *)v3);
  while ( !v15 && __strex(0x11u, (unsigned int *)v3) );
  __dmb(0xBu);
  if ( v15 )
    result = ExfAcquirePushLockSharedEx(v3, v12, v3);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  return result;
}
