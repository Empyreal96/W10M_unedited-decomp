// ExAcquireAutoExpandPushLockShared 
 
int __fastcall ExAcquireAutoExpandPushLockShared(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r7
  int v4; // r9
  int v5; // r8
  unsigned int v6; // r6
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r2
  unsigned int v10; // r1
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  __int16 v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r2
  int result; // r0
  unsigned __int8 *v18; // r3
  unsigned int v19; // r2
  unsigned __int8 *v20; // r4
  char v21; // r5
  unsigned int v22; // r0
  int v23; // r0

  v2 = 0;
  v3 = a1;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_51D3BC();
  v4 = a2 & 2;
  if ( (a2 & 2) == 0 )
  {
    if ( !KiAbEnabled || (v5 = a1 & 0x7FFFFFFC, (a1 & 0x7FFFFFFC) == 0) )
    {
      v2 = 0;
      goto LABEL_21;
    }
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v7 = 0;
    }
    else
    {
      __disable_irq();
      v7 = 1;
    }
    v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v7 )
      __enable_irq();
    if ( (v8 & 0x10001) != 0 )
    {
      v23 = KeGetCurrentIrql(a1);
      KeBugCheck2(402, v6, v3, v23, 0, 0);
    }
    --*(_WORD *)(v6 + 310);
    if ( !*(_BYTE *)(v6 + 484) )
    {
      if ( !*(_BYTE *)(v6 + 810) )
      {
        v2 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          a1 = EtwTraceAutoBoostEntryExhaustion(v6, a1);
        goto LABEL_35;
      }
      v20 = (unsigned __int8 *)(v6 + 810);
      v21 = *(_BYTE *)(v6 + 810);
      __dmb(0xBu);
      do
        v22 = __ldrex(v20);
      while ( __strex(v22 & ~v21, v20) );
      __dmb(0xBu);
      *(_BYTE *)(v6 + 484) |= v21;
    }
    v9 = *(unsigned __int8 *)(v6 + 484);
    a1 = 1;
    v10 = __clz(__rbit(v9));
    v11 = v9 & ~(1 << v10);
    v12 = v6 + 48 * v10;
    v2 = v12 + 488;
    *(_BYTE *)(v6 + 484) = v11;
    if ( v12 != -488 )
    {
      if ( v3 >= dword_63389C
        && ((v13 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((v3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v13 == 1)
         || v13 == 11) )
      {
        a1 = MmGetSessionIdEx(*(_DWORD *)(v6 + 116));
      }
      else
      {
        a1 = -1;
      }
      *(_DWORD *)(v2 + 20) = a1;
      *(_DWORD *)(v2 + 16) = v5;
LABEL_18:
      v14 = *(_WORD *)(v6 + 310) + 1;
      *(_WORD *)(v6 + 310) = v14;
      if ( !v14 && *(_DWORD *)(v6 + 100) != v6 + 100 )
        KiCheckForKernelApcDelivery(a1);
      goto LABEL_21;
    }
LABEL_35:
    v18 = (unsigned __int8 *)(v6 + 81);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
    goto LABEL_18;
  }
LABEL_21:
  v15 = *(_DWORD *)(v3 + 4);
  if ( (v15 & 1) != 0 )
  {
    result = ExpAcquireFannedOutPushLockShared(v15 & 0xFFFFFFF8, v2, v3);
  }
  else
  {
    do
      v16 = __ldrex((unsigned int *)v3);
    while ( !v16 && __strex(0x11u, (unsigned int *)v3) );
    __dmb(0xBu);
    if ( v16 )
      ExfAcquirePushLockSharedEx(v3, v2, v3);
    result = v3 | 1;
  }
  if ( !v4 )
    result |= 2u;
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  return result;
}
