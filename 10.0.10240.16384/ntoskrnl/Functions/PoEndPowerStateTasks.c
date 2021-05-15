// PoEndPowerStateTasks 
 
int __fastcall PoEndPowerStateTasks(int a1)
{
  *(_DWORD *)(a1 + 16) = 8;
  return PopDispatchStateCallout(a1, 0);
}
