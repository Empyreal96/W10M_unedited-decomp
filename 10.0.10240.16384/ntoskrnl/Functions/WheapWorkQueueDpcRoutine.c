// WheapWorkQueueDpcRoutine 
 
int __fastcall WheapWorkQueueDpcRoutine(int a1, int a2)
{
  return ExQueueWorkItem((_DWORD *)(a2 + 48), 1);
}
