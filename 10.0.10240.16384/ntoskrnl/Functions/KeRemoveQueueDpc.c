// KeRemoveQueueDpc 
 
int __fastcall KeRemoveQueueDpc(int a1)
{
  return KeRemoveQueueDpcEx(a1, 0);
}
