// AlpcpCheckConnectionSecurity 
 
int __fastcall AlpcpCheckConnectionSecurity(_DWORD *a1, char a2, unsigned __int16 *a3, int a4)
{
  int v8; // r4
  int v10; // r6
  int v11; // [sp+18h] [bp-80h] BYREF
  int v12; // [sp+1Ch] [bp-7Ch] BYREF
  int v13[4]; // [sp+20h] [bp-78h] BYREF
  unsigned __int16 v14[52]; // [sp+30h] [bp-68h] BYREF

  if ( !a3 )
    goto LABEL_21;
  v11 = 0;
  v10 = PsReferencePrimaryToken(a1);
  v8 = SeQueryInformationToken(v10, 29, &v11);
  v12 = v8;
  if ( v8 >= 0 )
  {
    if ( v11 )
    {
      v8 = -1073741152;
      v12 = -1073741152;
    }
    if ( v8 >= 0 )
      SeQueryUserSidToken(v10, (int)v14, 0x44u, 0);
  }
  ObFastDereferenceObject(a1 + 61, v10);
  if ( v8 >= 0 )
  {
    if ( !RtlEqualSid(a3, v14) )
    {
      v8 = -1073741152;
      v12 = -1073741152;
    }
    if ( v8 >= 0 )
    {
LABEL_21:
      if ( !a4
        || ((SeCaptureSubjectContextEx(0, a1, v13),
             SeAccessCheck(a4, (int)v13, 0, 0x2000000, 0, 0, AlpcPortObjectType + 52, a2, (int)&v11, (int)&v12),
             RtlMapGenericMask(&v11, AlpcPortObjectType + 52),
             (v11 & 1) == 0) ? (v8 = -1073741152) : (v8 = v12),
            SeReleaseSubjectContext((int)v13),
            v8 >= 0) )
      {
        v8 = 0;
      }
    }
  }
  return v8;
}
