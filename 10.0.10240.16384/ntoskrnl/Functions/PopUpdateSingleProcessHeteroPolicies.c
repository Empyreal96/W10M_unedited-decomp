// PopUpdateSingleProcessHeteroPolicies 
 
int __fastcall PopUpdateSingleProcessHeteroPolicies(int a1)
{
  PsEnumProcessThreads(a1, (int (__fastcall *)(int, _DWORD *, int))PopUpdateSingleThreadHeteroPolicies, 0);
  return 0;
}
