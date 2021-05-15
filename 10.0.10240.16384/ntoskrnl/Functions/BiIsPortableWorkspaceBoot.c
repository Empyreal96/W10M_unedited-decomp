// BiIsPortableWorkspaceBoot 
 
int BiIsPortableWorkspaceBoot()
{
  int v0; // r4
  _DWORD *v2; // [sp+8h] [bp-10h] BYREF
  unsigned int v3[3]; // [sp+Ch] [bp-Ch] BYREF

  v0 = 0;
  if ( BiOpenKey(0, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT", 131097, &v2) < 0 )
  {
    if ( BiGetRegistryValue(
           0,
           L"PortableOperatingSystem",
           (int)L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control",
           4,
           (int *)&v2,
           v3) >= 0 )
    {
      if ( *v2 )
        v0 = 1;
      ExFreePoolWithTag((unsigned int)v2);
    }
  }
  else
  {
    BiCloseKey();
  }
  return v0;
}
