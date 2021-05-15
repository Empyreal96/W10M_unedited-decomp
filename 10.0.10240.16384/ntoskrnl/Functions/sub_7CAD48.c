// sub_7CAD48 
 
void sub_7CAD48()
{
  int v0; // r5
  int v1; // r8
  _DWORD *v2; // r2
  __int64 v3; // r0
  int v4; // r1

  v2 = (_DWORD *)(v0 + 36);
  v3 = *(_QWORD *)(v0 + 36);
  if ( *(_DWORD *)(v3 + 4) == v0 + 36 && *(_DWORD **)HIDWORD(v3) == v2 )
  {
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    *v2 = v2;
    *(_DWORD *)(v0 + 40) = v0 + 36;
    PipDereferenceDependencyNode(v0);
    ExReleaseResourceLite((int)&PiDependencyRelationsLock);
    PpDevNodeUnlockTree(0);
    PiQueryPowerRelations(*(int **)(*(_DWORD *)(v1 + 176) + 20), 1);
    ObfDereferenceObject(v1);
    PnpAcquireDependencyRelationsLock(1, v4);
    JUMPOUT(0x76B7F0);
  }
  __fastfail(3u);
}
