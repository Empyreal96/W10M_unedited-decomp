// IopIssueTrEERequest 
 
int __fastcall IopIssueTrEERequest(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8, _DWORD *a9)
{
  int result; // r0
  int v10; // r1
  unsigned int v11; // r4
  unsigned int v12; // [sp+18h] [bp-58h] BYREF
  char v13[12]; // [sp+20h] [bp-50h] BYREF
  int v14; // [sp+2Ch] [bp-44h]
  int v15; // [sp+30h] [bp-40h]
  int v16; // [sp+34h] [bp-3Ch]
  int v17; // [sp+38h] [bp-38h]
  int v18; // [sp+3Ch] [bp-34h]
  __int64 v19; // [sp+40h] [bp-30h]
  int v20; // [sp+48h] [bp-28h]
  int v21; // [sp+4Ch] [bp-24h]
  char v22[8]; // [sp+50h] [bp-20h] BYREF
  unsigned int v23; // [sp+58h] [bp-18h]
  int v24; // [sp+5Ch] [bp-14h]

  v15 = a4;
  v16 = a4 >> 31;
  v14 = a1;
  v17 = a5;
  v18 = 0;
  v19 = a6;
  v20 = a7;
  v21 = 0;
  result = IopIssueSystemEnvironmentRequest(5668868, 0, a2, a3, v13, 48, v22, 16, &v12);
  if ( result >= 0 )
  {
    if ( v12 < 0x10 )
      goto LABEL_7;
    v11 = v23;
    v10 = v24;
    if ( a9 )
      result = RtlULongLongToULong(v23, v24, a9);
    if ( !v10 && v11 < a8 )
LABEL_7:
      result = -1073741434;
  }
  return result;
}
