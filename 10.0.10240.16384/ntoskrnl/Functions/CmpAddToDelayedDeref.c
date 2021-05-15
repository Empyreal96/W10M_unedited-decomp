// CmpAddToDelayedDeref 
 
int __fastcall CmpAddToDelayedDeref(int result, int a2)
{
  _DWORD *v2; // r2
  _DWORD *v3; // r4

  v2 = *(_DWORD **)(result + 24);
  if ( v2 )
  {
    v3 = *(_DWORD **)(a2 + 4);
    *v2 = a2;
    v2[1] = v3;
    if ( *v3 != a2 )
      sub_7EBB08();
    *v3 = v2;
    *(_DWORD *)(a2 + 4) = v2;
    *(_DWORD *)(result + 24) = 0;
  }
  return result;
}
