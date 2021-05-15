// NtSetTimerEx 
 
int __fastcall NtSetTimerEx(int a1, int a2, int *a3, int a4)
{
  int *v4; // r5
  int v6; // r8
  unsigned int v7; // r2
  int v8; // r6
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int *v12; // r5
  int v13; // r1
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r0
  _DWORD *v17; // r4
  int v18; // r2
  int v19; // r0
  char v21[4]; // [sp+18h] [bp-68h] BYREF
  _DWORD *v22; // [sp+1Ch] [bp-64h] BYREF
  int v23; // [sp+20h] [bp-60h]
  int v24; // [sp+24h] [bp-5Ch]
  int v25; // [sp+28h] [bp-58h]
  int v26; // [sp+2Ch] [bp-54h]
  int v27; // [sp+30h] [bp-50h]
  int v28; // [sp+34h] [bp-4Ch]
  int v29; // [sp+38h] [bp-48h]
  int v30; // [sp+3Ch] [bp-44h]
  _DWORD _40[22]; // [sp+40h] [bp-40h] BYREF

  _40[21] = a4;
  v4 = a3;
  _40[20] = a3;
  _40[19] = a2;
  _40[18] = a1;
  v21[0] = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = v21[0];
  if ( v21[0] && a4 )
  {
    if ( ((unsigned __int8)a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v7 = (unsigned int)a3 + a4;
    if ( (unsigned int)v4 + a4 > MmUserProbeAddress || v7 < (unsigned int)v4 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  if ( a2 )
    return -1073741821;
  if ( a4 != 32 )
    return -1073741820;
  if ( v6 )
  {
    v9 = v4[1];
    v10 = v4[2];
    v11 = v4[3];
    v23 = *v4;
    v24 = v9;
    v25 = v10;
    v26 = v11;
    v12 = v4 + 4;
    v13 = v12[1];
    v14 = v12[2];
    v15 = v12[3];
    v27 = *v12;
    v28 = v13;
    v29 = v14;
    v30 = v15;
    __dmb(0xBu);
    _40[0] = v23;
    _40[1] = v24;
    _40[2] = v25;
    _40[3] = v26;
    _40[4] = v27;
    _40[5] = v28;
    _40[6] = v29;
    _40[7] = v30;
    v4 = _40;
  }
  if ( (unsigned int)v4[5] > 0x7FFFFFFF )
    return -1073741583;
  v16 = v4[4];
  if ( v16 )
  {
    v8 = PoCaptureReasonContext(v16, v6, 0, 0, (int)v21, &v22);
    if ( v8 < 0 )
      return v8;
    v17 = v22;
    v18 = (unsigned __int8)v21[0];
  }
  else
  {
    v17 = 0;
    v18 = 0;
  }
  v19 = ExpSetTimer(a1, v6, v4, v4[2], v4[3], v17, v18, v4[5], v4[6], v4[7]);
  v8 = v19;
  if ( v19 < 0 || v19 == 1073741861 )
  {
    if ( v17 )
      PoDestroyReasonContext(v17);
  }
  return v8;
}
