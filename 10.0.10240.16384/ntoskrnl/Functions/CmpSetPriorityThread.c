// CmpSetPriorityThread 
 
int __fastcall CmpSetPriorityThread(int a1, int a2)
{
  return KeSetPriorityThread(a1, a2);
}
