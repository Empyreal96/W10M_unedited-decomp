// SepInitQuerySigningPolicyExt 
 
int SepInitQuerySigningPolicyExt()
{
  char v1; // [sp+10h] [bp-14h]

  SeQuerySigningPolicyExtAllowed = 0;
  SeFailIfExtensionNotSupported = 0;
  if ( ZwQuerySystemInformation() < 0 )
    JUMPOUT(0x81C56A);
  SeQuerySigningPolicyExtAllowed = (v1 & 0x40) != 0;
  if ( (v1 & 0x40) == 0 )
    return sub_81C550();
  SeFailIfExtensionNotSupported = 1;
  return 1;
}
