// MmQueryProcessWorkingSetSwapPages 
 
int __fastcall MmQueryProcessWorkingSetSwapPages(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 612) <= 2u )
    result = -1073741275;
  else
    result = sub_515C60();
  return result;
}
