// RtlSelfRelativeToAbsoluteSD 
 
int __fastcall RtlSelfRelativeToAbsoluteSD(int a1, int a2, _DWORD *a3, int a4, unsigned int *a5, int a6, unsigned int *a7, int a8, _DWORD *a9, int a10, unsigned int *a11)
{
  int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r8
  unsigned int v17; // r9
  unsigned int v18; // r10
  int v19; // r0
  int v20; // r1
  int result; // r0
  unsigned int v22; // [sp+18h] [bp-40h] BYREF
  unsigned int v23; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v24; // [sp+20h] [bp-38h] BYREF
  unsigned int v25; // [sp+24h] [bp-34h] BYREF
  int v26; // [sp+28h] [bp-30h] BYREF
  int v27; // [sp+2Ch] [bp-2Ch] BYREF
  int v28; // [sp+30h] [bp-28h] BYREF
  int v29[9]; // [sp+34h] [bp-24h] BYREF

  if ( (*(_WORD *)(a1 + 2) & 0x8000) == 0 )
    return -1073741593;
  v14 = RtlpQuerySecurityDescriptor(a1, &v26, &v22, &v27, &v25, v29, &v24, &v28, &v23);
  v15 = a11;
  v16 = v23;
  v17 = v24;
  v18 = v25;
  if ( a2 && *a3 >= 0x14u && (v15 = a11, v22 <= *a9) && v24 <= *a5 && v23 <= *a7 && v25 <= *a11 )
  {
    v19 = memmove(a2, v14, 0x14u);
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 16) = 0;
    v20 = v26;
    *(_WORD *)(a2 + 2) &= 0x7FFFu;
    if ( v20 )
    {
      v19 = memmove(a8, v20, 4 * (*(unsigned __int8 *)(v20 + 1) + 2));
      *(_DWORD *)(a2 + 4) = a8;
    }
    if ( v27 )
    {
      v19 = memmove(a10, v27, 4 * (*(unsigned __int8 *)(v27 + 1) + 2));
      *(_DWORD *)(a2 + 8) = a10;
    }
    if ( v28 )
    {
      result = sub_819C08(v19);
    }
    else
    {
      if ( v29[0] )
      {
        memmove(a4, v29[0], *(unsigned __int16 *)(v29[0] + 2));
        *(_DWORD *)(a2 + 16) = a4;
      }
      result = 0;
    }
  }
  else
  {
    *a3 = 20;
    *v15 = v18;
    result = -1073741789;
    *a9 = v22;
    *a7 = v16;
    *a5 = v17;
  }
  return result;
}
