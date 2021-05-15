// NtUnloadDriver 
 
int __fastcall NtUnloadDriver(int *a1)
{
  return IopUnloadDriver(a1, 0);
}
