// PipSortDevicesByOrdinal 
 
int __fastcall PipSortDevicesByOrdinal(int a1, int a2)
{
  return *(_DWORD *)(a1 + 8) - *(_DWORD *)(a2 + 8);
}
