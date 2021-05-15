// ObpLookupNamespaceEntry 
 
_DWORD *__fastcall ObpLookupNamespaceEntry(int a1, int a2)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  _DWORD v6[3]; // [sp+0h] [bp-30h] BYREF
  int v7; // [sp+Ch] [bp-24h]
  int v8; // [sp+10h] [bp-20h]
  int v9; // [sp+14h] [bp-1Ch]

  v3 = (_DWORD *)((char *)&ObpPrivateNamespaceLookupTable + 8 * *(unsigned __int8 *)(a2 + 20));
  v4 = (_DWORD *)*v3;
  if ( (_DWORD *)*v3 == v3 )
    return 0;
  while ( 1 )
  {
    if ( v4[3] == *(_DWORD *)(a2 + 12) && v4[7] == *(_DWORD *)(a2 + 28) )
    {
      v6[0] = v4;
      v6[1] = a2;
      v8 = 0;
      v9 = 0;
      v7 = 0;
      if ( RtlEnumerateBoundaryDescriptorEntries(v4 + 6, ObpCompareEntryLevel1, v6) >= 0 && v9 >= 0 && v8 == v7 )
        break;
    }
    v4 = (_DWORD *)*v4;
    if ( v4 == v3 )
      return 0;
  }
  return v4;
}
