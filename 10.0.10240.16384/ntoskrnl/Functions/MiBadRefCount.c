// MiBadRefCount 
 
void __fastcall __noreturn MiBadRefCount(int a1)
{
  KeBugCheckEx(78, 154, (a1 - MmPfnDatabase) / 24, *(_BYTE *)(a1 + 18) & 7, *(unsigned __int16 *)(a1 + 16));
}
