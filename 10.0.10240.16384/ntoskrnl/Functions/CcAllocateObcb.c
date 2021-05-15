// CcAllocateObcb 
 
int __fastcall CcAllocateObcb(_DWORD *a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r5
  int result; // r0

  v6 = 4
     * (((unsigned int)(*a1 - *(_DWORD *)((a3 & 0xFFFFFFFE) + 8) - *(_DWORD *)((a3 & 0xFFFFFFFE) + 4) + a2 + 4095) >> 12)
      + 6);
  v7 = ExAllocatePoolWithTag(528, v6, 1649369923);
  memset((_BYTE *)v7, 0, v6);
  *(_WORD *)v7 = 762;
  *(_WORD *)(v7 + 2) = v6;
  *(_DWORD *)(v7 + 4) = a2;
  result = v7;
  *(_DWORD *)(v7 + 8) = *a1;
  *(_DWORD *)(v7 + 12) = a1[1];
  *(_DWORD *)(v7 + 16) = a3;
  return result;
}
