// WmipBuildInstanceSet 
 
int __fastcall WmipBuildInstanceSet(_DWORD *a1, int a2, int a3, _DWORD *a4, int a5)
{
  unsigned int v5; // r10
  int v7; // r5
  _WORD *v8; // r8
  int v10; // r4
  int v12; // lr
  unsigned int v13; // r5
  int v14; // r3
  int v15; // r4
  int v17; // r4
  int v18; // r9
  int v19; // r0
  _DWORD *v20; // r5
  int v21; // r3
  unsigned int v22; // r4
  unsigned int v23; // r8
  int v24; // r9
  unsigned int v25; // r2
  int v26; // r0
  unsigned __int16 **v27; // r9
  int v28; // r3
  unsigned int v29; // r6
  unsigned __int16 *v30; // r5
  unsigned __int16 *v31; // r2
  int v32; // r4
  int v33; // r2
  int v34; // [sp+0h] [bp-30h] BYREF
  int v35; // [sp+4h] [bp-2Ch]
  unsigned __int16 *v36; // [sp+8h] [bp-28h]
  int v37; // [sp+Ch] [bp-24h]
  int v38; // [sp+10h] [bp-20h]

  v5 = a1[5];
  v7 = a4[2];
  a4[11] = a5;
  v34 = 0;
  v8 = 0;
  a4[9] = v5;
  a4[10] = 0;
  a4[2] = v7 & 0xFFFD7FF8;
  v10 = a1[4];
  v37 = a3;
  v38 = a2;
  v12 = a2;
  if ( (v10 & 1) != 0 )
    a4[2] = v7 & 0xFFFD7FF8 | 4;
  if ( (a1[4] & 0x80000) != 0 )
  {
    v33 = a4[2] | 0x1000;
    a4[2] = v33;
    if ( (a1[4] & 0x1000) != 0 )
      a4[2] = v33 | 0x80000;
  }
  if ( (a1[4] & 0x40) != 0 )
    a4[2] |= 0x8000u;
  v13 = a1[6];
  v36 = (unsigned __int16 *)(v13 + a2);
  v14 = a1[4];
  if ( (v14 & 4) != 0 )
  {
    v22 = 0;
    v35 = 0;
    v23 = 0;
    v24 = 1;
    if ( !v5 )
    {
LABEL_27:
      v26 = ExAllocatePoolWithTag(1, v24, 1885957463);
      v27 = (unsigned __int16 **)v26;
      if ( v26 )
      {
        v28 = a4[2];
        a4[12] = v26;
        a4[2] = v28 | 2;
        v8 = (_WORD *)ExAllocatePoolWithTag(1, 2 * (v22 + 1), 1885957463);
        if ( v8 )
        {
          v29 = 0;
          v30 = (unsigned __int16 *)&v27[v5];
          if ( v5 )
          {
            v31 = v36;
            do
            {
              *v27++ = v30;
              v32 = *v31 >> 1;
              v36 = v31 + 1;
              v38 = v32;
              RtlStringCchCopyNW(v8, v35 + 1, (int)(v31 + 1), v32);
              v15 = WmipMangleInstanceName(a1, v8, v32 + 7, v30);
              if ( v15 < 0 )
                goto LABEL_9;
              v30 += wcslen(v30) + 1;
              ++v29;
              v31 = &v36[v38];
            }
            while ( v29 < v5 );
          }
LABEL_8:
          v15 = 0;
LABEL_9:
          if ( v8 )
            ExFreePoolWithTag((unsigned int)v8);
          return v15;
        }
      }
      return -1073741670;
    }
    while ( 1 )
    {
      v34 = 0;
      if ( WmipValidateWmiRegInfoString(v12, v37, v13, &v34) < 0 || !v34 )
        break;
      v25 = *(unsigned __int16 *)v34 >> 1;
      if ( v25 > v22 )
        v35 = *(unsigned __int16 *)v34 >> 1;
      v24 += 2 * (v25 + 9);
      if ( v25 == -1 )
        return -1073741675;
      v34 = v25 + 1;
      v15 = RtlULongLongToULong(2 * (v25 + 1), 0, &v34);
      if ( v15 < 0 )
        return v15;
      if ( v34 + v13 < v13 )
        return -1073741675;
      ++v23;
      v22 = v35;
      v13 += v34;
      if ( v23 >= v5 )
        goto LABEL_27;
      v12 = v38;
    }
  }
  else
  {
    if ( (v14 & 8) == 0 )
      goto LABEL_8;
    if ( WmipValidateWmiRegInfoString(a2, a3, v13, &v34) >= 0 )
    {
      v17 = v34;
      if ( v34 )
      {
        v18 = *(unsigned __int16 *)v34 >> 1;
        v19 = ExAllocatePoolWithTag(1, 2 * (v18 + 3), 1885957463);
        v20 = (_DWORD *)v19;
        if ( v19 )
        {
          RtlStringCchCopyNW((_WORD *)(v19 + 4), v18 + 1, v17 + 2, v18);
          *v20 = WmipDetermineInstanceBaseIndex(a1, v20 + 1);
          v21 = a4[2];
          a4[12] = v20;
          a4[2] = v21 | 1;
          if ( (a1[4] & 0x20) != 0 )
            a4[2] = v21 | 0x20001;
          goto LABEL_8;
        }
        return -1073741670;
      }
    }
  }
  return sub_7CBA9C();
}
