// MiStoreWriteModifiedCompleteApc 
 
int __fastcall MiStoreWriteModifiedCompleteApc(int a1, int a2, int a3, _DWORD **a4)
{
  return MiWriteComplete(*a4, *a4 + 2, 0);
}
