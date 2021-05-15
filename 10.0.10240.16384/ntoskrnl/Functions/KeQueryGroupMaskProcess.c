// KeQueryGroupMaskProcess 
 
int __fastcall KeQueryGroupMaskProcess(int a1)
{
  return (*(_DWORD *)(a1 + 100) >> 8) & 1;
}
