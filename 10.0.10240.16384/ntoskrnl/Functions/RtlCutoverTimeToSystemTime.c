// RtlCutoverTimeToSystemTime 
 
int __fastcall RtlCutoverTimeToSystemTime(_WORD *a1, _QWORD *a2, int a3, int a4)
{
  unsigned int v6; // r0
  int v8; // r4
  __int16 v9; // r2
  int v10; // r5
  __int16 v11; // r7
  __int16 v12; // r3
  __int16 v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r6
  __int16 v17; // r5
  int v18; // r2
  int v19; // r3
  __int16 v20; // r3
  __int64 v21; // [sp+0h] [bp-40h] BYREF
  __int16 v22[2]; // [sp+8h] [bp-38h] BYREF
  __int16 v23; // [sp+Ch] [bp-34h]
  __int16 v24; // [sp+Eh] [bp-32h]
  __int16 v25; // [sp+10h] [bp-30h]
  __int16 v26; // [sp+12h] [bp-2Eh]
  __int16 v27; // [sp+14h] [bp-2Ch]
  __int16 v28; // [sp+16h] [bp-2Ah]
  __int16 v29[7]; // [sp+18h] [bp-28h] BYREF
  __int16 v30; // [sp+26h] [bp-1Ah]

  v6 = RtlTimeToTimeFields(a3, v29, a3, a4);
  if ( *a1 )
    return sub_80BAC8(v6);
  v8 = (__int16)a1[2];
  if ( v8 > 5 )
    return 0;
  if ( !a1[2] )
    return 0;
  v9 = a1[1];
  v10 = (__int16)a1[7];
  v22[0] = v29[0];
  v11 = 1;
  v24 = a1[3];
  v12 = a1[4];
  v22[1] = v9;
  v25 = v12;
  v13 = a1[5];
  v23 = 1;
  v26 = v13;
  v27 = a1[6];
  v28 = 0;
  if ( !RtlTimeFieldsToTime(v22, &v21) )
    return 0;
  RtlTimeToTimeFields((int)&v21, v29, v14, v15);
  if ( v30 > v10 )
  {
    v20 = v10 - v30 + 8;
  }
  else
  {
    if ( v30 >= v10 )
      goto LABEL_8;
    v20 = v10 - v30 + 1;
  }
  v11 = v20;
LABEL_8:
  LOWORD(v16) = 1;
  v17 = v11;
  if ( v8 > 1 )
  {
    do
    {
      v11 += 7;
      v23 = v11;
      if ( !RtlTimeFieldsToTime(v22, &v21) )
        break;
      RtlTimeToTimeFields((int)&v21, v29, v18, v19);
      v16 = (__int16)(v16 + 1);
      v17 = v29[2];
    }
    while ( v16 < v8 );
  }
  v23 = v17;
  if ( !RtlTimeFieldsToTime(v22, &v21) )
    return 0;
  *a2 = v21;
  return 1;
}
