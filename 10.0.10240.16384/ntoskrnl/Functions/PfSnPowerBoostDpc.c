// PfSnPowerBoostDpc 
 
__int64 __fastcall PfSnPowerBoostDpc(int a1, int a2)
{
  return (unsigned int)ExQueueWorkItem((_DWORD *)(a2 + 88), 0);
}
