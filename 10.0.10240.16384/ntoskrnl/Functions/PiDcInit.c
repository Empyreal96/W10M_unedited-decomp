// PiDcInit 
 
int __fastcall PiDcInit(int a1)
{
  int v1; // r4

  v1 = 0;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v1 = PiDcInitUpdateProperties();
      if ( v1 >= 0 )
        v1 = PiDcGenerateConfigNotificationIfContainerRequiresConfiguration((int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}");
    }
  }
  else
  {
    RtlInitializeGenericTableAvl(
      (int)&PiDcUpdateProperties,
      (unsigned int)PiDcCompareDevPropKeys,
      (unsigned int)PiDcAllocateGenericTableEntry,
      (int)PiDcFreeGenericTableEntry,
      0);
  }
  return v1;
}
