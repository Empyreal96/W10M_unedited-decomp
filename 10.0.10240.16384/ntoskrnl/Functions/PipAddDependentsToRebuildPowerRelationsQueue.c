// PipAddDependentsToRebuildPowerRelationsQueue 
 
_DWORD **__fastcall PipAddDependentsToRebuildPowerRelationsQueue(int a1, int a2, int a3, int a4)
{
  _DWORD **result; // r0
  _DWORD *v5; // r5
  _DWORD *v6; // r4
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  result = (_DWORD **)PiGetDependentList(a1);
  v5 = result;
  v6 = *result;
  while ( v6 != v5 )
  {
    PiEnumerateDependentListEntry(v6, v7, 0);
    result = (_DWORD **)v7[0];
    v6 = (_DWORD *)*v6;
    if ( v7[0] )
      result = (_DWORD **)PipAddtoRebuildPowerRelationsQueue(v7[0]);
  }
  return result;
}
