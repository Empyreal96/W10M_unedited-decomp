// MmGetVirtualForPhysical 
 
int __fastcall MmGetVirtualForPhysical(__int64 a1)
{
  return (a1 & 0xFFF) + (*(_DWORD *)(MmPfnDatabase + 24 * (a1 >> 12) + 4) << 10);
}
