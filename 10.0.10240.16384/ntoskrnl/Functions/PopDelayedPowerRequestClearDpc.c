// PopDelayedPowerRequestClearDpc 
 
int __fastcall PopDelayedPowerRequestClearDpc(int a1, int a2, int a3)
{
  return PoClearPowerRequestInternal(*(_DWORD *)(a2 + 80), *(_DWORD *)(a2 + 84), a3, a2);
}
