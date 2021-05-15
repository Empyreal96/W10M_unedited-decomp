// SdbpCheckAllAttributes 
 
int __fastcall SdbpCheckAllAttributes(int *a1, int a2, int a3, int a4, int a5)
{
  int v5; // r10
  int v6; // r9
  int v7; // r5
  _BYTE *v8; // r6
  int v9; // r4
  unsigned int v10; // r7
  __int16 *v11; // r8
  __int16 v12; // r4
  int v13; // r2
  int v14; // r0
  int v15; // r2
  unsigned __int16 *v16; // r9
  int v17; // r3
  unsigned int v18; // r10
  void (__fastcall *v19)(int, unsigned __int16 *, unsigned int, int); // r4
  int v21; // [sp+8h] [bp-48h]
  int v22; // [sp+Ch] [bp-44h] BYREF
  int v23; // [sp+10h] [bp-40h]
  int v24; // [sp+14h] [bp-3Ch] BYREF
  int v25; // [sp+18h] [bp-38h]
  int v26; // [sp+1Ch] [bp-34h]
  int *v27; // [sp+20h] [bp-30h]
  __int64 v28; // [sp+28h] [bp-28h] BYREF

  v21 = a3;
  v5 = a4;
  v25 = a2;
  v26 = a4;
  v6 = a3;
  v7 = 1;
  v27 = a1;
  *a1 = 0;
  v22 = 1;
  if ( !a5 || !*(_DWORD *)(a5 + 520) )
    return 0;
  v8 = AslAlloc((int)a1, 768);
  if ( !v8 )
    return -1073741801;
  v10 = 0;
  v11 = g_rgAttributeTags;
  while ( 1 )
  {
    v12 = *v11;
    v13 = (unsigned __int16)*v11;
    v23 = v13;
    v14 = SdbFindFirstTag(v6, v5, v13);
    if ( !v14 )
      goto LABEL_20;
    v16 = 0;
    v17 = v12 & 0xF000;
    v18 = 0;
    switch ( v17 )
    {
      case 16384:
        v24 = SdbReadDWORDTag(v21, v14, 0);
        v16 = (unsigned __int16 *)&v24;
        v18 = 4;
        break;
      case 20480:
        v28 = SdbReadQWORDTag(v21, v14, 0i64);
        v16 = (unsigned __int16 *)&v28;
        v18 = 8;
        break;
      case 24576:
        v16 = (unsigned __int16 *)SdbGetStringTagPtr(v21, v14, v15, 24576);
        v18 = 2 * wcslen(v16);
        break;
    }
    v9 = AslFileAllocAndGetAttributes(v8, a5, 1 << *((_DWORD *)v11 + 1), 1 << (*((_DWORD *)v11 + 1) - 32));
    if ( v9 < 0 )
      break;
    if ( (*(_DWORD *)&v8[24 * *((_DWORD *)v11 + 1) + 16] & 1) == 0 )
      goto LABEL_22;
    if ( !SdbpCheckAttribute(&v22, v23, v16, v18, &v8[24 * *((_DWORD *)v11 + 1)]) )
    {
      v9 = -1073741595;
      AslLogCallPrintf(1, (int)"SdbpCheckAllAttributes", 738, "SdbpCheckAttribute failed [%x]", -1073741595);
      goto LABEL_23;
    }
    v7 = v22;
    v19 = *(void (__fastcall **)(int, unsigned __int16 *, unsigned int, int))(v25 + 620);
    if ( v19 )
      v19(v23, v16, v18, v22);
    if ( !v7 )
    {
LABEL_21:
      *v27 = v7;
LABEL_22:
      v9 = 0;
      goto LABEL_23;
    }
    v6 = v21;
    v5 = v26;
LABEL_20:
    ++v10;
    v11 += 4;
    if ( v10 >= 0x21 )
      goto LABEL_21;
  }
  AslLogCallPrintf(
    1,
    (int)"SdbpCheckAllAttributes",
    715,
    "Failed to get attribute %d [%x]",
    *(_DWORD *)&g_rgAttributeTags[4 * v10 + 2],
    v9);
LABEL_23:
  AslFileFreeAttributes(v8);
  ExFreePoolWithTag((unsigned int)v8);
  return v9;
}
