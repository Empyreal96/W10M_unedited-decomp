// PspSetProcessBackgroundCountCallback 
 
int __fastcall PspSetProcessBackgroundCountCallback(int a1, _BYTE *a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r1

  if ( (*(_DWORD *)(a1 + 188) & 1) == 0 )
  {
    v2 = *(_DWORD *)(a1 + 288);
    __dmb(0xBu);
    v3 = *(_DWORD *)(v2 + 412);
    if ( !*a2 )
    {
      if ( v3 )
        return 0;
      v4 = 0;
      goto LABEL_5;
    }
    if ( v3 == 1 )
    {
      v4 = 1;
LABEL_5:
      PspNotifyProcessBackgroundTransition(a1, v4);
      return 0;
    }
  }
  return 0;
}
