// RtlpInitNlsFileName 
 
int __fastcall RtlpInitNlsFileName(int a1, char *a2, unsigned __int16 *a3, int a4, unsigned int a5)
{
  char *v6; // r6
  const __int16 *v7; // r2
  char *v8; // r3
  int v9; // r4
  __int16 v11[2]; // [sp+10h] [bp-1A8h] BYREF
  char *v12; // [sp+14h] [bp-1A4h]
  int v13; // [sp+18h] [bp-1A0h]
  int v14; // [sp+1Ch] [bp-19Ch]
  char *v15; // [sp+20h] [bp-198h]
  int v16; // [sp+24h] [bp-194h]
  int v17; // [sp+28h] [bp-190h]
  int v18; // [sp+2Ch] [bp-18Ch]
  char v19[8]; // [sp+30h] [bp-188h] BYREF
  char v20; // [sp+40h] [bp-178h] BYREF
  int v21; // [sp+84h] [bp-134h]
  char v22; // [sp+8Ch] [bp-12Ch] BYREF

  v6 = a2;
  if ( a1 == 11 )
  {
    v7 = L"\\SystemRoot\\System32\\c_%.3d.nls";
    v8 = a2;
LABEL_3:
    v9 = RtlStringCchPrintfW(a3, 0x40u, (int)v7, (int)v8);
    if ( v9 >= 0 )
      RtlInitUnicodeString(a5, a3);
    return v9;
  }
  if ( a1 != 12 )
    return -1073741585;
  RtlInitUnicodeString(
    (unsigned int)v19,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Normalization");
  v13 = 24;
  v14 = 0;
  v16 = 576;
  v15 = v19;
  v17 = 0;
  v18 = 0;
  v9 = ZwOpenKey();
  if ( v9 >= 0 )
  {
    v11[0] = 64;
    v11[1] = 64;
    v12 = &v20;
    RtlIntegerToUnicodeString(v6, 16, v11);
    v9 = ZwQueryValueKey();
    ZwClose();
    if ( v9 >= 0 )
    {
      if ( v21 != 1 )
        return -1073741823;
      v7 = L"\\SystemRoot\\System32\\%s";
      v8 = &v22;
      goto LABEL_3;
    }
  }
  return v9;
}
