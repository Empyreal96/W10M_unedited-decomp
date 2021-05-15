// CmpDoReDoCreateKey 
 
int __fastcall CmpDoReDoCreateKey(int a1, int a2)
{
  int v3; // r1
  __int16 v4; // r4
  __int16 v5; // r3
  unsigned int v6; // r2
  int v7; // r3
  int v8; // r4
  int v10; // [sp+10h] [bp-48h] BYREF
  __int16 v11[2]; // [sp+20h] [bp-38h] BYREF
  int v12; // [sp+24h] [bp-34h]
  __int16 v13[2]; // [sp+28h] [bp-30h] BYREF
  unsigned int v14; // [sp+2Ch] [bp-2Ch]
  int v15; // [sp+30h] [bp-28h]
  int v16; // [sp+34h] [bp-24h]
  __int16 *v17; // [sp+38h] [bp-20h]
  int v18; // [sp+3Ch] [bp-1Ch]
  int v19; // [sp+40h] [bp-18h]
  int v20; // [sp+44h] [bp-14h]

  v3 = *(_DWORD *)(a2 + 36);
  v4 = *(_WORD *)(a2 + 32);
  v5 = *(_WORD *)(a2 + 34);
  v12 = v3;
  LOWORD(v6) = v4;
  v11[1] = v5;
  do
  {
    v6 = (unsigned __int16)(v6 - 2);
    v7 = *(unsigned __int16 *)(v3 + 2 * (v6 >> 1));
    v11[0] = v6;
  }
  while ( v7 != 92 );
  v14 = v6 + v3 + 2;
  v13[0] = v4 - v6 - 2;
  v13[1] = v13[0];
  v8 = CmpDoReOpenTransKey(a1, v11, 131078, &v10);
  if ( v8 >= 0 )
  {
    v15 = 24;
    v18 = 576;
    v17 = v13;
    v19 = *(_DWORD *)(a2 + 48);
    v20 = 0;
    v16 = v10;
    v8 = ZwCreateKey();
    ZwClose();
    if ( v8 >= 0 )
      ZwClose();
  }
  return v8;
}
