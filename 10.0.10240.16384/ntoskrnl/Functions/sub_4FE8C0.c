// sub_4FE8C0 
 
int __fastcall sub_4FE8C0(int result, int a2, int *a3)
{
  int v3; // r5
  int v4; // r3
  int v5; // r3

  v3 = *(_DWORD *)(a2 + 12);
  if ( ((v3 & 0x40) == 0 || *(_DWORD *)(a2 + 8))
    && ((v4 = *(_DWORD *)(a2 + 4) - 2, *(_DWORD *)(a2 + 4) = v4, v4 < 0) ? (*(_DWORD *)(a2 + 12) = v3 | 0x20,
                                                                            result = 0xFFFF) : (**(_WORD **)a2 = result,
                                                                                                *(_DWORD *)a2 += 2),
        result == 0xFFFF && (*(_DWORD *)(a2 + 12) & 0x20) != 0) )
  {
    v5 = -1;
  }
  else
  {
    v5 = *a3 + 1;
  }
  *a3 = v5;
  return result;
}
