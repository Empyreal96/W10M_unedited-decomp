// FstubFreeDiskInformation 
 
int __fastcall FstubFreeDiskInformation(unsigned int a1)
{
  unsigned int v2; // r0

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 40);
    if ( v2 )
    {
      ExFreePoolWithTag(v2);
      *(_DWORD *)(a1 + 40) = 0;
    }
    ExFreePoolWithTag(a1);
  }
  return 0;
}
