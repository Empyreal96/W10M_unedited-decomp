// ExpSaAllocatorInitialize 
 
_BYTE *__fastcall ExpSaAllocatorInitialize(int a1, char a2)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 40);
  if ( (a2 & 1) != 0 )
    *(_DWORD *)(a1 + 36) |= 1u;
  *(_DWORD *)(a1 + 4) = a1 + 4;
  *(_DWORD *)(a1 + 8) = a1 + 4;
  *(_DWORD *)(a1 + 12) = a1 + 12;
  *(_DWORD *)(a1 + 16) = a1 + 12;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 28) = 3;
  return result;
}
