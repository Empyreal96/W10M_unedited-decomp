// sub_96ECAC 
 
void sub_96ECAC()
{
  int v0; // r4
  int v1; // r6

  if ( ZwCreateKey() >= 0 )
  {
    v0 = ZwEnumerateValueKey();
    v1 = 1;
    if ( v0 < 0 )
    {
LABEL_5:
      if ( v0 == -2147483622 )
        v0 = 0;
      if ( v0 >= 0 )
        ZwDeleteKey();
    }
    else
    {
      while ( ZwSetValueKey() >= 0 )
      {
        v0 = ZwEnumerateValueKey();
        ++v1;
        if ( v0 < 0 )
          goto LABEL_5;
      }
    }
    ZwClose();
  }
  ZwClose();
  JUMPOUT(0x962332);
}
