// ExAcquireCacheAwarePushLockSharedEx 
 
unsigned int *__fastcall ExAcquireCacheAwarePushLockSharedEx(int a1, int a2, int a3)
{
  int v3; // r7
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
  unsigned int *v14; // r5
  unsigned int v15; // r1
  unsigned __int8 *v17; // r4
  char v18; // r5
  unsigned int v19; // r3
  unsigned __int8 *v20; // r3
  unsigned int v21; // r2
  int v22; // r0

  v3 = a1;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_52F378(a1, a2, a3, a2 & 0xFFFFFFFC);
  if ( (a2 & 2) != 0 || !KiAbEnabled || (v4 = a1 & 0x7FFFFFFC, (a1 & 0x7FFFFFFC) == 0) )
  {
    v12 = 0;
    goto LABEL_17;
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
    v22 = KeGetCurrentIrql(a1);
    KeBugCheck2(402, v5, v3, v22, 0, 0);
  }
  --*(_WORD *)(v5 + 310);
  if ( !*(_BYTE *)(v5 + 484) )
  {
    if ( !*(_BYTE *)(v5 + 810) )
    {
      v12 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        a1 = EtwTraceAutoBoostEntryExhaustion(v5, a1);
      goto LABEL_33;
    }
    v17 = (unsigned __int8 *)(v5 + 810);
    v18 = *(_BYTE *)(v5 + 810);
    __dmb(0xBu);
    do
      v19 = __ldrex(v17);
    while ( __strex(v19 & ~v18, v17) );
    __dmb(0xBu);
    *(_BYTE *)(v5 + 484) |= v18;
  }
  v8 = *(unsigned __int8 *)(v5 + 484);
  a1 = 1;
  v9 = __clz(__rbit(v8));
  v10 = v8 & ~(1 << v9);
  v11 = v5 + 48 * v9;
  v12 = v11 + 488;
  *(_BYTE *)(v5 + 484) = v10;
  if ( v11 == -488 )
  {
LABEL_33:
    v20 = (unsigned __int8 *)(v5 + 81);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 | 0x80, v20) );
    goto LABEL_16;
  }
  if ( MmIsSessionAddress(v3) )
    a1 = MmGetSessionIdEx(*(_DWORD *)(v5 + 116));
  else
    a1 = -1;
  *(_DWORD *)(v12 + 20) = a1;
  *(_DWORD *)(v12 + 16) = v4;
LABEL_16:
  v13 = (__int16)(*(_WORD *)(v5 + 310) + 1);
  *(_WORD *)(v5 + 310) = v13;
  if ( !v13 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    KiCheckForKernelApcDelivery(a1);
LABEL_17:
  v14 = *(unsigned int **)(v3 + 4 * (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) & 0x1F));
  do
    v15 = __ldrex(v14);
  while ( !v15 && __strex(0x11u, v14) );
  __dmb(0xBu);
  if ( v15 && !ExfTryAcquirePushLockShared(v14) )
    ExfAcquirePushLockSharedEx(v14, v12, v3);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  return v14;
}
