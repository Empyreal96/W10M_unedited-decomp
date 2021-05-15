// PiDevCfgInitResolveContext 
 
int __fastcall PiDevCfgInitResolveContext(int a1, int a2, _DWORD *a3)
{
  int v4; // r0
  int v5; // r4
  int v7; // r0
  unsigned int i; // r2
  _DWORD *v9; // r3
  __int16 v10[2]; // [sp+0h] [bp-30h] BYREF
  const __int16 *v11; // [sp+4h] [bp-2Ch]
  int v12; // [sp+8h] [bp-28h]
  int v13; // [sp+Ch] [bp-24h]
  __int16 *v14; // [sp+10h] [bp-20h]
  int v15; // [sp+14h] [bp-1Ch]
  int v16; // [sp+18h] [bp-18h]
  int v17; // [sp+1Ch] [bp-14h]

  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  v10[1] = 20;
  v10[0] = 18;
  *a3 = a1;
  v13 = a2;
  v11 = L"Variables";
  a3[2] = 0;
  v12 = 24;
  v15 = 576;
  v14 = v10;
  v16 = 0;
  v17 = 0;
  v4 = ZwOpenKey();
  v5 = v4;
  if ( v4 == -1073741772 )
    return 0;
  if ( v4 < 0 )
    JUMPOUT(0x7E524A);
  v7 = ExAllocatePoolWithTag(1, 1016, 1667526736);
  a3[3] = v7;
  if ( v7 )
  {
    for ( i = 0; i < 0x3F8; i += 8 )
    {
      v9 = (_DWORD *)(a3[3] + i);
      *v9 = v9;
      v9[1] = v9;
    }
    return v5;
  }
  return sub_7E5248();
}
