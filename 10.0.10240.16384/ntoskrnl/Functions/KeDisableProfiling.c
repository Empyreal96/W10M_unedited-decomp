// KeDisableProfiling 
 
int __fastcall KeDisableProfiling(int a1, int a2)
{
  int v3; // r3
  int result; // r0
  unsigned __int8 *v5; // r1
  unsigned int v6; // r3
  unsigned int v7; // r3
  int v8; // r0

  v3 = *(_DWORD *)(a1 + 236);
  result = -1073741054;
  if ( v3 )
  {
    if ( *(_DWORD *)(v3 + 8) == a2 )
    {
      __dmb(0xBu);
      v5 = (unsigned __int8 *)(a1 + 2);
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 & 0xFD, v5) );
      __dmb(0xBu);
      do
        v7 = __ldrex(v5);
      while ( __strex(v7 & 0xFE, v5) );
      __dmb(0xBu);
      v8 = *(_DWORD *)(a1 + 236);
      *(_DWORD *)(a1 + 236) = 0;
      ExFreePoolWithTag(v8);
      result = 0;
    }
    else
    {
      result = -1073741811;
    }
  }
  return result;
}
