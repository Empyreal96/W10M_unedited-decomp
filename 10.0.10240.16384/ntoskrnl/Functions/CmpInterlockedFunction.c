// CmpInterlockedFunction 
 
int CmpInterlockedFunction()
{
  int v0; // r4
  char v2[56]; // [sp+30h] [bp-38h] BYREF

  v0 = ZwOpenKey();
  if ( v0 >= 0 )
  {
    v0 = ZwOpenKey();
    ZwClose();
    if ( v0 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v2, L"ProcessorControl");
      v0 = ZwQueryValueKey();
      if ( v0 < 0 )
        JUMPOUT(0x80B52A);
      if ( v2[28] != 2 )
        return sub_80B520();
      ZwClose();
    }
  }
  return v0;
}
