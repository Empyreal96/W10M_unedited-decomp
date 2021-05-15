// RaspDestroySegmentList 
 
int __fastcall RaspDestroySegmentList(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r6
  int v6; // r7
  int i; // r4
  int v9; // r0
  int v10; // r0

  v3 = 0;
  v6 = a1;
  for ( i = a1; v3 < a2; i += 13 )
  {
    if ( !i )
      break;
    if ( *(_BYTE *)(i + 12) == 3 && *(_DWORD *)i )
      RaspFreeMemory(*(_DWORD *)i, a3);
    if ( *(_BYTE *)(i + 12) == 4 )
    {
      v10 = *(_DWORD *)(i + 8);
      if ( v10 )
        RaspFreeMemory(v10, a3);
    }
    if ( *(_BYTE *)(i + 12) == 5 )
    {
      if ( *(_DWORD *)i )
        RaspFreeMemory(*(_DWORD *)i, a3);
      v9 = *(_DWORD *)(i + 8);
      if ( v9 )
        RaspFreeMemory(v9, a3);
    }
    ++v3;
  }
  return RaspFreeMemory(v6, a3);
}
