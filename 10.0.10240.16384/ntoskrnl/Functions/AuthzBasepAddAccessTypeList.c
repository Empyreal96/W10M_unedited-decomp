// AuthzBasepAddAccessTypeList 
 
int __fastcall AuthzBasepAddAccessTypeList(int result, unsigned int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v7; // r4
  int v8; // r5
  int v10; // r8
  unsigned __int16 *v11; // lr
  int v12; // r2
  int v13; // r9
  int v14; // r3
  int *v15; // r2
  int v16; // r1
  unsigned __int16 *v17; // lr
  __int64 v18; // kr00_8
  int v19; // r3
  int *v20; // r2
  int v21; // r1
  unsigned int v22; // r5
  unsigned __int16 *v23; // r4
  unsigned int v24; // r8
  __int64 v25; // kr08_8
  int *v26; // r2
  int v27; // r1
  int v28; // r3
  int *v29; // r2
  int v30; // r1
  unsigned __int16 *v31; // [sp+8h] [bp-28h]

  v7 = a2;
  v8 = 0;
  v10 = result;
  if ( a6 )
  {
    if ( a6 != 1 )
      return sub_524678();
    v17 = (unsigned __int16 *)(result + 44 * a3);
    v31 = v17;
    v18 = *(_QWORD *)(v17 + 14);
    v13 = a5;
    v19 = a5 & ~HIDWORD(v18) | v18;
    *((_DWORD *)v17 + 7) = v19;
    if ( (_DWORD)v18 == v19 )
    {
      v8 = 1;
    }
    else
    {
      v20 = (int *)*((_DWORD *)v17 + 10);
      v21 = 1;
      result = ~(_DWORD)v18 & ~HIDWORD(v18) & a5;
      if ( v20 )
      {
        while ( v21 )
        {
          if ( (v21 & result) != 0 && !*v20 )
            *v20 = a4 | 0x10000;
          ++v20;
          v21 *= 2;
        }
      }
    }
  }
  else
  {
    v11 = (unsigned __int16 *)(result + 44 * a3);
    v31 = v11;
    v12 = *((_DWORD *)v11 + 6);
    v13 = a5;
    v14 = v12 & ~a5;
    *((_DWORD *)v11 + 6) = v14;
    if ( v12 == v14 )
      return result;
    result = v12 & a5;
    v15 = (int *)*((_DWORD *)v11 + 10);
    v16 = 1;
    if ( v15 )
    {
      while ( v16 )
      {
        if ( (v16 & result) != 0 && !*v15 )
          *v15 = a4 | 0x10000;
        ++v15;
        v16 *= 2;
      }
    }
  }
  if ( v7 != 1 )
  {
    if ( !v8 )
      result = AuthzBasepUpdateParentTypeList(v10, v7, a3, a4, a6);
    v22 = a3 + 1;
    if ( a3 + 1 < v7 )
    {
      v23 = (unsigned __int16 *)(v10 + 44 * v22);
      v24 = a2;
      do
      {
        if ( *v23 <= (unsigned int)*v31 )
          break;
        if ( a6 )
        {
          v25 = *(_QWORD *)(v23 + 14);
          result = ~(_DWORD)v25 & ~HIDWORD(v25) & v13;
          *((_DWORD *)v23 + 7) = v13 & ~HIDWORD(v25) | v25;
          if ( result )
          {
            v26 = (int *)*((_DWORD *)v23 + 10);
            v27 = 1;
            if ( v26 )
            {
              while ( v27 )
              {
                if ( (v27 & result) != 0 && !*v26 )
                  *v26 = a4 | 0x10000;
                ++v26;
                v27 *= 2;
              }
            }
          }
        }
        else
        {
          v28 = *((_DWORD *)v23 + 6);
          result = v28 & v13;
          *((_DWORD *)v23 + 6) = v28 & ~v13;
          if ( (v28 & v13) != 0 )
          {
            v29 = (int *)*((_DWORD *)v23 + 10);
            v30 = 1;
            if ( v29 )
            {
              while ( v30 )
              {
                if ( (v30 & result) != 0 && !*v29 )
                  *v29 = a4 | 0x10000;
                ++v29;
                v30 *= 2;
              }
              v24 = a2;
            }
          }
        }
        ++v22;
        v23 += 22;
      }
      while ( v22 < v24 );
    }
  }
  return result;
}
