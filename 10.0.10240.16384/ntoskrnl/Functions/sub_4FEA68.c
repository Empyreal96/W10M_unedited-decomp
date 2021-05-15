// sub_4FEA68 
 
int __fastcall sub_4FEA68(char a1, _DWORD *a2, int *a3, _DWORD *a4, _WORD **a5, int a6, int a7, int a8, _DWORD *a9)
{
  unsigned int v13; // r6
  _BYTE *v14; // r5
  unsigned int i; // r3
  unsigned int v16; // r2
  unsigned int v17; // r0
  char v19[64]; // [sp+28h] [bp-40h] BYREF

  v13 = 0;
  memset(v19, 0, 32);
  v14 = (_BYTE *)(*a2 + 1);
  *a2 = v14;
  if ( *v14 == 94 )
  {
    ++v14;
    a1 |= 8u;
  }
  if ( *v14 == 93 )
  {
    v13 = 93;
    ++v14;
    v19[11] = 32;
  }
  for ( i = (unsigned __int8)*v14; i != 93; i = (unsigned __int8)*v14 )
  {
    ++v14;
    if ( i == 45 && v13 && (v16 = (unsigned __int8)*v14, v16 != 93) )
    {
      ++v14;
      if ( v13 >= v16 )
      {
        v17 = v13;
        v13 = v16;
      }
      else
      {
        v17 = v16;
      }
      for ( ; v13 <= v17; v13 = (unsigned __int8)(v13 + 1) )
        v19[v13 >> 3] |= 1 << (v13 & 7);
      v13 = 0;
    }
    else
    {
      v13 = i;
      v19[i >> 3] |= 1 << (i & 7);
    }
  }
  if ( !*v14 )
    return -1;
  *a2 = v14;
  return sub_4FE914(a1, (int)v19, a3, a4, a5, a6, a7, a8, a9);
}
