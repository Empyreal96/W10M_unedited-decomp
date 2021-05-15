// PfpPrefetchDirectoryStream 
 
int __fastcall PfpPrefetchDirectoryStream(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // r10
  _DWORD *v10; // r7
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r4
  unsigned int v14; // r5
  int v15; // r4
  unsigned int *v16; // r3
  unsigned int v17; // r0
  unsigned int v18; // r1
  __int64 v19; // kr08_8
  _DWORD *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r2
  int v24; // r2
  unsigned __int64 v26; // [sp+18h] [bp-50h]
  unsigned int v27; // [sp+20h] [bp-48h]
  int v28; // [sp+28h] [bp-40h] BYREF
  char v29[8]; // [sp+30h] [bp-38h] BYREF
  int v30[12]; // [sp+38h] [bp-30h] BYREF

  v6 = (_DWORD *)a1[5];
  memset(v30, 0, 20);
  v10 = (_DWORD *)a1[3];
  v30[4] |= 2u;
  v26 = 0i64;
  v11 = *(unsigned __int16 *)(*a1 + 30);
  *v10 = 4;
  v27 = v11;
  v10[2] = *(_DWORD *)(*a1 + 28) & 7 | (8 * (v11 & 7));
  v13 = PfpOpenHandleCreate(v30, v6, *(_DWORD *)(a5 + 8), *(_DWORD *)(a5 + 4), 1048577, a6, 0, a2);
  if ( v13 < 0 )
    goto LABEL_36;
  if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
    MmQueryMemoryListInformation((int)(a1 + 6), 0x58u, v12, &v28);
  v14 = 0;
  if ( !*(_DWORD *)(a3 + 16) )
  {
LABEL_35:
    v13 = 0;
    goto LABEL_36;
  }
  while ( 2 )
  {
    v10[1] = 0;
    if ( v14 >= *(_DWORD *)(a3 + 16) )
      goto LABEL_35;
    v15 = 16 * v14;
    do
    {
      v16 = (unsigned int *)(*(_DWORD *)(a3 + 20) + v15);
      v17 = v16[1];
      v18 = *v16;
      v19 = *(_QWORD *)v16 + v16[2];
      if ( *(_QWORD *)v16 < v26 )
      {
        v17 = HIDWORD(v26);
        v18 = v26;
      }
      if ( v17 <= HIDWORD(v19) )
      {
        if ( v17 >= HIDWORD(v19) )
        {
LABEL_14:
          if ( v18 >= (unsigned int)v19 )
            goto LABEL_17;
        }
        do
        {
          v20 = &v10[2 * v10[1]];
          v20[4] = v18;
          v20[5] = v17;
          v21 = v10[1] + 1;
          v10[1] = v21;
          if ( v21 >= a1[4] )
          {
            LODWORD(v26) = v18 + 4096;
            HIDWORD(v26) = __CFADD__(v18, 4096) + v17;
            goto LABEL_17;
          }
          v17 = (__PAIR64__(v17, v18) + 4096) >> 32;
          v18 += 4096;
        }
        while ( v17 < HIDWORD(v19) );
        if ( v17 <= HIDWORD(v19) )
          goto LABEL_14;
      }
LABEL_17:
      if ( v10[1] >= a1[4] )
        break;
      ++v14;
      v15 += 16;
    }
    while ( v14 < *(_DWORD *)(a3 + 16) );
    if ( !v10[1] )
      goto LABEL_35;
    v22 = *(_DWORD *)(*a1 + 52);
    if ( v22 && *(_DWORD *)(v22 + 4)
      || ((*(_DWORD *)(*a1 + 56) >> 2) & 1) != 0
      && ((v23 = a1[5], *(_DWORD *)(v23 + 44))
       || (*(_DWORD *)(v23 + 40) & 4) != 0
       || !PfpAvailablePagesForPrefetch(a1 + 6, v27)) )
    {
      v13 = -1073741248;
      goto LABEL_36;
    }
    v13 = NtFsControlFile(v30[0], 0, 0, 0, (int)v29, 590112, (int)v10);
    if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
      PfpUpdateRepurposedByPrefetch((int)(a1 + 6), v10[1], v24);
    if ( v13 >= 0 )
    {
      if ( v13 == 259 )
        KeBugCheckEx(401, 5234, 0, 0, 0);
      if ( v14 >= *(_DWORD *)(a3 + 16) )
        goto LABEL_35;
      continue;
    }
    break;
  }
  if ( v13 == -1073741807 )
    goto LABEL_35;
LABEL_36:
  if ( (v30[4] & 4) != 0 )
    PfpOpenHandleClose(v30, (int)v6);
  return v13;
}
