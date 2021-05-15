// PipAttemptDependentsStart 
 
_DWORD **__fastcall PipAttemptDependentsStart(int a1, int a2, int a3, int a4)
{
  _DWORD **result; // r0
  _DWORD *v5; // r5
  _DWORD *v6; // r4
  _DWORD **v7; // [sp+0h] [bp-10h] BYREF
  int v8[3]; // [sp+4h] [bp-Ch] BYREF

  v7 = (_DWORD **)a3;
  v8[0] = a4;
  result = (_DWORD **)PiGetDependentList(*(_DWORD *)(a1 + 16));
  v5 = result;
  v6 = *result;
  while ( v6 != v5 )
  {
    PiEnumerateDependentListEntry(v6, &v7, v8);
    result = v7;
    v6 = (_DWORD *)*v6;
    if ( v7 )
      result = (_DWORD **)PipAttemptDependentStart();
  }
  return result;
}
