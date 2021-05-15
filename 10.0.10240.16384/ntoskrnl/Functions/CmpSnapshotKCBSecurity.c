// CmpSnapshotKCBSecurity 
 
int __fastcall CmpSnapshotKCBSecurity(int a1, int a2, int a3, int *a4)
{
  int v6; // r6
  int v7; // r0

  v6 = CmGetKCBCacheSecurity(a1, a2);
  v7 = ExAllocatePoolWithTag(1, *(_DWORD *)(v6 + 16), a3);
  *a4 = v7;
  if ( !v7 )
    return -1073741670;
  memmove(v7, v6 + 24, *(_DWORD *)(v6 + 16));
  return 0;
}
