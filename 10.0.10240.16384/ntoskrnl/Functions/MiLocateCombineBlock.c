// MiLocateCombineBlock 
 
_DWORD *__fastcall MiLocateCombineBlock(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r4
  int v7; // r0
  _DWORD v8[12]; // [sp+0h] [bp-30h] BYREF

  v8[4] = a3;
  v8[5] = a4;
  v8[7] = a5;
  v5 = *(_DWORD **)(a1 + 8 * (a3 & 0xF) + 48);
  if ( !v5 )
    return 0;
  do
  {
    v7 = MiCombineCompare(v8, v5);
    if ( v7 < 0 )
    {
      v5 = (_DWORD *)*v5;
    }
    else
    {
      if ( v7 <= 0 )
        break;
      v5 = (_DWORD *)v5[1];
    }
  }
  while ( v5 );
  if ( !v5 )
    return 0;
  return v5;
}
