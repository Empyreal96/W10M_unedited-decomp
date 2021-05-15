// RtlRemoveEntryHashTable 
 
int __fastcall RtlRemoveEntryHashTable(int a1, _DWORD *a2, int a3)
{
  __int64 v3; // kr00_8
  int result; // r0

  --*(_DWORD *)(a1 + 20);
  if ( *a2 == a2[1] )
    --*(_DWORD *)(a1 + 24);
  v3 = *(_QWORD *)a2;
  if ( *(_DWORD **)(*a2 + 4) != a2 || *(_DWORD **)HIDWORD(v3) != a2 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v3) = v3;
  *(_DWORD *)(v3 + 4) = HIDWORD(v3);
  if ( a3 )
    result = sub_5148DC();
  else
    result = 1;
  return result;
}
