// WmipProbeAndCaptureGuidObjectAttributes 
 
int __fastcall WmipProbeAndCaptureGuidObjectAttributes(int a1, _DWORD *a2, int a3, unsigned int a4)
{
  int v4; // r4
  int v5; // r9
  _DWORD *v6; // r5
  _DWORD *v7; // r8
  _DWORD *v8; // r3
  unsigned int v10; // r2
  int v11; // [sp+Ch] [bp-1Ch]
  unsigned int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r3 = a4;
  v4 = a4;
  v5 = a3;
  v6 = a2;
  v7 = (_DWORD *)a1;
  if ( a4 >= MmUserProbeAddress )
    v4 = MmUserProbeAddress;
  memmove(a1, v4, 0x18u);
  v8 = (_DWORD *)v7[2];
  if ( !v8 )
    return -1073741811;
  if ( (unsigned int)v8 >= MmUserProbeAddress )
    v8 = (_DWORD *)MmUserProbeAddress;
  v11 = v8[1];
  *v6 = *v8;
  v6[1] = v11;
  if ( v7[4] || v7[5] )
    return -1073741811;
  if ( *(_WORD *)v6 != 90 )
    return -1073741811;
  v10 = v6[1];
  if ( v10 + 90 > MmUserProbeAddress || v10 + 90 < v10 )
    *(_BYTE *)MmUserProbeAddress = 0;
  memmove(v5, v6[1], *(unsigned __int16 *)v6);
  *(_WORD *)(v5 + 90) = 0;
  v6[1] = v5;
  v7[2] = v6;
  return 0;
}
