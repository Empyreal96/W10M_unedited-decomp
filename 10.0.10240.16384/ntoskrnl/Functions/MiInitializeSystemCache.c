// MiInitializeSystemCache 
 
BOOL MiInitializeSystemCache()
{
  InitializeListHeadPte(&dword_6342C4);
  dword_6342D0 = 0;
  byte_634E70 = byte_634E70 & 0xF8 | 2;
  return MiInitializeSystemWorkingSetList(dword_634E00, (unsigned int)(MiLowHalVa - dword_63389C) >> 12) != 0;
}
