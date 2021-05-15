// PfTFreeTraceDump 
 
int __fastcall PfTFreeTraceDump(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 20) == 1 )
    result = PfpRepurposeNameLoggingTrace();
  else
    result = ExFreePoolWithTag(a1);
  return result;
}
