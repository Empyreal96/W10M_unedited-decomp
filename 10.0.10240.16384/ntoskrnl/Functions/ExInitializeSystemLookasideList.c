// ExInitializeSystemLookasideList 
 
_DWORD *__fastcall ExInitializeSystemLookasideList(int a1, int a2, int a3, int a4, __int16 a5, int a6)
{
  _DWORD *v6; // r2
  _DWORD *result; // r0

  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 28) = a2;
  *(_DWORD *)(a1 + 32) = a4;
  *(_DWORD *)(a1 + 36) = a3;
  *(_DWORD *)(a1 + 40) = ExAllocatePoolWithTag;
  v6 = (_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 44) = ExFreePool;
  *(_WORD *)(a1 + 8) = 2;
  *(_WORD *)(a1 + 10) = a5;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  result = *(_DWORD **)(a6 + 4);
  *v6 = a6;
  v6[1] = result;
  if ( *result != a6 )
    sub_694144();
  *result = v6;
  *(_DWORD *)(a6 + 4) = v6;
  return result;
}
