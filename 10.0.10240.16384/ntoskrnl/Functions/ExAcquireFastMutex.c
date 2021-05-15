// ExAcquireFastMutex 
 
int __fastcall ExAcquireFastMutex(int a1)
{
  unsigned int v1; // r6
  int v2; // r8
  unsigned int v3; // r7
  int result; // r0
  int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r1
  int v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r4
  __int16 v11; // r3
  int v12; // r5
  unsigned int v13; // r2
  unsigned __int8 *v14; // r4
  char v15; // r5
  unsigned int v16; // r0
  unsigned __int8 *v17; // r3
  unsigned int v18; // r2

  v1 = a1;
  if ( KiAbEnabled )
  {
    v2 = a1 & 0x7FFFFFFC;
    if ( (a1 & 0x7FFFFFFC) != 0 )
    {
      v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (__get_CPSR() & 0x80) != 0 )
        return sub_50DD08();
      __disable_irq();
      v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      __enable_irq();
      if ( (v5 & 0x10001) != 0 )
      {
        KeGetCurrentIrql(a1);
        KeBugCheckEx(402, v3, v1);
      }
      --*(_WORD *)(v3 + 310);
      if ( !*(_BYTE *)(v3 + 484) )
      {
        if ( !*(_BYTE *)(v3 + 810) )
        {
          v10 = 0;
          if ( (dword_682604 & 0x200) != 0 )
            a1 = EtwTraceAutoBoostEntryExhaustion(v3, a1);
          goto LABEL_28;
        }
        v14 = (unsigned __int8 *)(v3 + 810);
        v15 = *(_BYTE *)(v3 + 810);
        __dmb(0xBu);
        do
          v16 = __ldrex(v14);
        while ( __strex(v16 & ~v15, v14) );
        __dmb(0xBu);
        *(_BYTE *)(v3 + 484) |= v15;
      }
      v6 = *(unsigned __int8 *)(v3 + 484);
      a1 = 1;
      v7 = __clz(__rbit(v6));
      v8 = v6 & ~(1 << v7);
      v9 = v3 + 48 * v7;
      v10 = v9 + 488;
      *(_BYTE *)(v3 + 484) = v8;
      if ( v9 != -488 )
      {
        if ( MmIsSessionAddress(v1) )
          a1 = MmGetSessionIdEx(*(_DWORD *)(v3 + 116));
        else
          a1 = -1;
        *(_DWORD *)(v10 + 20) = a1;
        *(_DWORD *)(v10 + 16) = v2;
LABEL_11:
        v11 = *(_WORD *)(v3 + 310) + 1;
        *(_WORD *)(v3 + 310) = v11;
        if ( !v11 && *(_DWORD *)(v3 + 100) != v3 + 100 )
          KiCheckForKernelApcDelivery(a1);
        goto LABEL_14;
      }
LABEL_28:
      v17 = (unsigned __int8 *)(v3 + 81);
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 0x80, v17) );
      goto LABEL_11;
    }
  }
  v10 = 0;
LABEL_14:
  result = KfRaiseIrql(1);
  v12 = result;
  do
    v13 = __ldrex((unsigned __int8 *)v1);
  while ( __strex(v13 & 0xFE, (unsigned __int8 *)v1) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
    result = ExpAcquireFastMutexContended(v1, v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  *(_DWORD *)(v1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v1 + 28) = v12;
  return result;
}
