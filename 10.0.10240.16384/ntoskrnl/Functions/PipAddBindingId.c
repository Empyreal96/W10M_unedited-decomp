// PipAddBindingId 
 
int __fastcall PipAddBindingId(int a1, int a2)
{
  int v4; // r0
  _DWORD *v5; // r4
  int result; // r0
  _DWORD *v7; // r1

  v4 = ExAllocatePoolWithTag(1, 16, 1399877200);
  v5 = (_DWORD *)v4;
  if ( !v4 )
    return -1073741670;
  result = RtlDuplicateUnicodeString(0, a2, v4 + 8);
  if ( result >= 0 )
  {
    v7 = *(_DWORD **)(a1 + 32);
    *v5 = a1 + 28;
    v5[1] = v7;
    if ( *v7 != a1 + 28 )
      sub_7F4780();
    *v7 = v5;
    *(_DWORD *)(a1 + 32) = v5;
  }
  return result;
}
