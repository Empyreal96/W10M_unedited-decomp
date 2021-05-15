// ExIsResourceAcquiredExclusiveLite 
 
BOOL __fastcall ExIsResourceAcquiredExclusiveLite(int a1)
{
  int v1; // r2

  v1 = __mrc(15, 0, 13, 0, 3);
  if ( (*(_WORD *)(a1 + 14) & 0x80) == 0 )
    return 0;
  return *(_DWORD *)(a1 + 24) == (v1 & 0xFFFFFFC0);
}
