// RtlLookupFirstMatchingElementGenericTableAvl 
 
_DWORD *__fastcall RtlLookupFirstMatchingElementGenericTableAvl(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v8; // r4
  _DWORD *v9; // r5
  _DWORD *v10; // r0
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a4;
  *a3 = 0;
  if ( FindNodeOrParent(a1, a2, v11) != 1 )
    return 0;
  v8 = (_DWORD *)v11[0];
  do
  {
    v9 = v8;
    v10 = RealPredecessor(v8);
    v8 = v10;
  }
  while ( v10 && (*(int (__fastcall **)(int, int, _DWORD *))(a1 + 40))(a1, a2, v10 + 4) == 2 );
  *a3 = v9;
  return v9 + 4;
}
