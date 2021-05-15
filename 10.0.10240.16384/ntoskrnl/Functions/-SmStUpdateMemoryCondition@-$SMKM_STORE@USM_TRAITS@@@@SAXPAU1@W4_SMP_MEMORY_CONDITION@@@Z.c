// -SmStUpdateMemoryCondition@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@W4_SMP_MEMORY_CONDITION@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStUpdateMemoryCondition(int a1, int a2)
{
  int v2; // r2
  int v5; // r4
  int v6; // r6
  int result; // r0

  *(_BYTE *)(a1 + 3518) = a2;
  v2 = *(unsigned __int8 *)(a1 + 3518);
  if ( v2 == 4 )
    v5 = *(_DWORD *)(a1 + 3948);
  else
    v5 = `SMKM_STORE<SM_TRAITS>::SmStGetDesiredStoreWorkerPriority'::`2'::PriorityByMemoryCondition[v2];
  v6 = *(_DWORD *)(a1 + 3648);
  result = KeQueryPriorityThread(v6);
  if ( a2 >= 4 )
  {
    if ( result > v5 )
      result = KeSetActualBasePriorityThread(v6, v5);
  }
  else
  {
    if ( result != v5 )
      result = KeSetActualBasePriorityThread(v6, v5);
    if ( a2 <= 0 )
      result = ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(a1 + 56, a1 + 3480);
  }
  return result;
}
