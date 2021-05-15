// sub_6E2418 
 
int __fastcall sub_6E2418(int *a1)
{
  int v1; // lr
  int v2; // r0
  int *v3; // r5
  int v4; // r1
  int v5; // r9
  char v6; // r4
  int v7; // t1
  int v8; // r5
  unsigned __int8 *v9; // r7
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // lr
  int v13; // r3
  int *v14; // r6
  int result; // r0
  int v16; // r2
  int v17; // r0
  int v18; // r0
  int v19; // [sp+10h] [bp-50h]
  int *v20; // [sp+14h] [bp-4Ch] BYREF
  int v21; // [sp+18h] [bp-48h]
  int v22; // [sp+1Ch] [bp-44h]
  unsigned int v23; // [sp+20h] [bp-40h] BYREF
  int v24; // [sp+24h] [bp-3Ch]
  int v25; // [sp+28h] [bp-38h]
  _DWORD *v26; // [sp+2Ch] [bp-34h]
  unsigned __int8 *v27; // [sp+30h] [bp-30h]
  int v28[10]; // [sp+38h] [bp-28h] BYREF

  v1 = 0;
  v23 = *a1;
  v24 = 0;
  v25 = 0;
  v26 = a1;
  v28[0] = dword_920598;
  v2 = -1;
  v3 = (int *)&v23;
  v4 = 0;
  v28[1] = dword_92059C;
  v19 = 0;
  v20 = (int *)&v20;
  v21 = 0;
  v22 = -1;
  v5 = 0;
  v6 = 24;
  do
  {
    v7 = *(unsigned __int8 *)v3;
    v3 = (int *)((char *)v3 + 1);
    v5 |= v7 << v6;
    ++v4;
    v6 -= 8;
  }
  while ( v4 < 4 );
  v24 = 0;
  v25 = v5;
  v8 = 30;
  v9 = (unsigned __int8 *)&byte_920570;
  do
  {
    v10 = &byte_920578[v8];
    v11 = byte_920578[v8 + 1];
    v27 = &byte_920578[v8];
    v23 = v11;
    if ( v11 < 0x1F )
    {
      v18 = ((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, int *, int))*(&off_9205A0 + v23))(
              v8 + 1,
              v9[4],
              v9[5],
              v9[6],
              v9[7],
              v28,
              v1);
      v2 = v18 ^ v22;
      v22 = v2;
      v19 = v21;
      v10 = v27;
    }
    v12 = *v10;
    if ( v12 < 0x1F )
    {
      v17 = ((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD, int *, int))*(&off_9205A0 + v12))(
              v8,
              *v9,
              v9[1],
              v9[2],
              v9[3],
              v28,
              v2);
      v1 = v17 ^ v21;
      v2 = v22;
      v19 = v1;
      v21 = v1;
    }
    else
    {
      v1 = v19;
    }
    v8 -= 2;
    v9 -= 8;
  }
  while ( v8 >= 0 );
  v13 = 0;
  v14 = v20;
  result = 24;
  v16 = v25 ^ v1;
  do
  {
    v16 = __ROR4__(v16, 24);
    *(_BYTE *)v14 = v16;
    v14 = (int *)((char *)v14 + 1);
    ++v13;
  }
  while ( v13 < 4 );
  *v26 = v20;
  return result;
}
