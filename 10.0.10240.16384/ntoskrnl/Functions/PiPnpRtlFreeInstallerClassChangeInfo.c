// PiPnpRtlFreeInstallerClassChangeInfo 
 
int *__fastcall PiPnpRtlFreeInstallerClassChangeInfo(int *result)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r0
  int v4; // r3

  v1 = result;
  if ( result )
  {
    v2 = *result;
    if ( *v1 )
      PiDmObjectRelease(v2);
    v3 = v1[1];
    if ( v3 )
      PiDmObjectRelease(v3);
    v4 = v1[2];
    if ( v4 )
    {
      PiDmRemoveCacheReferenceForObject(*(_DWORD *)(v4 + 20), *(_DWORD *)(v4 + 12));
      PiDmObjectRelease(v1[2]);
    }
    result = (int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
