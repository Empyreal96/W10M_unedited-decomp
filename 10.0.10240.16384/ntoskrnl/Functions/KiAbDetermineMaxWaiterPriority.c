// KiAbDetermineMaxWaiterPriority 
 
int __fastcall KiAbDetermineMaxWaiterPriority(__int64 a1)
{
  int v1; // r3

  if ( *(_WORD *)(a1 + 46) )
    *(_BYTE *)(HIDWORD(a1) + 1) = 2;
  else
    *(_BYTE *)(HIDWORD(a1) + 1) = 0;
  v1 = *(_DWORD *)(a1 + 36);
  if ( v1 )
    *(_BYTE *)HIDWORD(a1) = *(_BYTE *)(v1 + 24);
  else
    *(_BYTE *)HIDWORD(a1) = 0;
  if ( (*(_BYTE *)(a1 + 13) & 1) != 0 )
  {
    a1 = KiAbWaiterComputeCpuPriorityKey();
    if ( (int)a1 > (char)*(_BYTE *)HIDWORD(a1) )
      *(_BYTE *)HIDWORD(a1) = a1;
  }
  return a1;
}
