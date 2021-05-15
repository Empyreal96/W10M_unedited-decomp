// NtCreateThreadEx 
 
int __fastcall NtCreateThreadEx(_DWORD *a1, int a2, int a3, int a4, __int64 a5, int a6, int a7, int a8, int a9, int a10)
{
  int v14; // r4
  _DWORD *v15; // r2
  int v16; // r2
  char v18[4]; // [sp+38h] [bp-2D8h] BYREF
  int v19; // [sp+3Ch] [bp-2D4h]
  int v20; // [sp+40h] [bp-2D0h]
  int v21; // [sp+44h] [bp-2CCh]
  _DWORD v22[6]; // [sp+48h] [bp-2C8h] BYREF
  _DWORD *v23[60]; // [sp+60h] [bp-2B0h] BYREF
  int v24; // [sp+150h] [bp-1C0h] BYREF
  _BYTE v25[412]; // [sp+154h] [bp-1BCh] BYREF
  _DWORD *varg_r0; // [sp+318h] [bp+8h]
  int varg_r1; // [sp+31Ch] [bp+Ch]
  int varg_r2; // [sp+320h] [bp+10h]
  int varg_r3; // [sp+324h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  v22[0] = 0;
  v22[1] = 0;
  v22[2] = 0;
  v22[3] = 0;
  v22[4] = 0;
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  if ( (a6 & 0xFFFFFFE0) != 0 )
    return -1073741579;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v15 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
  }
  v18[0] = 0;
  v20 = a8;
  v21 = a9;
  v19 = a7;
  memset(v23, 0, sizeof(v23));
  if ( !a10
    || (v14 = PspBuildCreateProcessContext(a10, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, v23),
        v14 >= 0) )
  {
    PspCreateUserContext((int)&v24, PspUserThreadStart, a5);
    v14 = PspCreateThread(a1, a2, a3, a4, 0, (int)v23, v23[3], (int)&v24, (int)v22, a6, v16, SHIDWORD(a5), v18);
    PspDeleteCreateProcessContext(v23);
  }
  return v14;
}
