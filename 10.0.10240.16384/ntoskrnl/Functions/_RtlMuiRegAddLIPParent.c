// _RtlMuiRegAddLIPParent 
 
int __fastcall RtlMuiRegAddLIPParent(_DWORD *a1, int a2, unsigned int a3, unsigned __int16 *a4)
{
  int v5; // r7
  int result; // r0
  __int16 v10; // r4
  int v11; // r1
  __int16 v12; // r5
  int v13; // r3
  _WORD *v14; // r2
  int v15; // r3
  __int16 v16[2]; // [sp+0h] [bp-28h] BYREF
  int v17; // [sp+4h] [bp-24h] BYREF
  _DWORD v18[8]; // [sp+8h] [bp-20h] BYREF

  v16[1] = HIWORD(a1);
  v18[0] = a3;
  v18[1] = a4;
  v5 = -1;
  v16[0] = -1;
  v17 = 0;
  if ( !a1 || !a2 || a3 >= 4 || !a4 || !*a4 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v18, a4);
  if ( !RtlCultureNameToLCID((unsigned __int16 *)v18, &v17) )
    return -1073741823;
  result = RtlpMuiRegGetOrAddString(a1, a4, 1, v16);
  if ( result < 0 )
    return -1073741823;
  v10 = v16[0];
  if ( v16[0] < 0 )
    return -1073741823;
  v11 = 0;
  v12 = v17;
  v13 = a1[5];
  v14 = *(_WORD **)(v13 + 12);
  if ( !*(_WORD *)(v13 + 6) )
  {
LABEL_18:
    if ( v5 < 0 )
    {
      if ( (_WORD)v17 )
      {
        *(_WORD *)(a2 + 8) = (1 << (2 * a3)) | *(_WORD *)(a2 + 8) & ~(3 << (2 * a3));
        *(_WORD *)(2 * a3 + a2 + 12) = v12;
      }
      else
      {
        if ( v16[0] <= 0 )
          return -1073741823;
        *(_WORD *)(a2 + 8) = *(_WORD *)(a2 + 8) & ~(unsigned __int16)(3 << (2 * a3)) | (3 << (2 * a3));
        *(_WORD *)(2 * a3 + a2 + 12) = v10;
      }
    }
    else
    {
      *(_WORD *)(a2 + 8) = (2 << (2 * a3)) | *(_WORD *)(a2 + 8) & ~(3 << (2 * a3));
      *(_WORD *)(2 * a3 + a2 + 12) = v5;
    }
    return result;
  }
  while ( 1 )
  {
    if ( (*v14 & 0x3004) != 0 || (*v14 & 0x20) == 0 )
      goto LABEL_21;
    if ( (unsigned __int16)v17 != 4096 && (unsigned __int16)v17 != 5120 )
      break;
    if ( (__int16)v14[3] == v16[0] )
      goto LABEL_17;
LABEL_21:
    ++v11;
    v14 += 14;
    if ( v11 >= *(unsigned __int16 *)(v13 + 6) )
      goto LABEL_18;
  }
  if ( (unsigned __int16)v14[2] != (unsigned __int16)v17 )
    goto LABEL_21;
  v15 = (__int16)v14[3];
  if ( v15 < 0 || v15 == v16[0] )
  {
LABEL_17:
    v5 = (__int16)v11;
    goto LABEL_18;
  }
  return -1073741823;
}
