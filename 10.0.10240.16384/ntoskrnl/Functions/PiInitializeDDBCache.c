// PiInitializeDDBCache 
 
int PiInitializeDDBCache()
{
  RtlInitializeGenericTableAvl(
    (int)&PiDDBCacheTable,
    (unsigned int)PiCompareDDBCacheEntries,
    (unsigned int)PnpAllocateGenericTableEntry,
    (int)CMFFreeFn,
    0);
  PiDDBCacheList = &PiDDBCacheList;
  off_920A74 = &PiDDBCacheList;
  return 0;
}
