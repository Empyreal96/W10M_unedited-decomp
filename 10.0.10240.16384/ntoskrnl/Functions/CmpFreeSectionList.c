// CmpFreeSectionList 
 
unsigned int __fastcall CmpFreeSectionList(unsigned int result)
{
  unsigned int v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r0

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
      CmpFreeLineList(*(_DWORD *)(v1 + 8));
      result = ExFreePoolWithTag(v1);
      v1 = v2;
    }
    while ( v2 );
  }
  return result;
}
