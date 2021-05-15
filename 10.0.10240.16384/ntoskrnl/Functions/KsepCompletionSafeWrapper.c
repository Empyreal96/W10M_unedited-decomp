// KsepCompletionSafeWrapper 
 
int __fastcall KsepCompletionSafeWrapper(int a1, int a2, _DWORD *a3)
{
  int v4; // r6
  void (__fastcall *v7)(_DWORD, int, _DWORD); // r3
  bool v8; // zf
  int (__fastcall *v9)(int, int, _DWORD); // r3

  v4 = 0;
  if ( a3 )
  {
    v7 = (void (__fastcall *)(_DWORD, int, _DWORD))a3[1];
    if ( v7 )
      v7(*a3, a2, a3[2]);
  }
  if ( *(int *)(a2 + 24) < 0 )
    v8 = (a3[5] & 0x80) == 0;
  else
    v8 = (a3[5] & 0x40) == 0;
  if ( !v8 || *(_BYTE *)(a2 + 36) && (a3[5] & 0x20) != 0 )
  {
    v9 = (int (__fastcall *)(int, int, _DWORD))a3[3];
    if ( v9 )
      v4 = v9(a1, a2, a3[4]);
  }
  else if ( *(_BYTE *)(a2 + 33) )
  {
    v4 = 259;
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  }
  KsepPoolFreeNonPaged((int)a3);
  return v4;
}
