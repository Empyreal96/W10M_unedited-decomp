// BcdUtilGetBootOptionString 
 
int __fastcall BcdUtilGetBootOptionString(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0
  int v6; // r3

  if ( (a2 & 0xF000000) != 0x2000000 )
    return -1073741811;
  v4 = BcdUtilGetBootOption();
  if ( !v4 )
    return -1073741275;
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(v4 + 4) + v4;
  v6 = *(_DWORD *)(v4 + 8);
  result = 0;
  *(_WORD *)a3 = v6;
  *(_WORD *)(a3 + 2) = v6;
  return result;
}
