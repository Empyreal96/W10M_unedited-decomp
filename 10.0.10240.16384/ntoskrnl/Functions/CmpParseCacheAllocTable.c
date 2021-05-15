// CmpParseCacheAllocTable 
 
int CmpParseCacheAllocTable()
{
  int v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = -1073741670;
  CmpParseCacheTable = 0;
  v1 = ExAllocatePoolWithTag(1, 132, 1951419715);
  v2 = v1;
  if ( v1 )
  {
    *(_DWORD *)v1 = 1951419715;
    memset((_BYTE *)(v1 + 4), 0, 128);
    CmpParseCacheTable = v2;
    v0 = 0;
  }
  return v0;
}
