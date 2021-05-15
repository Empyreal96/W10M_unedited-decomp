// CmpFreeLineList 
 
unsigned int __fastcall CmpFreeLineList(unsigned int result)
{
  unsigned int v1; // r4
  unsigned int v2; // r6
  unsigned int v3; // r0
  unsigned int v4; // r5
  unsigned int v5; // r7
  unsigned int v6; // r0

  v1 = result;
  if ( result )
  {
    do
    {
      v2 = *(_DWORD *)v1;
      if ( *(_BYTE *)(v1 + 12) )
      {
        v3 = *(_DWORD *)(v1 + 4);
        if ( v3 )
          ExFreePoolWithTag(v3);
      }
      v4 = *(_DWORD *)(v1 + 8);
      if ( v4 )
      {
        do
        {
          v5 = *(_DWORD *)v4;
          if ( *(_BYTE *)(v4 + 8) )
          {
            v6 = *(_DWORD *)(v4 + 4);
            if ( v6 )
              ExFreePoolWithTag(v6);
          }
          ExFreePoolWithTag(v4);
          v4 = v5;
        }
        while ( v5 );
      }
      result = ExFreePoolWithTag(v1);
      v1 = v2;
    }
    while ( v2 );
  }
  return result;
}
