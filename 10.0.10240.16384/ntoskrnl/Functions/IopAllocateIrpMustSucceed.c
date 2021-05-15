// IopAllocateIrpMustSucceed 
 
int __fastcall IopAllocateIrpMustSucceed(int a1, char a2)
{
  int result; // r0

  result = ((int (__fastcall *)(int, _DWORD, _DWORD))pIoAllocateIrp)(a1, a2, 0);
  if ( !result )
    return sub_52C76C();
  *(_BYTE *)(result + 39) |= 0x20u;
  return result;
}
