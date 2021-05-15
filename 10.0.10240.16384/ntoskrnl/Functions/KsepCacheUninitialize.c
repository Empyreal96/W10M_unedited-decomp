// KsepCacheUninitialize 
 
int __fastcall KsepCacheUninitialize(int a1)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r6
  _DWORD *v4; // r0

  v2 = *(_DWORD **)(a1 + 20);
  v3 = (_DWORD *)(a1 + 20);
  while ( v2 != v3 )
  {
    v4 = v2 - 3;
    v2 = (_DWORD *)*v2;
    (*(void (__fastcall **)(_DWORD *))(a1 + 56))(v4);
  }
  KsepPoolFreePaged(*(_DWORD *)(a1 + 12));
  return KsepPoolFreePaged(a1);
}
