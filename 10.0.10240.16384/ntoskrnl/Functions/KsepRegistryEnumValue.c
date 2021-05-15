// KsepRegistryEnumValue 
 
__int64 __fastcall KsepRegistryEnumValue(int a1, int a2, unsigned int a3, int a4, unsigned int *a5)
{
  int v7; // r0
  int v8; // r5
  int v9; // r4
  unsigned int v10; // r2

  v7 = ZwEnumerateValueKey();
  v8 = v7;
  if ( v7 == -1073741789 || v7 == -2147483643 )
  {
    v9 = KsepPoolAllocatePaged(0);
    if ( v9 )
    {
      v8 = ZwEnumerateValueKey();
      if ( !v8 )
      {
        v10 = *(_DWORD *)(v9 + 8) + 2;
        if ( v10 <= a3 )
        {
          memmove(a4, v9 + 12, *(_DWORD *)(v9 + 8));
          *(_WORD *)(a4 + 2 * (*(_DWORD *)(v9 + 8) >> 1)) = 0;
          v10 = *(_DWORD *)(v9 + 8) + 2;
        }
        else
        {
          v8 = -1073741789;
        }
        *a5 = v10;
      }
      KsepPoolFreePaged(v9);
    }
    else
    {
      v8 = -1073741801;
    }
  }
  return (unsigned int)v8;
}
