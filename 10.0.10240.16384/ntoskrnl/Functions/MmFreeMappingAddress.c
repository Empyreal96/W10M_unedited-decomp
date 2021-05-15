// MmFreeMappingAddress 
 
int __fastcall MmFreeMappingAddress(unsigned int a1, int a2)
{
  unsigned int v3; // r0
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r0

  v3 = MiValidateReservedMapping(a1, a2);
  v4 = (a1 >> 10) & 0x3FFFFC;
  v5 = (_DWORD *)(v4 - 0x40000000);
  v6 = v3 - 2;
  v7 = v4 - 1073741832;
  v8 = v4 - 0x40000000 + 4 * (v3 - 2);
  while ( (unsigned int)v5 < v8 )
  {
    if ( *v5++ )
      sub_817164();
  }
  if ( (dword_681258 & 1) != 0 )
    MiRemovePteTracker(0, a1, v6);
  return MiReleasePtes(&dword_634D58, v7, v6 + 2);
}
