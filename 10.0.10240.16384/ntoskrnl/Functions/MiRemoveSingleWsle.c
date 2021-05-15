// MiRemoveSingleWsle 
 
BOOL __fastcall MiRemoveSingleWsle(int a1, unsigned int a2)
{
  unsigned int v4; // r2
  _DWORD *v5; // r1
  unsigned int v7[36]; // [sp+0h] [bp-90h] BYREF

  if ( dword_634484 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 36) * a2 + *(_DWORD *)(*(_DWORD *)(a1 + 92) + 252));
    v5 = (_DWORD *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
    if ( (*v5 & 0x10) != 0 && (v4 & 0xE00) != 3584 )
      MiLogPageAccess(a1, v5);
  }
  v7[0] = 1;
  v7[1] = a2;
  return MiFreeWsleList(a1, v7, 0) == 0;
}
