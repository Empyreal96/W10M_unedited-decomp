// DrvDbGetCompositeMappedPropertyKeys 
 
int __fastcall DrvDbGetCompositeMappedPropertyKeys(int a1, _DWORD **a2, unsigned int a3, _DWORD *a4, unsigned int a5, unsigned int *a6)
{
  int result; // r0
  unsigned int v7; // r6
  unsigned int v8; // r8
  _DWORD *v9; // r7
  unsigned int v12; // r10
  _DWORD *v13; // r4
  int v14; // r1
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r2
  _DWORD *v18; // [sp+0h] [bp-20h]

  result = 0;
  v7 = 0;
  v8 = 0;
  v9 = a4;
  if ( a3 )
  {
    v18 = a4;
    v12 = a5;
    while ( 1 )
    {
      if ( v9 )
      {
        if ( v8 < v12 )
        {
          v13 = *a2;
          ++v8;
          v14 = (*a2)[1];
          v15 = (*a2)[2];
          v16 = (*a2)[3];
          *v18 = **a2;
          v18[1] = v14;
          v18[2] = v15;
          v18[3] = v16;
          v18[4] = v13[4];
          v18 += 5;
          v12 = a5;
        }
      }
      v17 = *a6 + 1;
      if ( v17 < *a6 )
        break;
      ++v7;
      result = 0;
      *a6 = v17;
      ++a2;
      if ( v7 >= a3 )
        return result;
    }
    *a6 = -1;
    result = -1073741675;
    *a6 = 0;
  }
  return result;
}
