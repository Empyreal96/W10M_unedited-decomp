// BiDeleteEfiVariable 
 
int __fastcall BiDeleteEfiVariable(unsigned __int16 *a1)
{
  int v2; // r4
  int v3; // r0
  char v5[8]; // [sp+10h] [bp-30h] BYREF
  char v6[8]; // [sp+18h] [bp-28h] BYREF
  int v7; // [sp+20h] [bp-20h]
  __int16 v8; // [sp+24h] [bp-1Ch]
  __int16 v9; // [sp+26h] [bp-1Ah]
  char v10; // [sp+28h] [bp-18h]
  char v11; // [sp+29h] [bp-17h]
  char v12; // [sp+2Ah] [bp-16h]
  char v13; // [sp+2Bh] [bp-15h]
  char v14; // [sp+2Ch] [bp-14h]
  char v15; // [sp+2Dh] [bp-13h]
  char v16; // [sp+2Eh] [bp-12h]
  char v17; // [sp+2Fh] [bp-11h]

  v7 = -1947934879;
  v8 = -27702;
  v9 = 4562;
  v10 = -86;
  v11 = 13;
  v12 = 0;
  v13 = -32;
  v14 = -104;
  v15 = 3;
  v16 = 43;
  v17 = -116;
  v2 = BiAcquirePrivilege(22, v6);
  if ( v2 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v5, a1);
    v3 = ZwQuerySystemEnvironmentValueEx();
    v2 = v3;
    if ( v3 == -1073741789 )
      return sub_814614();
    if ( v3 == -1073741568 )
      v2 = 0;
    BiReleasePrivilege(v6);
  }
  return v2;
}
