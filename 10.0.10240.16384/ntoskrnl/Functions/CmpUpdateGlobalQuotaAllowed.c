// CmpUpdateGlobalQuotaAllowed 
 
int CmpUpdateGlobalQuotaAllowed()
{
  int v0; // r3
  int result; // r0

  v0 = MmSizeOfPagedPoolInBytes;
  __dmb(0xBu);
  if ( !CmpQuotaExplicitlySet )
  {
    __dmb(0xBu);
    if ( v0 != CmpSizeOfPagedPoolInBytes )
      result = sub_805B30();
  }
  return result;
}
