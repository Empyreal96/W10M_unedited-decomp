// PcwCloseInstance 
 
_DWORD *__fastcall PcwCloseInstance(int a1)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExGetExtensionTable(ExpPcwExtensionHost);
  if ( result )
  {
    ((void (__fastcall *)(int))result[3])(a1);
    result = ExReleaseExtensionTable(ExpPcwExtensionHost);
  }
  return result;
}
