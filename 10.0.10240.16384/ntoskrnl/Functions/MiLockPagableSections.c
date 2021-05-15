// MiLockPagableSections 
 
int *__fastcall MiLockPagableSections(int *a1, int a2)
{
  unsigned int v2; // r6
  int *result; // r0
  int v5; // r5
  int *v6; // r4

  v2 = a1[6];
  result = MiImagePagable(a1, v2);
  if ( result )
  {
    result = (int *)RtlImageNtHeader(v2);
    v5 = *((unsigned __int16 *)result + 3);
    v6 = (int *)((char *)result + *((unsigned __int16 *)result + 10) + 24);
    while ( v5 )
    {
      result = (int *)MmImageSectionPagable(v6);
      if ( result )
      {
        if ( a2 != 1 )
          return (int *)sub_96A8B0();
        result = (int *)MmLockPagableDataSection(v6[3] + v2);
      }
      --v5;
      v6 += 10;
    }
  }
  return result;
}
