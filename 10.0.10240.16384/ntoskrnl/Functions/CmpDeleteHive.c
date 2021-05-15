// CmpDeleteHive 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpDeleteHive(_DWORD *a1)
{
  _DWORD *v1; // r4
  int v3; // r0
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED
  int v6; // r0

  v1 = a1 + 452;
  if ( (_DWORD *)a1[452] != a1 + 452 )
  {
    v3 = CmpLockHiveListExclusive();
    *(_QWORD *)&v4 = *(_QWORD *)v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v5 != v1 )
      sub_51A0B0(v3);
    *v5 = v4;
    *(_DWORD *)(v4 + 4) = v5;
    CmpUnlockHiveList(v3);
  }
  *a1 = -1160724768;
  HvFreeDirtyData(a1);
  CmpDeleteKcbCache(a1);
  ExDeleteResourceLite(a1[468]);
  ExFreePoolWithTag(a1[466], 0);
  v6 = a1[495];
  if ( v6 )
    ExFreePoolWithTag(v6, 1649298755);
  return CmpFree(a1, 3872);
}
