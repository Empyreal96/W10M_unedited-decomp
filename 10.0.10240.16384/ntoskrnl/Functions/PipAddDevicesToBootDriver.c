// PipAddDevicesToBootDriver 
 
int __fastcall PipAddDevicesToBootDriver(int a1, int a2, int a3)
{
  return PipApplyFunctionToServiceInstances(a1, *(_DWORD *)(a1 + 24) + 12, a3, *(_DWORD *)(a1 + 24), a1, a1);
}
