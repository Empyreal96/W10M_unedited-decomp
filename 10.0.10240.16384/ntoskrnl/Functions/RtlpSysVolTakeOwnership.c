// RtlpSysVolTakeOwnership 
 
int __fastcall RtlpSysVolTakeOwnership(int a1)
{
  int result; // r0
  int v3; // [sp+8h] [bp-70h] BYREF
  int v4; // [sp+Ch] [bp-6Ch] BYREF
  int v5[6]; // [sp+10h] [bp-68h] BYREF
  char v6[24]; // [sp+28h] [bp-50h] BYREF
  char v7[8]; // [sp+40h] [bp-38h] BYREF
  int v8[4]; // [sp+48h] [bp-30h] BYREF
  char v9[2]; // [sp+58h] [bp-20h] BYREF
  int v10; // [sp+5Ah] [bp-1Eh]
  __int16 v11; // [sp+5Eh] [bp-1Ah]
  int v12; // [sp+60h] [bp-18h]
  int v13; // [sp+64h] [bp-14h]

  result = NtOpenProcessTokenEx(-1, 40, 512, (unsigned int)&v3);
  if ( result >= 0 )
  {
    v8[0] = 1;
    v8[1] = 9;
    v8[3] = 2;
    v8[2] = 0;
    if ( NtAdjustPrivilegesToken(v3, 0, (unsigned int)v8, 16, 0, 0) >= 0 )
    {
      v5[0] = 24;
      v5[1] = 0;
      v5[2] = a1;
      v5[3] = 576;
      v5[4] = 0;
      v5[5] = 0;
      if ( NtOpenFile((int)&v4, 1572864, (int)v5, (int)v7, 7, 33) >= 0 )
      {
        RtlCreateSecurityDescriptor(v6, 1);
        v9[0] = 1;
        v9[1] = 2;
        v10 = 0;
        v11 = 1280;
        v12 = 32;
        v13 = 544;
        if ( RtlSetOwnerSecurityDescriptor((int)v6, (int)v9, 0) >= 0 )
          NtSetSecurityObject(v4, 1, (int)v6);
        NtClose();
      }
    }
    result = NtClose();
  }
  return result;
}
