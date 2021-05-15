// sub_500E50 
 
int __fastcall sub_500E50(unsigned int a1, int a2, int a3, void (__fastcall *a4)(_DWORD, _DWORD, int), _BYTE *a5)
{
  _BYTE *v5; // r6
  int v7; // r9
  int v8; // r8
  _BYTE *v9; // r10
  char v11; // r0
  _BYTE *v12; // r7
  int v13; // lr
  unsigned int v14; // r1
  _BYTE *v15; // r0
  char v16; // r2
  unsigned int v17; // r5
  unsigned int v18; // r2
  _DWORD *v19; // r1
  int v20; // r0
  _DWORD *v21; // r2
  int v22; // r1
  _BYTE *v23; // r5
  char v24; // r3
  unsigned int v25; // r6
  char v26; // r2
  char v28; // [sp+4h] [bp-3Ch]
  unsigned int v29; // [sp+8h] [bp-38h] BYREF
  unsigned int v30; // [sp+Ch] [bp-34h]
  unsigned int v31; // [sp+10h] [bp-30h]
  int v32; // [sp+14h] [bp-2Ch]
  void (__fastcall *v33)(_DWORD, _DWORD, int); // [sp+18h] [bp-28h]
  int *v34; // [sp+1Ch] [bp-24h]
  int vars4; // [sp+44h] [bp+4h] BYREF

  v5 = a5;
  v32 = a3;
  v33 = a4;
  LOBYTE(v7) = *a5;
  LOBYTE(v8) = a5[1];
  v9 = a5 + 2;
  v28 = *a5;
  v34 = &vars4;
  memmove((int)(a5 + 258), (int)(a5 + 2), 0x100u);
  v11 = a5[2];
  v30 = 0;
  v31 = 0;
  if ( (v11 & 1) != 0 )
  {
    v31 = RtlpGetFrameChain() ^ a1;
    RtlpSetFrameChain();
    v30 = vars4 ^ a1;
    vars4 = 0;
  }
  v12 = (_BYTE *)(a1 + a2);
  LOBYTE(a2) = v8;
  LOBYTE(v13) = v28;
  v14 = 0;
  v15 = (_BYTE *)a1;
  if ( (_BYTE *)a1 != v12 )
  {
    do
    {
      v13 = (unsigned __int8)(v13 + 1);
      a2 = (unsigned __int8)(v9[v13] + a2);
      v16 = v9[a2];
      v9[a2] = v9[v13];
      v9[v13] = v16;
      if ( v14 < 0x400 )
        ++v14;
      else
        *v15++ ^= v9[(unsigned __int8)(v9[a2] + v16)] ^ 0x3C;
    }
    while ( v15 != v12 );
    v5 = a5;
  }
  v5[1] = a2;
  v17 = a1 ^ (unsigned int)&v29;
  v18 = a1 ^ (unsigned int)&v29;
  *v5 = v13;
  v19 = v5;
  v20 = 128;
  do
  {
    *v19++ ^= v18;
    v18 = __ROR4__(v18, 3);
    --v20;
  }
  while ( v20 );
  v29 = v18;
  v33(0, 0, v32);
  v21 = v5;
  v22 = 128;
  do
  {
    *v21++ ^= v17;
    v17 = __ROR4__(v17, 3);
    --v22;
  }
  while ( v22 );
  v29 = v17;
  v23 = v5 + 258;
  v24 = v5[258];
  v25 = 0;
  if ( (v24 & 1) != 0 )
  {
    *v34 = v30 ^ a1;
    RtlpSetFrameChain();
  }
  while ( (_BYTE *)a1 != v12 )
  {
    v7 = (unsigned __int8)(v7 + 1);
    v8 = (unsigned __int8)(v23[v7] + v8);
    v26 = v23[v8];
    v23[v8] = v23[v7];
    v23[v7] = v26;
    if ( v25 < 0x400 )
      ++v25;
    else
      *(_BYTE *)a1++ ^= v23[(unsigned __int8)(v23[v8] + v26)] ^ 0x3C;
  }
  return KeSweepIcache();
}
