// -SmQueueContextCleanup@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAU1@PAU_SM_QUEUE_CONTEXT@1@@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmQueueContextCleanup(int result, unsigned int *a2)
{
  unsigned int v3; // r3
  int v4; // r6
  int *v5; // r1
  bool v6; // zf
  int v7; // r3

  v3 = a2[2];
  v4 = result;
  if ( v3 )
    result = SmFpFree(result + 5720, 4, -1, v3);
  while ( 1 )
  {
    v5 = (int *)a2[1];
    if ( v5 == (int *)a2 )
      break;
    v6 = *a2 == (_DWORD)v5;
    *a2 = *(_DWORD *)*a2 & 0xFFFFFFF8;
    if ( v6 )
    {
      v7 = 0;
      *(_QWORD *)a2 = *(_QWORD *)(&a2 - 1);
    }
    else
    {
      *v5 = *v5 & 7 | (8 * ((unsigned int)*v5 >> 3) - 8);
    }
    result = SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFreeResource(v4);
  }
  return result;
}
