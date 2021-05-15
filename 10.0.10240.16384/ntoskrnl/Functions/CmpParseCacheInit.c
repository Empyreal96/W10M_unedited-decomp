// CmpParseCacheInit 
 
int CmpParseCacheInit()
{
  CmpParseCacheLock = 0;
  return CmpParseCacheAllocTable();
}
