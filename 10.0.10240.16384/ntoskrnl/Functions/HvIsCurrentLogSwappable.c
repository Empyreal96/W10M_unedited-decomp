// HvIsCurrentLogSwappable 
 
BOOL __fastcall HvIsCurrentLogSwappable(int a1)
{
  int v2; // r3
  int v3; // r0

  v2 = *(_DWORD *)(a1 + 96);
  if ( v2 == 4 )
  {
    v3 = HvpLogTypeToLogArrayIndex(5);
  }
  else
  {
    if ( v2 != 5 )
      return 0;
    v3 = 0;
  }
  return *(_BYTE *)(v3 + a1 + 120) == 0;
}
