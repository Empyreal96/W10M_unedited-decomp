// CcCancelMmWaitForUninitializeCacheMap 
 
int __fastcall CcCancelMmWaitForUninitializeCacheMap(int result)
{
  unsigned int *v1; // r4
  int v2; // r5
  unsigned int v3; // r3

  v1 = (unsigned int *)(result + 176);
  v2 = result;
  while ( *v1 )
  {
    v3 = *v1;
    if ( (*v1 & 1) != 0 )
    {
      *v1 = *(_DWORD *)(v3 & 0xFFFFFFFE);
      result = KeSetEvent((v3 & 0xFFFFFFFE) + 4, 0, 0);
      ++CcDbgNumberOfAbortedTeardowns;
    }
    else
    {
      v1 = (unsigned int *)*v1;
    }
  }
  *(_DWORD *)(v2 + 96) &= 0xFFFEFFFF;
  return result;
}
