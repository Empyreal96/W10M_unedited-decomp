// PiDevCfgOpenDriverConfiguration 
 
int __fastcall PiDevCfgOpenDriverConfiguration(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  int v5; // r4
  __int16 v7[2]; // [sp+8h] [bp-38h] BYREF
  const __int16 *v8; // [sp+Ch] [bp-34h]
  int v9; // [sp+10h] [bp-30h]
  int v10; // [sp+14h] [bp-2Ch]
  __int16 *v11; // [sp+18h] [bp-28h]
  int v12; // [sp+1Ch] [bp-24h]
  int v13; // [sp+20h] [bp-20h]
  int v14; // [sp+24h] [bp-1Ch]

  v7[1] = 30;
  v7[0] = 28;
  v8 = L"Configurations";
  v9 = 24;
  v10 = a1;
  v11 = v7;
  v13 = 0;
  v14 = 0;
  v12 = 576;
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v7, a2);
    *a3 = 0;
    v9 = 24;
    v10 = 0;
    v11 = v7;
    v12 = 576;
    v13 = 0;
    v14 = 0;
    v5 = ZwOpenKey();
  }
  return v5;
}
