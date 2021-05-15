// RtlpAllocateSecondLevelDir 
 
int RtlpAllocateSecondLevelDir()
{
  int result; // r0
  _DWORD *v1; // r3
  int v2; // r2

  result = RtlpAllocateSecondLevelDirUsingFreeList();
  if ( result )
  {
    v1 = (_DWORD *)result;
    v2 = 128;
    do
    {
      *v1 = v1;
      v1[1] = v1;
      v1 += 2;
      --v2;
    }
    while ( v2 );
  }
  return result;
}
