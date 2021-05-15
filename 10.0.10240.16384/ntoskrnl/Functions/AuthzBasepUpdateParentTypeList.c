// AuthzBasepUpdateParentTypeList 
 
int __fastcall AuthzBasepUpdateParentTypeList(int result, unsigned int a2, int a3, int a4, int a5)
{
  unsigned int v6; // r2
  int v8; // r10
  unsigned __int16 *v9; // r4
  int v10; // r6
  int v11; // r5
  int v12; // r7
  int v13; // lr
  unsigned int v14; // r4
  _DWORD *v15; // r2
  unsigned int v16; // r3
  _DWORD *v17; // r2
  int v18; // r1
  int v19; // r3
  int *v20; // r2
  int v21; // r1
  int v22; // r3
  int *v23; // r2
  int v24; // r1
  int v25; // r0
  int *v26; // r2
  int v27; // r1
  int v29; // [sp+4h] [bp-24h]

  v6 = a2;
  v29 = result;
  v8 = a5;
  while ( 1 )
  {
    v9 = (unsigned __int16 *)(result + 44 * a3);
    v10 = 0;
    v11 = -1;
    a3 = *((_DWORD *)v9 + 5);
    v12 = 0;
    if ( a3 == -1 )
      break;
    v13 = *v9;
    v14 = a3 + 1;
    if ( a3 + 1 < v6 )
    {
      v15 = (_DWORD *)(result + 44 * v14);
      do
      {
        v16 = *(unsigned __int16 *)v15;
        if ( v16 <= *(unsigned __int16 *)(44 * a3 + result) )
          break;
        if ( v16 == v13 )
        {
          v10 |= v15[6];
          v11 &= v15[7];
          v12 |= v15[8];
        }
        ++v14;
        v15 += 11;
      }
      while ( v14 < a2 );
      v8 = a5;
    }
    v17 = (_DWORD *)(result + 44 * a3);
    v18 = v17[6];
    if ( v10 == v18 && v11 == v17[7] && v12 == v17[8] )
      break;
    if ( v8 )
    {
      if ( v8 == 1 )
      {
        v22 = v17[7];
        v17[7] = v11;
        if ( (v11 & ~v22) != 0 )
        {
          v23 = (int *)v17[10];
          v24 = 1;
          if ( v23 )
          {
            while ( v24 )
            {
              if ( (v24 & v11 & ~v22) != 0 && !*v23 )
                *v23 = a4 | 0x10000;
              ++v23;
              v24 *= 2;
            }
          }
        }
      }
      else
      {
        if ( v8 != 2 )
          return result;
        v19 = v17[8];
        v17[8] = v12;
        if ( (v12 & ~v19) != 0 )
        {
          v20 = (int *)v17[10];
          v21 = 1;
          if ( v20 )
          {
            while ( v21 )
            {
              if ( (v21 & v12 & ~v19) != 0 && !*v20 )
                *v20 = a4 | 0x20000;
              ++v20;
              v21 *= 2;
            }
          }
        }
      }
    }
    else
    {
      v25 = v18 & ~v10;
      v17[6] = v10;
      if ( v25 )
      {
        v26 = (int *)v17[10];
        v27 = 1;
        if ( v26 )
        {
          while ( v27 )
          {
            if ( (v27 & v25) != 0 && !*v26 )
              *v26 = a4 | 0x10000;
            ++v26;
            v27 *= 2;
          }
          v8 = a5;
        }
      }
    }
    v6 = a2;
    result = v29;
  }
  return result;
}
