// SepSecureBootFilterBootOptionDelete 
 
int __fastcall SepSecureBootFilterBootOptionDelete(int a1)
{
  int v1; // r1
  _WORD *v2; // r2

  v1 = 0;
  v2 = (_WORD *)(*(_DWORD *)(a1 + 8) + dword_64185C);
  if ( (*v2 & 0x1F) != 8 || v2[1] )
    v1 = -1069350910;
  return v1;
}
