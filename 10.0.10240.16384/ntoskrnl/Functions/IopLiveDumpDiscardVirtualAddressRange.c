// IopLiveDumpDiscardVirtualAddressRange 
 
_BYTE *__fastcall IopLiveDumpDiscardVirtualAddressRange(_BYTE *result, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r4
  _BYTE *v5; // r6
  unsigned int v6; // r3
  unsigned int i; // r5
  __int64 v8; // [sp+0h] [bp-18h] BYREF
  int v9; // [sp+8h] [bp-10h]

  v8 = __PAIR64__(a3, a2);
  v9 = a4;
  v4 = a2;
  v5 = result;
  if ( a3 )
  {
    if ( a2 )
    {
      v6 = (a3 & 0xFFF) != 0;
      for ( i = v6 + (a3 >> 12); i; --i )
      {
        result = (_BYTE *)MmIsAddressValid(v4, a2, a3, v6);
        if ( result )
        {
          result = (_BYTE *)MmGetPhysicalAddress((int)&v8, v4, a3, v6);
          a3 = v8;
          a2 = v8 >> 12;
          v6 = *((_DWORD *)v5 + 59);
          if ( a2 < v6 )
            result = RtlClearBits(v5 + 236, a2, 1u);
        }
        v4 += 4096;
      }
    }
  }
  return result;
}
