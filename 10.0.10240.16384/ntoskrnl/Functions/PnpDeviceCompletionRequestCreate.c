// PnpDeviceCompletionRequestCreate 
 
int __fastcall PnpDeviceCompletionRequestCreate(int a1, int a2)
{
  int result; // r0

  result = ExAllocatePoolWithTag(512, 36, 829451856);
  if ( result )
  {
    *(_DWORD *)result = result;
    *(_DWORD *)(result + 4) = result;
    *(_DWORD *)(result + 32) = 1;
    *(_QWORD *)(result + 20) = 0xC00000E500000000ui64;
    *(_DWORD *)(result + 8) = a1;
    *(_DWORD *)(result + 12) = 0;
    *(_DWORD *)(result + 16) = a2;
    *(_DWORD *)(result + 28) = 0;
  }
  return result;
}
