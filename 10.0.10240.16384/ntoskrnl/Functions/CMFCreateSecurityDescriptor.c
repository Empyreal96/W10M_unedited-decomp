// CMFCreateSecurityDescriptor 
 
int __fastcall CMFCreateSecurityDescriptor(unsigned int *a1, _DWORD *a2)
{
  unsigned int *v2; // r6
  _BYTE *v3; // r10
  _BYTE *v5; // r8
  int v6; // r4
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r9
  int v10; // r0
  _BYTE *v11; // r0
  int v12; // r4
  _DWORD *v13; // r0
  int v14; // r2
  int v15; // r0
  int v16; // r0
  int v17; // r4
  int v18; // r0
  unsigned __int8 *v19; // r6
  int v20; // r9
  int v21; // r3
  int v22; // r9
  int v23; // r3
  int v24; // r1
  int v25; // r0
  _BYTE *v27; // [sp+8h] [bp-58h]
  int v28; // [sp+Ch] [bp-54h] BYREF
  _BYTE *v29; // [sp+10h] [bp-50h]
  int *v30; // [sp+14h] [bp-4Ch]
  int v31; // [sp+18h] [bp-48h] BYREF
  char v32; // [sp+1Ch] [bp-44h]
  char v33; // [sp+1Dh] [bp-43h]
  char v34[8]; // [sp+20h] [bp-40h] BYREF
  char v35[8]; // [sp+28h] [bp-38h] BYREF
  char v36[48]; // [sp+30h] [bp-30h] BYREF

  v34[0] = 0;
  v34[1] = 0;
  v34[2] = 0;
  v34[3] = 0;
  v34[4] = 0;
  v34[5] = 5;
  v31 = 0;
  v32 = 0;
  v33 = 1;
  v35[0] = 0;
  v35[1] = 0;
  v35[2] = 0;
  v35[3] = 0;
  v35[4] = 0;
  v35[5] = 15;
  v2 = a1;
  v29 = 0;
  v30 = (int *)a1;
  v3 = 0;
  v5 = 0;
  if ( !a1 )
    return -1073741811;
  *a1 = 0;
  v6 = RtlCreateSecurityDescriptor(v36, 1);
  if ( (v6 & 0xC0000000) == -1073741824 )
    goto LABEL_47;
  v7 = RtlLengthRequiredSid(1u);
  v8 = ExAllocatePoolWithTag(1, v7, 1668114000);
  v9 = v8;
  v27 = (_BYTE *)v8;
  if ( v8 )
  {
    v6 = RtlInitializeSid(v8, (int)&v31, 1u);
    if ( (v6 & 0xC0000000) != -1073741824 )
    {
      *(_DWORD *)RtlSubAuthoritySid(v9, 0) = 0;
      v28 = *(unsigned __int8 *)(v9 + 1) + 7;
      v10 = RtlLengthRequiredSid(6u);
      v11 = (_BYTE *)ExAllocatePoolWithTag(1, v10, 1668114000);
      v12 = (int)v11;
      v29 = v11;
      if ( v11 )
      {
        RtlInitializeSid((int)v11, (int)v34, 6u);
        *(_DWORD *)RtlSubAuthoritySid(v12, 0) = 80;
        *(_DWORD *)RtlSubAuthoritySid(v12, 1) = 956008885;
        *(_DWORD *)RtlSubAuthoritySid(v12, 2) = -876444647;
        *(_DWORD *)RtlSubAuthoritySid(v12, 3) = 1831038044;
        *(_DWORD *)RtlSubAuthoritySid(v12, 4) = 1853292631;
        v13 = (_DWORD *)RtlSubAuthoritySid(v12, 5);
        v14 = v28;
        *v13 = -2023488832;
        v28 = 4 * (*(unsigned __int8 *)(v12 + 1) + 5) + 4 * v14;
        v31 = RtlLengthRequiredSid(2u);
        v15 = ExAllocatePoolWithTag(1, v31, 1668114000);
        v3 = (_BYTE *)v15;
        if ( v15 )
        {
          v6 = RtlInitializeSid(v15, (int)v35, 2u);
          if ( (v6 & 0xC0000000) == -1073741824 )
            goto LABEL_41;
          *(_DWORD *)RtlSubAuthoritySid((int)v3, 0) = 2;
          *(_DWORD *)RtlSubAuthoritySid((int)v3, 1) = 1;
          v28 += 4 * ((unsigned __int8)v3[1] + 5);
          v16 = ExAllocatePoolWithTag(1, v31, 1668114000);
          v5 = (_BYTE *)v16;
          if ( v16 )
          {
            v6 = RtlInitializeSid(v16, (int)v34, 2u);
            if ( (v6 & 0xC0000000) != -1073741824 )
            {
              *(_DWORD *)RtlSubAuthoritySid((int)v5, 0) = 32;
              *(_DWORD *)RtlSubAuthoritySid((int)v5, 1) = 544;
              v17 = (unsigned __int8)v5[1] + 5;
              v18 = ExAllocatePoolWithTag(1, v28 + 4 * v17, 1668114000);
              v19 = (unsigned __int8 *)v18;
              if ( v18 )
              {
                v6 = RtlCreateAcl(v18, v28 + 4 * v17, 2);
                if ( (v6 & 0xC0000000) != -1073741824 )
                {
                  v20 = 0x10000000;
                  v21 = 0x10000000;
                  v28 = 0x10000000;
                  if ( a2 )
                  {
                    RtlMapGenericMask(&v28, a2);
                    v21 = v28;
                  }
                  v6 = RtlpAddKnownAce(v19, 2u, 3, v21, v29, 0);
                  if ( (v6 & 0xC0000000) != -1073741824 )
                  {
                    v28 = 0x10000000;
                    if ( a2 )
                    {
                      RtlMapGenericMask(&v28, a2);
                      v20 = v28;
                    }
                    v6 = RtlpAddKnownAce(v19, 2u, 3, v20, v5, 0);
                    if ( (v6 & 0xC0000000) != -1073741824 )
                    {
                      v22 = 0x80000000;
                      v23 = 0x80000000;
                      v28 = 0x80000000;
                      if ( a2 )
                      {
                        RtlMapGenericMask(&v28, a2);
                        v23 = v28;
                      }
                      v6 = RtlpAddKnownAce(v19, 2u, 3, v23, v27, 0);
                      if ( (v6 & 0xC0000000) != -1073741824 )
                      {
                        v28 = 0x80000000;
                        if ( a2 )
                        {
                          RtlMapGenericMask(&v28, a2);
                          v22 = v28;
                        }
                        v6 = RtlpAddKnownAce(v19, 2u, 3, v22, v3, 0);
                        if ( (v6 & 0xC0000000) != -1073741824 )
                        {
                          if ( RtlValidAcl(v19) )
                          {
                            v6 = RtlSetDaclSecurityDescriptor((int)v36, 1, (int)v19, 0);
                            if ( (v6 & 0xC0000000) != -1073741824 )
                            {
                              v6 = RtlSetOwnerSecurityDescriptor((int)v36, (int)v29, 0);
                              if ( (v6 & 0xC0000000) != -1073741824 )
                              {
                                if ( RtlValidSecurityDescriptor((int)v36, v24) )
                                {
                                  v28 = 0;
                                  v6 = RtlAbsoluteToSelfRelativeSD((int)v36);
                                  if ( v28 )
                                  {
                                    v25 = ExAllocatePoolWithTag(1, v28, 1668114000);
                                    *v30 = v25;
                                    if ( v25 )
                                      v6 = RtlAbsoluteToSelfRelativeSD((int)v36);
                                    else
                                      v6 = -1073741801;
                                  }
                                }
                                else
                                {
                                  v6 = -1073741703;
                                }
                              }
                            }
                          }
                          else
                          {
                            v6 = -1073741705;
                          }
                        }
                      }
                    }
                  }
                  v9 = (unsigned int)v27;
                }
                ExFreePoolWithTag((unsigned int)v19);
              }
              else
              {
                v6 = -1073741801;
              }
              v2 = (unsigned int *)v30;
            }
            goto LABEL_41;
          }
        }
      }
      v6 = -1073741801;
    }
LABEL_41:
    ExFreePoolWithTag(v9);
    if ( v29 )
      ExFreePoolWithTag((unsigned int)v29);
    if ( v3 )
      ExFreePoolWithTag((unsigned int)v3);
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v5);
LABEL_47:
    if ( v6 >= 0 )
      return v6;
    goto LABEL_48;
  }
  v6 = -1073741801;
LABEL_48:
  if ( *v2 )
  {
    ExFreePoolWithTag(*v2);
    *v2 = 0;
  }
  return v6;
}
