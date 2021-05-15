// MiCheckForConflictingVad 
 
_DWORD *__fastcall MiCheckForConflictingVad(int a1, unsigned int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r4
  int v5; // r0
  unsigned int v7; // [sp+0h] [bp-10h] BYREF
  unsigned int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  v4 = *(_DWORD **)(a1 + 636);
  v7 = a2 >> 12;
  v8 = a3 >> 12;
  if ( !v4 )
    return 0;
  do
  {
    v5 = MiVadCompareVpnRange(&v7, v4);
    if ( v5 < 0 )
    {
      v4 = (_DWORD *)*v4;
    }
    else
    {
      if ( v5 <= 0 )
        break;
      v4 = (_DWORD *)v4[1];
    }
  }
  while ( v4 );
  if ( !v4 )
    return 0;
  return v4;
}
