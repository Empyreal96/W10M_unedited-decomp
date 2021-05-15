// RtlCheckTokenCapability 
 
int __fastcall RtlCheckTokenCapability(int a1, int a2, _BYTE *a3)
{
  int v7; // r4
  int v8; // r0
  int v9; // r9
  int v10; // r0
  int v11; // r5
  int v12; // [sp+24h] [bp-1B4h] BYREF
  int v13; // [sp+30h] [bp-1A8h]
  int v14; // [sp+34h] [bp-1A4h]
  int v15; // [sp+38h] [bp-1A0h]
  int v16; // [sp+3Ch] [bp-19Ch]
  int v17; // [sp+40h] [bp-198h]
  int *v18; // [sp+44h] [bp-194h]
  char *v19; // [sp+48h] [bp-190h] BYREF
  int v20; // [sp+4Ch] [bp-18Ch] BYREF
  int v21; // [sp+50h] [bp-188h] BYREF
  _DWORD v22[2]; // [sp+58h] [bp-180h] BYREF
  int v23; // [sp+60h] [bp-178h]
  int v24; // [sp+64h] [bp-174h]
  char v25[24]; // [sp+68h] [bp-170h] BYREF
  int v26; // [sp+80h] [bp-158h]
  int v27; // [sp+D0h] [bp-108h] BYREF
  int v28; // [sp+D4h] [bp-104h]
  char v29; // [sp+D8h] [bp-100h]
  char v30; // [sp+D9h] [bp-FFh]
  char v31[160]; // [sp+E0h] [bp-F8h] BYREF
  char v32; // [sp+180h] [bp-58h] BYREF

  v22[0] = 0;
  v22[1] = 0;
  v23 = 0;
  v24 = 0;
  *a3 = 0;
  if ( !RtlIsCapabilitySid(a2) )
    return sub_524A74();
  if ( a1 )
  {
    v13 = 24;
    v14 = 0;
    v16 = 512;
    v15 = 0;
    v17 = 0;
    v27 = 12;
    v28 = 2;
    v29 = 1;
    v30 = 0;
    v18 = &v27;
    v7 = ZwDuplicateToken();
    if ( v7 >= 0 )
    {
LABEL_5:
      v21 = 76;
      ZwQueryInformationToken();
      RtlCreateSecurityDescriptor(v25, 1);
      RtlSetOwnerSecurityDescriptor(v25, v26, 0);
      RtlSetGroupSecurityDescriptor(v25, v26, 0);
      RtlCreateAcl(v31, 160, 2);
      RtlAddAccessAllowedAce(v31, 2, 65537, v26);
      RtlAddAccessAllowedAce(v31, 2, 65537, a2);
      RtlSetDaclSecurityDescriptor(v25, 1, v31, 0, &v21);
      v19 = &v32;
      v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
      v8 = ObReferenceObjectByHandle(0, 8, SeTokenObjectType, 0, &v12, 0);
      v9 = v12;
      v7 = v8;
      v23 = v12;
      if ( v8 >= 0 )
      {
        v10 = SeAccessCheckWithHint(
                v25,
                0,
                v22,
                0,
                65537,
                0,
                &v19,
                RtlpCheckTokenCapabilityGenericMapping,
                *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
                &v20,
                &v12);
        v11 = v12;
        v7 = v10 ? v12 : -1073741790;
        ObfDereferenceObjectWithTag(v9);
        if ( v7 >= 0 )
        {
          if ( !v11 && v20 == 65537 )
            *a3 = 1;
          v7 = 0;
        }
      }
      return v7;
    }
  }
  else
  {
    v7 = ZwOpenThreadTokenEx();
    if ( v7 == -1073741700 )
    {
      v7 = ZwOpenProcessTokenEx();
      if ( v7 < 0 )
        return v7;
      v13 = 24;
      v14 = 0;
      v15 = 0;
      v16 = 512;
      v17 = 0;
      v27 = 12;
      v28 = 2;
      v29 = 1;
      v30 = 0;
      v18 = &v27;
      v7 = ZwDuplicateToken();
      ZwClose();
    }
    if ( v7 >= 0 )
      goto LABEL_5;
  }
  return v7;
}
