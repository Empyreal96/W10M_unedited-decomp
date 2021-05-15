// IopCreateCmResourceList 
 
int __fastcall IopCreateCmResourceList(unsigned int *a1, int a2, int a3, unsigned int **a4)
{
  unsigned int *v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r1
  _DWORD *v7; // r0
  unsigned int v8; // r7
  __int64 v9; // r4
  unsigned int **v10; // r9
  int v11; // r9
  int v12; // r10
  unsigned int v13; // lr
  _BYTE *v14; // r8
  unsigned int v16; // kr18_4
  unsigned __int64 v17; // kr20_8
  _DWORD *v18; // r4
  __int64 v19; // kr28_8
  _DWORD *v20; // r0
  _DWORD *v21; // r8
  int v22; // r0
  int v23; // lr
  _DWORD *v24; // r5
  unsigned int i; // r9
  int v26; // r1
  unsigned int v27; // r7
  _DWORD *v28; // r2
  int v29; // r0
  unsigned __int64 v30; // [sp+0h] [bp-38h]
  _DWORD *v31; // [sp+0h] [bp-38h]
  _DWORD *v32; // [sp+4h] [bp-34h]

  v4 = a1;
  v5 = *a1;
  v6 = 0;
  v7 = a1 + 1;
  v8 = 0;
  HIDWORD(v9) = 0;
  v30 = v5;
  v10 = a4;
  if ( !v5 )
    goto LABEL_16;
  v11 = 4;
  do
  {
    v12 = v7[3];
    LODWORD(v9) = 16;
    v13 = 0;
    v14 = v7 + 4;
    if ( v12 )
    {
      do
      {
        if ( *v14 == 5 )
          return sub_80CD38();
        v13 = (__PAIR64__(v13, v9) + 16) >> 32;
        LODWORD(v9) = v9 + 16;
        --v12;
        v14 += 16;
      }
      while ( v12 );
      v6 = HIDWORD(v30);
      v5 = v30;
    }
    if ( *v7 == a2 && v7[1] == a3 )
    {
      HIDWORD(v9) = (__PAIR64__(v13, v8) + v9) >> 32;
      v8 += v9;
    }
    v16 = v11 + v9;
    v6 = (__PAIR64__(v6, v11) + __PAIR64__(v13, v9)) >> 32;
    v11 += v9;
    v7 = (_DWORD *)((char *)v7 + v9);
    v30 = __PAIR64__(v6, --v5);
  }
  while ( v5 );
  LODWORD(v30) = v16;
  v10 = a4;
  if ( !(v8 | HIDWORD(v9)) )
  {
LABEL_16:
    *v10 = v4;
    return 0;
  }
  v17 = __PAIR64__(HIDWORD(v9), v8) + 4;
  if ( __PAIR64__(HIDWORD(v9), v8) + 4 != __PAIR64__(v6, v16) )
  {
    if ( HIDWORD(v17) || (v18 = (_DWORD *)ExAllocatePoolWithTag(1, v17, 538996816)) == 0 )
    {
      v4 = 0;
      goto LABEL_14;
    }
    v19 = v30 - (unsigned int)v17 + 4;
    if ( HIDWORD(v19) )
    {
      *a4 = 0;
    }
    else
    {
      v20 = (_DWORD *)ExAllocatePoolWithTag(1, v19, 538996816);
      v21 = v20;
      *a4 = v20;
      if ( v20 )
      {
        *v18 = 0;
        *v20 = 0;
        v22 = (int)(v18 + 1);
        v23 = (int)(v21 + 1);
        v24 = v4 + 1;
        v31 = v21 + 1;
        v32 = v18 + 1;
        for ( i = 0; i < *v4; ++i )
        {
          v26 = v24[3];
          v27 = 16;
          v28 = v24 + 4;
          if ( v26 )
          {
            do
            {
              v29 = 16;
              if ( *(_BYTE *)v28 == 5 )
                v29 = v28[1] + 16;
              v27 += v29;
              v28 = (_DWORD *)((char *)v28 + v29);
              --v26;
            }
            while ( v26 );
            v23 = (int)v31;
            v22 = (int)v32;
          }
          if ( *v24 == a2 && v24[1] == a3 )
          {
            ++*v18;
            memmove(v22, (int)v24, v27);
            v23 = (int)v31;
            v22 = (int)v32 + v27;
            v32 = (_DWORD *)((char *)v32 + v27);
          }
          else
          {
            ++*v21;
            memmove(v23, (int)v24, v27);
            v22 = (int)v32;
            v23 = (int)v31 + v27;
            v31 = (_DWORD *)((char *)v31 + v27);
          }
          v24 = (_DWORD *)((char *)v24 + v27);
        }
        return (int)v18;
      }
    }
    ExFreePoolWithTag((unsigned int)v18);
    return 0;
  }
LABEL_14:
  *a4 = 0;
  return (int)v4;
}
