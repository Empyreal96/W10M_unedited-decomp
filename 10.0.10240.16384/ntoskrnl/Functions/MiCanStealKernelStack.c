// MiCanStealKernelStack 
 
BOOL __fastcall MiCanStealKernelStack(int a1, int a2)
{
  return MI_IS_PFN((a1 - MmPfnDatabase) / 24)
      && (*(_BYTE *)(a1 + 23) & 7) == 2
      && ((MiFlags & 0x800) == 0 || *(_DWORD *)a1 != -5 && (*(_DWORD *)a1 & 1) != 0)
      && (*(_BYTE *)(a1 + 18) & 7) == 6
      && *(unsigned __int16 *)(a1 + 16) == a2;
}
