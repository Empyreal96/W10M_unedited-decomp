// PoFxIssueComponentPerfStateChangeMultiple 
 
int __fastcall PoFxIssueComponentPerfStateChangeMultiple(int a1, int a2, unsigned int a3, int a4)
{
  if ( (a2 & 1) != 0 && (unsigned int)KeGetCurrentIrql(a1) >= 2 )
    PopFxBugCheck(1556, a1, a3, 1);
  if ( (a2 & 3) == 3 )
    PopFxBugCheck(1556, a1, a3, 1);
  if ( a3 >= *(_DWORD *)(a1 + 388) )
    PopFxBugCheck(1556, a1, a3, 2);
  return PopFxIssueComponentPerfStateChanges(a1, *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a3), a2, a4);
}
