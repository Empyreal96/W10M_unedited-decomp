// IopCheckDeviceFlags 
 
int __fastcall IopCheckDeviceFlags(int a1, int a2)
{
  int v2; // r0
  int v3; // r2

  v2 = *(_DWORD *)(a1 + 24);
  v3 = 0;
  while ( v2 )
  {
    if ( (*(_DWORD *)(v2 + 28) & a2) != 0 )
      return 1;
    v2 = *(_DWORD *)(*(_DWORD *)(v2 + 176) + 24);
  }
  return v3;
}
