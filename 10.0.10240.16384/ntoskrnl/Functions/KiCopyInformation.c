// KiCopyInformation 
 
int __fastcall KiCopyInformation(int a1, int a2)
{
  memmove(a1, a2, 0x50u);
  memset((_BYTE *)(a1 + 4 * (*(_DWORD *)(a1 + 16) + 5)), 0, -4 * (*(_DWORD *)(a1 + 16) + 5) + 80);
  return 1;
}
