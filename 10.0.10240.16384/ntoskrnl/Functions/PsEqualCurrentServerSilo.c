// PsEqualCurrentServerSilo 
 
int __fastcall PsEqualCurrentServerSilo(int a1)
{
  int v1; // r5
  unsigned int v2; // r6
  unsigned int v3; // r0
  int v5; // r9
  unsigned int *v6; // r8
  unsigned int v7; // r7
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r4
  int v15; // r3
  __int16 v16; // r3
  unsigned int v17; // r2
  int v18; // r2
  BOOL v21; // r4
  unsigned int v22; // r2
  int v23; // r0
  __int16 v24; // r3
  unsigned __int8 *v25; // r4
  char v26; // r5
  unsigned int v27; // r0
  char v28; // r3
  unsigned __int8 *v29; // r3
  unsigned int v30; // r2

  v1 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = KeGetCurrentIrql(a1);
  if ( v3 >= 2 )
    return sub_5183EC();
  v5 = *(_DWORD *)(v2 + 336);
  --*(_WORD *)(v2 + 308);
  v6 = (unsigned int *)(v5 + 168);
  if ( KiAbEnabled && ((unsigned int)v6 & 0x7FFFFFFC) != 0 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v8 = 0;
    }
    else
    {
      __disable_irq();
      v8 = 1;
    }
    v9 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v8 )
      __enable_irq();
    if ( (v9 & 0x10001) != 0 )
    {
      KeGetCurrentIrql(v3);
      KeBugCheckEx(402, v7, v5 + 168);
    }
    --*(_WORD *)(v7 + 310);
    if ( !*(_BYTE *)(v7 + 484) )
    {
      if ( !*(_BYTE *)(v7 + 810) )
      {
        v14 = 0;
        if ( (dword_682604 & 0x200) != 0 )
          v3 = EtwTraceAutoBoostEntryExhaustion(v7, v5 + 168);
        goto LABEL_54;
      }
      v25 = (unsigned __int8 *)(v7 + 810);
      v26 = *(_BYTE *)(v7 + 810);
      __dmb(0xBu);
      do
        v27 = __ldrex(v25);
      while ( __strex(v27 & ~v26, v25) );
      __dmb(0xBu);
      v28 = *(_BYTE *)(v7 + 484) | v26;
      v1 = a1;
      *(_BYTE *)(v7 + 484) = v28;
    }
    v10 = *(unsigned __int8 *)(v7 + 484);
    v3 = 1;
    v11 = __clz(__rbit(v10));
    v12 = v10 & ~(1 << v11);
    v13 = v7 + 48 * v11;
    v14 = v13 + 488;
    *(_BYTE *)(v7 + 484) = v12;
    if ( v13 != -488 )
    {
      if ( (unsigned int)v6 >= dword_63389C
        && ((v15 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)((((unsigned int)v6 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v15 == 1)
         || v15 == 11) )
      {
        v3 = MmGetSessionIdEx(*(_DWORD *)(v7 + 116));
      }
      else
      {
        v3 = -1;
      }
      *(_DWORD *)(v14 + 20) = v3;
      *(_DWORD *)(v14 + 16) = (unsigned int)v6 & 0x7FFFFFFC;
LABEL_17:
      v16 = *(_WORD *)(v7 + 310) + 1;
      *(_WORD *)(v7 + 310) = v16;
      if ( !v16 && *(_DWORD *)(v7 + 100) != v7 + 100 )
        KiCheckForKernelApcDelivery(v3);
      goto LABEL_20;
    }
LABEL_54:
    v29 = (unsigned __int8 *)(v7 + 81);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 | 0x80, v29) );
    goto LABEL_17;
  }
  v14 = 0;
  do
LABEL_20:
    v17 = __ldrex(v6);
  while ( !v17 && __strex(0x11u, v6) );
  __dmb(0xBu);
  if ( v17 )
    ExfAcquirePushLockSharedEx(v5 + 168, v14, v5 + 168);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v18 = *(_DWORD *)(v2 + 1096);
  if ( v18 == -3 )
    v18 = *(_DWORD *)(v5 + 804);
  while ( v18 && !*(_DWORD *)(v18 + 144) )
    v18 = *(_DWORD *)(v18 + 84);
  while ( v1 && !*(_DWORD *)(v1 + 144) )
    v1 = *(_DWORD *)(v1 + 84);
  v21 = v18 == v1;
  __dmb(0xBu);
  do
    v22 = __ldrex(v6);
  while ( v22 == 17 && __strex(0, v6) );
  if ( v22 != 17 )
    ExfReleasePushLockShared(v5 + 168, 0);
  v23 = KeAbPostRelease(v5 + 168);
  v24 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v23);
  return v21;
}
