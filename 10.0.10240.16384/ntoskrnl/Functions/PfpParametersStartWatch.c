// PfpParametersStartWatch 
 
int __fastcall PfpParametersStartWatch(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 4) )
    result = ZwNotifyChangeKey();
  else
    result = -1073741816;
  return result;
}
