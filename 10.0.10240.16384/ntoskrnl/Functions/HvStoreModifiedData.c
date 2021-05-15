// HvStoreModifiedData 
 
int __fastcall HvStoreModifiedData(int a1, int a2, int a3)
{
  int v4; // r3
  unsigned int v5; // r10
  int v6; // r5
  unsigned int v7; // r6
  unsigned int v8; // r7
  unsigned int v9; // r8
  int v11; // r0
  int v12; // r3
  __int64 v13; // kr00_8
  int v14; // r0
  int v15; // r0
  _BYTE *v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r4
  _BYTE *v20; // r0
  int v21; // r0
  int v22; // r0
  int *v23; // r1
  int v24; // r3
  int v25; // r2
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r2
  int v30; // r3
  unsigned int v31; // r5
  unsigned int v32; // r0
  int v33; // [sp+10h] [bp-60h] BYREF
  _BYTE *v34; // [sp+14h] [bp-5Ch]
  unsigned int v35; // [sp+18h] [bp-58h]
  int *v36; // [sp+1Ch] [bp-54h] BYREF
  int v37; // [sp+20h] [bp-50h]
  int v38; // [sp+24h] [bp-4Ch] BYREF
  int v39; // [sp+28h] [bp-48h] BYREF
  int v40; // [sp+2Ch] [bp-44h]
  int v41; // [sp+30h] [bp-40h]
  int v42; // [sp+34h] [bp-3Ch]
  int v43; // [sp+38h] [bp-38h]
  int v44; // [sp+40h] [bp-30h] BYREF
  unsigned int v45; // [sp+44h] [bp-2Ch]
  int v46; // [sp+48h] [bp-28h] BYREF
  int v47; // [sp+4Ch] [bp-24h]

  v41 = 0;
  v42 = a2;
  v37 = a3;
  v38 = 0;
  v34 = 0;
  v44 = 0;
  v45 = 0;
  v43 = 0;
  v47 = 0;
  v4 = *(_DWORD *)(a1 + 92);
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v36 = 0;
  if ( (v4 & 0x8000) != 0 )
    return sub_7D3E74();
  v11 = HvpTruncateBins();
  v12 = *(_DWORD *)(a1 + 92);
  *(_DWORD *)(a1 + 1896) = v11;
  if ( (v12 & 1) != 0 )
    return sub_7D3E74();
  v13 = *(_QWORD *)(a1 + 44);
  if ( !(_DWORD)v13 )
  {
    v40 = v44;
    goto LABEL_8;
  }
  v14 = ExAllocatePoolWithTag(1, SHIDWORD(v13), 808799555);
  v5 = v14;
  if ( v14 )
  {
    memmove(v14, *(_DWORD *)(a1 + 40), HIDWORD(v13));
    v40 = *(_DWORD *)(a1 + 36);
    v44 = v40;
    v45 = v5;
    v15 = HvpGenerateLogEntry(a1, &v36, &v38);
    v9 = (unsigned int)v36;
    if ( v15 < 0 )
      goto LABEL_12;
    v41 = v38;
LABEL_8:
    if ( !v42 && !v37 )
      goto LABEL_24;
    v16 = (_BYTE *)ExAllocatePoolWithTag(1, 4096, 808799555);
    v34 = v16;
    if ( !v16 )
      goto LABEL_12;
    memset(v16, 0, 4096);
    v17 = (int)v34;
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40) = *(_DWORD *)(a1 + 952);
    memmove(v17, *(_DWORD *)(a1 + 32), 0x200u);
    if ( !v37 )
    {
LABEL_24:
      v26 = *(_DWORD *)(a1 + 952);
      if ( *(_DWORD *)(a1 + 1936) < v26 || *(_DWORD *)(a1 + 1896) )
        *(_DWORD *)(a1 + 1936) = v26;
      if ( *(_DWORD *)(a1 + 44) )
      {
        v27 = v40;
        *(_DWORD *)(a1 + 1880) = v5;
        v5 = 0;
        *(_DWORD *)(a1 + 1876) = v27;
        v28 = v41;
        *(_DWORD *)(a1 + 1888) = v9;
        *(_DWORD *)(a1 + 1892) = v28;
        *(_DWORD *)(a1 + 1884) = HIDWORD(v13);
        v9 = 0;
        HvResetDirtyData(a1);
      }
      v29 = v37;
      if ( v42 || v37 )
      {
        *(_DWORD *)(a1 + 1924) = v34;
        v34 = 0;
        if ( *(_BYTE *)(a1 + 123) )
          *(_BYTE *)(a1 + 1900) = 1;
        if ( v29 )
        {
          v30 = v43;
          *(_DWORD *)(a1 + 1908) = v6;
          v6 = 0;
          *(_DWORD *)(a1 + 1904) = v30;
          *(_DWORD *)(a1 + 1916) = v7;
          v7 = 0;
          *(_DWORD *)(a1 + 1912) = HIDWORD(v13);
          *(_DWORD *)(a1 + 1920) = v8;
          HvResetUnreconciledData(a1);
        }
      }
      v19 = 0;
      goto LABEL_34;
    }
    v18 = ExAllocatePoolWithTag(1, SHIDWORD(v13), 808799555);
    v6 = v18;
    if ( v18 )
    {
      memmove(v18, *(_DWORD *)(a1 + 56), HIDWORD(v13));
      v46 = *(_DWORD *)(a1 + 52);
      v47 = v6;
      v43 = v46;
      if ( *(_DWORD *)(a1 + 44) )
        RtlMergeBitMaps((unsigned int *)&v46, (unsigned int *)&v44);
      v8 = HvpCountSetRangesInVector(&v46);
      v20 = (_BYTE *)ExAllocatePoolWithTag(1, 12 * v8, 842353987);
      v7 = (unsigned int)v20;
      if ( v20 )
      {
        memset(v20, 0, 12 * v8);
        v35 = 0;
        v39 = 0;
        if ( v8 )
        {
          v36 = (int *)v7;
          do
          {
            if ( (*(_BYTE *)(a1 + 72) & 4) != 0 )
            {
              v21 = HvpFindNextDirtyBlockAndCreateTemporary(a1, (int)&v46, (int)&v39, &v38, &v33);
              if ( v21 == -2147483622 )
                break;
              if ( v21 < 0 )
                goto LABEL_12;
              v22 = 0;
            }
            else
            {
              if ( !HvpFindNextDirtyBlock(a1, &v46, &v39, &v44, &v38, &v33, 1) )
                break;
              v22 = v44;
              if ( !v44 )
                goto LABEL_12;
            }
            v23 = v36;
            v24 = v38;
            v25 = v33;
            v36[2] = v38;
            *v23 = v25;
            v23[1] = v22;
            v36 = v23 + 3;
            ++v35;
            v33 = v24 + v25;
          }
          while ( v35 < v8 );
        }
        memmove(v6, *(_DWORD *)(a1 + 56), HIDWORD(v13));
        goto LABEL_24;
      }
    }
LABEL_12:
    v19 = 2;
LABEL_34:
    if ( v5 )
      ExFreePoolWithTag(v5);
    if ( v9 )
      ExFreePoolWithTag(v9);
    if ( v6 )
      ExFreePoolWithTag(v6);
    if ( v7 )
    {
      if ( v8 )
      {
        v31 = v7;
        do
        {
          v32 = *(_DWORD *)(v31 + 4);
          if ( v32 )
            ExFreePoolWithTag(v32);
          v31 += 12;
          --v8;
        }
        while ( v8 );
      }
      ExFreePoolWithTag(v7);
    }
    if ( v34 )
      ExFreePoolWithTag((unsigned int)v34);
    return v19;
  }
  return 2;
}
