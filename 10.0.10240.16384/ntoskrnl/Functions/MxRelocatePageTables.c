// MxRelocatePageTables 
 
void MxRelocatePageTables()
{
  int v0; // r7
  unsigned int v1; // r0
  char v2[32]; // [sp+8h] [bp-20h] BYREF

  MI_INITIALIZE_COLOR_BASE(0, 0, (int)v2);
  v0 = MmPfnDatabase;
  v1 = ((((((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000;
  if ( v1 < ((((((unsigned int)MmPfnDatabase >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000 )
  {
    MxMovePageTables(v1);
    v0 = MmPfnDatabase;
  }
  if ( ((((((unsigned int)(v0 + (MxPfnAllocation << 12)) >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC)
     - 0x40000000 < 0xC0300FFC )
    MxMovePageTables(((((((unsigned int)(v0 + (MxPfnAllocation << 12)) >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 1073741820);
  MxSwapPages(v2, -1069547548);
  MiIncrementPfn(MmPfnDatabase + 24 * (MEMORY[0xC03FFFE4] >> 12));
}
