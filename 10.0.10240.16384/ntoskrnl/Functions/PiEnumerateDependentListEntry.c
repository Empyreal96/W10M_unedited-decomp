// PiEnumerateDependentListEntry 
 
int __fastcall PiEnumerateDependentListEntry(int a1, _DWORD *a2)
{
  int result; // r0
  _DWORD *v4; // r2

  result = PiListEntryToDependencyEdge(a1, 1);
  *a2 = *(_DWORD *)(*(_DWORD *)(result + 20) + 24);
  if ( v4 )
    *v4 = *(_DWORD *)(result + 24);
  return result;
}
