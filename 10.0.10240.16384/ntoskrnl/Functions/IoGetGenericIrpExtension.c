// IoGetGenericIrpExtension 
 
int __fastcall IoGetGenericIrpExtension(int a1, int a2, unsigned int a3)
{
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r3

  result = -1073741275;
  if ( a3 > 4 )
    return -1073741811;
  v5 = *(_DWORD *)(a1 + 104);
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 || (!v5 || (*(_WORD *)(v5 + 2) & 4) == 0 ? (v6 = 0) : (v6 = 1), v6) )
  {
    if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
      v7 = a1 + 100;
    else
      v7 = *(_DWORD *)(a1 + 104);
    memmove(a2, v7 + 4, a3);
    result = 0;
  }
  return result;
}
