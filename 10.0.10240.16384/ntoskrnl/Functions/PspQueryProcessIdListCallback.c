// PspQueryProcessIdListCallback 
 
int __fastcall PspQueryProcessIdListCallback(int a1, int a2)
{
  if ( (*(_DWORD *)(a1 + 188) & 1) == 0 )
  {
    if ( *(_DWORD *)(a2 + 4) < 4u )
      return -2147483643;
    **(_DWORD **)a2 = *(_DWORD *)(a1 + 176);
    ++*(_DWORD *)(a2 + 8);
    *(_DWORD *)a2 += 4;
    *(_DWORD *)(a2 + 4) -= 4;
    --*(_DWORD *)(a2 + 12);
  }
  return 0;
}
