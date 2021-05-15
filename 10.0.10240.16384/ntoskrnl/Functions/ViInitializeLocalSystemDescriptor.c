// ViInitializeLocalSystemDescriptor 
 
int ViInitializeLocalSystemDescriptor()
{
  _BYTE *v0; // r0
  unsigned int v1; // r5
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r8
  int v5; // r4
  unsigned int v6; // r2

  if ( !ViLocalSystemDescriptor )
  {
    if ( SeLocalSystemSid )
    {
      v0 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1432777302);
      v1 = (unsigned int)v0;
      if ( v0 )
      {
        if ( RtlCreateSecurityDescriptor(v0, 1) < 0 )
          goto LABEL_16;
        v2 = RtlLengthSid(SeLocalSystemSid);
        v3 = ExAllocatePoolWithTag(1, v2 + 20, 1432777302);
        v4 = v3;
        if ( !v3 )
          goto LABEL_16;
        v5 = RtlCreateAcl(v3, v2 + 20, 2);
        if ( v5 < 0 )
          goto LABEL_20;
        v5 = RtlAddAccessAllowedAce(v4, 2, 1, SeLocalSystemSid);
        if ( v5 < 0 )
          goto LABEL_20;
        v5 = RtlSetDaclSecurityDescriptor(v1, 1, v4, 0);
        if ( v5 < 0 )
          goto LABEL_20;
        __dmb(0xBu);
        do
          v6 = __ldrex((unsigned int *)&ViLocalSystemDescriptor);
        while ( !v6 && __strex(v1, (unsigned int *)&ViLocalSystemDescriptor) );
        __dmb(0xBu);
        if ( v6 )
          v5 = -1073741595;
        if ( v5 < 0 )
        {
LABEL_20:
          ExFreePoolWithTag(v4);
          if ( v5 < 0 )
LABEL_16:
            ExFreePoolWithTag(v1);
        }
      }
    }
  }
  return ViLocalSystemDescriptor;
}
