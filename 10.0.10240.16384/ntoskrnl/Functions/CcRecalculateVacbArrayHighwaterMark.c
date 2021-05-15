// CcRecalculateVacbArrayHighwaterMark 
 
int __fastcall CcRecalculateVacbArrayHighwaterMark(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1

  v1 = *(_DWORD *)(result + 8);
  v2 = v1 + 1;
  if ( v1 != -1 )
  {
    v3 = result + 16 + 24 * v2;
    do
    {
      if ( *(_DWORD *)(v3 - 20) )
        break;
      *(_DWORD *)(result + 8) = --v2;
      v3 -= 24;
    }
    while ( v2 );
  }
  return result;
}
