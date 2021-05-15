// MiInitializeColors 
 
int MiInitializeColors()
{
  unsigned int v0; // r2
  int result; // r0

  v0 = (unsigned int)dword_633818 >> 12;
  dword_633818 = (unsigned int)dword_633818 >> 12;
  if ( !dword_633818 )
    return sub_96B93C();
  if ( v0 > 0x100 )
  {
    v0 = 256;
    dword_633818 = 256;
  }
  else if ( ((v0 - 1) & v0) != 0 || v0 < 8 )
  {
    JUMPOUT(0x96B94C);
  }
  dword_633814 = v0 - 1;
  byte_6337FC = 31 - __clz(v0);
  byte_6337F5 = byte_6337FC;
  dword_6337E0 = (1 << byte_6337FC) - 1;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1030) = v0 - 1;
  return result;
}
