// sub_4FC120 
 
int __fastcall sub_4FC120(int result, int a2, int *a3)
{
  int v4; // r3
  int v5; // r3

  if ( (*(_DWORD *)(a2 + 12) & 0x40) != 0 && !*(_DWORD *)(a2 + 8)
    || ((v4 = *(_DWORD *)(a2 + 4) - 1, *(_DWORD *)(a2 + 4) = v4, v4 < 0) ? (result = flsbuf((unsigned __int8)result, a2)) : (**(_BYTE **)a2 = result, result = (unsigned __int8)result, ++*(_DWORD *)a2),
        v5 = -1,
        result != -1) )
  {
    v5 = *a3 + 1;
  }
  *a3 = v5;
  return result;
}
