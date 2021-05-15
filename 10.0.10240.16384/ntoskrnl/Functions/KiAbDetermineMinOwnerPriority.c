// KiAbDetermineMinOwnerPriority 
 
int __fastcall KiAbDetermineMinOwnerPriority(__int64 a1)
{
  char v1; // r3
  int v2; // r3
  char v3; // r3

  if ( *(_WORD *)(a1 + 46) )
    v1 = 2;
  else
    v1 = 0;
  *(_BYTE *)(HIDWORD(a1) + 1) = v1;
  v2 = *(_DWORD *)(a1 + 28);
  if ( v2 )
    v3 = *(_BYTE *)(v2 + 24);
  else
    v3 = 15;
  *(_BYTE *)HIDWORD(a1) = v3;
  if ( (*(_BYTE *)(a1 + 13) & 1) == 0 )
  {
    a1 = KiAbOwnerComputeCpuPriorityKey(a1);
    if ( (int)a1 < (char)*(_BYTE *)HIDWORD(a1) )
      *(_BYTE *)HIDWORD(a1) = a1;
  }
  return a1;
}
