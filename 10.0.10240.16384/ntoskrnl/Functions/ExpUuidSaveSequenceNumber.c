// ExpUuidSaveSequenceNumber 
 
int __fastcall ExpUuidSaveSequenceNumber(int a1, int a2)
{
  int v2; // r4
  char v4[8]; // [sp+10h] [bp-30h] BYREF
  char v5[8]; // [sp+18h] [bp-28h] BYREF
  int v6; // [sp+20h] [bp-20h]
  int v7; // [sp+24h] [bp-1Ch]
  char *v8; // [sp+28h] [bp-18h]
  int v9; // [sp+2Ch] [bp-14h]
  int v10; // [sp+30h] [bp-10h]
  int v11; // [sp+34h] [bp-Ch]
  int vars8; // [sp+48h] [bp+8h]
  int anonymous1; // [sp+4Ch] [bp+Ch]

  vars8 = a1;
  anonymous1 = a2;
  RtlInitUnicodeString(
    (unsigned int)v4,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Executive");
  RtlInitUnicodeString((unsigned int)v5, L"UuidSequenceNumber");
  v6 = 24;
  v7 = 0;
  v9 = 576;
  v8 = v4;
  v10 = 0;
  v11 = 0;
  v2 = ZwOpenKey();
  if ( v2 >= 0 )
  {
    v2 = ZwSetValueKey();
    ZwClose();
  }
  return v2;
}
