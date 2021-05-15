// MiLocateSessionProtosInSubsection 
 
_DWORD *__fastcall MiLocateSessionProtosInSubsection(int a1, int a2)
{
  _DWORD *v2; // r4
  int v4; // r0

  v2 = *(_DWORD **)(a1 + 12);
  if ( !v2 )
    return 0;
  do
  {
    v4 = MiPerSessionProtosCompare(a2, v2);
    if ( v4 >= 0 )
    {
      if ( v4 <= 0 )
        break;
      v2 = (_DWORD *)v2[1];
    }
    else
    {
      v2 = (_DWORD *)*v2;
    }
  }
  while ( v2 );
  if ( !v2 )
    return 0;
  return v2;
}
