// PfpCreateEvent 
 
int __fastcall PfpCreateEvent(int a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r4
  int v7; // r4
  int v8; // r0
  unsigned int v9; // r5
  int v11; // [sp+Ch] [bp-54h] BYREF
  char v12[24]; // [sp+10h] [bp-50h] BYREF
  int v13; // [sp+28h] [bp-38h]
  int v14; // [sp+2Ch] [bp-34h]
  int v15; // [sp+30h] [bp-30h]
  int v16; // [sp+34h] [bp-2Ch]
  char *v17; // [sp+38h] [bp-28h]
  int v18; // [sp+3Ch] [bp-24h]

  v5 = RtlCreateSecurityDescriptor(v12, 1);
  if ( v5 >= 0 )
  {
    v6 = RtlLengthSid(SeAliasAdminsSid);
    v7 = v6 + RtlLengthSid(SeLocalSystemSid);
    v8 = ExAllocatePoolWithTag(1, v7 + 32, 1818452292);
    v9 = v8;
    if ( v8 )
    {
      v5 = RtlCreateAcl(v8, v7 + 32, 2);
      if ( v5 >= 0 )
      {
        v5 = RtlAddAccessAllowedAce(v9, 2, 2031619, SeAliasAdminsSid);
        if ( v5 >= 0 )
        {
          v5 = RtlAddAccessAllowedAce(v9, 2, 2031619, SeLocalSystemSid);
          if ( v5 >= 0 )
          {
            v5 = RtlSetDaclSecurityDescriptor((int)v12, 1, v9, 0);
            if ( v5 >= 0 )
            {
              v13 = 24;
              v14 = 0;
              v15 = a1;
              v16 = 656;
              v17 = v12;
              v18 = 0;
              v5 = ZwCreateEvent();
              if ( v5 >= 0 )
              {
                v5 = ObReferenceObjectByHandle(0, 2031619, ExEventObjectType, 0, (int)&v11, 0);
                if ( v5 >= 0 )
                  v5 = 0;
                *a3 = v11;
              }
            }
          }
        }
      }
    }
    else
    {
      v5 = -1073741670;
    }
    if ( v9 )
      ExFreePoolWithTag(v9);
  }
  return v5;
}
