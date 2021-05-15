// PiDevCfgGetKeySecurityDescriptor 
 
int __fastcall PiDevCfgGetKeySecurityDescriptor(int a1, _DWORD *a2)
{
  int v2; // r0
  int v3; // r4
  unsigned __int8 *v4; // r5
  unsigned int v5; // r4
  int v6; // r6
  __int16 v8; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+Ch] [bp-24h]
  int v10[8]; // [sp+10h] [bp-20h] BYREF

  *a2 = 0;
  v2 = ZwQuerySecurityObject();
  v3 = v2;
  if ( v2 == -1073741789 || v2 >= 0 )
  {
    v4 = (unsigned __int8 *)ExAllocatePoolWithTag(1, v9, 1667526736);
    if ( v4 )
    {
      v3 = ZwQuerySecurityObject();
      if ( v3 >= 0 )
      {
        v3 = RtlGetControlSecurityDescriptor(v4, &v8, v10);
        if ( v3 >= 0 )
        {
          if ( (v8 & 4) != 0 )
          {
            v3 = RtlGetGroupSecurityDescriptor(v4, v10, &v8);
            if ( v3 >= 0 )
            {
              v5 = v10[0];
              if ( v10[0] )
              {
                v6 = RtlLengthSid(v10[0]);
                v9 = v6;
                if ( v6 == RtlLengthSid((int)PiDevCfgNullSid) && !memcmp(v5, (unsigned int)PiDevCfgNullSid, v6) )
                  return sub_7E51F4();
                v3 = -1073741720;
              }
              else
              {
                v3 = -1073741722;
              }
            }
          }
          else
          {
            v3 = -1073741275;
          }
        }
      }
      ExFreePoolWithTag((unsigned int)v4);
    }
    else
    {
      v3 = -1073741670;
    }
  }
  return v3;
}
