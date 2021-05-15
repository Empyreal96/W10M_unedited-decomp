// NtSetTimer 
 
int __fastcall NtSetTimer(int a1, unsigned int a2, int a3, int a4, unsigned __int8 a5, int a6, _BYTE *a7)
{
  _DWORD *v7; // r5
  int v8; // r8
  char v9; // r10
  int v10; // r2
  int v11; // r4
  _DWORD *v12; // r6
  unsigned __int8 v13; // r2
  int v14; // r0
  char v16[3]; // [sp+19h] [bp-47h] BYREF
  int v17; // [sp+1Ch] [bp-44h]
  int v18; // [sp+20h] [bp-40h]
  int v19; // [sp+24h] [bp-3Ch]
  _QWORD *v20; // [sp+28h] [bp-38h]
  __int64 v21; // [sp+30h] [bp-30h] BYREF
  _QWORD v22[5]; // [sp+38h] [bp-28h] BYREF
  int varg_r0; // [sp+68h] [bp+8h]
  unsigned int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r1 = a2;
  v17 = a4;
  varg_r3 = a4;
  v18 = a3;
  varg_r2 = a3;
  v7 = (_DWORD *)a2;
  v19 = a1;
  varg_r0 = a1;
  v8 = 0;
  v16[0] = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = v16[0];
  if ( v16[0] )
  {
    if ( a2 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    v21 = *(_QWORD *)v7;
    v22[0] = v21;
    v7 = v22;
    v20 = v22;
    v10 = a5;
  }
  else
  {
    v10 = a5;
    if ( a5 && PoPowerDownActionInProgress )
      v8 = 1;
  }
  if ( a6 < 0 )
    return -1073741580;
  if ( !v10 || v8 )
  {
    v12 = 0;
    v13 = 0;
  }
  else
  {
    v11 = PoCaptureReasonContext(0, v16[0], 0, 1, (int)v16, &v21);
    if ( v11 < 0 )
      return v11;
    v12 = (_DWORD *)v21;
    v13 = v16[0];
  }
  v14 = ExpSetTimer(v19, v9, v7, v18, v17, (int)v12, v13, a6, 0, a7);
  v11 = v14;
  if ( (v14 < 0 || v14 == 1073741861) && v12 )
    PoDestroyReasonContext(v12);
  if ( v11 >= 0 && v8 )
    v11 = 1073741861;
  return v11;
}
