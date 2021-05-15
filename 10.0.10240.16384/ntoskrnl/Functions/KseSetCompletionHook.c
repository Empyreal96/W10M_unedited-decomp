// KseSetCompletionHook 
 
int __fastcall KseSetCompletionHook(int a1, int a2, int a3, int a4)
{
  _DWORD *v8; // r0
  int v10; // r2

  v8 = (_DWORD *)KsepPoolAllocateNonPaged(24);
  if ( !v8 )
    return -1073741670;
  v10 = *(_DWORD *)(a2 + 96);
  *v8 = a1;
  v8[1] = a3;
  v8[2] = a4;
  v8[3] = *(_DWORD *)(v10 + 32);
  v8[4] = *(_DWORD *)(v10 + 36);
  v8[5] = *(unsigned __int8 *)(v10 + 3);
  *(_DWORD *)(v10 + 32) = KsepCompletionSafeWrapper;
  *(_DWORD *)(v10 + 36) = v8;
  *(_BYTE *)(v10 + 3) = -32;
  return 0;
}
