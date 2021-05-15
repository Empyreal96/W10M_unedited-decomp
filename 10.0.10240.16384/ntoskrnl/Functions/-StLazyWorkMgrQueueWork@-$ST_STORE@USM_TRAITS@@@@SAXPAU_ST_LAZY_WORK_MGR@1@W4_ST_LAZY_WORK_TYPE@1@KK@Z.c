// -StLazyWorkMgrQueueWork@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_LAZY_WORK_MGR@1@W4_ST_LAZY_WORK_TYPE@1@KK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(int a1, int a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // r0
  __int64 v7; // kr20_8
  unsigned int v8; // lr
  unsigned int v9; // r9
  __int64 v10; // kr28_8
  int v11; // r3
  int v12; // r3
  int v13; // r1

  LODWORD(v5) = -27728;
  do
  {
    v7 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v8 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v9 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v8 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v7 != MEMORY[0xFFFF93B0] );
  v11 = 3 * a2;
  HIDWORD(v5) = -1;
  v10 = __PAIR64__(v8, v9) - v7;
  v12 = a1 + 8 * v11;
  if ( a4 == -1 )
  {
    *(_DWORD *)v12 = -1;
    *(_DWORD *)(v12 + 4) = -1;
    *(_DWORD *)(v12 + 8) = -1;
  }
  else
  {
    *(_QWORD *)(v12 + 16) = v10;
    *(_QWORD *)v12 = 10000i64 * a3;
    v5 = 10000i64 * a4 + v10;
    *(_DWORD *)(v12 + 8) = v5;
  }
  *(_DWORD *)(v12 + 12) = HIDWORD(v5);
  v13 = *(_DWORD *)(a1 + 192);
  if ( (v13 & 1) == 0 )
    LODWORD(v5) = ST_STORE<SM_TRAITS>::StLazyWorkMgrSetSchedule(a1, v13, v10, HIDWORD(v10));
  return v5;
}
