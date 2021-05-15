// -StLazyWorkMgrResetIdle@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_LAZY_WORK_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StLazyWorkMgrResetIdle(int result)
{
  __int64 v1; // r6
  int v2; // r2
  __int64 v3; // kr00_8
  unsigned int v4; // lr
  unsigned int v5; // r8
  __int64 v6; // r2
  unsigned __int64 v7; // kr08_8

  v1 = *(_QWORD *)(result + 160);
  v2 = *(_DWORD *)(result + 144);
  *(_DWORD *)(result + 160) = 0;
  *(_DWORD *)(result + 164) = 0;
  if ( (*(_DWORD *)(result + 148) & v2) != -1 )
  {
    do
    {
      v3 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v4 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v5 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v4 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v3 != MEMORY[0xFFFF93B0] );
    v6 = __PAIR64__(v4, v5) - v3;
    v7 = *(_QWORD *)(result + 144);
    if ( v7 <= __PAIR64__(v4, v5) - v3 )
    {
      result = ST_STORE<SM_TRAITS>::StLazyWorkMgrRunExpiredWork(result, HIDWORD(v7), v6, HIDWORD(v6));
    }
    else if ( v1 )
    {
      result = ST_STORE<SM_TRAITS>::StLazyWorkMgrSetSchedule(result, v1 | HIDWORD(v1), v6, HIDWORD(v6));
    }
  }
  return result;
}
