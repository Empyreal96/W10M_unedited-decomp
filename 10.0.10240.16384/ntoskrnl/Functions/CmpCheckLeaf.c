// CmpCheckLeaf 
 
int __fastcall CmpCheckLeaf(int a1, int a2, unsigned __int16 *a3, unsigned int a4)
{
  unsigned __int16 *v4; // r8
  int v5; // r5
  int v6; // r6
  int v8; // r4
  unsigned int v9; // r5
  unsigned __int16 *i; // r10
  int v11; // r0
  unsigned int v12; // r6
  int v13; // r3
  int v14; // r5
  bool v15; // zf
  __int16 v16; // r3
  int v17; // r7
  unsigned int v18; // r4
  unsigned int v19; // r0
  unsigned int v21; // r2
  int j; // r1
  unsigned int v23; // r3
  int v24; // r3
  int v25; // r0
  int v26; // [sp+8h] [bp-40h] BYREF
  int v27; // [sp+Ch] [bp-3Ch]
  unsigned int v28; // [sp+10h] [bp-38h]
  unsigned __int16 *v29; // [sp+14h] [bp-34h]
  int v30; // [sp+18h] [bp-30h]
  int v31; // [sp+1Ch] [bp-2Ch]
  __int16 v32; // [sp+20h] [bp-28h] BYREF
  int v33; // [sp+24h] [bp-24h]

  v4 = a3;
  v5 = *a3;
  v6 = *(_DWORD *)(a1 + 28);
  v29 = a3;
  v30 = a2;
  v31 = a4;
  v26 = -1;
  v27 = v6;
  if ( v5 != 26732 && v5 != 26220 )
    return 0;
  v8 = a3[1];
  v9 = 0;
  v28 = 0;
  if ( !v8 )
    return 0;
  for ( i = a3; ; i += 4 )
  {
    if ( !HvIsCellAllocated(a1, *((_DWORD *)i + 1), 0, a4) )
      goto LABEL_17;
    v11 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *((_DWORD *)i + 1), &v26);
    if ( !v11 )
      break;
    if ( (unsigned int)(-4 - *(_DWORD *)(v11 - 4)) < 0x4C
      || (v12 = *(unsigned __int16 *)(v11 + 72), v12 > -80 - *(_DWORD *)(v11 - 4)) )
    {
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
    }
    else
    {
      v13 = *v4;
      v14 = v11 + 76;
      v32 = *(_WORD *)(v11 + 72);
      v15 = v13 == 26732;
      v16 = *(_WORD *)(v11 + 2);
      v33 = v11 + 76;
      if ( v15 )
      {
        if ( (v16 & 0x20) != 0 )
        {
          v17 = 0;
          v18 = 0;
          if ( v12 )
          {
            do
            {
              v19 = *(unsigned __int8 *)(v18 + v14);
              if ( v19 >= 0x61 )
              {
                if ( v19 > 0x7A )
                  v19 = RtlUpcaseUnicodeChar(v19);
                else
                  v19 -= 32;
              }
              ++v18;
              v17 = 37 * v17 + v19;
            }
            while ( v18 < v12 );
            v4 = v29;
          }
        }
        else
        {
          v17 = CmpComputeHashKey(0, &v32);
        }
      }
      else
      {
        v17 = 0;
        if ( (v16 & 0x20) == 0 )
          return sub_8053A4();
        v21 = 0;
        for ( j = 0; ; j += 8 )
        {
          v23 = v12 <= 4 ? v12 : 4;
          if ( v21 >= v23 )
            break;
          v24 = *(unsigned __int8 *)(v21 + v14);
          ++v21;
          v17 += v24 << j;
        }
      }
      if ( *((_DWORD *)i + 2) != v17 )
      {
        if ( (v30 & 0x20000) != 0 || !CmpSelfHeal && (CmpBootType & 6) == 0 || !HvpMarkCellDirty(a1, v31, 0, 0) )
        {
          SetFailureLocation(v27, 0, 14, 4160, 2);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
          return 4160;
        }
        *((_DWORD *)i + 2) = v17;
        v25 = v27;
        *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
        SetFailureLocation(v25, 1, 14, 4160, 1);
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
      v9 = v28;
    }
LABEL_17:
    a4 = v4[1];
    v28 = ++v9;
    if ( v9 >= a4 )
      return 0;
  }
  SetFailureLocation(v27, 0, 14, 4160, 3);
  return 4160;
}
