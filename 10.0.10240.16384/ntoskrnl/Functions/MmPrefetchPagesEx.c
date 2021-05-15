// MmPrefetchPagesEx 
 
int __fastcall MmPrefetchPagesEx(unsigned int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r5
  int v6; // r0
  unsigned int v7; // r7
  int v8; // r9
  _DWORD *v9; // r8
  unsigned int v10; // r10
  int v11; // r3
  char v12; // r6
  char v13; // r10
  unsigned int v14; // r6
  unsigned int *v15; // r8
  unsigned int v16; // r6
  unsigned int v17; // r8
  int v18; // r3
  unsigned int *v19; // r4
  unsigned int v20; // r0
  unsigned int v21; // t1
  unsigned int *v22; // r8
  unsigned int v23; // r4
  int v24; // r3
  int v25; // r7
  int *v26; // r2
  int v27; // r0
  __int64 v28; // kr00_8
  int v31; // [sp+10h] [bp-20h]

  v3 = a1;
  if ( a1 > 0x3FFFFFFF )
    return sub_806568();
  v6 = ExAllocatePoolWithTag(512, 4 * a1, 1817341261);
  v7 = v6;
  v31 = v6;
  if ( !v6 )
    return -1073741670;
  v12 = 0;
  v8 = 0;
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v23 + 308);
  if ( v3 )
  {
    v24 = a2 - v6;
    v10 = v3;
    v9 = (_DWORD *)v6;
    v25 = v24;
    do
    {
      v6 = MiPfPrepareReadList(*(_DWORD **)((char *)v9 + v25), v9);
      if ( v6 < 0 )
      {
        v8 = v6;
      }
      else if ( *v9 )
      {
        v12 |= 1u;
      }
      ++v9;
      --v10;
    }
    while ( v10 );
    v3 = a1;
    v7 = v31;
  }
  if ( (v12 & 1) == 0 )
  {
    v11 = (__int16)(*(_WORD *)(v23 + 308) + 1);
    *(_WORD *)(v23 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v6);
    goto LABEL_12;
  }
  v13 = v12 & 0xFE;
  v14 = 0;
  ++*(_BYTE *)(v23 + 974);
  v8 = 0;
  if ( !v3 )
    goto LABEL_18;
  v15 = (unsigned int *)v7;
  while ( !*v15 )
  {
LABEL_17:
    ++v14;
    ++v15;
    if ( v14 >= v3 )
      goto LABEL_18;
  }
  *(_DWORD *)(*v15 + 44) = 0;
  v6 = MiPfPutPagesInTransition((_DWORD *)*v15, a3);
  if ( v6 >= 0 )
  {
    if ( *(_DWORD *)(*v15 + 56) == *v15 + 56 )
    {
      MiReleaseReadListResources();
      v6 = ExFreePoolWithTag(*v15);
      *v15 = 0;
    }
    else
    {
      v13 |= 1u;
      v6 = MiPfExecuteReadList(*v15, 0);
    }
    goto LABEL_17;
  }
  v8 = v6;
  if ( v14 < v3 )
  {
    v22 = (unsigned int *)(v7 + 4 * v14);
    do
    {
      if ( *v22 )
      {
        while ( 1 )
        {
          v26 = (int *)(*v22 + 56);
          if ( (int *)*v26 == v26 )
            break;
          v27 = *v26;
          v28 = *(_QWORD *)*v26;
          if ( (int *)HIDWORD(v28) != v26 || *(_DWORD *)(v28 + 4) != v27 )
            __fastfail(3u);
          *v26 = v28;
          *(_DWORD *)(v28 + 4) = v26;
          MiFreeInPageSupportBlock(v27);
        }
        MiReleaseReadListResources();
        v6 = ExFreePoolWithTag(*v22);
        *v22 = 0;
      }
      ++v14;
      ++v22;
    }
    while ( v14 < v3 );
  }
LABEL_18:
  if ( (v13 & 1) != 0 )
  {
    v8 = 0;
    if ( v3 )
    {
      v16 = v7;
      v17 = v3;
      do
      {
        if ( *(_DWORD *)v16 )
        {
          MiPfCompletePrefetchIos((_DWORD *)(*(_DWORD *)v16 + 56), 0);
          v6 = MiReleaseReadListResources();
        }
        v16 += 4;
        --v17;
      }
      while ( v17 );
    }
  }
  v18 = (__int16)(*(_WORD *)(v23 + 308) + 1);
  *(_WORD *)(v23 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v6);
  --*(_BYTE *)(v23 + 974);
  if ( v3 )
  {
    v19 = (unsigned int *)v7;
    do
    {
      v21 = *v19++;
      v20 = v21;
      if ( v21 )
        ExFreePoolWithTag(v20);
      --v3;
    }
    while ( v3 );
  }
LABEL_12:
  ExFreePoolWithTag(v7);
  return v8;
}
