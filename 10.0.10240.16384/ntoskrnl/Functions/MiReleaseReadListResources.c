// MiReleaseReadListResources 
 
unsigned int __fastcall MiReleaseReadListResources(int a1)
{
  __int64 v1; // r4
  unsigned int result; // r0
  int v3; // r1
  __int64 v4; // r2
  unsigned int v5; // r7
  int v6; // r6

  HIDWORD(v1) = a1;
  LODWORD(v1) = *(_DWORD *)(a1 + 4);
  result = MiFreeReadListPages(a1);
  if ( (*(_DWORD *)(v1 + 28) & 0x20) == 0 )
  {
    LODWORD(v1) = HIDWORD(v1) + 12;
    while ( *(_DWORD *)v1 != (_DWORD)v1 )
    {
      HIDWORD(v1) = *(_DWORD *)v1;
      v4 = *(_QWORD *)*(_DWORD *)v1;
      if ( __PAIR64__(*(_DWORD *)(v4 + 4), HIDWORD(v4)) != v1 )
        sub_805FE8(result);
      *(_DWORD *)v1 = v4;
      *(_DWORD *)(v4 + 4) = v1;
      v5 = 0;
      if ( *(_DWORD *)(HIDWORD(v1) + 8) )
      {
        v6 = HIDWORD(v1);
        do
        {
          MiRemoveViewsFromSectionWithPfn(*(_DWORD **)(v6 + 12), v3, *(_DWORD *)(*(_DWORD *)(v6 + 12) + 28), 0);
          ++v5;
          v6 += 4;
        }
        while ( v5 < *(_DWORD *)(HIDWORD(v1) + 8) );
      }
      result = ExFreePoolWithTag(HIDWORD(v1));
    }
  }
  return result;
}
