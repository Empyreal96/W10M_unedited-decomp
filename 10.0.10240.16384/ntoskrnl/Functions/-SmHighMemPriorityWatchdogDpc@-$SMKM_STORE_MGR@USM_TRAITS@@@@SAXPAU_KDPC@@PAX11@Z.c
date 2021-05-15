// -SmHighMemPriorityWatchdogDpc@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU_KDPC@@PAX11@Z 
 
_DWORD *__fastcall SMKM_STORE_MGR<SM_TRAITS>::SmHighMemPriorityWatchdogDpc(int a1, int a2)
{
  _DWORD *result; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1

  result = (_DWORD *)(a2 + 5872);
  __dmb(0xBu);
  v3 = (unsigned int *)(a2 + 5884);
  do
    v4 = __ldrex(v3);
  while ( !v4 && __strex((unsigned int)result, v3) );
  __dmb(0xBu);
  if ( !v4 )
    result = (_DWORD *)ExQueueWorkItem(result, 3);
  return result;
}
