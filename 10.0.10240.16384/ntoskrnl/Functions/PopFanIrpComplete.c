// PopFanIrpComplete 
 
int __fastcall PopFanIrpComplete(int a1, int a2, int a3)
{
  ExQueueWorkItem((_DWORD *)(a3 + 44), 1);
  return -1073741802;
}
