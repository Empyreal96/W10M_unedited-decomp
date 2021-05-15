// PcwUnregister 
 
_DWORD *__fastcall PcwUnregister(int a1)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExGetExtensionTable(ExpPcwExtensionHost);
  if ( result )
  {
    ((void (__fastcall *)(int))result[1])(a1);
    result = ExReleaseExtensionTable(ExpPcwExtensionHost);
  }
  return result;
}
