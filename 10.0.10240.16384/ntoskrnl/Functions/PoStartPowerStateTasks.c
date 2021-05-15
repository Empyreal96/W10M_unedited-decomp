// PoStartPowerStateTasks 
 
int __fastcall PoStartPowerStateTasks(int a1)
{
  *(_DWORD *)(a1 + 16) = 1;
  return PopDispatchStateCallout(a1, 0);
}
