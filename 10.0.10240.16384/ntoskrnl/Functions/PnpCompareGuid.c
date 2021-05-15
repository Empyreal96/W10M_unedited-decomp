// PnpCompareGuid 
 
BOOL __fastcall PnpCompareGuid(unsigned __int8 *a1, int a2)
{
  return RtlCompareMemory(a1, a2, 16) == 16;
}
