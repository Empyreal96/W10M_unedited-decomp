// -StDeviceWorkItemCleanup@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDeviceWorkItemCleanup(_DWORD *a1, int a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r2
  int v7; // r2
  int v8; // r2

  v4 = *(_DWORD *)(a2 + 12) >> a1[25];
  v6 = a1[77];
  result = a1[76];
  if ( *(_BYTE *)(v6 + v4) )
    --*(_BYTE *)(v6 + v4);
  else
    *(_WORD *)(result + 2 * v4) &= 0xBFFFu;
  v7 = a1[168];
  if ( (v7 & 1) != 0 && (*(_DWORD *)(a2 + 8) | 1) == v7 )
    a1[168] = v7 & 0xFFFFFFFE;
  else
    result = ExFreePoolWithTag(*(_DWORD *)(a2 + 8));
  v8 = a1[169];
  if ( (v8 & 1) == 0 || (a2 | 1) != v8 )
    return ExFreePoolWithTag(a2);
  a1[169] = v8 & 0xFFFFFFFE;
  return result;
}
