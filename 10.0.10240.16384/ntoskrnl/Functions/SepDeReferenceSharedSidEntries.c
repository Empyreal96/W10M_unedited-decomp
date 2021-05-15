// SepDeReferenceSharedSidEntries 
 
int __fastcall SepDeReferenceSharedSidEntries(int *a1, int a2, int a3, int a4)
{
  int v4; // r7
  unsigned int v6; // r4
  unsigned __int8 *v7; // r5
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned __int16 *v11; // r4
  int v12; // t1
  _DWORD *v13; // r6
  unsigned int v14; // r1
  int v15; // r5
  _DWORD *v16; // r10
  unsigned int *v17; // r2
  unsigned int v18; // r1
  signed int v19; // r1
  unsigned int *v20; // r4
  unsigned int v21; // r1
  int result; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  _DWORD v25[10]; // [sp+0h] [bp-28h] BYREF

  v25[0] = a2;
  v25[1] = a3;
  v25[2] = a4;
  v4 = a2;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned __int8 *)g_SepSidMapping;
  v8 = KeAbPreAcquire((unsigned int)g_SepSidMapping, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    v8 = ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( v4 )
  {
    while ( 1 )
    {
      v12 = *a1;
      a1 += 2;
      v11 = (unsigned __int16 *)v12;
      v13 = 0;
      v14 = *(_DWORD *)(v12 + 4 * *(unsigned __int8 *)(v12 + 1) + 4);
      if ( !v14 )
        break;
      v8 = RtlLookupEntryHashTable(*((_DWORD **)g_SepSidMapping + 1), v14, v25, (int)g_SepSidMapping);
      v15 = v8;
      if ( v8 )
      {
        v16 = g_SepSidMapping;
        while ( 1 )
        {
          v8 = RtlEqualSid(v11, *(unsigned __int16 **)(v15 + 16));
          if ( v8 )
            break;
          v8 = RtlGetNextEntryHashTable(v16[1], (int)v25);
          v15 = v8;
          if ( !v8 )
            goto LABEL_13;
        }
        v13 = (_DWORD *)v15;
      }
LABEL_13:
      __dmb(0xBu);
      v17 = v13 + 3;
      do
      {
        v18 = __ldrex(v17);
        v19 = v18 - 1;
      }
      while ( __strex(v19, v17) );
      if ( v19 <= 0 )
      {
        if ( v19 )
          __fastfail(0xEu);
        __dmb(0xBu);
        v8 = RtlRemoveEntryHashTable(*((_DWORD *)g_SepSidMapping + 1), v13, 0);
        if ( v8 )
          v8 = ExFreePoolWithTag((unsigned int)v13);
      }
      if ( !--v4 )
        goto LABEL_17;
    }
    result = sub_7C5984(v8);
  }
  else
  {
LABEL_17:
    v20 = (unsigned int *)g_SepSidMapping;
    __dmb(0xBu);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 - 1, v20) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock(v20);
    result = KeAbPostRelease((unsigned int)v20);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
