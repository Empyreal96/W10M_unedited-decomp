// ExBurnMemory 
 
int __fastcall ExBurnMemory(int a1, unsigned int a2, int a3)
{
  _DWORD *v3; // r7
  _DWORD *v4; // r0
  unsigned int v5; // r4
  int v6; // r3
  unsigned int v7; // r5

  v3 = (_DWORD *)(a1 + 24);
  v4 = *(_DWORD **)(a1 + 28);
  v5 = a2;
  do
  {
    v6 = v4[2];
    if ( v6 == 5 || v6 == 2 )
    {
      v7 = v4[4];
      if ( v7 )
      {
        if ( v7 > v5 )
          return sub_96E6B0();
        v4[2] = a3;
        v5 -= v7;
        if ( !v5 )
          break;
      }
    }
    v4 = (_DWORD *)v4[1];
  }
  while ( v4 != v3 );
  return a2 - v5;
}
