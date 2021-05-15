// CmpExamineSaclForAuditEvent 
 
int __fastcall CmpExamineSaclForAuditEvent(int a1, _BYTE *a2, int a3)
{
  int v5; // r6
  int v6; // r4
  int v7; // r2
  char v9; // [sp+10h] [bp-30h] BYREF
  char v10; // [sp+11h] [bp-2Fh] BYREF
  char v11; // [sp+12h] [bp-2Eh] BYREF
  bool v12; // [sp+13h] [bp-2Dh] BYREF
  int v13; // [sp+14h] [bp-2Ch] BYREF
  char v14[8]; // [sp+18h] [bp-28h] BYREF
  int v15[2]; // [sp+20h] [bp-20h] BYREF
  int v16; // [sp+28h] [bp-18h]

  v9 = 0;
  v10 = 0;
  *a2 = 0;
  v13 = 0;
  SeCaptureSubjectContext(v15, (int)a2, a3, 0);
  v5 = RtlGetSaclSecurityDescriptor(a1, &v11, &v13, &v12);
  if ( v5 >= 0 )
  {
    v6 = v15[0];
    if ( v11 )
    {
      if ( v15[0] )
        v7 = v15[0];
      else
        v7 = v16;
      SeExamineSacl(v13, v13, v7, 983103, 1, &v9, &v10);
    }
    RtlInitUnicodeString((unsigned int)v14, L"Key");
    if ( !v6 )
      v6 = v16;
    SeExamineGlobalSacl(v14, v13, v6, 983103, 1, &v9, &v10);
    if ( v9 || v10 )
      *a2 = 1;
  }
  SeReleaseSubjectContext((int)v15);
  return v5;
}
