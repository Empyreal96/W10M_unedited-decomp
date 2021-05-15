// MiRemoveWakeListEntry 
 
int __fastcall MiRemoveWakeListEntry(int result, _DWORD **a2)
{
  _DWORD **v2; // r2
  _DWORD *v3; // r4
  _DWORD *v4; // r3

  v2 = *(_DWORD ***)(result + 44);
  v3 = (_DWORD *)(result + 44);
  v4 = *v2;
  while ( v2 != a2 )
  {
    v3 = v2;
    v2 = (_DWORD **)v4;
    v4 = (_DWORD *)*v4;
  }
  *v3 = v4;
  return result;
}
