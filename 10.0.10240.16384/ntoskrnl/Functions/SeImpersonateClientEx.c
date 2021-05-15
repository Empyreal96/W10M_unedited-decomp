// SeImpersonateClientEx 
 
int __fastcall SeImpersonateClientEx(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  unsigned int v3; // r5

  v2 = a2;
  if ( *(_BYTE *)(a1 + 16) )
    v3 = *(unsigned __int8 *)(a1 + 17);
  else
    v3 = *(unsigned __int8 *)(a1 + 9);
  if ( !a2 )
    v2 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return PsImpersonateClient(v2, *(_DWORD *)(a1 + 12), 1, v3, *(_DWORD *)(a1 + 4));
}
