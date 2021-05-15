// HvpReleaseCellPaged 
 
_DWORD *__fastcall HvpReleaseCellPaged(int a1, int *a2)
{
  int v3; // r7
  unsigned int v4; // lr
  unsigned int v5; // r1
  int v6; // r1

  v3 = *a2;
  v4 = *a2 & 0xFFFFFFFE;
  v5 = a1 + 412 * (v4 >> 31);
  if ( v4 + (v4 >> 31 << 31) >= *(_DWORD *)(v5 + 952)
    || (v6 = *(_DWORD *)(*(_DWORD *)(v5 + 956) + 4 * ((v4 >> 21) & 0x3FF)) + 20 * ((v4 >> 12) & 0x1FF)) == 0 )
  {
    sub_7FF30C();
  }
  if ( (v3 & 1) != 0 )
    HvpMapEntryReleaseBinAddress(a1, v6);
  return HvpGetCellContextReinitialize(a2);
}
