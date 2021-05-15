// PopSqmThermalZoneEnumeration 
 
int __fastcall PopSqmThermalZoneEnumeration(int result, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v13; // r9
  unsigned __int16 *v14; // r1
  int v15; // [sp+8h] [bp-108h] BYREF
  int v16; // [sp+Ch] [bp-104h] BYREF
  int v17; // [sp+10h] [bp-100h] BYREF
  int v18; // [sp+14h] [bp-FCh] BYREF
  int v19; // [sp+18h] [bp-F8h] BYREF
  int v20; // [sp+1Ch] [bp-F4h] BYREF
  int v21; // [sp+20h] [bp-F0h] BYREF
  int v22; // [sp+24h] [bp-ECh] BYREF
  int v23; // [sp+28h] [bp-E8h] BYREF
  int v24[8]; // [sp+30h] [bp-E0h] BYREF
  char v25[16]; // [sp+50h] [bp-C0h] BYREF
  int *v26; // [sp+60h] [bp-B0h]
  int v27; // [sp+64h] [bp-ACh]
  int v28; // [sp+68h] [bp-A8h]
  int v29; // [sp+6Ch] [bp-A4h]
  int *v30; // [sp+70h] [bp-A0h]
  int v31; // [sp+74h] [bp-9Ch]
  int v32; // [sp+78h] [bp-98h]
  int v33; // [sp+7Ch] [bp-94h]
  int *v34; // [sp+80h] [bp-90h]
  int v35; // [sp+84h] [bp-8Ch]
  int v36; // [sp+88h] [bp-88h]
  int v37; // [sp+8Ch] [bp-84h]
  int *v38; // [sp+90h] [bp-80h]
  int v39; // [sp+94h] [bp-7Ch]
  int v40; // [sp+98h] [bp-78h]
  int v41; // [sp+9Ch] [bp-74h]
  int *v42; // [sp+A0h] [bp-70h]
  int v43; // [sp+A4h] [bp-6Ch]
  int v44; // [sp+A8h] [bp-68h]
  int v45; // [sp+ACh] [bp-64h]
  int *v46; // [sp+B0h] [bp-60h]
  int v47; // [sp+B4h] [bp-5Ch]
  int v48; // [sp+B8h] [bp-58h]
  int v49; // [sp+BCh] [bp-54h]
  int *v50; // [sp+C0h] [bp-50h]
  int v51; // [sp+C4h] [bp-4Ch]
  int v52; // [sp+C8h] [bp-48h]
  int v53; // [sp+CCh] [bp-44h]
  int *v54; // [sp+D0h] [bp-40h]
  int v55; // [sp+D4h] [bp-3Ch]
  int v56; // [sp+D8h] [bp-38h]
  int v57; // [sp+DCh] [bp-34h]
  int *v58; // [sp+E0h] [bp-30h]
  int v59; // [sp+E4h] [bp-2Ch]
  int v60; // [sp+E8h] [bp-28h]
  int v61; // [sp+ECh] [bp-24h]

  v13 = result;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
    if ( result )
    {
      v14 = *(unsigned __int16 **)(v13 + 4);
      v22 = a4;
      v23 = a6;
      v15 = a10;
      v16 = a9;
      v17 = a7;
      v20 = a3;
      v21 = a8;
      v18 = a5;
      v19 = a2;
      TlgCreateWsz((int)v25, v14);
      v26 = &v23;
      v27 = 0;
      v28 = 4;
      v29 = 0;
      v30 = &v17;
      v31 = 0;
      v32 = 4;
      v33 = 0;
      v34 = &v21;
      v35 = 0;
      v36 = 4;
      v37 = 0;
      v38 = &v19;
      v39 = 0;
      v40 = 4;
      v41 = 0;
      v42 = &v15;
      v43 = 0;
      v44 = 4;
      v45 = 0;
      v46 = &v16;
      v47 = 0;
      v48 = 4;
      v49 = 0;
      v50 = &v18;
      v51 = 0;
      v52 = 4;
      v53 = 0;
      v54 = &v20;
      v55 = 0;
      v56 = 4;
      v57 = 0;
      v58 = &v22;
      v59 = 0;
      v60 = 4;
      v61 = 0;
      result = TlgWrite(&dword_6163C8, (unsigned __int8 *)&byte_414621[1], 0, 0, 12, v24);
    }
  }
  return result;
}
