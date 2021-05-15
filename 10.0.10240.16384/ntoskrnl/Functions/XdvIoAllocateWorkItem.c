// XdvIoAllocateWorkItem 
 
int __fastcall XdvIoAllocateWorkItem(int a1, int a2, int (*a3)(void))
{
  return a3();
}
