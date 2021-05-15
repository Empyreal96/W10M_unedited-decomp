// -StDmInitialize@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@0@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmInitialize(int a1, int a2)
{
  int v4; // r2
  _DWORD *v5; // r3
  int v6; // r3
  int v7; // r2
  int result; // r0
  __int64 v9; // [sp+0h] [bp-28h] BYREF
  char v10[32]; // [sp+8h] [bp-20h] BYREF

  memset((_BYTE *)a1, 0, 768);
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultInit(a1 + 12, 1);
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultInit(a1 + 48, 1);
  NP_CONTEXT::NpInitialize((struct NP_CONTEXT *)(a1 + 488));
  *(_DWORD *)(a1 + 556) = 0;
  *(_DWORD *)(a1 + 572) = a2;
  NP_CONTEXT::NpInitialize((struct NP_CONTEXT *)(a1 + 576));
  *(_DWORD *)(a1 + 644) = 1;
  *(_DWORD *)(a1 + 560) = 1;
  *(_DWORD *)(a1 + 564) = 1;
  *(_DWORD *)(a1 + 568) = 0x1FFFFFFF;
  *(_DWORD *)(a1 + 648) = 0x20000000;
  *(_DWORD *)(a1 + 652) = 0x20000000;
  v4 = 6;
  *(_DWORD *)(a1 + 656) = 0x3FFFFFFF;
  *(_DWORD *)(a1 + 660) = a2;
  *(_DWORD *)(a1 + 8) = a1 + 488;
  *(_DWORD *)(a1 + 44) = a1 + 576;
  v5 = (_DWORD *)(a1 + 320);
  do
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    *v5 = -1;
    v5 += 3;
    --v4;
  }
  while ( v4 );
  v6 = a1;
  v7 = 8;
  do
  {
    *(_DWORD *)(v6 + 392) = -1;
    v6 += 12;
    --v7;
  }
  while ( v7 );
  memset((_BYTE *)(a1 + 160), 0, 52);
  __dmb(0xBu);
  *(_DWORD *)(a1 + 160) = 0;
  *(_DWORD *)(a1 + 216) = *(_DWORD *)(a1 + 216) & 0xFFFFFFF8 | 6;
  *(_DWORD *)(a1 + 220) = 4;
  *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 136) & 0xFFFFFFF8 | 6;
  *(_DWORD *)(a1 + 140) = 5;
  *(_BYTE *)(a1 + 72) = 2;
  *(_DWORD *)(a1 + 296) = -10001;
  KeQueryPerformanceCounter(v10, &v9);
  result = _rt_sdiv64(1000000i64, 10000 * v9);
  *(_DWORD *)(a1 + 280) = result;
  return result;
}
