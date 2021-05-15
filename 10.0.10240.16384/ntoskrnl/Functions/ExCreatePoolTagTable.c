// ExCreatePoolTagTable 
 
int __fastcall ExCreatePoolTagTable(int a1, int a2)
{
  _BYTE *v3; // r0
  int v4; // r4

  if ( (unsigned int)PoolTrackTableSize >= 0x9249248 )
    return 0;
  v3 = (_BYTE *)MmAllocateIndependentPages(28 * (PoolTrackTableSize + 1), a2);
  v4 = (int)v3;
  if ( v3 )
  {
    memset(v3, 0, 28 * PoolTrackTableSize);
    ExPoolTagTables[a1] = v4;
  }
  return v4;
}
