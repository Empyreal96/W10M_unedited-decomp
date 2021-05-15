// IopWriteDriverList 
 
int __fastcall IopWriteDriverList(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int *v7; // r9
  _DWORD *v8; // r8
  int v9; // r2
  int v10; // r3

  v6 = PsLoadedModuleList;
  v7 = (int *)(a1 + a4);
  if ( (int *)PsLoadedModuleList == &PsLoadedModuleList )
    return 0;
  v8 = (_DWORD *)(a1 + a3);
  while ( a2 != 1
       || IopIsAddressRangeValid(v6, 92, a3)
       && IopIsAddressRangeValid(*(_DWORD *)(v6 + 48), *(unsigned __int16 *)(v6 + 44), v9) )
  {
    v10 = *(unsigned __int16 *)(v6 + 44) >> 1;
    *v7 = v10;
    memmove((int)(v7 + 1), *(_DWORD *)(v6 + 48), 2 * v10);
    *((_WORD *)v7 + *v7 + 2) = 0;
    memmove((int)(v8 + 1), v6, 0x48u);
    v8[18] = *(_DWORD *)(v6 + 88);
    v8[9] = *(_DWORD *)(v6 + 84);
    *v8 = (char *)v7 - a1;
    v8 += 19;
    v6 = *(_DWORD *)v6;
    v7 = (int *)(((unsigned int)v7 + 2 * *v7 + 13) & 0xFFFFFFF8);
    if ( (int *)v6 == &PsLoadedModuleList )
      return 0;
  }
  return -1073741823;
}
