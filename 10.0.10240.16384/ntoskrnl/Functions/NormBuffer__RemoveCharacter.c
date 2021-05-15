// NormBuffer__RemoveCharacter 
 
int __fastcall NormBuffer__RemoveCharacter(int result, _WORD *a2)
{
  int v2; // r2
  unsigned int v3; // r3

  v2 = *(_DWORD *)(result + 20) - 2;
  v3 = *(_DWORD *)(result + 36);
  *(_DWORD *)(result + 20) = v2;
  if ( v3 == v2 )
  {
    if ( (unsigned int)a2 >= v3 )
    {
      *(_DWORD *)(result + 36) = *(_DWORD *)(result + 12) - 2;
      *(_DWORD *)(result + 32) = 0;
      *(_BYTE *)(result + 41) = 0;
      *(_BYTE *)(result + 40) = 0;
    }
    else
    {
      *(_DWORD *)(result + 36) = v3 - 2;
    }
  }
  while ( a2 != (_WORD *)v2 )
  {
    *a2 = a2[1];
    ++a2;
  }
  return result;
}
