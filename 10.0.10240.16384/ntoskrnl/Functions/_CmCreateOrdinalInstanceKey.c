// _CmCreateOrdinalInstanceKey 
 
int __fastcall CmCreateOrdinalInstanceKey(int *a1, int a2, unsigned __int16 *a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r4
  unsigned int v8; // r8
  unsigned int v9; // r0
  unsigned int i; // r5
  int v12; // r3
  unsigned __int16 *v13; // r2
  int v14; // t1
  int v15; // r0
  int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch]
  int *v18; // [sp+18h] [bp-28h]
  int v19[9]; // [sp+1Ch] [bp-24h] BYREF

  v17 = a2;
  v18 = a1;
  v7 = 0;
  v16 = 0;
  v8 = wcstoul(L"999A", 0, 36);
  v9 = wcstoul(L"ZZZZ", 0, 36);
  if ( !v8 || v8 == -1 || !v9 || v9 == -1 )
    return -1073741595;
  for ( i = 0; ; ++i )
  {
    if ( i > 0x270F )
      return sub_7EF1E4();
    if ( swprintf_s((int)a3, 5, (int)L"%04u", i) < 0 )
      return -1073741595;
    v12 = *a3;
    v13 = a3;
    while ( v12 )
    {
      if ( v12 > 97 )
        JUMPOUT(0x7EF210);
      if ( v12 == 97 || v12 == 65 || v12 == 69 || v12 == 73 || v12 == 79 )
        JUMPOUT(0x7EF22C);
      if ( v12 > 84 )
        JUMPOUT(0x7EF208);
      v14 = v13[1];
      ++v13;
      v12 = v14;
    }
    v15 = PnpCtxRegCreateKey(v18, v17, a3, 1, 1, 0, (int)&v16, (int)v19);
    if ( v15 == -1073741444 )
      return -1073741595;
    if ( v15 < 0 )
      JUMPOUT(0x7EF248);
    if ( v19[0] == 1 )
      break;
    ZwClose();
    v16 = 0;
  }
  *a6 = v16;
  return v7;
}
