// -SmEmptyQueueToStore@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@K@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmEmptyQueueToStore(int a1, int a2)
{
  unsigned int *v3; // r0
  unsigned int v5; // r1
  int v6; // r4

  v3 = (unsigned int *)(a1 + 4 * (a2 + 802));
  do
    v5 = __ldrex(v3);
  while ( !v5 && __strex(1u, v3) );
  __dmb(0xBu);
  if ( v5 && v5 != 1 )
    ExfWaitForRundownProtectionRelease(v3, v5);
  v6 = a1 + 32 * a2;
  *(_DWORD *)(v6 + 3360) = 1;
  return SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(*(_DWORD *)(96 * (a2 & 0x1F) + a1), v6 + 3336, 0);
}
