// MiUpdatePfnPriority 
 
int __fastcall MiUpdatePfnPriority(int a1, unsigned int a2, int a3)
{
  char v3; // r6
  int v4; // r5
  unsigned int v5; // r4
  int v7; // r3

  v3 = *(_BYTE *)(a1 + 19);
  v4 = -1;
  if ( (v3 & 8) != 0 )
    v5 = 5;
  else
    v5 = v3 & 7;
  if ( a2 == v5 )
    return -1;
  if ( a2 < v5 )
  {
    if ( !a3 )
      return -1;
    if ( v5 > 5 )
      return sub_5456D4();
  }
  v7 = *(_BYTE *)(a1 + 18) & 7;
  if ( v7 == 2 )
  {
    MiRelinkStandbyPage(a1, a2, 1022);
    return -1;
  }
  if ( v7 == 6 && (*(_DWORD *)(a1 + 12) & 0x3FFFFFFFu) > 1 && a2 < v5 )
    return -1;
  *(_BYTE *)(a1 + 19) = v3 & 0xF8 | a2 & 7;
  if ( v5 < 5 )
  {
    if ( a2 == 5 )
      v4 = 0;
    return v4;
  }
  if ( a2 >= 5 )
    return v4;
  return 7;
}
