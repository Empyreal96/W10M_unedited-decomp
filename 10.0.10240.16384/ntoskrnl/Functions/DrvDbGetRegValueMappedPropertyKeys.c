// DrvDbGetRegValueMappedPropertyKeys 
 
int __fastcall DrvDbGetRegValueMappedPropertyKeys(int a1, int a2, _DWORD **a3, unsigned int a4, _DWORD *a5, unsigned int a6, unsigned int *a7)
{
  int result; // r0
  unsigned int v8; // r7
  unsigned int v9; // r9
  unsigned int v12; // r4
  unsigned __int16 *v13; // r2
  _DWORD *v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  _DWORD *v19; // [sp+8h] [bp-28h]
  unsigned int v20; // [sp+Ch] [bp-24h] BYREF
  int v21; // [sp+10h] [bp-20h]

  result = 0;
  v8 = 0;
  v9 = 0;
  v21 = a2;
  if ( a4 )
  {
    v12 = a6;
    v19 = a5;
    while ( 1 )
    {
      v13 = (unsigned __int16 *)a3[2];
      v20 = 0;
      result = PnpCtxRegQueryValue((int)&v20, a2, v13, 0, 0, &v20);
      if ( result != -1073741772 )
      {
        if ( result && result != -1073741789 )
          return result;
        if ( a5 )
        {
          if ( v9 < v12 )
          {
            v14 = *a3;
            ++v9;
            v15 = (*a3)[1];
            v16 = (*a3)[2];
            v17 = (*a3)[3];
            *v19 = **a3;
            v19[1] = v15;
            v19[2] = v16;
            v19[3] = v17;
            v19[4] = v14[4];
            v19 += 5;
            v12 = a6;
          }
        }
        v18 = *a7 + 1;
        if ( v18 < *a7 )
        {
          *a7 = -1;
          result = -1073741675;
          *a7 = 0;
          return result;
        }
        *a7 = v18;
      }
      ++v8;
      result = 0;
      a3 += 6;
      if ( v8 >= a4 )
        return result;
      a2 = v21;
    }
  }
  return result;
}
