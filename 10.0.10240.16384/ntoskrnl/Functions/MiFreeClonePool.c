// MiFreeClonePool 
 
int MiFreeClonePool()
{
  int v0; // r5
  unsigned int v1; // r6
  int result; // r0
  int v3; // r4

  while ( 1 )
  {
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)&dword_6337B8);
    v3 = result;
    if ( !result )
      break;
    v0 = *(_DWORD *)(result + 12);
    if ( v0 )
    {
      v1 = result;
      do
      {
        MiUnlockPagedAddress(v1);
        v1 += 4096;
        --v0;
      }
      while ( v0 );
    }
    ExFreePoolWithTag(v3);
  }
  return result;
}
