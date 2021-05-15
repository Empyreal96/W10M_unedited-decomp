// ExpCreateRestrictedFastCacheRegistryKey 
 
int __fastcall ExpCreateRestrictedFastCacheRegistryKey(unsigned __int16 *a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r4
  int v10; // [sp+10h] [bp-50h]
  char v11[24]; // [sp+18h] [bp-48h] BYREF
  int v12; // [sp+30h] [bp-30h]
  int v13; // [sp+34h] [bp-2Ch]
  int *v14; // [sp+38h] [bp-28h]
  int v15; // [sp+3Ch] [bp-24h]
  char *v16; // [sp+40h] [bp-20h]
  int v17; // [sp+44h] [bp-1Ch]

  v4 = RtlLengthSid(SeAliasAdminsSid);
  v5 = v4 + RtlLengthSid(SeLocalSystemSid);
  v6 = ExAllocatePoolWithTag(1, v5 + 24, 542329939);
  v7 = v6;
  if ( v6 )
  {
    v8 = RtlCreateAcl(v6, v5 + 24, 2);
    if ( v8 >= 0 )
    {
      v8 = RtlAddAccessAllowedAce(v7, 2, 0x10000000, SeLocalSystemSid);
      if ( v8 >= 0 )
      {
        v8 = RtlAddAccessAllowedAce(v7, 2, 0x10000000, SeAliasAdminsSid);
        if ( v8 >= 0 )
        {
          v8 = RtlCreateSecurityDescriptor(v11, 1);
          if ( v8 >= 0 )
          {
            v8 = RtlSetDaclSecurityDescriptor((int)v11, 1, v7, 0);
            if ( v8 >= 0 )
            {
              if ( !RtlCompareUnicodeString(a1, (unsigned __int16 *)&dword_8C821C, 0) )
                goto LABEL_11;
              v12 = 24;
              v13 = 0;
              v14 = &dword_8C821C;
              v15 = 576;
              v16 = v11;
              v17 = 0;
              v8 = ZwCreateKey();
              if ( v8 >= 0 )
              {
                ZwClose();
LABEL_11:
                v12 = 24;
                v13 = 0;
                v14 = (int *)a1;
                v15 = 576;
                v16 = v11;
                v17 = 0;
                v8 = ZwCreateKey();
                if ( v8 >= 0 )
                  *a2 = v10;
                goto LABEL_13;
              }
            }
          }
        }
      }
    }
LABEL_13:
    ExFreePoolWithTag(v7);
    return v8;
  }
  return -1073741801;
}
