// BiGetDriveLayoutInformation 
 
int __fastcall BiGetDriveLayoutInformation(unsigned __int16 *a1, int a2)
{
  int v3; // r4
  char v5[8]; // [sp+18h] [bp-28h] BYREF
  int v6; // [sp+20h] [bp-20h]
  int v7; // [sp+24h] [bp-1Ch]
  char *v8; // [sp+28h] [bp-18h]
  int v9; // [sp+2Ch] [bp-14h]
  int v10; // [sp+30h] [bp-10h]
  int v11; // [sp+34h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v5, a1);
  v6 = 24;
  v7 = 0;
  v9 = 576;
  v8 = v5;
  v10 = 0;
  v11 = 0;
  v3 = ZwOpenFile();
  if ( v3 >= 0 )
    v3 = BiIssueGetDriveLayoutIoctl(0, a2);
  return v3;
}
