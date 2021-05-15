// MiBadShareCount 
 
void __fastcall __noreturn MiBadShareCount(int a1)
{
  KeBugCheckEx(78, 153, (a1 - MmPfnDatabase) / 24, *(_BYTE *)(a1 + 18) & 7, *(_DWORD *)(a1 + 12) & 0x3FFFFFFF);
}
