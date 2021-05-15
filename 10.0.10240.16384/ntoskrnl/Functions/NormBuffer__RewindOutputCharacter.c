// NormBuffer__RewindOutputCharacter 
 
int __fastcall NormBuffer__RewindOutputCharacter(int result)
{
  unsigned __int16 *v1; // r2
  unsigned int v2; // r1

  v1 = (unsigned __int16 *)(*(_DWORD *)(result + 20) - 2);
  v2 = *v1;
  *(_DWORD *)(result + 20) = v1;
  if ( v2 > 0xDC00 && v2 < 0xDFFF )
    *(_DWORD *)(result + 20) = v1 - 1;
  *(_DWORD *)(result + 36) = *(_DWORD *)(result + 12) - 2;
  *(_DWORD *)(result + 32) = 0;
  *(_BYTE *)(result + 41) = 0;
  *(_BYTE *)(result + 40) = 0;
  return result;
}
