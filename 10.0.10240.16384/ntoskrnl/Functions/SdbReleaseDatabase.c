// SdbReleaseDatabase 
 
unsigned int __fastcall SdbReleaseDatabase(unsigned int a1, int a2)
{
  unsigned int i; // r5
  unsigned int *v4; // r0
  _DWORD **v5; // r0

  if ( (*(_DWORD *)(a1 + 16) & 0xFFF8) != 0 )
  {
    for ( i = 3; i < 0x10; ++i )
    {
      if ( (*(_DWORD *)(a1 + 16) & (1 << i)) != 0 )
        SdbpCloseLocalDatabaseEx(a1, a2, i);
    }
  }
  if ( *(_DWORD *)(a1 + 8) )
    SdbpCloseLocalDatabaseEx(a1, a2, 1);
  if ( (*(_DWORD *)(a1 + 88) & 2) != 0 )
    SdbCloseDatabaseRead(*(unsigned int **)(a1 + 84));
  v4 = *(unsigned int **)(a1 + 4);
  if ( v4 )
    SdbCloseDatabaseRead(v4);
  while ( 1 )
  {
    v5 = *(_DWORD ***)(a1 + 416);
    if ( !v5 )
      break;
    if ( v5[1] == v5 )
    {
      *(_DWORD *)(a1 + 416) = 0;
    }
    else
    {
      *(_DWORD *)(a1 + 416) = *v5;
      *v5[1] = *v5;
      (*v5)[1] = v5[1];
    }
    ExFreePoolWithTag((unsigned int)v5);
  }
  return ExFreePoolWithTag(a1);
}
