// AslpImageRvaToSection 
 
int __fastcall AslpImageRvaToSection(int a1, unsigned int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r4
  int v4; // r2
  unsigned int v5; // r0

  v2 = *(unsigned __int16 *)(a1 + 6);
  v3 = 0;
  v4 = a1 + *(unsigned __int16 *)(a1 + 20) + 24;
  if ( !*(_WORD *)(a1 + 6) )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v4 + 12);
    if ( a2 >= v5 && a2 < *(_DWORD *)(v4 + 16) + v5 )
      break;
    ++v3;
    v4 += 40;
    if ( v3 >= v2 )
      return 0;
  }
  return v4;
}
