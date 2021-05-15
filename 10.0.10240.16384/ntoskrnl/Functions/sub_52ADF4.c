// sub_52ADF4 
 
void __fastcall sub_52ADF4(int a1, int a2, int a3, int a4, char a5)
{
  _DWORD *v5; // r4
  int v6; // r6
  _DWORD *v7; // r7
  int v8; // r3

  if ( (v5[8] & 4) != 0 )
    JUMPOUT(0x46ADBC);
  AuthzBasepAddSecurityAttributeToLists(v7, v5, 0, 1);
  if ( *(_DWORD *)(v6 + 16) )
  {
    if ( AuthzBasepDeleteSecurityAttributeValues(v5, v6, &a5) < 0 )
      goto LABEL_11;
    if ( a5 )
      v5[8] |= 4u;
  }
  else
  {
    v5[8] |= 4u;
    AuthzBasepDeleteAllSecurityAttributeValues(v5);
  }
  v8 = v5[8];
  if ( (v8 & 4) != 0 && (v8 & 1) == 0 )
  {
    AuthzBasepRemoveSecurityAttributeFromLists(v7, v5, 0, 1);
    AuthzBasepFreeSecurityAttributeValues((int)v5, 0);
    ExFreePoolWithTag(v5, 0);
  }
LABEL_11:
  JUMPOUT(0x46ADBE);
}
