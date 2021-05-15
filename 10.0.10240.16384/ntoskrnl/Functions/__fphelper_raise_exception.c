// __fphelper_raise_exception 
 
int __fastcall _fphelper_raise_exception(unsigned int a1, __int16 a2, char a3, char a4, int a5, int a6, int a7, int a8)
{
  int v14; // r5
  int v15; // r10
  int v16; // r4
  int result; // r0
  int v18; // r3
  int v19; // r3
  int v20; // r1
  unsigned int v22; // [sp-80h] [bp-F8h] BYREF
  unsigned int v23; // [sp-7Ch] [bp-F4h]
  unsigned int v24; // [sp-78h] [bp-F0h]
  unsigned int v25; // [sp-74h] [bp-ECh]
  int v26; // [sp-70h] [bp-E8h]
  int v27; // [sp-6Ch] [bp-E4h]
  int v28; // [sp-60h] [bp-D8h]
  int v29; // [sp-40h] [bp-B8h]
  int v30; // [sp-30h] [bp-A8h]
  int v31; // [sp-2Ch] [bp-A4h]
  int v32; // [sp-20h] [bp-98h]
  unsigned int v33; // [sp+0h] [bp-78h]
  unsigned int *v34; // [sp+4h] [bp-74h] BYREF
  _DWORD v35[28]; // [sp+8h] [bp-70h] BYREF

  v34 = &v22;
  __asm { VMRS            R2, FPSCR }
  v33 = _R2;
  v22 = v22 & 0xFFFE0000 | (32 * (a2 & 0xFFF)) | ((_R2 & 0x400000 | (_R2 >> 2) & 0x200000) >> 21);
  v14 = 2048;
  v15 = 512;
  v16 = 1024;
  v23 = a1 & 4 | (4 * (a1 & 2 | (4 * (a1 & 1)))) | (((a1 >> 2) & 4 | a1 & 8) >> 2) | v23 & 0xFFFFFFE0;
  v24 = v24 & 0xFFFFFFE0 | ((v33 & 0x100 | ((v33 & 0x200 | ((v33 & 0x400 | (((_R2 >> 2) & 0x400 | v33 & 0x800) >> 2)) >> 2)) >> 2)) >> 4);
  v25 = v33 & 4 | ((_R2 & 8 | (_R2 >> 2) & 4) >> 2) | (4 * (v33 & 2 | (4 * (v33 & 1)))) | v25 & 0xFFFFFFE0;
  result = a7;
  v26 = a5;
  v27 = a6;
  v28 = v28 ^ ((unsigned __int8)v28 ^ (unsigned __int8)(2 * a3)) & 0x1E | 1;
  v29 &= 0xFFFFFFFE;
  v30 = a7;
  v31 = a8;
  v32 = v32 ^ ((unsigned __int8)v32 ^ (unsigned __int8)(2 * a4)) & 0x1E | 1;
  if ( (v25 & 0x10) != 0 && (v24 & 0x10) != 0 )
  {
    v18 = -1073741680;
  }
  else if ( (v25 & 8) != 0 && (v24 & 8) != 0 )
  {
    v18 = -1073741682;
  }
  else if ( (v25 & 4) != 0 && (v24 & 4) != 0 )
  {
    v18 = -1073741679;
  }
  else if ( (v25 & 2) != 0 && (v24 & 2) != 0 )
  {
    v18 = -1073741677;
  }
  else
  {
    if ( (v25 & 1) == 0 || (v24 & 1) == 0 )
      return result;
    v18 = -1073741681;
  }
  v35[0] = v18;
  v35[1] = 0;
  v35[2] = 0;
  v35[3] = _fphelper_raise_exception;
  v35[4] = 1;
  v35[5] = &v34;
  RtlRaiseException(v35);
  if ( (v24 & 0x10) != 0 )
    v19 = 256;
  else
    v19 = 0;
  if ( (v24 & 8) == 0 )
    v15 = 0;
  if ( (v24 & 4) == 0 )
    v16 = 0;
  if ( (v24 & 2) == 0 )
    v14 = 0;
  if ( (v24 & 1) != 0 )
    v20 = 4096;
  else
    v20 = 0;
  _R3 = v20 | ((v22 & 2 | (4 * (v22 & 1))) << 21) | v14 | v33 & 0xFF3FE0FF | v19 | v15 | v16;
  __asm { VMSR            FPSCR, R3 }
  return v30;
}
