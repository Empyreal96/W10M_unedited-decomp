// IoAllocateController 
 
int __fastcall IoAllocateController(int a1, _DWORD *a2, int (__fastcall *a3)(_DWORD *, _DWORD, _DWORD, int), int a4)
{
  int result; // r0

  a2[17] = a3;
  a2[18] = a4;
  result = KeInsertDeviceQueue(a1 + 8, a2 + 13);
  if ( !result )
  {
    result = a3(a2, a2[5], 0, a4);
    if ( result == 2 )
      result = IoFreeController(a1);
  }
  return result;
}
