// KiUpdateSharedReadyQueueAffinityThread 
 
unsigned int __fastcall KiUpdateSharedReadyQueueAffinityThread(unsigned int result, int a2)
{
  int v3; // r2
  int v4; // r2
  BOOL v5; // r1
  unsigned int *v6; // r2

  v3 = *(_DWORD *)(a2 + 68);
  if ( !v3 )
    goto LABEL_2;
  while ( (*(_DWORD *)(v3 + 4) & 2) != 0 )
  {
    v3 = *(_DWORD *)(v3 + 60);
    if ( !v3 )
      goto LABEL_2;
  }
  if ( (*(_DWORD *)(a2 + 80) & 0x100) != 0 || *(char *)(a2 + 123) >= 16 )
  {
LABEL_2:
    if ( !result )
      result = (unsigned int)*(&KiProcessorBlock + *(_DWORD *)(a2 + 364));
    v4 = *(_DWORD *)(result + 3456);
    v5 = 0;
    if ( v4 )
      v5 = (*(_DWORD *)(a2 + 356) & v4) == v4;
  }
  else
  {
    v5 = 0;
  }
  if ( v5 != ((*(_DWORD *)(a2 + 80) >> 12) & 1) )
  {
    v6 = (unsigned int *)(a2 + 80);
    do
      result = __ldrex(v6);
    while ( __strex(result ^ 0x1000, v6) );
  }
  return result;
}
