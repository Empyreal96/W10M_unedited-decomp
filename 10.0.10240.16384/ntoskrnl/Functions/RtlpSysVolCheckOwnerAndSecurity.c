// RtlpSysVolCheckOwnerAndSecurity 
 
int __fastcall RtlpSysVolCheckOwnerAndSecurity(int a1, int a2)
{
  int v4; // r4
  int v5; // r0
  _DWORD *v6; // r5
  unsigned int v7; // r0
  unsigned __int8 *v8; // r7
  unsigned int i; // r6
  int v10; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r0
  int v16; // [sp+8h] [bp-60h] BYREF
  int v17; // [sp+Ch] [bp-5Ch] BYREF
  char v18; // [sp+10h] [bp-58h] BYREF
  bool v19[3]; // [sp+11h] [bp-57h] BYREF
  unsigned __int16 *v20; // [sp+14h] [bp-54h] BYREF
  unsigned __int16 v21; // [sp+18h] [bp-50h] BYREF
  int v22; // [sp+1Ah] [bp-4Eh]
  __int16 v23; // [sp+1Eh] [bp-4Ah]
  int v24; // [sp+20h] [bp-48h]
  int v25; // [sp+24h] [bp-44h]
  unsigned __int16 v26; // [sp+30h] [bp-38h] BYREF
  int v27; // [sp+32h] [bp-36h]
  __int16 v28; // [sp+36h] [bp-32h]
  int v29; // [sp+38h] [bp-30h]

  v16 = 0;
  if ( NtQuerySecurityObject(a1, 5, 0, 0, &v17) == -1073741789 )
  {
    v5 = ExAllocatePoolWithTag(1, v17, 1399615318);
    v6 = (_DWORD *)v5;
    if ( !v5 )
      return -1073741670;
    v4 = NtQuerySecurityObject(a1, 5, v5, v17, &v17);
    v7 = (unsigned int)v6;
    if ( v4 < 0 || (v4 = RtlGetDaclSecurityDescriptor((int)v6, &v18, &v16, v19), v7 = (unsigned int)v6, v4 < 0) )
    {
LABEL_36:
      ExFreePoolWithTag(v7);
      return v4;
    }
    v4 = RtlGetOwnerSecurityDescriptor((int)v6, &v20, v19);
    if ( v4 < 0 )
    {
LABEL_8:
      v7 = (unsigned int)v6;
      goto LABEL_36;
    }
    v26 = 257;
    v27 = 0;
    v28 = 1280;
    v29 = 18;
    v21 = 513;
    v22 = 0;
    v23 = 1280;
    v24 = 32;
    v25 = 544;
    if ( v20 )
    {
      if ( RtlEqualSid(v20, &v21) )
      {
        if ( v18 )
        {
          v8 = (unsigned __int8 *)v16;
          if ( v16 )
          {
            for ( i = 0; ; ++i )
            {
              if ( RtlGetAce(v8, i, (int)&v16) >= 0 )
              {
                v10 = v16;
              }
              else
              {
                v10 = 0;
                v16 = 0;
              }
              if ( !v10 )
                break;
              if ( !*(_BYTE *)v10 && RtlEqualSid((unsigned __int16 *)(v10 + 8), &v26) )
              {
                if ( (*(_BYTE *)(v10 + 1) & 1) != 0 && (*(_BYTE *)(v10 + 1) & 2) != 0 )
                {
                  v4 = 0;
                }
                else
                {
                  *(_BYTE *)(v10 + 1) |= 3u;
                  v4 = NtSetSecurityObject(a1, 4, (int)v6);
                }
                goto LABEL_8;
              }
            }
          }
        }
      }
    }
    v16 = v17;
    if ( RtlSelfRelativeToAbsoluteSD2((int)v6, &v16) != -1073741789 )
      goto LABEL_28;
    v11 = v16;
    v12 = ExAllocatePoolWithTag(1, v16, 1399615318);
    v13 = v12;
    if ( !v12 )
    {
LABEL_32:
      v4 = -1073741670;
      goto LABEL_8;
    }
    memmove(v12, (int)v6, v17);
    ExFreePoolWithTag((unsigned int)v6);
    v6 = (_DWORD *)v13;
    v17 = v11;
    v4 = RtlSelfRelativeToAbsoluteSD2(v13, &v17);
    if ( v4 >= 0 )
    {
LABEL_28:
      v4 = RtlSetOwnerSecurityDescriptor((int)v6, (int)&v21, 0);
      if ( v4 < 0 )
        goto LABEL_8;
      v4 = RtlSetDaclSecurityDescriptor((int)v6, 1, a2, 0);
      if ( v4 < 0 )
        goto LABEL_8;
      v16 = 0;
      v4 = RtlMakeSelfRelativeSD(v6, 0, (unsigned int *)&v16);
      if ( v4 != -1073741789 )
        goto LABEL_8;
      v14 = ExAllocatePoolWithTag(1, v16, 1399615318);
      v13 = v14;
      if ( !v14 )
        goto LABEL_32;
      v4 = RtlMakeSelfRelativeSD(v6, v14, (unsigned int *)&v16);
      ExFreePoolWithTag((unsigned int)v6);
      if ( v4 >= 0 )
      {
        v17 = v16;
        v4 = NtSetSecurityObject(a1, 5, v13);
      }
    }
    v7 = v13;
    goto LABEL_36;
  }
  return 0;
}
