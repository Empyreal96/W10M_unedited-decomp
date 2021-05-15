// RtlGenerate8dot3Name 
 
int __fastcall RtlGenerate8dot3Name(unsigned __int16 *a1, int a2, int a3, int a4)
{
  unsigned __int16 *v4; // r7
  int result; // r0
  unsigned int v9; // r4
  unsigned int v10; // r6
  BOOL v11; // r3
  BOOL i; // r2
  int v13; // r0
  char v14; // r3
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r4
  char *v22; // r0
  int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r3
  int v26; // r2
  unsigned int v27; // r0
  unsigned int j; // r1
  __int16 v29; // r3
  char v30; // r3
  unsigned int v31; // r0
  int v32; // r4
  int v33; // r6
  __int16 v34; // r3
  unsigned int v35; // [sp+4h] [bp-44h] BYREF
  unsigned int v36; // [sp+8h] [bp-40h] BYREF
  int v37; // [sp+Ch] [bp-3Ch]
  unsigned __int16 *v38; // [sp+10h] [bp-38h]
  char v39; // [sp+26h] [bp-22h] BYREF
  char v40[32]; // [sp+28h] [bp-20h] BYREF

  v4 = (unsigned __int16 *)a4;
  v37 = 1;
  v38 = (unsigned __int16 *)a4;
  if ( a2 && NlsMbOemCodePageTag )
    return sub_7E7FF4();
  if ( !*(_BYTE *)(a3 + 3) )
  {
    v9 = *a1;
    v10 = -1;
    v36 = -1;
    v35 = 0;
    v11 = v9 && **((_WORD **)a1 + 1) == 46;
    for ( i = v11; ; i = 0 )
    {
      v13 = GetNextWchar(a1, &v35, i, a2);
      if ( !v13 )
        break;
      if ( v13 == 46 )
        v10 = v35;
    }
    v36 = v10;
    if ( v10 == v9 >> 1 )
    {
      v10 = -1;
      v36 = -1;
    }
    v14 = 0;
    v35 = 0;
    while ( 1 )
    {
      *(_BYTE *)(a3 + 3) = v14;
      v15 = GetNextWchar(a1, &v35, 1, a2);
      if ( !v15 )
        break;
      if ( v35 >= v10 )
        break;
      v16 = *(unsigned __int8 *)(a3 + 3);
      if ( v16 >= 6 )
        break;
      *(_WORD *)(a3 + 2 * v16 + 4) = v15;
      v14 = *(_BYTE *)(a3 + 3) + 1;
    }
    v4 = v38;
    if ( *(unsigned __int8 *)(a3 + 3) <= 2u )
    {
      v27 = RtlComputeLfnChecksum(a1);
      *(_WORD *)a3 = v27;
      for ( j = 0; j < 4; ++j )
      {
        if ( (v27 & 0xF) > 9 )
          v29 = 55;
        else
          v29 = 48;
        *(_WORD *)(a3 + 2 * (*(unsigned __int8 *)(a3 + 3) + j) + 4) = (v27 & 0xF) + v29;
        LOWORD(v27) = v27 >> 4;
      }
      v30 = *(_BYTE *)(a3 + 3);
      *(_BYTE *)(a3 + 2) = 1;
      *(_BYTE *)(a3 + 3) = v30 + 4;
    }
    if ( v10 == -1 )
    {
      *(_DWORD *)(a3 + 20) = 0;
    }
    else
    {
      *(_WORD *)(a3 + 24) = 46;
      for ( *(_DWORD *)(a3 + 20) = 1; ; ++*(_DWORD *)(a3 + 20) )
      {
        v17 = GetNextWchar(a1, &v36, 1, a2);
        if ( !v17 )
          break;
        v18 = *(_DWORD *)(a3 + 20);
        if ( v18 >= 4 )
        {
          if ( FsRtlSafeExtensions )
            *(_WORD *)(a3 + 2 * *(_DWORD *)(a3 + 20) + 22) = 126;
          break;
        }
        *(_WORD *)(a3 + 2 * v18 + 24) = v17;
      }
    }
  }
  v19 = *(_DWORD *)(a3 + 32) + 1;
  *(_DWORD *)(a3 + 32) = v19;
  if ( v19 > 4 && !*(_BYTE *)(a3 + 2) )
  {
    v31 = RtlComputeLfnChecksum(a1);
    *(_WORD *)a3 = v31;
    v32 = a3 + 4;
    v33 = 4;
    do
    {
      if ( (v31 & 0xF) > 9 )
        v34 = 55;
      else
        v34 = 48;
      *(_WORD *)(v32 + 4) = v34 + (v31 & 0xF);
      v32 += 2;
      LOWORD(v31) = v31 >> 4;
      --v33;
    }
    while ( v33 );
    *(_DWORD *)(a3 + 32) = 1;
    *(_BYTE *)(a3 + 2) = 1;
    *(_BYTE *)(a3 + 3) = 6;
  }
  v20 = *(_DWORD *)(a3 + 32);
  v21 = 1;
  v22 = &v39;
  do
  {
    if ( !v20 )
      break;
    v23 = (unsigned __int16)(v20 % 0xA + 48);
    *(_WORD *)v22 = v23;
    v22 -= 2;
    if ( v23 != 57 )
      v37 = 0;
    ++v21;
    v20 /= 0xAu;
  }
  while ( v21 <= 7 );
  *(_WORD *)&v40[-2 * v21] = 126;
  v24 = *(unsigned __int8 *)(a3 + 3);
  if ( *(_BYTE *)(a3 + 3) && v24 <= 0xC )
  {
    memmove(*((_DWORD *)v4 + 1), a3 + 4, 2 * v24);
    *v4 = 2 * *(unsigned __int8 *)(a3 + 3);
  }
  else
  {
    *v4 = 0;
  }
  memmove(*((_DWORD *)v4 + 1) + 2 * (*v4 >> 1), (int)&v40[-2 * v21], 2 * v21);
  v25 = (unsigned __int16)(*v4 + 2 * v21);
  *v4 = v25;
  v26 = *(_DWORD *)(a3 + 20);
  if ( v26 )
  {
    memmove(*((_DWORD *)v4 + 1) + 2 * (v25 >> 1), a3 + 24, 2 * v26);
    *v4 += 2 * *(_WORD *)(a3 + 20);
  }
  if ( !v37 || (--*(_BYTE *)(a3 + 3), *(_BYTE *)(a3 + 3)) )
    result = 0;
  else
    result = -1073740761;
  return result;
}
