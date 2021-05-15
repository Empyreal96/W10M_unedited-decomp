// MiRemoveWsle 
 
unsigned int __fastcall MiRemoveWsle(unsigned int a1, int a2)
{
  _DWORD *v3; // r5
  int v5; // r4
  unsigned int result; // r0

  v3 = *(_DWORD **)(a2 + 92);
  if ( a1 > v3[4] )
    sub_538AF4();
  v5 = *(_DWORD *)(v3[9] * a1 + v3[63]);
  if ( (v5 & 1) == 0 )
    KeBugCheckEx(26, 20496, v3);
  result = v5 & 0xFFFFF000;
  if ( (int *)a2 == &dword_634F00 )
  {
    if ( PsNtosImageBase
      && (result >= PsNtosImageBase && result < PsNtosImageEnd || result >= PsHalImageBase && result < PsHalImageEnd) )
    {
      --dword_632F50;
    }
    else if ( result >= dword_63389C
           && *((_BYTE *)&MiState[2423]
              + ((int)(((result >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
    {
      --dword_632F54;
    }
  }
  if ( (v5 & 8) == 0 && (v5 & 4) != 0 )
    result = MiUpdateWsleHash(result, a1, a2, 1);
  if ( (dword_682604 & 0x8000000) != 0 )
    result = MiLogRemoveWsleEvent(v5, *(_BYTE *)(a2 + 112) & 7);
  *(_DWORD *)(v3[9] * a1 + v3[63]) = v5 & 0xFFFFFFFE;
  return result;
}
