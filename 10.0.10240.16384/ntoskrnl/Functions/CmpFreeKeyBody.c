// CmpFreeKeyBody 
 
int __fastcall CmpFreeKeyBody(int a1, unsigned int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, unsigned int, int *); // r3
  int v7; // r0
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4);
  v9[0] = -1;
  v7 = v5(a1, a2, v9);
  if ( !v7 )
    return 0;
  if ( (*(_WORD *)(v7 + 2) & 2) == 0 )
  {
    if ( *(_DWORD *)(v7 + 44) != -1 )
      return sub_805EEC();
    if ( *(_WORD *)(v7 + 74) )
      HvFreeCell(a1, *(_DWORD *)(v7 + 48));
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v9);
  HvFreeCell(a1, a2);
  return 1;
}
