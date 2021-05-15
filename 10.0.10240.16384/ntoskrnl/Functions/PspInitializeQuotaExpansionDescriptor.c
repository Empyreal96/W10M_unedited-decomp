// PspInitializeQuotaExpansionDescriptor 
 
_DWORD *__fastcall PspInitializeQuotaExpansionDescriptor(_DWORD *result, int a2, int a3, int a4, int a5, unsigned __int8 a6)
{
  result[1] = a3;
  result[3] = MmRaisePoolQuota;
  result[4] = MmReturnPoolQuota;
  result[5] = result + 5;
  result[6] = result + 5;
  *result = a6 >= 2u;
  result[2] = 0;
  return result;
}
