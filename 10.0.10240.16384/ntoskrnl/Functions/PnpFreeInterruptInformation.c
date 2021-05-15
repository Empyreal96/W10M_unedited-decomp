// PnpFreeInterruptInformation 
 
int __fastcall PnpFreeInterruptInformation(int a1)
{
  int result; // r0

  result = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 48);
  if ( result )
    result = sub_7EE364();
  return result;
}
