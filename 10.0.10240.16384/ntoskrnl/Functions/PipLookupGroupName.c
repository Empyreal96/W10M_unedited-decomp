// PipLookupGroupName 
 
int __fastcall PipLookupGroupName(unsigned __int16 *a1, int a2)
{
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r3
  int v7; // r3
  int v8; // r0
  int i; // r4
  int v11; // r0

  v4 = IopGroupListHead;
  if ( IopGroupListHead )
  {
    v5 = *a1;
    while ( 1 )
    {
      v6 = *(unsigned __int16 *)(v4 + 20);
      if ( v5 < v6 )
      {
        v7 = *(_DWORD *)v4;
        if ( !*(_DWORD *)v4 )
        {
          if ( !a2 )
            return 0;
          i = PipCreateEntry(a1);
          *(_DWORD *)v4 = i;
          return i;
        }
      }
      else
      {
        if ( v5 <= v6 )
        {
          if ( RtlEqualUnicodeString(a1, (unsigned __int16 *)(v4 + 20), 1) )
            return v4;
          for ( i = *(_DWORD *)(v4 + 8); i; i = *(_DWORD *)(i + 8) )
          {
            if ( RtlEqualUnicodeString(a1, (unsigned __int16 *)(i + 20), 1) )
              return i;
            v4 = *(_DWORD *)(v4 + 8);
          }
          if ( a2 )
          {
            v11 = PipCreateEntry(a1);
            *(_DWORD *)(v4 + 8) = v11;
            return v11;
          }
          return 0;
        }
        v7 = *(_DWORD *)(v4 + 4);
        if ( !v7 )
        {
          if ( !a2 )
            return 0;
          v8 = PipCreateEntry(a1);
          *(_DWORD *)(v4 + 4) = v8;
          return v8;
        }
      }
      v4 = v7;
    }
  }
  if ( !a2 )
    return 0;
  i = PipCreateEntry(a1);
  IopGroupListHead = i;
  return i;
}
