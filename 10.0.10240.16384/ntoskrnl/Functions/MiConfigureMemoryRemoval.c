// MiConfigureMemoryRemoval 
 
int __fastcall MiConfigureMemoryRemoval(_DWORD *a1, _DWORD *a2, int *a3)
{
  int v3; // r3
  _DWORD *v4; // r6
  _WORD *v5; // r9
  __int64 v6; // kr00_8
  int v7; // r1
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r7
  _DWORD *v11; // r0
  int v12; // r2
  __int64 v13; // t1
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r1
  _DWORD *v17; // r0
  int result; // r0
  int v19; // r10
  unsigned int *v20; // r1
  int v21; // r2
  _WORD *v22; // r4
  _WORD *v23; // r0
  _DWORD *v24; // r7
  unsigned int v25; // r2
  __int64 v26; // t1
  unsigned int v27; // lr
  int v28; // r3
  char v29; // [sp+0h] [bp-30h]
  _DWORD *v31; // [sp+8h] [bp-28h]

  v3 = *a3;
  v4 = a2;
  v29 = 0;
  *a1 = 0;
  if ( v3 )
    v5 = &a2[2 * *a2 + 2];
  else
    v5 = 0;
  v6 = *((_QWORD *)a3 + 1);
  v7 = 0;
  v8 = -2;
  v9 = HIDWORD(v6) + v6;
  v10 = a3[3];
  v11 = v4;
  while ( 1 )
  {
    v13 = *((_QWORD *)v11 + 1);
    v11 += 2;
    v12 = v13;
    v14 = HIDWORD(v13) + v13;
    if ( (unsigned int)v6 >= (unsigned int)v13 && v9 <= v14 )
      break;
    if ( ++v7 == *v4 )
      goto LABEL_15;
  }
  if ( (_DWORD)v6 != v12 )
  {
    if ( v9 != v14 )
    {
      v8 = 1;
      goto LABEL_15;
    }
LABEL_14:
    v8 = 0;
    goto LABEL_15;
  }
  if ( v9 != v14 )
    goto LABEL_14;
  v8 = -1;
LABEL_15:
  v15 = *v4 + v8;
  v16 = 8 * (v15 + 2);
  if ( v5 )
    v16 += 2 * v15;
  v17 = (_DWORD *)ExAllocatePoolWithTag(512, v16, 538996045);
  if ( !v17 )
    return -1073741670;
  v17[1] = 1;
  v19 = 0;
  *v17 = MiSystemPartition;
  v31 = v17 + 2;
  v20 = v17 + 4;
  v21 = *v4 + v8;
  v17[2] = v21;
  v22 = v5;
  v17[3] = v4[1] - v10;
  v23 = &v17[2 * v21 + 4];
  v24 = v4;
  do
  {
    v26 = *((_QWORD *)v24 + 1);
    v24 += 2;
    v25 = v26;
    v27 = HIDWORD(v26) + v26;
    if ( (v29 & 1) != 0 || (unsigned int)v6 < v25 || v9 > v27 )
    {
      *v20 = *v24;
      v28 = v24[1];
      goto LABEL_32;
    }
    v29 |= 1u;
    if ( (_DWORD)v6 == v25 )
    {
      if ( v9 == v27 )
        goto LABEL_34;
      *v20 = HIDWORD(v6) + v25;
LABEL_26:
      v28 = v24[1] - HIDWORD(v6);
LABEL_32:
      v20[1] = v28;
      v20 += 2;
      if ( v5 )
        *v23++ = *v22;
      goto LABEL_34;
    }
    *v20 = v25;
    if ( v9 == v27 )
      goto LABEL_26;
    v20[1] = v6 - v25;
    if ( v5 )
    {
      *v23 = *v22;
      v23[1] = *v22;
      v23 += 2;
    }
    v20[2] = v9;
    v20[3] = v27 - v9;
    v20 += 4;
LABEL_34:
    ++v19;
    ++v22;
  }
  while ( v19 != *a2 );
  result = 0;
  *a1 = v31;
  return result;
}
