// MiSplitBitmapPages 
 
int __fastcall MiSplitBitmapPages(int a1, unsigned int a2, int a3)
{
  int v5; // r4

  if ( a1 == 16 )
    a1 = 9;
  v5 = 32;
  if ( a1 == 9 || a1 == 5 )
  {
    v5 = 48;
  }
  else if ( a1 != 8 && a1 != 13 && (unsigned int)KeGetCurrentIrql(a1) <= 1 )
  {
    v5 = 33;
  }
  return MiMakeZeroedPageTables(
           ((a2 >> 10) & 0x3FFFFC) - 0x40000000,
           (((a2 + ((unsigned int)(a3 - 1) >> 3)) >> 10) & 0x3FFFFC) - 0x40000000,
           v5);
}
