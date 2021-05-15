// PopReadHiberbootGroupPolicy 
 
int __fastcall PopReadHiberbootGroupPolicy(_BYTE *a1)
{
  int v2; // r4
  char v4[8]; // [sp+10h] [bp-48h] BYREF
  int v5; // [sp+18h] [bp-40h]
  int v6; // [sp+1Ch] [bp-3Ch]
  char *v7; // [sp+20h] [bp-38h]
  int v8; // [sp+24h] [bp-34h]
  int v9; // [sp+28h] [bp-30h]
  int v10; // [sp+2Ch] [bp-2Ch]
  char v11[20]; // [sp+38h] [bp-20h] BYREF

  *a1 = 0;
  RtlInitUnicodeString((unsigned int)v4, L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\System");
  v5 = 24;
  v6 = 0;
  v8 = 576;
  v7 = v4;
  v9 = 0;
  v10 = 0;
  v2 = ZwOpenKey();
  if ( v2 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v4, L"HiberbootEnabled");
    memset(v11, 0, sizeof(v11));
    v2 = ZwQueryValueKey();
    if ( v2 >= 0 )
      *a1 = v11[12];
    ZwClose();
  }
  return v2;
}
