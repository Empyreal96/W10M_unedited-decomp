// IoQueueWorkItem 
 
int __fastcall IoQueueWorkItem(int a1, int a2, int a3, int a4)
{
  int v5; // r0

  *(_DWORD *)(a1 + 32) = 0;
  v5 = IopQueueWorkItemProlog(a1, a2, a4);
  return ExQueueWorkItem(v5, a3);
}
