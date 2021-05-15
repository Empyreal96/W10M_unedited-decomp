// PipCheckForUnsatisfiedDependencies 
 
int __fastcall PipCheckForUnsatisfiedDependencies(int a1, int a2, int a3, int a4)
{
  BOOL v5; // r4
  _DWORD **v6; // r6
  _DWORD *v7; // r5
  int v9; // r0
  int v10; // [sp+0h] [bp-18h] BYREF
  int v11[5]; // [sp+4h] [bp-14h] BYREF

  v10 = a3;
  v11[0] = a4;
  v5 = 0;
  v6 = (_DWORD **)PiGetProviderList(*(_DWORD *)(a1 + 16));
  v7 = *v6;
  while ( v7 != v6 )
  {
    PiEnumerateProviderListEntry(v7, &v10, v11);
    v7 = (_DWORD *)*v7;
    if ( v10 )
      v9 = *(_DWORD *)(*(_DWORD *)(v10 + 176) + 20);
    else
      v9 = 0;
    if ( !v10 || !v9 )
      return 1;
    if ( (v11[0] & a2 & 3) != 0 )
    {
      v5 = PipIsProviderStarted(v9) == 0;
      if ( v5 )
        return v5;
    }
  }
  return v5;
}
