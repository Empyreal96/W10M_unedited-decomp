// CmQueryRegistryQuotaInformation 
 
int __fastcall CmQueryRegistryQuotaInformation(_DWORD *a1)
{
  CmpUpdateGlobalQuotaAllowed();
  *a1 = CmpGlobalQuota;
  a1[1] = CmpGlobalQuotaUsed;
  a1[2] = CmpSizeOfPagedPoolInBytes;
  return 0;
}
