// PoCaptureReasonContext 
 
int __fastcall PoCaptureReasonContext(unsigned int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r8
  _DWORD *v8; // r5
  int v9; // r5
  int v11; // [sp+8h] [bp-58h]
  int v12; // [sp+Ch] [bp-54h]
  int v13; // [sp+10h] [bp-50h]
  int v14; // [sp+14h] [bp-4Ch]
  int v15; // [sp+18h] [bp-48h]
  int v16; // [sp+1Ch] [bp-44h]
  int v17; // [sp+20h] [bp-40h]
  _DWORD _28[17]; // [sp+28h] [bp-38h] BYREF
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  _28[16] = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v7 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v8 = (_DWORD *)a1;
  *a6 = 0;
  if ( a1 && (_BYTE)a2 )
  {
    if ( !a4 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a1 + 28 > MmUserProbeAddress || a1 + 28 < a1 )
        *(_BYTE *)MmUserProbeAddress = 0;
      v11 = *(_DWORD *)a1;
      v12 = *(_DWORD *)(a1 + 4);
      v13 = *(_DWORD *)(a1 + 8);
      v14 = *(_DWORD *)(a1 + 12);
      v15 = *(_DWORD *)(a1 + 16);
      v16 = *(_DWORD *)(a1 + 20);
      v17 = *(_DWORD *)(a1 + 24);
      __dmb(0xBu);
      _28[0] = v11;
      _28[1] = v12;
      _28[2] = v13;
      _28[3] = v14;
      _28[4] = v15;
      _28[5] = v16;
      _28[6] = v17;
      v8 = _28;
    }
    v9 = PopCaptureReasonContext(v8, (char)a2, a5, a6);
  }
  else
  {
    v9 = PopCaptureReasonContext(a1, (char)a2, a5, a6);
  }
  if ( v9 >= 0 )
    PoGetRequester(v7, a3, *a6);
  return v9;
}
