// PspQueryPooledQuotaLimits 
 
int __fastcall PspQueryPooledQuotaLimits(int a1, int a2, int a3, _DWORD *a4, char a5)
{
  int result; // r0
  unsigned int *v8; // r3
  unsigned int v9; // r5
  unsigned int v10; // r10
  unsigned int v11; // r1
  unsigned int v12; // r4
  unsigned int v13; // lr
  unsigned int v14; // r0
  unsigned int v15; // r3
  int v16; // [sp+10h] [bp-48h] BYREF
  unsigned int v17; // [sp+14h] [bp-44h]
  _DWORD v18[2]; // [sp+18h] [bp-40h] BYREF
  unsigned int v19; // [sp+20h] [bp-38h]
  unsigned int v20; // [sp+24h] [bp-34h]
  unsigned int v21; // [sp+28h] [bp-30h]
  unsigned int v22; // [sp+2Ch] [bp-2Ch]
  unsigned int v23; // [sp+30h] [bp-28h]
  unsigned int v24; // [sp+34h] [bp-24h]
  unsigned int v25; // [sp+38h] [bp-20h]

  if ( a3 != 36 )
    return -1073741820;
  result = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, a5, 2035381072, &v16, 0);
  if ( result >= 0 )
  {
    v8 = *(unsigned int **)(v16 + 332);
    __dmb(0xBu);
    v19 = v8[96];
    v9 = v8[64];
    v18[1] = v9;
    v10 = v8[65];
    v18[0] = v10;
    v11 = v8[32];
    v22 = v11;
    v12 = *v8;
    v21 = *v8;
    v17 = v8[1];
    v20 = v17;
    v13 = v8[160];
    v25 = v13;
    v14 = v8[128];
    v24 = v14;
    v15 = v8[129];
    v23 = v15;
    if ( v19 <= v9 )
      v19 = v9;
    if ( v11 <= v12 )
      v22 = v12;
    if ( v13 <= v14 )
      v25 = v14;
    if ( v10 <= v9 )
      v18[0] = v9;
    if ( v17 <= v12 )
      v20 = v12;
    if ( v15 <= v14 )
      v23 = v14;
    ObfDereferenceObjectWithTag(v16);
    memmove(a2, (int)v18, 0x24u);
    if ( a4 )
      *a4 = 36;
    result = 0;
  }
  return result;
}
