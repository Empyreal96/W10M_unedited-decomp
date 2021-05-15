// KiRescheduleThreadAfterAffinityChange 
 
int __fastcall KiRescheduleThreadAfterAffinityChange(_BYTE *a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v9; // r4
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2

  if ( a3 != 2 )
  {
    if ( a3 != 1 )
      return sub_51BFE0();
    v9 = (char)a1[123];
    KiRemoveThreadFromAnyReadyQueue(a4, a5, a1, v9);
    KiPrepareReadyThreadForRescheduling(a1, v9, a6);
    return 0;
  }
  if ( *(unsigned __int8 *)(a4 + 1052) == *(unsigned __int16 *)(a2 + 4) && (*(_DWORD *)a2 & *(_DWORD *)(a4 + 1048)) != 0 )
    return 0;
  if ( a1[132] != 2 )
  {
    a1[72] |= 8u;
    return 0;
  }
  v10 = a1 + 81;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 8, v10) );
  if ( *(_DWORD *)(a4 + 8) )
    return 0;
  KiSelectNextThread(a4, a6);
  return 1;
}
