// HvpApplyLogEntry 
 
int __fastcall HvpApplyLogEntry(int a1, _DWORD *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r5
  int v8; // r4
  __int64 *v9; // r10
  unsigned int v10; // r6
  unsigned int v11; // r2
  int v12; // lr
  int v13; // r9
  int result; // r0
  unsigned int v16; // r1
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r9
  unsigned int *v20; // r10
  unsigned int v21; // r3
  unsigned int v22; // r4
  __int64 v23; // kr08_8
  unsigned int v24; // r5
  unsigned int v25; // r5
  BOOL v26; // r0
  int v27; // r3
  unsigned int v28; // r3
  unsigned int v29; // r3
  int v30; // r4
  unsigned int i; // r5
  __int64 v32; // kr10_8
  int v33; // [sp+8h] [bp-30h]
  int v34; // [sp+Ch] [bp-2Ch]
  int v35; // [sp+10h] [bp-28h] BYREF
  unsigned int v36; // [sp+14h] [bp-24h]
  __int64 *v37; // [sp+18h] [bp-20h]

  v7 = *(_DWORD *)(a1 + 32);
  v8 = a2[4];
  v9 = (__int64 *)a3;
  v37 = (__int64 *)a3;
  *(_DWORD *)(v7 + 40) = v8;
  v10 = *(_DWORD *)(a1 + 952);
  v11 = a2[4];
  v12 = a4;
  v34 = a4;
  v13 = 0;
  v33 = 0;
  if ( v10 >= v11 )
    goto LABEL_39;
  result = CmpDoFileSetSizeEx(a1, 0, v11, 0, 1);
  if ( result < 0 )
    return result;
  if ( (*(_BYTE *)(a1 + 72) & 4) != 0 )
  {
    result = HvViewMapPinFile((int *)(a1 + 152));
    if ( result < 0 )
      return result;
  }
  result = HvpExpandMap(a1, 0, v10, a2[4]);
  if ( result < 0 )
    return result;
  v12 = v34;
  v16 = 0;
  *(_DWORD *)(a1 + 952) = a2[4];
  v17 = a2[5];
  v18 = 0;
  v19 = v34;
  v36 = 0;
  if ( !v17 )
  {
LABEL_31:
    v29 = a2[4];
    if ( v18 < v10 )
      v18 = v10;
    if ( v29 > v18 )
    {
      v30 = v29 - v18;
      if ( v29 != v18 )
      {
        while ( 1 )
        {
          result = HvpAddDummyBinToHive(a1, 0, a2[4] - v30, &v35);
          if ( result < 0 )
            return result;
          v30 -= 4096;
          if ( !v30 )
          {
            v12 = v34;
            break;
          }
        }
      }
    }
    v13 = v33;
LABEL_39:
    for ( i = 0; i < a2[5]; ++v9 )
    {
      v32 = *v9;
      if ( *(_DWORD *)v9 >= v10 )
        break;
      HvpCopyModifiedData(a1, v32, v12, HIDWORD(v32));
      ++i;
      v12 = v34 + HIDWORD(v32);
      v34 += HIDWORD(v32);
      v13 += HIDWORD(v32);
    }
    if ( (a2[2] & 1) != 0 )
      *(_DWORD *)(*(_DWORD *)(a1 + 32) + 144) |= 1u;
    result = 1073741833;
    *a6 = v13;
    return result;
  }
  while ( 1 )
  {
    v20 = (unsigned int *)&v9[v16];
    v21 = v20[1];
    v22 = *v20;
    v18 = v21 + *v20;
    if ( v18 > v10 )
      break;
    v19 += v21;
LABEL_29:
    v28 = a2[5];
    ++v16;
    v9 = v37;
    v36 = v16;
    if ( v16 >= v28 )
    {
      v12 = v34;
      goto LABEL_31;
    }
  }
  if ( v22 < v10 )
  {
    v19 = v19 - v22 + v10;
    v22 = v10;
  }
  if ( v16 && (v23 = *((_QWORD *)v20 - 1), HIDWORD(v23) + (int)v23 >= v10) )
    v24 = v22 - HIDWORD(v23) - v23;
  else
    v24 = v22 - v10;
  if ( !v24 )
  {
LABEL_18:
    v25 = v20[1] + *v20;
    while ( v22 < v25 )
    {
      v26 = HvpValidateLoadedBin(v19, v22, a2[4]);
      if ( !v26 )
        goto LABEL_24;
      if ( *(_DWORD *)(v19 + 8) > v25 - v22 )
        v26 = 0;
      if ( v26 )
        result = HvpAddLoadedBinToHive(a1, v19, v22, &v35);
      else
LABEL_24:
        result = HvpAddDummyBinToHive(a1, v19, v22, &v35);
      if ( result < 0 )
        return result;
      v27 = *(_DWORD *)(v35 + 8);
      v22 += v27;
      v33 += v27;
      v19 += v27;
    }
    v16 = v36;
    v18 = v20[1] + *v20;
    goto LABEL_29;
  }
  while ( 1 )
  {
    result = HvpAddDummyBinToHive(a1, 0, v22 - v24, &v35);
    if ( result < 0 )
      return result;
    v24 -= 4096;
    if ( !v24 )
      goto LABEL_18;
  }
}
