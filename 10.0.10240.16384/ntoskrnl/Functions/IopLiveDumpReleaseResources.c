// IopLiveDumpReleaseResources 
 
int __fastcall IopLiveDumpReleaseResources(int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r0
  unsigned int v6; // r0

  v1 = (_DWORD *)result;
  if ( result )
  {
    IopLiveDumpFreeMappingResources(result);
    v2 = v1[57];
    if ( v2 )
    {
      ExFreePoolWithTag(v2);
      v1[57] = 0;
    }
    v3 = v1[61];
    if ( v3 )
    {
      ExFreePoolWithTag(v3);
      v1[61] = 0;
    }
    v4 = v1[64];
    if ( v4 )
    {
      ExFreePoolWithTag(v4);
      v1[64] = 0;
    }
    v5 = v1[67];
    if ( v5 )
    {
      ExFreePoolWithTag(v5);
      v1[67] = 0;
    }
    v6 = v1[18];
    if ( v6 )
    {
      ExFreePoolWithTag(v6);
      v1[18] = 0;
    }
    IopLiveDumpFreeDumpBuffers((unsigned int)(v1 + 68));
    if ( v1[79] )
    {
      ZwClose();
      v1[79] = 0;
    }
    result = v1[80];
    if ( result )
    {
      result = ZwClose();
      v1[80] = 0;
    }
  }
  return result;
}
