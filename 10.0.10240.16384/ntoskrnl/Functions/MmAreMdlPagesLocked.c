// MmAreMdlPagesLocked 
 
int __fastcall MmAreMdlPagesLocked(int a1)
{
  unsigned int *v1; // r8
  unsigned int v2; // r7
  unsigned int v3; // r4
  unsigned int v4; // t1
  int v5; // r4
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r5

  if ( (*(_WORD *)(a1 + 6) & 0x804) != 0 )
    return 1;
  v1 = (unsigned int *)(a1 + 28);
  v2 = (*(_DWORD *)(a1 + 20)
      + (((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFFu)
      + 4095) >> 12;
  while ( 1 )
  {
    v4 = *v1++;
    v3 = v4;
    if ( MI_IS_PFN(v4) )
      break;
LABEL_20:
    if ( !--v2 )
      return 1;
  }
  v5 = MmPfnDatabase + 24 * v3;
  if ( dword_634380 == 2 )
    v6 = 17;
  else
    v6 = MiLockPage(v5);
  v7 = *(unsigned __int16 *)(v5 + 16);
  if ( v7 > (*(_DWORD *)(v5 + 12) & 0x3FFFFFFFu)
    || (*(_DWORD *)(v5 + 20) & 0xFFFFF) == 1048573
    || (*(_DWORD *)(v5 + 20) & 0x7000000) == 0x1000000
    || v7 > 1
    || !*(_DWORD *)v5
    || (v8 = *(_DWORD *)(v5 + 4) << 10, (*(_BYTE *)(v5 + 18) & 7) == 6)
    && v8 >= dword_63389C
    && *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(*(_DWORD *)(v5 + 4) << 10)) == 5
    || v8 && v8 >= dword_63389C && *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v8)) == 13 )
  {
    if ( v6 != 17 )
      MiUnlockPage(v5, v6);
    goto LABEL_20;
  }
  if ( v6 != 17 )
    MiUnlockPage(v5, v6);
  return 0;
}
