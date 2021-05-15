// SepInitProcessAuditSd 
 
int __fastcall SepInitProcessAuditSd(int a1, int a2, int a3)
{
  int v3; // r4
  int result; // r0
  int v5; // r8
  int v6; // r0
  int v7; // r6
  int v8; // r1
  int v9; // r1
  int v10; // r7
  int v11; // r0

  v3 = 0;
  result = SepProcessAuditSd;
  if ( SepProcessAuditSd )
    return sub_550664();
  if ( SepProcessAccessesToAudit )
  {
    v5 = 4 * (*(unsigned __int8 *)(SeWorldSid + 1) + 6);
    v6 = ExAllocatePoolWithTag(1, v5 + 20);
    v7 = v6;
    if ( v6 )
    {
      result = RtlCreateAcl(v6 + 20, v5, 2);
      if ( result < 0 )
        goto LABEL_20;
      result = RtlAddAuditAccessAce(v7 + 20, v8, SepProcessAccessesToAudit, SeWorldSid);
      if ( result < 0 )
        goto LABEL_20;
      result = RtlCreateSecurityDescriptor(v7, 1);
      if ( result < 0 )
        goto LABEL_20;
      result = RtlSetSaclSecurityDescriptor(v7, 1, v7 + 20, 0);
      if ( result < 0 )
        goto LABEL_20;
      v9 = *(unsigned __int8 *)(SeIUserSid + 1);
      SepProcessAuditSd = v7;
      v10 = 4
          * (*(unsigned __int8 *)(SeLocalSystemSid + 1)
           + v9
           + *(unsigned __int8 *)(SeNetworkServiceSid + 1)
           + *(unsigned __int8 *)(SeLocalServiceSid + 1)
           + 18);
      v11 = ExAllocatePoolWithTag(1, v10 + 20);
      v3 = v11;
      if ( v11 )
      {
        result = RtlCreateAcl(v11 + 20, v10, 2);
        if ( result >= 0 )
        {
          result = RtlAddAccessAllowedAce(v3 + 20, 2, 1, SeLocalSystemSid);
          if ( result >= 0 )
          {
            result = RtlAddAccessAllowedAce(v3 + 20, 2, 1, SeLocalServiceSid);
            if ( result >= 0 )
            {
              result = RtlAddAccessAllowedAce(v3 + 20, 2, 1, SeNetworkServiceSid);
              if ( result >= 0 )
              {
                result = RtlAddAccessAllowedAce(v3 + 20, 2, 1, SeIUserSid);
                if ( result >= 0 )
                {
                  result = RtlCreateSecurityDescriptor(v3, 1);
                  if ( result >= 0 )
                  {
                    result = RtlSetDaclSecurityDescriptor(v3, 1, v3 + 20, 0, a3);
                    if ( result >= 0 )
                    {
                      SepImportantProcessSd = v3;
                      return result;
                    }
                  }
                }
              }
            }
          }
        }
        goto LABEL_20;
      }
    }
    result = -1073741670;
LABEL_20:
    result = SepAuditFailed(result);
    if ( v7 )
    {
      result = ExFreePoolWithTag(v7, 0);
      SepProcessAuditSd = 0;
    }
    if ( v3 )
    {
      result = ExFreePoolWithTag(v3, 0);
      SepImportantProcessSd = 0;
    }
  }
  return result;
}
