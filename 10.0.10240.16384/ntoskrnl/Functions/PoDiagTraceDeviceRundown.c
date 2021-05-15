// PoDiagTraceDeviceRundown 
 
int __fastcall PoDiagTraceDeviceRundown(int a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  unsigned int v4; // r0
  int v5; // r3
  unsigned int v6; // r1
  int v7; // r3
  char v9; // [sp+8h] [bp-70h] BYREF
  __int16 v10; // [sp+Ah] [bp-6Eh] BYREF
  __int16 v11; // [sp+Ch] [bp-6Ch] BYREF
  int *v12; // [sp+10h] [bp-68h]
  int v13; // [sp+14h] [bp-64h]
  int v14; // [sp+18h] [bp-60h]
  int v15; // [sp+1Ch] [bp-5Ch]
  char *v16; // [sp+20h] [bp-58h]
  int v17; // [sp+24h] [bp-54h]
  int v18; // [sp+28h] [bp-50h]
  int v19; // [sp+2Ch] [bp-4Ch]
  __int16 *v20; // [sp+30h] [bp-48h]
  int v21; // [sp+34h] [bp-44h]
  int v22; // [sp+38h] [bp-40h]
  int v23; // [sp+3Ch] [bp-3Ch]
  int v24; // [sp+40h] [bp-38h]
  int v25; // [sp+44h] [bp-34h]
  unsigned int v26; // [sp+48h] [bp-30h]
  int v27; // [sp+4Ch] [bp-2Ch]
  __int16 *v28; // [sp+50h] [bp-28h]
  int v29; // [sp+54h] [bp-24h]
  int v30; // [sp+58h] [bp-20h]
  int v31; // [sp+5Ch] [bp-1Ch]
  int v32; // [sp+60h] [bp-18h]
  int v33; // [sp+64h] [bp-14h]
  unsigned int v34; // [sp+68h] [bp-10h]
  int v35; // [sp+6Ch] [bp-Ch]
  int varg_r0[4]; // [sp+80h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = (int)a2;
  varg_r0[2] = (int)a3;
  varg_r0[3] = a4;
  v9 = a4 - 1;
  v16 = &v9;
  v17 = 0;
  v12 = varg_r0;
  v4 = *a2;
  v18 = 1;
  v19 = 0;
  v10 = v4 >> 1;
  v20 = &v10;
  v21 = 0;
  v22 = 2;
  v23 = 0;
  v5 = *((_DWORD *)a2 + 1);
  v6 = *a3;
  v24 = v5;
  v25 = 0;
  v26 = v4;
  v27 = 0;
  v11 = v6 >> 1;
  v28 = &v11;
  v13 = 0;
  v29 = 0;
  v14 = 4;
  v30 = 2;
  v15 = 0;
  v31 = 0;
  if ( v6 )
  {
    v7 = *((_DWORD *)a3 + 1);
    v34 = v6;
    v32 = v7;
    v33 = 0;
    v35 = 0;
  }
  return EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_RUNDOWN, 0);
}
