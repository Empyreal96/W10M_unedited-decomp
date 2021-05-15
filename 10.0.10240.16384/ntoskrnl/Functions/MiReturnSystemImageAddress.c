// MiReturnSystemImageAddress 
 
int __fastcall MiReturnSystemImageAddress(unsigned int a1, unsigned int a2)
{
  BOOL v3; // r0

  v3 = a1 >= dword_63389C
    && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(a1)) == 1
     || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(a1)) == 11);
  return MiReleaseDriverPtes(v3, ((a1 >> 10) & 0x3FFFFC) - 0x40000000, a2 >> 12);
}
