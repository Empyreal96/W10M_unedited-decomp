// MiMapNewPfns 
 
_BYTE *__fastcall MiMapNewPfns(int a1, int a2, char a3)
{
  MiMakeZeroedPageTables(
    (((unsigned int)(MmPfnDatabase + 24 * a1) >> 10) & 0x3FFFFC) - 0x40000000,
    (((unsigned int)(MmPfnDatabase + 24 * a2 - 1) >> 10) & 0x3FFFFC) - 0x40000000,
    41);
  return MiInitializeDynamicPfns(a1, a2 - a1, a3);
}
