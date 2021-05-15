// PerfLogImageUnload 
 
int __fastcall PerfLogImageUnload(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9)
{
  unsigned __int16 *v11; // r5
  int result; // r0
  bool v13; // nf
  _DWORD *v14; // r0
  int v15; // r3
  int v16; // [sp+8h] [bp-90h] BYREF
  _BYTE *v17; // [sp+Ch] [bp-8Ch]
  _BYTE v18[8]; // [sp+10h] [bp-88h] BYREF
  _DWORD v19[3]; // [sp+18h] [bp-80h] BYREF
  int v20; // [sp+24h] [bp-74h]
  int v21; // [sp+28h] [bp-70h]
  char v22; // [sp+2Ch] [bp-6Ch]
  char v23; // [sp+2Dh] [bp-6Bh]
  __int16 v24; // [sp+2Eh] [bp-6Ah]
  int v25; // [sp+30h] [bp-68h]
  int v26; // [sp+34h] [bp-64h]
  int v27; // [sp+38h] [bp-60h]
  int v28; // [sp+3Ch] [bp-5Ch]
  int v29; // [sp+40h] [bp-58h]
  int v30[20]; // [sp+48h] [bp-50h] BYREF

  v11 = (unsigned __int16 *)a1;
  v17 = (_BYTE *)a1;
  result = 0;
  v16 = 0;
  if ( a2 )
  {
    if ( FltMgrCallbacks )
    {
      v13 = (*(int (__fastcall **)(int, int, _BYTE *, int *))(FltMgrCallbacks + 8))(a2, 512, v18, &v16) < 0;
      result = v16;
      if ( !v13 )
      {
        v11 = (unsigned __int16 *)v18;
        v17 = v18;
      }
    }
  }
  if ( v11 && *v11 && *((_DWORD *)v11 + 1) )
  {
    v19[2] = a3;
    v19[0] = a4;
    v19[1] = a5;
    v20 = a6;
    v24 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v21 = 0;
    v25 = 0;
    v22 = a7;
    v23 = a8;
    if ( a3 )
    {
      v14 = (_DWORD *)RtlImageNtHeader(a4);
      if ( v14 )
      {
        v20 = v14[22];
        v21 = v14[2];
        v25 = v14[13];
      }
    }
    if ( (dword_61AD40 & 4) != 0 )
      EtwpPsProvTraceImage(v11, v19, 5122, a9);
    v30[0] = (int)v19;
    v30[1] = 0;
    v30[2] = 44;
    v30[3] = 0;
    v30[4] = *((_DWORD *)v11 + 1);
    v30[5] = 0;
    v30[6] = *v11;
    v30[7] = 0;
    v30[8] = (int)&EtwpNull;
    v30[9] = 0;
    v30[10] = 2;
    v30[11] = 0;
    v15 = 4200707;
    if ( a9 )
      v15 = 20977923;
    EtwTraceKernelEvent(v30, 3, 4u, 5122, v15);
    result = v16;
  }
  if ( result )
    result = (*(int (**)(void))(FltMgrCallbacks + 12))();
  return result;
}
