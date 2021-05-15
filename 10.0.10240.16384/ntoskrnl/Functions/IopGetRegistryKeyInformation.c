// IopGetRegistryKeyInformation 
 
int __fastcall IopGetRegistryKeyInformation(int a1, int *a2, int a3)
{
  int v4; // r0
  int v5; // r4
  int v7; // r5

  v4 = ZwQueryKey();
  v5 = v4;
  if ( v4 == -2147483643 || v4 == -1073741789 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
      return sub_7E51C0();
    v7 = ExAllocatePoolWithTag(512, a3, 538996553);
    if ( v7 )
    {
      v5 = ZwQueryKey();
      if ( v5 < 0 )
      {
        ExFreePoolWithTag(v7);
      }
      else
      {
        *a2 = v7;
        v5 = 0;
      }
    }
    else
    {
      v5 = -1073741670;
    }
  }
  return v5;
}
