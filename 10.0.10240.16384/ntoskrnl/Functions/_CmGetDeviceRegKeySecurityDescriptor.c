// _CmGetDeviceRegKeySecurityDescriptor 
 
int __fastcall CmGetDeviceRegKeySecurityDescriptor(_DWORD *a1, int a2, int *a3)
{
  int v3; // r4
  unsigned __int8 *v4; // r5
  int v5; // r6
  int v7; // r0
  int v8; // r2
  int v10; // r5
  int v11; // r4
  int v12; // r4
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // [sp+8h] [bp-90h] BYREF
  char v17; // [sp+Ch] [bp-8Ch]
  char v18; // [sp+Dh] [bp-8Bh]
  char v19; // [sp+10h] [bp-88h]
  char v20; // [sp+11h] [bp-87h]
  char v21; // [sp+12h] [bp-86h]
  char v22; // [sp+13h] [bp-85h]
  char v23; // [sp+14h] [bp-84h]
  char v24; // [sp+15h] [bp-83h]
  char v25[8]; // [sp+18h] [bp-80h] BYREF
  char v26[2]; // [sp+20h] [bp-78h] BYREF
  __int16 v27; // [sp+22h] [bp-76h]
  char v28[16]; // [sp+38h] [bp-60h] BYREF
  char v29[16]; // [sp+48h] [bp-50h] BYREF
  char v30[16]; // [sp+58h] [bp-40h] BYREF

  v16 = 0;
  v17 = 0;
  v18 = 5;
  v25[0] = 0;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v25[4] = 0;
  v25[5] = 1;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v24 = 15;
  if ( !a2 || (a2 & 0xFFFFFCE8) != 0 )
  {
    v3 = -1073741811;
    goto LABEL_39;
  }
  *a3 = 0;
  if ( (a2 & 0xF00) == 0 && ((unsigned __int8)a2 == 19 || (unsigned __int8)a2 == 17 || (unsigned __int8)a2 == 20) )
  {
    v7 = SysCtxIsVersionAvailable(*a1);
    if ( v8 == 17 )
      return sub_7EF5D0(v7);
    v3 = RtlInitializeSid((int)v29, (int)&v16, 1u);
    if ( v3 >= 0 )
    {
      *(_DWORD *)RtlSubAuthoritySid((int)v29, 0) = 18;
      if ( !RtlValidSid(v29) )
        return -1073741762;
      v3 = RtlInitializeSid((int)v30, (int)v25, 1u);
      if ( v3 < 0 )
        return v3;
      *(_DWORD *)RtlSubAuthoritySid((int)v30, 0) = 0;
      if ( !RtlValidSid(v30) )
        return -1073741762;
      v3 = RtlInitializeSid((int)v28, (int)&v16, 2u);
      if ( v3 < 0 )
        return v3;
      *(_DWORD *)RtlSubAuthoritySid((int)v28, 0) = 32;
      *(_DWORD *)RtlSubAuthoritySid((int)v28, 1) = 544;
      if ( !RtlValidSid(v28) )
        return -1073741762;
      v10 = RtlLengthSid((int)v29);
      v11 = RtlLengthSid((int)v30);
      v12 = RtlLengthSid((int)v28) + v11 + v10 + 32;
      v13 = ExAllocatePoolWithTag(1, v12, 1380994640);
      v4 = (unsigned __int8 *)v13;
      if ( v13 )
      {
        v3 = RtlCreateAcl(v13, v12, 2);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlpAddKnownAce(v4, 2u, 2, 983103, v29, 0);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlpAddKnownAce(v4, 2u, 2, 131097, v30, 0);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlpAddKnownAce(v4, 2u, 2, 983103, v28, 0);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlCreateSecurityDescriptor(v26, 1);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlSetDaclSecurityDescriptor((int)v26, 1, (int)v4, 0);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlSetOwnerSecurityDescriptor((int)v26, (int)v28, 1);
        if ( v3 < 0 )
          goto LABEL_27;
        v3 = RtlSetGroupSecurityDescriptor((int)v26, (int)v28, 1);
        if ( v3 < 0 )
          goto LABEL_27;
        v27 |= 0x1500u;
        if ( RtlValidSecurityDescriptor((int)v26, v14) )
        {
          v15 = RtlLengthSecurityDescriptor((int)v26);
          v16 = v15;
          if ( v15 < 0x14 )
          {
            v3 = -1073741762;
          }
          else
          {
            v5 = ExAllocatePoolWithTag(1, v15, 1380994640);
            if ( v5 )
            {
              v3 = RtlAbsoluteToSelfRelativeSD((int)v26);
              if ( v3 >= 0 )
              {
                *a3 = v5;
                goto LABEL_27;
              }
LABEL_39:
              if ( v5 )
                ExFreePoolWithTag(v5);
              goto LABEL_27;
            }
            v3 = -1073741801;
          }
        }
        else
        {
          v3 = -1073741595;
        }
LABEL_27:
        if ( v4 )
          ExFreePoolWithTag((unsigned int)v4);
        return v3;
      }
      v3 = -1073741801;
    }
  }
  return v3;
}
