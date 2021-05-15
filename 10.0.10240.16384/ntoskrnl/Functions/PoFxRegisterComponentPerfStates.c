// PoFxRegisterComponentPerfStates 
 
int __fastcall PoFxRegisterComponentPerfStates(int a1, unsigned int a2)
{
  int v2; // r3

  if ( a2 >= *(_DWORD *)(a1 + 388) )
    PopFxBugCheck(1556, a1, a2, 2);
  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a2) + 184);
  __dmb(0xBu);
  if ( v2 )
    PopFxBugCheck(1536, a1, a2, 0);
  return PopFxRegisterComponentPerfStates();
}
