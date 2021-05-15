// -StLazyWorkMgrRunExpiredWork@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_LAZY_WORK_MGR@1@_K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StLazyWorkMgrRunExpiredWork(unsigned int a1, unsigned __int64 a2)
{
  unsigned int v4; // r10
  char v5; // r0
  unsigned int v6; // r6
  unsigned int i; // r4
  unsigned __int64 v8; // kr00_8
  int v9; // r1
  unsigned int v10; // r2
  int v12[14]; // [sp+8h] [bp-38h] BYREF

  v4 = a1 + 144;
  v5 = 0;
  v6 = 0;
  for ( i = a1; i < v4; ++v5 )
  {
    v8 = *(_QWORD *)(i + 8);
    if ( ((unsigned int)v8 & HIDWORD(v8)) != -1 && (*(_QWORD *)i <= *(_QWORD *)(a1 + 160) || v8 <= a2) )
    {
      v6 |= 1 << v5;
      *(_DWORD *)i = -1;
      *(_DWORD *)(i + 4) = -1;
      *(_DWORD *)(i + 8) = -1;
      *(_DWORD *)(i + 12) = -1;
    }
    i += 24;
  }
  memset(v12, 0, 24);
  v12[0] = v12[0] & 0xFFFFFFF8 | 6;
  v12[1] = 1;
  *(_DWORD *)(a1 + 192) |= 1u;
  while ( v6 )
  {
    v10 = __clz(__rbit(v6));
    v6 &= ~(1 << v10);
    v12[3] = v10;
    ST_STORE<SM_TRAITS>::StWorkItemProcess(a1 - 3280, (char *)v12 + 1);
  }
  *(_DWORD *)(a1 + 192) &= 0xFFFFFFFE;
  return ST_STORE<SM_TRAITS>::StLazyWorkMgrSetSchedule(a1, v9, 0, 0);
}
