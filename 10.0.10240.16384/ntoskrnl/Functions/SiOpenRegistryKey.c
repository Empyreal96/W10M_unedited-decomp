// SiOpenRegistryKey 
 
int __fastcall SiOpenRegistryKey(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  int v5; // r4
  char v7[8]; // [sp+8h] [bp-28h] BYREF
  int v8; // [sp+10h] [bp-20h]
  int v9; // [sp+14h] [bp-1Ch]
  char *v10; // [sp+18h] [bp-18h]
  int v11; // [sp+1Ch] [bp-14h]
  int v12; // [sp+20h] [bp-10h]
  int v13; // [sp+24h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v7, a2);
  v11 = 576;
  v8 = 24;
  v10 = v7;
  v9 = 0;
  v12 = 0;
  v13 = 0;
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
    *a4 = 0;
  return v5;
}
