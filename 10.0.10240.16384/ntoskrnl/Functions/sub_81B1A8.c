// sub_81B1A8 
 
int __fastcall sub_81B1A8(char *a1, int a2, _DWORD *a3)
{
  int v3; // r3
  __int64 v4; // r0
  int v5; // r2
  int v6; // r3
  _DWORD *v8; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r4
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r1
  int (__fastcall *v16)(_DWORD); // [sp-4h] [bp-4h]

  if ( (*a3 & 0x40000) != 0 )
  {
    __dmb(0xBu);
    v9 = v8 + 47;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x400, v9) );
    __dmb(0xBu);
  }
  v8[7] = *((_DWORD *)a1 + 7);
  v11 = *((_DWORD *)a1 + 8);
  v8[63] = 0;
  v8[64] = 0;
  v8[8] = v11;
  v8[218] = v8 + 218;
  v8[219] = v8 + 218;
  v8[217] = 0;
  __dmb(0xBu);
  v8[123] = 0;
  v8[159] = 0;
  v12 = (int)v8;
  v8[135] = *((_DWORD *)a1 + 135);
  v8[140] = *((_DWORD *)a1 + 140);
  v8[141] = *((_DWORD *)a1 + 141);
  v8[142] = *((_DWORD *)a1 + 142);
  v8[136] = *((_DWORD *)a1 + 136);
  v8[137] = *((_DWORD *)a1 + 137);
  v8[138] = *((_DWORD *)a1 + 138);
  v8[139] = *((_DWORD *)a1 + 139);
  v8[98] = *((_DWORD *)a1 + 98);
  v13 = *((_DWORD *)a1 + 69);
  v14 = a1 - (char *)v8;
  v15 = 7;
  v8[69] = v13;
  v8[146] = -1069539328;
  do
  {
    v3 = *(_DWORD *)(v14 + v12 + 512);
    *(_DWORD *)(v12 + 512) = v3;
    v12 += 4;
    --v15;
  }
  while ( v15 );
  v4 = MiInsertNewProcess((unsigned int)v8, v12, v3);
  MiAllowWorkingSetExpansion((int)(v8 + 123), SHIDWORD(v4), v5, v6);
  return v16(0);
}
