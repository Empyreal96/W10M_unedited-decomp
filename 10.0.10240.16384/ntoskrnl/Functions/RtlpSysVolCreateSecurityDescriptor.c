// RtlpSysVolCreateSecurityDescriptor 
 
int __fastcall RtlpSysVolCreateSecurityDescriptor(unsigned int *a1, unsigned __int8 **a2)
{
  _BYTE *v4; // r0
  unsigned int v5; // r6
  int v6; // r4
  int v7; // r4
  int v8; // r0
  unsigned __int8 *v9; // r5
  unsigned int v10; // r0
  char v12[2]; // [sp+8h] [bp-30h] BYREF
  int v13; // [sp+Ah] [bp-2Eh]
  __int16 v14; // [sp+Eh] [bp-2Ah]
  int v15; // [sp+10h] [bp-28h]

  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1399615318);
  v5 = (unsigned int)v4;
  if ( !v4 )
    return -1073741670;
  v6 = RtlCreateSecurityDescriptor(v4, 1);
  if ( v6 >= 0 )
  {
    v12[0] = 1;
    v12[1] = 1;
    v13 = 0;
    v14 = 1280;
    v15 = 18;
    v7 = RtlLengthSid((int)v12);
    v8 = ExAllocatePoolWithTag(1, v7 + 16, 1399615318);
    v9 = (unsigned __int8 *)v8;
    if ( v8 )
    {
      v6 = RtlCreateAcl(v8, v7 + 16, 2);
      v10 = (unsigned int)v9;
      if ( v6 >= 0 )
      {
        v6 = RtlpAddKnownAce(v9, 2u, 3, 0x1FFFFF, v12, 0);
        if ( v6 >= 0 )
        {
          v6 = RtlSetDaclSecurityDescriptor(v5, 1, (int)v9, 0);
          if ( v6 >= 0 )
          {
            v6 = RtlSetControlSecurityDescriptor(v5, 4096, 4096);
            if ( v6 >= 0 )
            {
              *a1 = v5;
              *a2 = v9;
              return 0;
            }
          }
        }
        v10 = (unsigned int)v9;
      }
      ExFreePoolWithTag(v10);
    }
    else
    {
      v6 = -1073741670;
    }
  }
  ExFreePoolWithTag(v5);
  return v6;
}
