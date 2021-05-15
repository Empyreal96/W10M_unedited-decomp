// PiAuCreateStandardSecurityObject 
 
int __fastcall PiAuCreateStandardSecurityObject(int *a1)
{
  unsigned __int8 *v2; // r5
  int v3; // r6
  unsigned int *v4; // r8
  unsigned int v5; // r10
  int *v6; // r9
  int v7; // r4
  unsigned int v8; // r1
  int v9; // r2
  unsigned int *v10; // r0
  unsigned int v11; // t1
  _BYTE *v12; // t1
  int v13; // r4
  char *v14; // r2
  int v15; // r1
  int v16; // t1
  int v17; // r0
  int v18; // r8
  int *v19; // r9
  int v20; // t1
  int v21; // r1
  unsigned int v22; // r0
  int v23; // r4
  _BYTE *v24; // r0
  char *v25; // r8
  int v26; // r7
  unsigned int v27; // r0
  unsigned int v28; // t1
  int result; // r0
  unsigned int v30; // [sp+8h] [bp-80h] BYREF
  char v31; // [sp+Ch] [bp-7Ch]
  char v32; // [sp+Dh] [bp-7Bh]
  char v33[24]; // [sp+10h] [bp-78h] BYREF
  char v34[96]; // [sp+28h] [bp-60h] BYREF

  v30 = 0;
  v31 = 0;
  v32 = 5;
  v2 = 0;
  v3 = 0;
  memset(v34, 0, 64);
  v4 = (unsigned int *)&PiAuSwDeviceCreateSidSubAuthorities;
  v5 = 0;
  v6 = (int *)v34;
  while ( 1 )
  {
    v7 = PiAuAllocateAndInitializeSid(v6, (int)&v30, *v4);
    if ( v7 < 0 )
      break;
    v8 = 0;
    if ( *v4 )
    {
      v9 = *v6;
      v10 = v4;
      do
      {
        v11 = v10[1];
        ++v10;
        ++v8;
        *(_DWORD *)(v9 + 8) = v11;
        v9 += 4;
      }
      while ( v8 < *v4 );
    }
    v12 = (_BYTE *)*v6++;
    if ( !RtlValidSid(v12) )
    {
LABEL_40:
      v7 = -1073741595;
      break;
    }
    ++v5;
    v4 += 7;
    if ( v5 >= 0x10 )
    {
      v13 = 4
          * (*(unsigned __int8 *)(*a1 + 1)
           + *(unsigned __int8 *)(a1[6] + 1)
           + *(unsigned __int8 *)(a1[5] + 1)
           + *(unsigned __int8 *)(a1[4] + 1)
           + *(unsigned __int8 *)(a1[3] + 1)
           + *(unsigned __int8 *)(a1[2] + 1)
           + 26);
      v14 = v34;
      v15 = 16;
      do
      {
        v16 = *(_DWORD *)v14;
        v14 += 4;
        v13 += 4 * (*(unsigned __int8 *)(v16 + 1) + 4);
        --v15;
      }
      while ( v15 );
      v17 = ExAllocatePoolWithTag(1, v13, 538996816);
      v2 = (unsigned __int8 *)v17;
      if ( v17 )
      {
        v7 = RtlCreateAcl(v17, v13, 2);
        if ( v7 >= 0 )
        {
          v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 131303, a1[2]);
          if ( v7 >= 0 )
          {
            v7 = RtlAddAccessDeniedAceEx(v2, 2u, 0, 983295, (_BYTE *)a1[3]);
            if ( v7 >= 0 )
            {
              v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 983295, *a1);
              if ( v7 >= 0 )
              {
                v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 131109, a1[4]);
                if ( v7 >= 0 )
                {
                  v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 64, a1[5]);
                  if ( v7 >= 0 )
                  {
                    v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 64, a1[6]);
                    if ( v7 >= 0 )
                    {
                      v18 = 0;
                      v19 = (int *)v34;
                      while ( 1 )
                      {
                        v20 = *v19++;
                        v7 = RtlAddAccessAllowedAceEx((int)v2, 2, 0, 128, v20);
                        if ( v7 < 0 )
                          break;
                        if ( (unsigned int)++v18 >= 0x10 )
                        {
                          v7 = RtlCreateSecurityDescriptor(v33, 1);
                          if ( v7 >= 0 )
                          {
                            v7 = RtlSetDaclSecurityDescriptor((int)v33, 1, (int)v2, 0);
                            if ( v7 >= 0 )
                            {
                              v7 = RtlSetOwnerSecurityDescriptor((int)v33, *a1, 0);
                              if ( v7 >= 0 )
                              {
                                v7 = RtlSetGroupSecurityDescriptor((int)v33, *a1, 0);
                                if ( v7 >= 0 )
                                {
                                  if ( !RtlValidSecurityDescriptor((int)v33, v21) )
                                    goto LABEL_40;
                                  v22 = RtlLengthSecurityDescriptor((int)v33);
                                  v23 = v22;
                                  v30 = v22;
                                  if ( v22 < 0x14 )
                                    goto LABEL_40;
                                  v24 = (_BYTE *)ExAllocatePoolWithTag(1, v22, 538996816);
                                  v3 = (int)v24;
                                  if ( !v24 )
                                    goto LABEL_39;
                                  memset(v24, 0, v23);
                                  v7 = RtlAbsoluteToSelfRelativeSD((int)v33);
                                  if ( v7 >= 0 )
                                  {
                                    PiAuSecurityObject = v3;
                                    v3 = 0;
                                  }
                                }
                              }
                            }
                          }
                          goto LABEL_30;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
LABEL_39:
        v7 = -1073741670;
      }
      break;
    }
  }
LABEL_30:
  v25 = v34;
  v26 = 16;
  do
  {
    v28 = *(_DWORD *)v25;
    v25 += 4;
    v27 = v28;
    if ( v28 )
      ExFreePoolWithTag(v27);
    --v26;
  }
  while ( v26 );
  if ( v2 )
    ExFreePoolWithTag((unsigned int)v2);
  if ( v3 )
    result = sub_96E498();
  else
    result = v7;
  return result;
}
