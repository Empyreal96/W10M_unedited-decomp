// MiInitializeColorBase 
 
int __fastcall MiInitializeColorBase(unsigned int a1, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r0

  if ( a1 >= dword_63389C )
  {
    v2 = *((unsigned __int8 *)&MiState[2423]
         + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v2 == 11 || v2 == 1 )
      return MiInitializeColorBaseSession(a2);
  }
  if ( a1 > MmHighestUserAddress && (a1 < 0xC0000000 || a1 > dword_633894) )
  {
    v3 = a2;
    v4 = 0;
  }
  else
  {
    v3 = a2;
    v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492;
  }
  return MI_INITIALIZE_COLOR_BASE(v4, 0, v3);
}
