// KeSetSystemAffinityThread 
 
int __fastcall KeSetSystemAffinityThread(int a1)
{
  return KeSetSystemAffinityThreadEx(a1);
}
