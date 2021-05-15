// SepInsertOrReferenceSharedSidEntries 
 
int __fastcall SepInsertOrReferenceSharedSidEntries(char *a1, char *a2, unsigned int a3)
{
  unsigned int v3; // r8
  char *v4; // r9
  unsigned int v6; // r4
  unsigned __int8 *v7; // r6
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r4
  int v11; // r2
  unsigned int v12; // r6
  int v13; // r3
  char *v14; // r8
  unsigned __int16 *v15; // r5
  int v16; // t1
  unsigned int v17; // r1
  int v18; // r4
  _DWORD *v19; // r9
  unsigned int v20; // r1
  signed int v21; // r1
  int v22; // r5
  unsigned int *v23; // r4
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  int v29; // r2
  int v30; // r5
  int v31; // r0
  int v32; // r0
  int v33; // r0
  int *v34; // r9
  int v35; // t1
  _DWORD *v36; // r0
  unsigned int v37; // r4
  unsigned int *v38; // r2
  unsigned int v39; // r1
  signed int v40; // r1
  int v42; // [sp+4h] [bp-34h]
  _DWORD v44[10]; // [sp+10h] [bp-28h] BYREF

  v3 = a3;
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
  v11 = 1;
  if ( (v10 & 1) != 0 )
  {
    v8 = ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
    v11 = 1;
  }
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v12 = 0;
  if ( !v3 )
  {
LABEL_18:
    v22 = 0;
    goto LABEL_19;
  }
  v13 = v4 - a1;
  v42 = v4 - a1;
  while ( 1 )
  {
    v14 = &a1[v13];
    *(_DWORD *)&a1[v13 + 4] = *((_DWORD *)a1 + 1);
    v16 = *(_DWORD *)a1;
    a1 += 8;
    v15 = (unsigned __int16 *)v16;
    v17 = *(_DWORD *)(v16 + 4 * *(unsigned __int8 *)(v16 + 1) + 4);
    if ( !v17 )
      return sub_7C59A8(v8, 0, v11);
    v18 = RtlLookupEntryHashTable(*((_DWORD **)g_SepSidMapping + 1), v17, v44, (int)g_SepSidMapping);
    if ( v18 )
    {
      v19 = g_SepSidMapping;
      while ( 1 )
      {
        v8 = RtlEqualSid(v15, *(unsigned __int16 **)(v18 + 16));
        if ( v8 )
          break;
        v33 = RtlGetNextEntryHashTable(v19[1], (int)v44);
        v18 = v33;
        if ( !v33 )
          goto LABEL_26;
      }
      if ( v18 )
      {
        v11 = v18 + 12;
        do
        {
          v20 = __ldrex((unsigned int *)v11);
          v21 = v20 + 1;
        }
        while ( __strex(v21, (unsigned int *)v11) );
        if ( v21 <= 1 )
          __fastfail(0xEu);
        goto LABEL_17;
      }
    }
LABEL_26:
    v29 = 4 * (*(unsigned __int8 *)(*((_DWORD *)a1 - 2) + 1) + 7);
    v30 = ((v29 + 3) & 0xFFFFFFFC) + v29;
    v31 = ExAllocatePoolWithTag(1, v30, 1934845267);
    v18 = v31;
    if ( !v31 )
      break;
    *(_DWORD *)(v31 + 12) = 1;
    *(_DWORD *)(v31 + 16) = v31 + 20;
    RtlCopySid(v30 - 20, v31 + 20, *((_DWORD *)a1 - 2));
    v32 = SepComputeSidSignature(*((_DWORD *)a1 - 2));
    v8 = RtlInsertEntryHashTable(*((_DWORD *)g_SepSidMapping + 1), v18, v32, 0);
    if ( !v8 )
    {
      v22 = -1073741823;
      ExFreePoolWithTag(v18);
      goto LABEL_39;
    }
LABEL_17:
    ++v12;
    *(_DWORD *)v14 = *(_DWORD *)(v18 + 16);
    v13 = v42;
    if ( v12 >= a3 )
      goto LABEL_18;
  }
  v22 = -1073741801;
LABEL_39:
  if ( v12 )
  {
    v34 = (int *)a2;
    do
    {
      v35 = *v34;
      v34 += 2;
      v36 = (_DWORD *)SepFindSharedSidEntry(v35);
      v37 = (unsigned int)v36;
      __dmb(0xBu);
      v38 = v36 + 3;
      do
      {
        v39 = __ldrex(v38);
        v40 = v39 - 1;
      }
      while ( __strex(v40, v38) );
      if ( v40 <= 0 )
      {
        if ( v40 )
          __fastfail(0xEu);
        __dmb(0xBu);
        if ( RtlRemoveEntryHashTable(*((_DWORD *)g_SepSidMapping + 1), v36, 0) )
          ExFreePoolWithTag(v37);
      }
      --v12;
    }
    while ( v12 );
  }
LABEL_19:
  v23 = (unsigned int *)g_SepSidMapping;
  __dmb(0xBu);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 - 1, v23) );
  if ( (v24 & 2) != 0 && (v24 & 4) == 0 )
    ExfTryToWakePushLock(v23);
  v25 = KeAbPostRelease((unsigned int)v23);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = *(_WORD *)(v26 + 0x134) + 1;
  *(_WORD *)(v26 + 308) = v27;
  if ( v27 )
    return v22;
  if ( *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    KiCheckForKernelApcDelivery(v25);
  return v22;
}
