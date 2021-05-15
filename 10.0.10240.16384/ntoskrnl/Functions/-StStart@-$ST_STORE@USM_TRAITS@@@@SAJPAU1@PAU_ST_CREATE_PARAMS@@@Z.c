// -StStart@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_CREATE_PARAMS@@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StStart(int a1, int *a2)
{
  unsigned int v3; // r2
  int v5; // r9
  unsigned int v6; // r4
  int v7; // r1
  unsigned int v8; // r5
  int result; // r0
  int v10; // r1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r4
  _BYTE *v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r3
  int v19; // r0
  int v20; // r3
  int v21; // r0
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // [sp+8h] [bp-80h] BYREF
  __int16 v27; // [sp+Ch] [bp-7Ch]
  __int16 v28; // [sp+Eh] [bp-7Ah]
  int v29[2]; // [sp+10h] [bp-78h] BYREF
  unsigned int v30; // [sp+18h] [bp-70h] BYREF
  unsigned int v31; // [sp+1Ch] [bp-6Ch] BYREF
  _DWORD v32[2]; // [sp+20h] [bp-68h] BYREF
  _DWORD v33[24]; // [sp+28h] [bp-60h] BYREF

  v3 = a2[2];
  if ( !v3 || ((v3 - 1) & v3) != 0 || v3 > 0x20000 || (v5 = 4096, v3 < 0x1000) )
    JUMPOUT(0x510A80);
  v6 = a2[3];
  if ( !v6 || v6 > 0x40000 )
    goto LABEL_51;
  v7 = *a2;
  v8 = (unsigned __int8)*a2;
  if ( v8 == 1 )
    return sub_5109AC();
  if ( !(unsigned __int8)*a2 && (a2[4] || a2[9]) || v8 >= 2 || (v7 & 0xFFF80000) != 0 )
LABEL_51:
    JUMPOUT(0x510A94);
  if ( (v7 & 0x200) != 0 )
    JUMPOUT(0x5109D2);
  if ( (v7 & 0x400) != 0 )
    JUMPOUT(0x5109DC);
  if ( a2[7] )
    JUMPOUT(0x5109E6);
  if ( a2[6] )
    JUMPOUT(0x5109EC);
  v10 = 0;
  do
    ++v10;
  while ( 16 << v10 < v3 );
  *(_DWORD *)(a1 + 24) = (1 << v10) - 1;
  *(_DWORD *)(a1 + 28) = v10;
  *(_DWORD *)(a1 + 32) = 1 << v10;
  if ( a2[2] == 0x20000 )
    *(_DWORD *)(a1 + 32) = (1 << v10) - 1;
  if ( *(_BYTE *)a2 )
    JUMPOUT(0x5109F2);
  *(_DWORD *)(a1 + 36) = (unsigned int)(*(_DWORD *)(a1 + 40) + 4111) >> 4;
  if ( a2[3] > (unsigned int)(1 << (32 - v10)) )
    JUMPOUT(0x510A06);
  v11 = a2[1];
  v12 = a2[2];
  v13 = a2[3];
  *(_DWORD *)a1 = *a2;
  *(_DWORD *)(a1 + 4) = v11;
  *(_DWORD *)(a1 + 8) = v12;
  *(_DWORD *)(a1 + 12) = v13;
  v14 = a2[5];
  *(_DWORD *)(a1 + 16) = a2[4];
  *(_DWORD *)(a1 + 20) = v14;
  v15 = a2[3];
  v16 = (_BYTE *)ExAllocatePoolWithTag(512, 2 * v15, 1951624563);
  *(_DWORD *)(a1 + 44) = v16;
  if ( !v16 )
    goto LABEL_48;
  memset(v16, 0, 2 * v15);
  if ( *(_BYTE *)a2 == 1 )
    JUMPOUT(0x510A0C);
  if ( (*((_WORD *)a2 + 1) & 1) == 0 )
    JUMPOUT(0x510A48);
  *(_WORD *)(a1 + 1656) = 3;
  result = RtlGetCompressionWorkSpaceSize(*(unsigned __int16 *)(a1 + 1656), &v30, &v31);
  if ( result >= 0 )
  {
    v17 = v30;
    v18 = v31;
    *(_DWORD *)(a1 + 1652) = v31;
    if ( v17 <= v18 )
      JUMPOUT(0x510A50);
    if ( !v17 || (v19 = ExAllocatePoolWithTag(512, v17, 1951624563), (*(_DWORD *)(a1 + 1648) = v19) != 0) )
    {
      v20 = a2[8];
      if ( !v20 )
      {
        v33[4] = 2048;
        v33[5] = 0;
        v33[6] = 4096;
        v33[7] = 0;
        v33[8] = 0x2000;
        v33[9] = 0;
        v33[10] = 0x4000;
        v33[11] = 0;
        v33[12] = 0x8000;
        v33[13] = 0;
        v33[14] = -1;
        v33[15] = 0;
        v33[2] = -1;
        v33[3] = 100000000;
        v33[0] = -1;
        v33[1] = 0;
        v32[0] = -1;
        v32[1] = 0;
        v29[0] = (int)v33;
        v29[1] = (int)v32;
        v26 = 983104;
        v27 = 0;
        v28 = 0;
        result = StEtaStart(a1 + 1600, v29, &v26);
        if ( result < 0 )
          return result;
        v20 = a1 + 1600;
      }
      *(_DWORD *)(a1 + 1592) = v20;
      if ( *(_BYTE *)a2 )
        JUMPOUT(0x510A58);
      if ( a2[7] )
        return -1073741066;
      if ( (*a2 & 0x8000) != 0 )
        v5 = 0x2000;
      v21 = ExAllocatePoolWithTag(512, v5, 1951624563);
      *(_DWORD *)(a1 + 1768) = v21;
      if ( v21 )
      {
        if ( *(_BYTE *)a2 == 1 )
          JUMPOUT(0x510A86);
        v22 = a2[3];
        v23 = *a2;
        if ( (unsigned __int8)*a2 )
        {
          v25 = ((unsigned int)*a2 >> 8) & 1;
        }
        else
        {
          v24 = ((unsigned int)*a2 >> 8) & 1 | 0x40;
          v29[0] = v24;
          if ( (v23 & 0x40000) == 0 )
            goto LABEL_44;
          v25 = v24 | 0x60;
        }
        v29[0] = v25;
LABEL_44:
        v26 = 0;
        result = ((int (__fastcall *)(int, int, int *, int, int *, int))ST_STORE<SM_TRAITS>::StDmStart)(
                   a1,
                   a1 + 56,
                   v29,
                   a2[9],
                   &v26,
                   v22);
        if ( result >= 0 )
          result = 0;
        return result;
      }
    }
LABEL_48:
    result = -1073741670;
  }
  return result;
}
