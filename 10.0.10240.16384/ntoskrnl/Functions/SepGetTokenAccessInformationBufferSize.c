// SepGetTokenAccessInformationBufferSize 
 
int __fastcall SepGetTokenAccessInformationBufferSize(_DWORD *a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int *a6, int *a7, int *a8, unsigned int *a9, int *a10, _DWORD *a11, unsigned int *a12, int *a13)
{
  unsigned int v14; // r7
  int v15; // r8
  int v16; // r1
  int v17; // r2
  int v18; // r4
  int v19; // r6
  int v20; // r7
  int v21; // lr
  int v22; // r5
  int *v23; // r5
  int v24; // t1
  int v26; // r3
  unsigned int v27; // r7
  unsigned int v28; // r4
  int v29; // r2
  int v30; // r2
  int v31; // r2
  int *v32; // r2
  int v33; // t1
  int v34; // [sp+0h] [bp-38h]
  int v35; // [sp+0h] [bp-38h]
  int v36; // [sp+4h] [bp-34h]
  int v37; // [sp+4h] [bp-34h]
  int v38; // [sp+8h] [bp-30h] BYREF
  _DWORD *v39; // [sp+Ch] [bp-2Ch]
  int v40; // [sp+10h] [bp-28h]
  int v41; // [sp+14h] [bp-24h]

  v38 = a2;
  v39 = a4;
  v14 = 0;
  v15 = 0;
  do
  {
    if ( (1 << (v14 - 32)) & a1[17] | (1 << v14) & a1[16] )
      ++v15;
    ++v14;
  }
  while ( v14 <= 0x23 );
  v16 = a1[32];
  v17 = a1[31];
  v18 = a1[122];
  v19 = 12 * v15 + 16;
  if ( v15 )
    v19 = 12 * v15 + 4;
  v20 = 8 * v17;
  v22 = 8 * v18;
  v34 = 8 * v17;
  v36 = 8 * v18;
  v40 = 8 * v17;
  v41 = 8 * v16;
  if ( v17 )
  {
    v23 = (int *)a1[37];
    do
    {
      v24 = *v23;
      v23 += 2;
      v20 += (4 * *(unsigned __int8 *)(v24 + 1) + 11) & 0xFFFFFFFC;
      --v17;
    }
    while ( v17 );
    v22 = 8 * v18;
    v34 = v20;
  }
  v21 = 8 * v16;
  if ( v16 )
    return sub_7E5B4C();
  if ( v18 )
  {
    v32 = (int *)a1[121];
    do
    {
      v33 = *v32;
      v32 += 2;
      v22 += (4 * *(unsigned __int8 *)(v33 + 1) + 11) & 0xFFFFFFFC;
      --v18;
    }
    while ( v18 );
  }
  v26 = a1[120];
  v27 = 0;
  if ( v26 )
    v27 = (4 * *(unsigned __int8 *)(v26 + 1) + 11) & 0xFFFFFFFC;
  if ( !v38 )
    a3 = a1[160];
  v28 = 0;
  if ( a3 )
    v28 = (4 * *(unsigned __int8 *)(a3 + 1) + 11) & 0xFFFFFFFC;
  ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, int *, int, int))AuthzBasepQueryInternalSecurityAttributesToken)(
    a1[119],
    0,
    0,
    &v38,
    v34,
    v36);
  v29 = v40;
  *v39 = v15;
  *a5 = v35;
  *a6 = v29;
  v30 = v41;
  *a7 = v21;
  *a8 = v30;
  *a9 = v27;
  *a10 = v22;
  *a11 = v37;
  v31 = v38;
  *a12 = v28;
  *a13 = v31;
  return v31 + v28 + v27 + v22 + v21 + v35 + v19 + 464;
}
