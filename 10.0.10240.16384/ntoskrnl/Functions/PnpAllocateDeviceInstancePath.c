// PnpAllocateDeviceInstancePath 
 
int __fastcall PnpAllocateDeviceInstancePath(int a1, int a2)
{
  int v3; // r0
  int result; // r0

  *(_WORD *)(a1 + 20) = 0;
  *(_WORD *)(a1 + 22) = a2;
  v3 = ExAllocatePoolWithTag(768, a2, 1232105040);
  *(_DWORD *)(a1 + 24) = v3;
  if ( v3 )
    result = 0;
  else
    result = -1073741670;
  return result;
}
