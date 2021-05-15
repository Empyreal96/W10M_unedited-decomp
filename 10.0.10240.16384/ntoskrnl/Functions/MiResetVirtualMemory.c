// MiResetVirtualMemory 
 
int __fastcall MiResetVirtualMemory(int a1, int a2, int a3, int a4)
{
  int v6; // r2
  int result; // r0

  v6 = *(_DWORD *)(a3 + 28);
  if ( (v6 & 0x8000) == 0 )
  {
    if ( *(_DWORD *)(**(_DWORD **)(a3 + 44) + 32) )
      return -1073741245;
    if ( (v6 & 0x20) == 0 )
      return -1073741746;
  }
  if ( (v6 & 7) == 4 )
    return -1073741800;
  result = MiWalkVaRange(a1, a2, a3, a4 != 0x80000);
  if ( a4 == 0x80000 )
    result = 0;
  return result;
}
