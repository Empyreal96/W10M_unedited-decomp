// HvpFreeHiveFreeDisplay 
 
int __fastcall HvpFreeHiveFreeDisplay(_DWORD *a1, int a2)
{
  _DWORD *v2; // r8
  _DWORD *v3; // r5
  int v4; // r6
  _DWORD *v5; // r4
  int v6; // r7
  int result; // r0

  v2 = a1;
  v3 = a1;
  v4 = (a2 != 0) + 1;
  do
  {
    v5 = v3;
    v6 = 24;
    do
    {
      result = v5[245];
      if ( result )
      {
        result = ((int (__fastcall *)(int, _DWORD))v2[4])(result, v5[242]);
        v5[244] = 0;
        v5[245] = 0;
        v5[242] = 0;
      }
      v5 += 4;
      --v6;
    }
    while ( v6 );
    v3 += 103;
    --v4;
  }
  while ( v4 );
  return result;
}
