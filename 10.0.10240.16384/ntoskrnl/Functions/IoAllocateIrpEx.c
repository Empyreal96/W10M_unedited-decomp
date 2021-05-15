// IoAllocateIrpEx 
 
int __fastcall IoAllocateIrpEx(int a1, char a2, int a3)
{
  return ((int (__fastcall *)(int, _DWORD, int))pIoAllocateIrp)(a1, a2, a3);
}
