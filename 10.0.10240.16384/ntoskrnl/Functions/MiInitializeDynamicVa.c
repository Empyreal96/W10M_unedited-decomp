// MiInitializeDynamicVa 
 
int MiInitializeDynamicVa()
{
  unsigned int v0; // r4
  _DWORD *v2; // r7

  dword_6342BC = 0;
  byte_6342AC = 0;
  algn_6342AD = 0;
  byte_6342AE = 4;
  unk_6342B0 = 0;
  unk_6342B8 = &dword_6342B4;
  dword_6342B4 = (int)&dword_6342B4;
  dword_635310 = -dword_63389C;
  dword_633888 = -dword_63389C;
  dword_633884 = ExGenRandom(1) & 0x3F;
  dword_633890 = 0x40000000;
  v0 = dword_63389C;
  if ( dword_63389C != 0x80000000 )
    return sub_96E384();
  v2 = (_DWORD *)((((unsigned int)dword_63389C >> 20) & 0xFFC) - 1070596096);
  if ( dword_63389C )
  {
    do
    {
      if ( *v2++ )
        MiInitializeSystemVaRange(v0, v0 + 0x400000, 3);
      v0 += 0x400000;
    }
    while ( v0 );
  }
  MiInitializeSystemVaRange(0xC0000000, dword_633894 + 1, 2);
  return MiInitializeSystemVaRange(MiLowHalVa, 0, 10);
}
