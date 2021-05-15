// KsepStringDuplicateUnicode 
 
int __fastcall KsepStringDuplicateUnicode(int a1, unsigned __int16 *a2)
{
  unsigned int v5; // r4
  int v6; // r0
  int v7; // r5

  if ( !a2 )
    return sub_7CD2E0();
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v5 = *a2 + 2;
  v6 = KsepPoolAllocatePaged(v5);
  v7 = v6;
  if ( !v6 )
    return -1073741801;
  memmove(v6, *((_DWORD *)a2 + 1), v5 - 2);
  *(_WORD *)(v7 + 2 * (v5 >> 1) - 2) = 0;
  *(_WORD *)a1 = v5 - 2;
  *(_DWORD *)(a1 + 4) = v7;
  *(_WORD *)(a1 + 2) = v5;
  return 0;
}
