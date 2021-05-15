// KeRemoveQueue 
 
int __fastcall KeRemoveQueue(int a1, char a2, int a3)
{
  KeRemoveQueueEx(a1, a2);
  return a3;
}
