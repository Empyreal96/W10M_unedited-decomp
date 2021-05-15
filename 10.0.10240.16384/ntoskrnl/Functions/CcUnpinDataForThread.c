// CcUnpinDataForThread 
 
unsigned int __fastcall CcUnpinDataForThread(unsigned int a1, int a2)
{
  int v3; // r0
  unsigned int v4; // r5
  int i; // r0
  int v6; // t1

  if ( (a1 & 1) != 0 )
  {
    v3 = a1 & 0xFFFFFFFE;
    return CcUnpinFileDataEx(v3, 1, 0);
  }
  if ( *(_WORD *)a1 != 762 )
  {
    ExReleaseResourceForThreadLite(a1 + 56, a2);
    v3 = a1;
    return CcUnpinFileDataEx(v3, 1, 0);
  }
  v4 = a1 + 16;
  for ( i = *(_DWORD *)(a1 + 16); i; i = v6 )
  {
    CcUnpinData(i);
    v6 = *(_DWORD *)(v4 + 4);
    v4 += 4;
  }
  return ExFreePoolWithTag(a1);
}
