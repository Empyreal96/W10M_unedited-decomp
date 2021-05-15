// -StLazyWorkMgrIdleTimeoutProcess@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_LAZY_WORK_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StLazyWorkMgrIdleTimeoutProcess(int a1)
{
  __int64 v1; // kr08_8
  unsigned int v2; // r6
  unsigned int v3; // r7

  *(_QWORD *)(a1 + 160) += *(_QWORD *)(a1 + 152);
  do
  {
    v1 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v2 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v3 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v2 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v1 != MEMORY[0xFFFF93B0] );
  return ST_STORE<SM_TRAITS>::StLazyWorkMgrRunExpiredWork(a1, HIDWORD(v1), v3 - v1, (__PAIR64__(v2, v3) - v1) >> 32);
}
