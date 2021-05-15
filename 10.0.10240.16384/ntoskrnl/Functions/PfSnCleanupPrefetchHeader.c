// PfSnCleanupPrefetchHeader 
 
int __fastcall PfSnCleanupPrefetchHeader(unsigned int *a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r6
  int v3; // r5

  v1 = a1;
  if ( a1[26] )
  {
    if ( *a1 )
    {
      v2 = 0;
      if ( *(_DWORD *)(*a1 + 88) )
      {
        v3 = 0;
        do
        {
          PfSnCleanupPrefetchSectionInfo(v3 + v1[26], v1, 0);
          ++v2;
          v3 += 32;
        }
        while ( v2 < *(_DWORD *)(*v1 + 88) );
      }
    }
    a1 = (unsigned int *)ExFreePoolWithTag(v1[26]);
  }
  return sub_80696C(a1);
}
