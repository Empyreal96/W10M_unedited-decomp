// FsRtlFreeExtraCreateParameter 
 
int __fastcall FsRtlFreeExtraCreateParameter(int a1)
{
  void (__fastcall *v1)(int, int); // r3
  int v3; // r0
  _DWORD *v4; // r1
  int result; // r0

  v1 = *(void (__fastcall **)(int, int))(a1 - 20);
  if ( v1 )
    v1(a1, a1 - 36);
  if ( (*(_DWORD *)(a1 - 16) & 0x20) != 0 && FltMgrCallbacks )
    (*(void (__fastcall **)(_DWORD, int))FltMgrCallbacks)(*(_DWORD *)(a1 - 4), a1);
  v3 = *(_DWORD *)(a1 - 8);
  if ( !v3 )
    return ExFreePoolWithTag(a1 - 52);
  v4 = (_DWORD *)(a1 - 52);
  if ( (*(_DWORD *)(a1 - 16) & 0x40) != 0 )
    result = ExFreeToNPagedLookasideList(v3, v4);
  else
    result = ExFreeToPagedLookasideList(v3, v4);
  return result;
}
