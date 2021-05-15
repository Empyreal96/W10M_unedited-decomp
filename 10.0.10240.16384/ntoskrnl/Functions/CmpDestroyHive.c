// CmpDestroyHive 
 
int __fastcall CmpDestroyHive(int a1, int a2)
{
  int v3; // r0
  int v4; // r4
  int v5; // r2
  int v6; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = -1;
  v3 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, v8);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 16);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v8);
    ExAcquireResourceExclusiveLite(*((_DWORD *)CmpMasterHive + 468), 1, v5, (int)CmpMasterHive);
    v6 = CmpFreeKeyByCell(CmpMasterHive, v4, 1);
    ExReleaseResourceLite(*((_DWORD *)CmpMasterHive + 468));
    if ( v6 >= 0 )
      CmpParseCacheRemoveHive(a1);
    JUMPOUT(0x7D1FA8);
  }
  return sub_7D1FA4();
}
