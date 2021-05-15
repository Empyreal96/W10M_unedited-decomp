// EmpProviderDeregisterEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EmpProviderDeregisterEntry(int result)
{
  int v1; // r4
  int v2; // r2
  __int64 v3; // r0
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED
  _DWORD *i; // r5

  v1 = result;
  if ( result )
  {
    v2 = result + 12;
    v3 = *(_QWORD *)(result + 12);
    if ( *(_DWORD *)(v3 + 4) != v2 || *(_DWORD *)HIDWORD(v3) != v2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    *(_QWORD *)&v4 = *(_QWORD *)(v1 + 20);
    if ( *(_DWORD *)(v4 + 4) != v1 + 20 || *v5 != v1 + 20 )
      __fastfail(3u);
    *v5 = v4;
    *(_DWORD *)(v4 + 4) = v5;
    for ( i = *(_DWORD **)(*(_DWORD *)v1 + 44); i; i = (_DWORD *)*i )
      EmpQueueRuleUpdateState(*(i - 1), 0);
    result = ExFreePoolWithTag(v1);
  }
  return result;
}
