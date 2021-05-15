// KeAbPreAcquire 
 
int __fastcall KeAbPreAcquire(unsigned int a1, int a2, char a3)
{
  unsigned int v5; // r7
  int v6; // r8
  unsigned int v7; // r6
  int v9; // r3
  int v10; // r10
  unsigned int v11; // r2
  unsigned int v12; // r1
  int v13; // r5
  int v14; // r3
  __int16 v15; // r3
  unsigned __int8 *v16; // r3
  unsigned int v17; // r2
  unsigned __int8 *v18; // r3
  unsigned int v19; // r2
  unsigned __int8 *v20; // r4
  char v21; // r5
  int v22; // r1
  unsigned int v23; // r3

  v5 = a1;
  if ( !KiAbEnabled )
    return 0;
  v6 = a1 & 0x7FFFFFFC;
  if ( (a1 & 0x7FFFFFFC) == 0 )
    return 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (a3 & 3) == 0 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
      return sub_50CAD0();
    __disable_irq();
    v9 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    __enable_irq();
    if ( (v9 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(a1);
      KeBugCheckEx(402, v7, v5);
    }
    goto LABEL_7;
  }
  a1 = KeGetCurrentIrql(a1);
  if ( a1 < 2 )
  {
LABEL_7:
    v10 = 1;
    --*(_WORD *)(v7 + 310);
    goto LABEL_8;
  }
  v10 = 0;
  if ( (a3 & 2) == 0 )
  {
    v18 = (unsigned __int8 *)(v7 + 81);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
    return 0;
  }
LABEL_8:
  if ( a2 )
  {
    v13 = KfRaiseIrql(2);
    KeAbEntryFree(a2, v7);
LABEL_13:
    if ( v5 >= dword_63389C
      && ((v14 = *((unsigned __int8 *)&MiState[2423]
                 + ((int)(((v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v14 == 1)
       || v14 == 11) )
    {
      a1 = MmGetSessionIdEx(*(_DWORD *)(v7 + 116));
    }
    else
    {
      a1 = -1;
    }
    *(_DWORD *)(a2 + 20) = a1;
    *(_DWORD *)(a2 + 16) = v6;
    if ( v13 != 2 )
      a1 = KfLowerIrql(v13);
    goto LABEL_19;
  }
  if ( *(_BYTE *)(v7 + 484) )
    goto LABEL_10;
  if ( *(_BYTE *)(v7 + 810) )
  {
    v20 = (unsigned __int8 *)(v7 + 810);
    v21 = *(_BYTE *)(v7 + 810);
    __dmb(0xBu);
    v22 = (char)~v21;
    do
    {
      v23 = __ldrex(v20);
      a1 = v23 & v22;
    }
    while ( __strex(v23 & v22, v20) );
    __dmb(0xBu);
    *(_BYTE *)(v7 + 484) |= v21;
LABEL_10:
    v11 = *(unsigned __int8 *)(v7 + 484);
    v12 = __clz(__rbit(v11));
    *(_BYTE *)(v7 + 484) = v11 & ~(unsigned __int8)(1 << v12);
    a2 = v7 + 48 * v12 + 488;
    goto LABEL_11;
  }
  a2 = 0;
  if ( (dword_682604 & 0x200) != 0 )
    a1 = EtwTraceAutoBoostEntryExhaustion(v7, v5);
LABEL_11:
  if ( a2 )
  {
    v13 = 2;
    goto LABEL_13;
  }
  v16 = (unsigned __int8 *)(v7 + 81);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 | 0x80, v16) );
LABEL_19:
  if ( !v10 )
    return a2;
  v15 = *(_WORD *)(v7 + 310) + 1;
  *(_WORD *)(v7 + 310) = v15;
  if ( v15 || *(_DWORD *)(v7 + 100) == v7 + 100 )
    return a2;
  KiCheckForKernelApcDelivery(a1);
  return a2;
}
