// KsepStringDuplicate 
 
int __fastcall KsepStringDuplicate(int a1, unsigned __int16 *a2)
{
  unsigned int v5; // r0
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r5

  if ( !a2 )
    return sub_7CD6C4();
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v5 = wcslen(a2);
  v6 = 2 * (v5 + 1);
  if ( v6 > 0xFFFE )
    return -1073741306;
  v7 = KsepPoolAllocatePaged(2 * (v5 + 1));
  v8 = v7;
  if ( !v7 )
    return -1073741801;
  memmove(v7, (int)a2, v6);
  *(_WORD *)a1 = v6 - 2;
  *(_DWORD *)(a1 + 4) = v8;
  *(_WORD *)(a1 + 2) = v6;
  return 0;
}
