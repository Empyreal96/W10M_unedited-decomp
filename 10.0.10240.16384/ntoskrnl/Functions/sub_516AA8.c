// sub_516AA8 
 
void sub_516AA8()
{
  int v0; // r4
  unsigned int v1; // r1
  unsigned int v2; // r1

  MiRestoreTransitionPte(v0, 1);
  if ( (*(_DWORD *)(v0 + 20) & 0x8000000) != 0 )
  {
    do
      v1 = __ldrex((unsigned int *)&dword_634680);
    while ( __strex(v1 - 1, (unsigned int *)&dword_634680) );
  }
  else
  {
    do
      v2 = __ldrex(dword_640300);
    while ( __strex(v2 - 1, dword_640300) );
  }
  *(_DWORD *)(v0 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(v0 + 19) &= 0xDFu;
  *(_DWORD *)v0 = 0;
  *(_BYTE *)(v0 + 18) = *(_BYTE *)(v0 + 18) & 0xC0 | 5;
  *(_DWORD *)(v0 + 8) = 128;
  *(_DWORD *)(v0 + 12) |= 0x40000000u;
  MiInsertPageInFreeOrZeroedList((v0 - MmPfnDatabase) / 24, 2);
  JUMPOUT(0x436270);
}
