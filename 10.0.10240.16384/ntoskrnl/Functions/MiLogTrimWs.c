// MiLogTrimWs 
 
int __fastcall MiLogTrimWs(int result, int a2, int a3)
{
  _DWORD *v4; // r4
  unsigned int v6; // r7
  int v7; // r5
  unsigned int v8; // r6
  int v9; // r2
  char v10; // [sp+8h] [bp-C0h] BYREF
  int v11; // [sp+Ch] [bp-BCh] BYREF
  _DWORD v12[2]; // [sp+10h] [bp-B8h] BYREF
  int v13[2]; // [sp+18h] [bp-B0h] BYREF
  _DWORD v14[2]; // [sp+20h] [bp-A8h] BYREF
  _DWORD v15[12]; // [sp+28h] [bp-A0h] BYREF
  char v16[16]; // [sp+58h] [bp-70h] BYREF
  int *v17; // [sp+68h] [bp-60h]
  int v18; // [sp+6Ch] [bp-5Ch]
  int v19; // [sp+70h] [bp-58h]
  int v20; // [sp+74h] [bp-54h]
  _DWORD *v21; // [sp+78h] [bp-50h]
  int v22; // [sp+7Ch] [bp-4Ch]
  int v23; // [sp+80h] [bp-48h]
  int v24; // [sp+84h] [bp-44h]
  _DWORD *v25; // [sp+88h] [bp-40h]
  int v26; // [sp+8Ch] [bp-3Ch]
  int v27; // [sp+90h] [bp-38h]
  int v28; // [sp+94h] [bp-34h]
  int *v29; // [sp+98h] [bp-30h]
  int v30; // [sp+9Ch] [bp-2Ch]
  int v31; // [sp+A0h] [bp-28h]
  int v32; // [sp+A4h] [bp-24h]

  v4 = (_DWORD *)dword_634CA0;
  if ( dword_634CA0 )
  {
    v6 = *(_BYTE *)(result + 112) & 7;
    if ( (*(_BYTE *)(result + 112) & 7) != 0 )
    {
      if ( v6 < 2 )
        v7 = *(_DWORD *)(result - 3240);
      else
        v7 = 0;
      v8 = 0;
    }
    else
    {
      v7 = *(_DWORD *)(result - 316);
      v8 = result - 132;
    }
    if ( *(_DWORD *)dword_634CA0 > 5u )
    {
      result = TlgKeywordOn(dword_634CA0, 1i64);
      if ( result )
      {
        v12[0] = a2;
        v12[1] = 0;
        v14[0] = a3;
        v14[1] = 0;
        v10 = v6;
        v11 = v7;
        v13[0] = dword_640580;
        v13[1] = 0;
        v15[8] = &v10;
        v15[9] = 0;
        v15[10] = 1;
        v15[11] = 0;
        TlgCreateSz((int)v16, v8);
        v17 = &v11;
        v18 = 0;
        v19 = 4;
        v20 = 0;
        v21 = v12;
        v22 = 0;
        v23 = 8;
        v24 = 0;
        v25 = v14;
        v26 = 0;
        v27 = 8;
        v28 = 0;
        v29 = v13;
        v30 = 0;
        v31 = 8;
        v32 = 0;
        result = MmTlgWrite(v4, (unsigned __int8 *)&byte_413E7D[1], v9, (int)byte_413E7D, 8, v15);
      }
    }
  }
  return result;
}
