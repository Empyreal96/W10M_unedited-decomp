// PopFxEnumerateUnmaskedInterruptsCallback 
 
int __fastcall PopFxEnumerateUnmaskedInterruptsCallback(int a1, int a2)
{
  int v2; // r4
  int v3; // r2
  int v5; // r3

  v2 = *(_DWORD *)(a1 + 8);
  v3 = *(_DWORD *)(a2 + 24);
  if ( v2 && v2 != *(_DWORD *)(v3 + 36) )
    return 1;
  if ( *(_DWORD *)(v3 + 36) )
    v5 = *(_DWORD *)(v3 + 40);
  else
    v5 = 0;
  *(_DWORD *)(a2 + 24) = v5;
  return (*(int (__fastcall **)(_DWORD))a1)(*(_DWORD *)(a1 + 4));
}
