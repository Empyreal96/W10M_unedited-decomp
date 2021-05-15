// IoSetGenericIrpExtension 
 
int __fastcall IoSetGenericIrpExtension(int a1, int a2, unsigned int a3, int a4)
{
  int v7; // r2
  int v9; // r0

  if ( a3 > 4 )
    return -1073741811;
  if ( !a4 )
  {
    v7 = *(_DWORD *)(a1 + 104);
    if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
      return -1073741791;
    if ( v7 && (*(_WORD *)(v7 + 2) & 4) != 0 )
      return -1073741791;
  }
  v9 = IopAllocateIrpExtension(a1, 2);
  if ( !v9 )
    return -1073741670;
  memmove(v9 + 4, a2, a3);
  return 0;
}
