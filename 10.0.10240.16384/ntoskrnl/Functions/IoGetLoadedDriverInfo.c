// IoGetLoadedDriverInfo 
 
int __fastcall IoGetLoadedDriverInfo(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r5
  int v5; // r4
  int i; // r6
  int v9; // r2
  int v10; // r3

  v3 = 0;
  v5 = PsLoadedModuleList;
  for ( i = 0; ; i += v10 + 9 )
  {
    if ( (int *)v5 == &PsLoadedModuleList )
    {
      *a2 = v3;
      *a3 = i;
      return 0;
    }
    if ( a1
      && (!IopIsAddressRangeValid(v5, 92, (int)a3)
       || !IopIsAddressRangeValid(*(_DWORD *)(v5 + 48), *(unsigned __int16 *)(v5 + 44), v9)) )
    {
      break;
    }
    v10 = *(unsigned __int16 *)(v5 + 44);
    ++v3;
    v5 = *(_DWORD *)v5;
  }
  return -1073741823;
}
