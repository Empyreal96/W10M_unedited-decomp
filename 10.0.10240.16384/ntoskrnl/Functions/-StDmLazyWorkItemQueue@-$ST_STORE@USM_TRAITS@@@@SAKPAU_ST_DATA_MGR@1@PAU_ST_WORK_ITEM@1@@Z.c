// -StDmLazyWorkItemQueue@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(int a1, int a2)
{
  int result; // r0
  unsigned __int16 *v4; // r2
  unsigned int v5; // r5

  result = 0;
  if ( (*(_WORD *)(a2 + 8) & 1) == 0 )
  {
    __dmb(0xBu);
    v4 = (unsigned __int16 *)(a2 + 8);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 1, v4) );
    __dmb(0xBu);
    if ( (v5 & 1) == 0 )
    {
      SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(*(_DWORD *)(a1 + 92), a2, 2);
      result = 1;
    }
  }
  return result;
}
