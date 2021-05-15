// IoAllocateIrp 
 
int __fastcall IoAllocateIrp(char a1, int a2)
{
  return ((int (__fastcall *)(_DWORD, _DWORD, int))pIoAllocateIrp)(0, a1, a2);
}
