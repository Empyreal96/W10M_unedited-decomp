// MiUnloadApproved 
 
int __fastcall MiUnloadApproved(int a1)
{
  unsigned int v2; // r1
  int v4; // r2

  if ( *(_DWORD *)(a1 + 76) != 1 )
  {
    if ( *(_DWORD *)(a1 + 24) >= (unsigned int)dword_63389C
      && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(*(_DWORD *)(a1 + 24))) == 1
       || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v2)) == 11) )
    {
      return sub_7CE994();
    }
    v4 = *(unsigned __int16 *)(a1 + 56);
    if ( v4 == 1 )
      JUMPOUT(0x7CE9A8);
    *(_WORD *)(a1 + 56) = v4 - 1;
  }
  return 0;
}
