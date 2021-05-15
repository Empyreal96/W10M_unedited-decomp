// ExTryAcquirePushLockSharedEx 
 
int __fastcall ExTryAcquirePushLockSharedEx(unsigned int *a1, int a2, int a3)
{
  int v4; // r8
  unsigned int v5; // r6
  unsigned int v6; // r0
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r3
  __int16 v10; // r3
  unsigned int v11; // r2
  int result; // r0
  unsigned __int8 *v13; // r4
  char v14; // r5
  unsigned int v15; // r0
  unsigned __int8 *v16; // r3
  unsigned int v17; // r2
  unsigned __int8 *v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // [sp+8h] [bp-18h]

  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_51C3D8(a1, a2, a3, a2 & 0xFFFFFFFC);
  if ( (a2 & 2) != 0 || !KiAbEnabled || (v4 = (unsigned int)a1 & 0x7FFFFFFC, ((unsigned int)a1 & 0x7FFFFFFC) == 0) )
  {
    v8 = 0;
    goto LABEL_18;
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = KeGetCurrentIrql(a1);
  if ( v6 >= 2 )
  {
    v8 = 0;
    v16 = (unsigned __int8 *)(v5 + 81);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    goto LABEL_18;
  }
  --*(_WORD *)(v5 + 310);
  if ( !*(_BYTE *)(v5 + 484) )
  {
    if ( !*(_BYTE *)(v5 + 810) )
    {
      v8 = 0;
      if ( (dword_682604 & 0x200) != 0 )
        v6 = EtwTraceAutoBoostEntryExhaustion(v5, a1);
      goto LABEL_9;
    }
    v13 = (unsigned __int8 *)(v5 + 810);
    v14 = *(_BYTE *)(v5 + 810);
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( __strex(v15 & ~v14, v13) );
    __dmb(0xBu);
    *(_BYTE *)(v5 + 484) |= v14;
  }
  v7 = *(unsigned __int8 *)(v5 + 484);
  v6 = 1;
  v20 = __clz(__rbit(v7));
  v8 = v5 + 48 * v20 + 488;
  *(_BYTE *)(v5 + 484) = v7 & ~(1 << v20);
LABEL_9:
  if ( v8 )
  {
    if ( (unsigned int)a1 >= dword_63389C
      && ((v9 = *((unsigned __int8 *)&MiState[2423]
                + ((int)((((unsigned int)a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v9 == 1)
       || v9 == 11) )
    {
      v6 = MmGetSessionIdEx(*(_DWORD *)(v5 + 116));
    }
    else
    {
      v6 = -1;
    }
    *(_DWORD *)(v8 + 20) = v6;
    *(_DWORD *)(v8 + 16) = v4;
  }
  else
  {
    v18 = (unsigned __int8 *)(v5 + 81);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
  }
  v10 = *(_WORD *)(v5 + 310) + 1;
  *(_WORD *)(v5 + 310) = v10;
  if ( !v10 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    KiCheckForKernelApcDelivery(v6);
  do
LABEL_18:
    v11 = __ldrex(a1);
  while ( !v11 && __strex(0x11u, a1) );
  __dmb(0xBu);
  if ( !v11 || ExfTryAcquirePushLockShared(a1, 17) )
  {
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    result = 1;
  }
  else
  {
    if ( v8 )
      KeAbPostReleaseEx(a1, v8);
    result = 0;
  }
  return result;
}
