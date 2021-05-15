// IopGetModeInformation 
 
int __fastcall IopGetModeInformation(int a1)
{
  int v1; // r2
  int v2; // r3

  v1 = *(_DWORD *)(a1 + 44);
  v2 = 0;
  if ( (v1 & 0x10) != 0 )
    v2 = 2;
  if ( (v1 & 0x20) != 0 )
    v2 |= 4u;
  if ( (v1 & 8) != 0 )
    v2 |= 8u;
  if ( (v1 & 2) != 0 )
  {
    if ( (v1 & 4) != 0 )
      v2 |= 0x10u;
    else
      v2 |= 0x20u;
  }
  if ( (v1 & 0x10000) != 0 )
    v2 |= 0x1000u;
  return v2;
}
