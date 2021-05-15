// IopSymlinkFreeRelatedMountPointChain 
 
unsigned int __fastcall IopSymlinkFreeRelatedMountPointChain(int a1)
{
  unsigned int result; // r0
  unsigned int v3; // r4

  result = *(_DWORD *)(a1 + 8);
  if ( result )
  {
    do
    {
      v3 = *(_DWORD *)(result + 8);
      ExFreePoolWithTag(result);
      result = v3;
    }
    while ( v3 );
  }
  *(_DWORD *)(a1 + 8) = 0;
  return result;
}
