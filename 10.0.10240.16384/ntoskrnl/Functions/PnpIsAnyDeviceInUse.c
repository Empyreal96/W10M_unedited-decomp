// PnpIsAnyDeviceInUse 
 
BOOL __fastcall PnpIsAnyDeviceInUse(int *a1, int a2, _DWORD *a3)
{
  int i; // r3
  int v4; // r1
  int v5; // r4
  int v6; // t1

  i = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    if ( v4 )
      break;
    v6 = *a1++;
    for ( i = v6; i; i = *(_DWORD *)(i + 16) )
    {
      v4 = *(_DWORD *)(i + 4);
      if ( v4 )
        break;
    }
    ++v5;
  }
  while ( !v5 );
  if ( a3 )
    *a3 = i;
  return v4 != 0;
}
