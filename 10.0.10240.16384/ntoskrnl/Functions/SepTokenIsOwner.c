// SepTokenIsOwner 
 
int __fastcall SepTokenIsOwner(int a1, int a2)
{
  int v3; // r3
  int v4; // r4
  int result; // r0

  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v3 = *(_DWORD *)(a2 + 4);
    if ( v3 )
      v4 = v3 + a2;
    else
      v4 = 0;
  }
  else
  {
    v4 = *(_DWORD *)(a2 + 4);
  }
  result = SepSidInTokenSidHash(a1 + 204, 0, v4, 0);
  if ( result )
  {
    if ( *(_DWORD *)(a1 + 128) )
      result = SepSidInToken(a1, 0, v4, 0, 1);
  }
  return result;
}
