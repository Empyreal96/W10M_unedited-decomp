// ExReleasePushLockEx 
 
int __fastcall ExReleasePushLockEx(unsigned int a1, int a2, int a3)
{
  char v3; // r4
  int v5; // r1
  int result; // r0
  unsigned int v7; // r2
  int v8; // r9
  int v9; // r4
  int v10; // r3
  int v11; // r10
  int v12; // r2
  int v13; // lr
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r7
  __int16 v18; // r3
  int v19; // r2
  __int16 v20; // r3
  unsigned int v21; // r3
  int v22; // r3
  char v23; // r2
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned __int8 *v26; // [sp+10h] [bp-20h]

  v3 = a2;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_50CB00(a1, a2, a3, a2 & 0xFFFFFFFC);
  __pld((void *)a1);
  v5 = *(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 0xFFFFFFF0) > 0x10 )
    result = v5 - 16;
  else
    result = 0;
  if ( (v5 & 2) != 0 )
    goto LABEL_40;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)a1);
  while ( v7 == v5 && __strex(result, (unsigned int *)a1) );
  if ( v7 != v5 )
LABEL_40:
    result = ExfReleasePushLock(a1);
  if ( (v3 & 2) == 0 && KiAbEnabled && (a1 & 0x7FFFFFFC) != 0 )
  {
    v8 = 0;
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( a1 >= dword_63389C
      && ((v10 = *((unsigned __int8 *)&MiState[2423]
                 + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v10 == 1)
       || v10 == 11) )
    {
      result = MmGetSessionIdEx(*(_DWORD *)(v9 + 116));
      v11 = result;
    }
    else
    {
      v11 = -1;
    }
    if ( (unsigned int)KeGetCurrentIrql(result) <= 1 )
    {
      v8 = 1;
      --*(_WORD *)(v9 + 310);
    }
    v12 = *(char *)(v9 + 484);
    __dmb(0xBu);
    v26 = (unsigned __int8 *)(v9 + 810);
    v13 = (v12 | *(char *)(v9 + 810)) ^ 0x3F;
    v14 = __clz(v13);
    result = 31 - v14;
    if ( 1 == (unsigned __int8)(v14 >> 5) )
    {
LABEL_35:
      if ( (*(_DWORD *)(v9 + 80) & 0x8000) == 0 )
        KeBugCheckEx(354, v9, a1);
      if ( v8 )
      {
        v22 = (__int16)(*(_WORD *)(v9 + 310) + 1);
        *(_WORD *)(v9 + 310) = v22;
        if ( !v22 && *(_DWORD *)(v9 + 100) != v9 + 100 )
          return KiCheckForKernelApcDelivery(result);
      }
    }
    else
    {
      v15 = 488;
      while ( 1 )
      {
        v13 &= ~(1 << result);
        v16 = v9 + 48 * result;
        v17 = v16 + 488;
        if ( (*(_BYTE *)(v16 + 502) & 1) != 0
          && (*(_DWORD *)(v16 + 504) & 1) == 0
          && (*(_DWORD *)(v16 + 504) & 0x7FFFFFFC) == (a1 & 0x7FFFFFFC)
          && *(_DWORD *)(v16 + 508) == v11 )
        {
          *(_BYTE *)(v16 + 502) &= 0xFEu;
          if ( *(_DWORD *)(v16 + 504) )
            break;
        }
        v21 = __clz(v13);
        result = 31 - v21;
        if ( 1 == (unsigned __int8)(v21 >> 5) )
          goto LABEL_35;
      }
      *(_BYTE *)(v16 + 504) |= 2u;
      if ( *(int *)(v16 + 504) < 0 )
        KiAbEntryRemoveFromTree(v17);
      v18 = *(_WORD *)(v17 + 44);
      if ( v18 )
      {
        if ( (v18 & 1) != 0 )
        {
          __dmb(0xBu);
          v24 = (unsigned int *)(v9 + 804);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 - 1, v24) );
          __dmb(0xBu);
          PsBoostThreadIoEx(v9, 1, 0);
        }
        if ( (*(_WORD *)(v17 + 44) & 0xFFFE) != 0 )
          KiAbThreadUnboostCpuPriority(v9, v17, v15, *(_WORD *)(v17 + 44) & 0xFFFE);
        if ( (dword_682604 & 0x200) != 0 )
          EtwTraceAutoBoostClearFloor(
            v9,
            *(_DWORD *)(v17 + 16) & 0xFFFFFFFC | 0x80000000,
            *(unsigned __int16 *)(v17 + 44));
        *(_WORD *)(v17 + 44) = 0;
      }
      *(_BYTE *)(v17 + 13) &= 0xFEu;
      result = (unsigned __int64)(715827883i64 * (v17 - v9 - 488)) >> 32;
      *(_DWORD *)(v17 + 16) = 0;
      v19 = (v17 - v9 - 488) / 48;
      if ( v8 )
      {
        *(_BYTE *)(v9 + 484) |= 1 << v19;
        v20 = *(_WORD *)(v9 + 310) + 1;
        *(_WORD *)(v9 + 310) = v20;
        if ( !v20 && *(_DWORD *)(v9 + 100) != v9 + 100 )
          return KiCheckForKernelApcDelivery(result);
      }
      else
      {
        __dmb(0xBu);
        v23 = 1 << v19;
        do
          result = __ldrex(v26);
        while ( __strex(result | v23, v26) );
        __dmb(0xBu);
      }
    }
  }
  return result;
}
