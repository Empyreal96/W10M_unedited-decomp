// AuthzBasepSetSecurityAttributesToken 
 
int __fastcall AuthzBasepSetSecurityAttributesToken(int a1, int *a2, int a3)
{
  int v3; // r6
  int *v5; // r9
  int v8; // r4
  unsigned int v9; // r10
  int v10; // r8
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r1

  v3 = 0;
  v5 = a2;
  if ( *a2 == 1 )
    v3 = 1;
  if ( !a3 )
    return sub_52ABA4();
  v8 = AuthzBasepValidateSecurityAttributes(a3, a2);
  if ( v8 < 0 )
  {
LABEL_23:
    v14 = 0;
  }
  else
  {
    if ( v3 )
      AuthzBasepDeleteAllSecurityAttributes(a1);
    v9 = 0;
    if ( *(_DWORD *)(a3 + 4) )
    {
      v10 = 0;
      do
      {
        v11 = *(_DWORD *)(a3 + 8);
        if ( !v3 )
        {
          v12 = *v5;
          if ( *v5 == 2 )
          {
            v13 = AuthzBasepAddSecurityAttribute(a1, v10 + v11);
            goto LABEL_16;
          }
          if ( !v12 )
          {
            v8 = 0;
            goto LABEL_17;
          }
          if ( v12 == 3 )
          {
            v13 = AuthzBasepDeleteSecurityAttribute(a1, v10 + v11);
            goto LABEL_16;
          }
          if ( v12 != 4 )
            JUMPOUT(0x52ABB2);
        }
        v13 = AuthzBasepReplaceSecurityAttribute(a1, v10 + v11);
LABEL_16:
        v8 = v13;
LABEL_17:
        if ( v8 < 0 )
          goto LABEL_23;
        ++v9;
        v10 += 24;
        ++v5;
      }
      while ( v9 < *(_DWORD *)(a3 + 4) );
    }
    v14 = 1;
  }
  AuthzBasepFinaliseSecurityAttributesList(a1, v14);
  return v8;
}
