// PnpCallAddDevice 
 
int __fastcall PnpCallAddDevice(int a1, int a2, int (__fastcall *a3)(int, int))
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 16) )
    result = sub_7CBCD8();
  else
    result = PpvUtilCallAddDevice(*(_DWORD *)(a1 + 16), a2, a3);
  return result;
}
