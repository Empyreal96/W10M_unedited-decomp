// BcdUtilGetBootOptionBoolean 
 
int __fastcall BcdUtilGetBootOptionBoolean(int a1, int a2, _BYTE *a3)
{
  int v4; // r0
  int result; // r0
  char v6; // r3

  if ( (a2 & 0xF000000) != 100663296 )
    return -1073741811;
  v4 = BcdUtilGetBootOption();
  if ( !v4 )
    return -1073741275;
  v6 = *(_BYTE *)(*(_DWORD *)(v4 + 4) + v4);
  result = 0;
  *a3 = v6;
  return result;
}
