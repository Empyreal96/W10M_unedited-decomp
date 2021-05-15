// RtlCapabilityCheck 
 
int __fastcall RtlCapabilityCheck(int a1, int a2, _BYTE *a3)
{
  int v5; // r0
  int v7; // r4
  int v8; // r0
  _DWORD *v10; // r6
  char v11; // [sp+8h] [bp-D8h] BYREF
  char v12[7]; // [sp+9h] [bp-D7h] BYREF
  char v13[8]; // [sp+10h] [bp-D0h] BYREF
  int v14; // [sp+18h] [bp-C8h]
  int v15; // [sp+1Ch] [bp-C4h]
  __int16 v16; // [sp+20h] [bp-C0h]
  int v17; // [sp+22h] [bp-BEh]
  __int16 v18; // [sp+26h] [bp-BAh]
  int v19; // [sp+48h] [bp-98h]
  int v20; // [sp+4Ch] [bp-94h]
  int v21; // [sp+50h] [bp-90h]
  int v22; // [sp+54h] [bp-8Ch]
  char v23[16]; // [sp+58h] [bp-88h] BYREF
  char v24[48]; // [sp+68h] [bp-78h] BYREF
  char v25[72]; // [sp+98h] [bp-48h] BYREF

  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v12[0] = 0;
  v11 = 0;
  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  v13[4] = 0;
  v5 = 0;
  v13[5] = 5;
  v14 = 0;
  if ( a2 && a3 )
  {
    *a3 = 0;
    v7 = ZwQueryInformationToken();
    if ( v7 >= 0 )
    {
      v8 = RtlDeriveCapabilitySidsFromName(a2, (int)v24, (int)v25);
      v7 = v8;
      if ( v8 >= 0 )
      {
        if ( RtlIsMultiSessionSku(v8) )
          return sub_7E89C8();
        v7 = RtlCheckTokenMembershipEx(a1, (int)v24, 1, &v11);
        if ( v7 >= 0 )
        {
          if ( v11 )
            goto LABEL_16;
          RtlInitializeSid(v23, v13, 1);
          v10 = (_DWORD *)RtlSubAuthoritySid((int)v23, 0);
          *v10 = 18;
          v7 = RtlCheckTokenMembership(a1, (int)v23, (int)&v11);
          if ( v7 >= 0 )
          {
            if ( v11
              || (*v10 = 4, v7 = RtlCheckTokenMembershipEx(a1, (int)v23, 1, &v11), v7 >= 0)
              && (v11
               || (RtlInitializeSid(v23, v13, 2),
                   *v10 = 32,
                   *(_DWORD *)RtlSubAuthoritySid((int)v23, 1) = 544,
                   v7 = RtlCheckTokenMembership(a1, (int)v23, (int)&v11),
                   v7 >= 0)
               && v11) )
            {
LABEL_16:
              if ( !v15 || (v7 = RtlCheckTokenCapability(a1, (int)v25, v12), v7 >= 0) && (!v15 || v12[0]) )
                *a3 = 1;
            }
          }
        }
      }
    }
    v5 = v14;
  }
  else
  {
    v7 = -1073741811;
  }
  if ( v5 )
    ZwClose();
  return v7;
}
