// PopThermalIrpComplete 
 
int __fastcall PopThermalIrpComplete(int a1, int a2, int a3)
{
  ExQueueWorkItem((_DWORD *)(a3 + 304), 1);
  return -1073741802;
}
