// MmZeroPageFileAtShutdown 
 
int MmZeroPageFileAtShutdown()
{
  int v0; // r4
  int result; // r0
  int v2; // [sp+8h] [bp-58h]
  __int16 v3[2]; // [sp+10h] [bp-50h] BYREF
  const __int16 *v4; // [sp+14h] [bp-4Ch]
  __int16 v5; // [sp+18h] [bp-48h]
  __int16 v6; // [sp+1Ah] [bp-46h]
  const __int16 *v7; // [sp+1Ch] [bp-44h]
  int v8; // [sp+20h] [bp-40h]
  int v9; // [sp+24h] [bp-3Ch]
  __int16 *v10; // [sp+28h] [bp-38h]
  int v11; // [sp+2Ch] [bp-34h]
  int v12; // [sp+30h] [bp-30h]
  int v13; // [sp+34h] [bp-2Ch]
  int v14; // [sp+44h] [bp-1Ch]
  int v15; // [sp+4Ch] [bp-14h]

  v3[0] = 168;
  v3[1] = 170;
  v4 = L"\\registry\\machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management";
  v5 = 46;
  v6 = 48;
  v0 = 0;
  v7 = L"ClearPageFileAtShutdown";
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v3;
  v12 = 0;
  v13 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_7;
  if ( ZwQueryValueKey() >= 0 && v14 == 4 )
    v0 = v15;
  ObCloseHandle(v2);
  if ( v0 )
    result = 1;
  else
LABEL_7:
    result = 0;
  return result;
}
