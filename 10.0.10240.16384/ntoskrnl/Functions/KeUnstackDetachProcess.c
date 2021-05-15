// KeUnstackDetachProcess 
 
int __fastcall KeUnstackDetachProcess(int a1)
{
  return KiUnstackDetachProcess(a1, 0);
}
