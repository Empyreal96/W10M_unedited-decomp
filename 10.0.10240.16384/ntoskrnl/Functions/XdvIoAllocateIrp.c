// XdvIoAllocateIrp 
 
int __fastcall XdvIoAllocateIrp(int a1, char a2, int a3, int a4, int (__fastcall *a5)(int, _DWORD))
{
  return a5(a1, a2);
}
