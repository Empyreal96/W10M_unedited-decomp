// CmpAddAliasEntry 
 
int __fastcall CmpAddAliasEntry(int a1, int a2, int a3)
{
  unsigned int v5; // r7
  int v6; // r4
  int v7; // r0
  int v8; // r0
  int v9; // r2
  int v10; // r3
  int v12; // [sp+10h] [bp-1D8h] BYREF
  int v13; // [sp+14h] [bp-1D4h] BYREF
  int v14; // [sp+18h] [bp-1D0h] BYREF
  int v15; // [sp+1Ch] [bp-1CCh]
  int *v16; // [sp+20h] [bp-1C8h]
  int v17; // [sp+24h] [bp-1C4h]
  int v18; // [sp+28h] [bp-1C0h]
  int v19; // [sp+2Ch] [bp-1BCh]
  unsigned __int16 v20[2]; // [sp+30h] [bp-1B8h] BYREF
  char *v21; // [sp+34h] [bp-1B4h]
  int v22; // [sp+38h] [bp-1B0h] BYREF
  unsigned __int16 v23[4]; // [sp+40h] [bp-1A8h] BYREF
  char v24[128]; // [sp+48h] [bp-1A0h] BYREF
  char v25; // [sp+C8h] [bp-120h] BYREF

  v12 = 0;
  v13 = 0;
  v14 = 24;
  v15 = a1;
  v17 = 64;
  v16 = &CmpStrAliasString;
  v18 = 0;
  v19 = 0;
  v5 = 0;
  v6 = NtOpenKey();
  if ( v6 == -1073741772 )
    v6 = NtCreateKey((int)&v13, 131103, (int)&v14, 0, 0);
  if ( v6 < 0 )
  {
    v13 = 0;
LABEL_16:
    v8 = v12;
    goto LABEL_17;
  }
  while ( 1 )
  {
    sprintf_s((int)v24, 128, (int)"%04d", ++v5);
    RtlInitAnsiString((unsigned int)v23, (unsigned int)v24);
    v20[1] = 256;
    v21 = &v25;
    v20[0] = 0;
    RtlAnsiStringToUnicodeString(v20, v23, 0, 0);
    v14 = 24;
    v15 = v13;
    v17 = 64;
    v16 = (int *)v20;
    v18 = 0;
    v19 = 0;
    v7 = NtOpenKey();
    v6 = v7;
    if ( v7 < 0 )
      break;
    NtClose();
    if ( v5 >= 0xC8 )
      goto LABEL_10;
  }
  if ( v7 == -1073741772 )
    v6 = 0;
LABEL_10:
  if ( v6 < 0 || (v6 = NtCreateKey((int)&v12, 131103, (int)&v14, 0, 0), v6 < 0) )
  {
    v8 = 0;
    v12 = 0;
  }
  else
  {
    CmpAddDockingInfo(v12, a2, v9, v10);
    v22 = a3;
    v6 = NtSetValueKey(v12, (int)&CmpStrProfileNumberString, 0, 4, (int)&v22, 4u);
    v8 = v12;
  }
  if ( v13 )
  {
    NtClose();
    goto LABEL_16;
  }
LABEL_17:
  if ( v8 )
    NtClose();
  return v6;
}
