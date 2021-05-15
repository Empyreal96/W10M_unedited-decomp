// RaspLoadEmptyGlyph 
 
int __fastcall RaspLoadEmptyGlyph(_DWORD *a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)RaspAllocateMemory(62);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 62);
  *(_DWORD *)(v3 + 38) = v3 + 46;
  *(_DWORD *)(v3 + 42) = v3 + 54;
  *a1 = v3;
  return 0;
}
