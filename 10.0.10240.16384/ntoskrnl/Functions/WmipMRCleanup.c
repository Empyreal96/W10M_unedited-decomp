// WmipMRCleanup 
 
unsigned int __fastcall WmipMRCleanup(_DWORD *a1)
{
  unsigned __int16 *v2; // r0
  unsigned __int16 *v3; // r1
  unsigned int v4; // r0
  unsigned int result; // r0

  v2 = (unsigned __int16 *)a1[5];
  if ( v2 )
  {
    v3 = (unsigned __int16 *)a1[6];
    if ( v3 && (a1[2] & 1) == 0 )
      WmipGenerateMofResourceNotification(v2, v3, &GUID_MOF_RESOURCE_REMOVED_NOTIFICATION, 1);
    v4 = a1[5];
    if ( v4 )
    {
      ExFreePoolWithTag(v4);
      a1[5] = 0;
    }
  }
  result = a1[6];
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    a1[6] = 0;
  }
  return result;
}
