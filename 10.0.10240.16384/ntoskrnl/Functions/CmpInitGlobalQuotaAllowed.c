// CmpInitGlobalQuotaAllowed 
 
void *CmpInitGlobalQuotaAllowed()
{
  void *result; // r0
  unsigned int v1; // r1
  unsigned int v2; // r3
  int v3; // r3

  CmpSizeOfPagedPoolInBytes = MmSizeOfPagedPoolInBytes;
  result = &CmRegistrySizeLimitType;
  if ( CmRegistrySizeLimitLength == 4 )
    return (void *)sub_96FBC4(&CmRegistrySizeLimitType, 8 * (MmSizeOfPagedPoolInBytes / 0xAu), CmRegistrySizeLimit);
  v1 = MmSizeOfPagedPoolInBytes / 3u;
  CmpGlobalQuota = MmSizeOfPagedPoolInBytes / 3u;
  if ( MmSizeOfPagedPoolInBytes / 3u > 0x7FFFFFFF )
  {
    v1 = 0x7FFFFFFF;
    CmpGlobalQuota = 0x7FFFFFFF;
  }
  if ( v1 < 0x1000000 )
  {
    v1 = 0x1000000;
    CmpGlobalQuota = 0x1000000;
  }
  CmpGlobalQuotaWarning = 95 * (v1 / 0x64);
  if ( CmSystemHiveLimitSize )
  {
    v3 = CmSystemHiveLimitSize << 20;
  }
  else
  {
    v2 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3592) >> 1;
    if ( v2 >= 0x19000 )
      v2 = 102400;
    v3 = v2 << 12;
  }
  CmSystemHiveLimitSize = v3;
  return result;
}
