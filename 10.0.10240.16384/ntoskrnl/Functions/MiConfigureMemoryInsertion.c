// MiConfigureMemoryInsertion 
 
int __fastcall MiConfigureMemoryInsertion(_DWORD *a1, unsigned int *a2, int *a3)
{
  int *v3; // r5
  __int64 v4; // kr00_8
  int v5; // r3
  int v7; // r4
  unsigned int v8; // r6
  unsigned int v9; // r2
  int v10; // lr
  unsigned int v11; // r1
  unsigned int v12; // r9
  int v13; // r10
  unsigned __int8 *v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r2
  int result; // r0
  int v20; // r1
  _DWORD *v21; // r0
  _DWORD *v22; // r8
  unsigned int v23; // lr
  _BYTE *v24; // r5
  unsigned int *v25; // r2
  int v26; // r10
  int v27; // r0
  _WORD *v28; // r9
  unsigned int *v29; // r6
  unsigned int v30; // t1
  int v31; // r10
  unsigned int v32; // r2
  _DWORD *v33; // r1
  int v34; // r3
  unsigned int v35; // r10
  unsigned int v36; // r6
  __int64 v37; // r1
  _DWORD *v38; // r0
  unsigned int v39; // [sp+0h] [bp-38h]
  unsigned int *v40; // [sp+4h] [bp-34h]
  _DWORD *v42; // [sp+10h] [bp-28h]

  v3 = a3;
  v4 = *((_QWORD *)a3 + 1);
  v39 = HIDWORD(v4) + v4;
  v5 = *a3;
  *a1 = 0;
  if ( v5 )
    v7 = (int)&a2[2 * *a2 + 2];
  else
    v7 = 0;
  v8 = *a2;
  v9 = *a2 + 1;
  if ( v9 < *a2 || v8 > 0x1FFFFFFC )
    return -1073741670;
  v10 = 8 * (v8 + 2);
  if ( v7 )
  {
    if ( (unsigned int)(-1 - v10) >> 1 >= v9 )
    {
      v10 += 2 * (v8 + 1);
      goto LABEL_6;
    }
    return -1073741670;
  }
LABEL_6:
  v11 = 0;
  v12 = 0;
  v13 = 1;
  v14 = (unsigned __int8 *)v7;
  v15 = a2;
  do
  {
    v16 = v15[2];
    v40 = v15 + 2;
    v17 = v15[3];
    if ( v17 )
    {
      v18 = v17 + v16;
      if ( (unsigned int)v4 < v16 )
      {
        v3 = a3;
        if ( v39 > v16 )
          return sub_80FB34(v14);
      }
      else if ( (unsigned int)v4 < v18 )
      {
        return sub_80FB34(v14);
      }
      if ( ((_DWORD)v4 == v18 || v39 == v16)
        && (!v7 || *v14 == *((unsigned __int8 *)v3 + 16) && v14[1] == *((unsigned __int8 *)v3 + 17)) )
      {
        if ( v13 == 1 )
        {
          v12 = v11;
          v13 = 0;
        }
        else
        {
          v13 = -1;
        }
      }
    }
    ++v11;
    v15 = v40;
    v14 += 2;
  }
  while ( v11 < v8 );
  v20 = v10 + 8 * v13;
  if ( v7 )
    v20 += 2 * (v13 + v8);
  v21 = (_DWORD *)ExAllocatePoolWithTag(512, v20, 538996045);
  if ( !v21 )
    return -1073741670;
  v21[1] = 1;
  v22 = v21 + 2;
  v23 = v4;
  *v21 = MiSystemPartition;
  v21[2] = v13 + v8;
  v24 = &v21[2 * v13 + 4 + 2 * v8];
  v42 = v21 + 2;
  v21[3] = a2[1] + HIDWORD(v4);
  if ( v13 == -1 )
  {
    v31 = 2 * v12;
    memmove((int)(v21 + 4), (int)(a2 + 2), 8 * v12 + 8);
    if ( v7 )
      memmove((int)v24, v7, 2 * (v12 + 1));
    v32 = a2[v31 + 5];
    v33 = &v22[v31];
    v34 = v22[v31 + 3];
    v35 = v12 + 2;
    v33[3] = v34 + v32 + HIDWORD(v4);
    if ( v12 + 2 != v8 )
    {
      v36 = v8 - v12;
      memmove((int)&v22[2 * v35], (int)&a2[2 * v12 + 6], 8 * v36 - 16);
      if ( v7 )
        memmove((int)&v24[2 * v12 + 2], v7 + 2 * v35, 2 * v36 - 4);
    }
  }
  else if ( v13 )
  {
    v25 = v21 + 4;
    v26 = 0;
    v27 = 0;
    v28 = (_WORD *)v7;
    v29 = a2;
    do
    {
      if ( !v27 )
      {
        v23 = v4;
        if ( v39 <= v29[2] )
        {
          *(_QWORD *)v25 = v4;
          v25 += 2;
          if ( v7 )
          {
            v24[1] = *((_BYTE *)a3 + 17);
            *v24 = *((_BYTE *)a3 + 16);
            v24 += 2;
          }
          v27 = 1;
        }
      }
      v30 = v29[2];
      v29 += 2;
      *v25 = v30;
      v25[1] = v29[1];
      v25 += 2;
      if ( v7 )
      {
        *(_WORD *)v24 = *v28;
        v24 += 2;
      }
      ++v26;
      ++v28;
    }
    while ( v26 != *a2 );
    v22 = v42;
    if ( !v27 )
    {
      *v25 = v23;
      v25[1] = HIDWORD(v4);
      if ( v7 )
      {
        v24[1] = *((_BYTE *)a3 + 17);
        *v24 = *((_BYTE *)a3 + 16);
      }
    }
  }
  else
  {
    memmove((int)(v21 + 4), (int)(a2 + 2), 8 * v8);
    if ( v7 )
      memmove((int)v24, v7, 2 * v8);
    v37 = *(_QWORD *)&a2[2 * v12 + 2];
    v38 = &v22[2 * v12];
    v38[3] += HIDWORD(v4);
    if ( (_DWORD)v4 != HIDWORD(v37) + (_DWORD)v37 )
      v38[2] = v4;
  }
  result = 0;
  *a1 = v22;
  return result;
}
