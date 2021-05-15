// PnpTraceDeviceConfig 
 
unsigned __int16 *__fastcall PnpTraceDeviceConfig(unsigned __int16 *result, unsigned __int16 *a2, unsigned __int16 *a3, unsigned __int16 *a4, unsigned __int16 *a5, unsigned __int16 *a6, unsigned __int16 *a7, char a8, char a9, char a10, int a11)
{
  unsigned __int16 *v14; // r9
  char v15; // [sp+8h] [bp-110h] BYREF
  char v16; // [sp+9h] [bp-10Fh] BYREF
  char v17; // [sp+Ah] [bp-10Eh] BYREF
  int v18; // [sp+Ch] [bp-10Ch] BYREF
  int v19; // [sp+10h] [bp-108h] BYREF
  _DWORD v20[12]; // [sp+18h] [bp-100h] BYREF
  char v21[16]; // [sp+48h] [bp-D0h] BYREF
  char v22[16]; // [sp+58h] [bp-C0h] BYREF
  char v23[16]; // [sp+68h] [bp-B0h] BYREF
  char v24[16]; // [sp+78h] [bp-A0h] BYREF
  char v25[16]; // [sp+88h] [bp-90h] BYREF
  char v26[16]; // [sp+98h] [bp-80h] BYREF
  char v27[16]; // [sp+A8h] [bp-70h] BYREF
  char *v28; // [sp+B8h] [bp-60h]
  int v29; // [sp+BCh] [bp-5Ch]
  int v30; // [sp+C0h] [bp-58h]
  int v31; // [sp+C4h] [bp-54h]
  char *v32; // [sp+C8h] [bp-50h]
  int v33; // [sp+CCh] [bp-4Ch]
  int v34; // [sp+D0h] [bp-48h]
  int v35; // [sp+D4h] [bp-44h]
  char *v36; // [sp+D8h] [bp-40h]
  int v37; // [sp+DCh] [bp-3Ch]
  int v38; // [sp+E0h] [bp-38h]
  int v39; // [sp+E4h] [bp-34h]
  int *v40; // [sp+E8h] [bp-30h]
  int v41; // [sp+ECh] [bp-2Ch]
  int v42; // [sp+F0h] [bp-28h]
  int v43; // [sp+F4h] [bp-24h]

  v14 = result;
  if ( (unsigned int)dword_6174F0 > 5 )
  {
    result = (unsigned __int16 *)TlgKeywordOn((int)&dword_6174F0, 0x400000000000i64);
    if ( result )
    {
      v18 = 0;
      v19 = a11;
      v17 = a8;
      v20[8] = &v18;
      v20[9] = 0;
      v16 = a9;
      v20[10] = 4;
      v20[11] = 0;
      v15 = a10;
      TlgCreateWsz((int)v21, v14);
      TlgCreateWsz((int)v22, a2);
      TlgCreateWsz((int)v23, a3);
      TlgCreateWsz((int)v24, a4);
      TlgCreateWsz((int)v25, a5);
      TlgCreateWsz((int)v26, a6);
      TlgCreateWsz((int)v27, a7);
      v28 = &v17;
      v29 = 0;
      v30 = 1;
      v31 = 0;
      v32 = &v16;
      v33 = 0;
      v34 = 1;
      v35 = 0;
      v36 = &v15;
      v37 = 0;
      v38 = 1;
      v39 = 0;
      v40 = &v19;
      v41 = 0;
      v42 = 4;
      v43 = 0;
      result = (unsigned __int16 *)TlgWrite(&dword_6174F0, (unsigned __int8 *)&byte_413AA9[1], 0, 0, 14, v20);
    }
  }
  return result;
}
