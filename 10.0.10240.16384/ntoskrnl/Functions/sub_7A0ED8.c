// sub_7A0ED8 
 
int __fastcall sub_7A0ED8(int a1, int a2, _BYTE *a3, unsigned int a4, unsigned int *a5)
{
  int v6; // r3
  unsigned int v8; // r5
  unsigned int v10; // lr
  unsigned __int16 *v11; // r4
  _BYTE *v12; // r7
  char *v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r1
  char *v16; // r2
  unsigned int v17; // r3
  unsigned int v18; // r3
  int result; // r0

  v6 = a2;
  v8 = 0;
  if ( a3 )
  {
    memset(a3, 0, 8 * a4);
    v6 = a2;
  }
  v10 = *(_DWORD *)(a1 + 4) + 20;
  v11 = (unsigned __int16 *)(a1 + 20);
  if ( a1 + 20 == v10 + a1 )
    v11 = 0;
  if ( v11 )
  {
    v12 = a3;
    while ( 1 )
    {
      v13 = (char *)v11 - a1;
      if ( v6 == 1 )
      {
        if ( (unsigned int)(v13 + 20) > v10 )
          return -1073741762;
        v14 = *v11;
        if ( (unsigned int)&v13[v14] > v10 )
          return -1073741762;
        v15 = v11[1];
        if ( v15 > v14 )
          return -1073741762;
        v16 = (char *)v11 + v14;
        if ( v16 < (char *)v11 )
          return -1073741762;
        v17 = (unsigned int)v11 + v15 + 16;
        if ( v17 < (unsigned int)(v11 + 8) )
          return -1073741762;
        if ( v17 > (unsigned int)v16 )
          return -1073741762;
        v18 = (unsigned int)v11 + v11[3] + v15 + 16;
        if ( v18 < (unsigned int)(v11 + 8) || v18 > (unsigned int)v16 )
          return -1073741762;
        if ( *((_DWORD *)v11 + 2) )
          return sub_8114EC();
      }
      if ( a3 && v8 < a4 )
      {
        *v12 = 2;
        *((_DWORD *)v12 + 1) = v11;
      }
      ++v8;
      v12 += 8;
      v11 = (unsigned __int16 *)((char *)v11 + *v11);
      if ( v11 == (unsigned __int16 *)(v10 + a1) )
        v11 = 0;
      if ( !v11 )
        break;
      v6 = a2;
    }
  }
  if ( a5 )
    *a5 = v8;
  if ( v8 > a4 )
    result = -1073741789;
  else
    result = 0;
  return result;
}
