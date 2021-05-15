// PopSqmThermalCriticalShutdown 
 
int __fastcall PopSqmThermalCriticalShutdown(int a1)
{
  return PopSqmThermalCriticalEvent(a1, *(_DWORD *)(a1 + 188), 1);
}
