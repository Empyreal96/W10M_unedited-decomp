// SepAdjustGroups 
 
int __fastcall SepAdjustGroups(int a1, int a2, int a3, unsigned int a4, int a5, int a6, int a7, _DWORD *a8, _DWORD *a9, bool *a10)
{
  int v11; // r6
  int v12; // r2
  unsigned int v14; // r4
  unsigned int v15; // r0
  int v16; // r1
  int v17; // lr
  unsigned int v18; // r8
  int v19; // r3
  unsigned __int16 *v20; // r0
  int v21; // r7
  unsigned int v22; // r9
  int v23; // r4
  bool v24; // r2
  int v25; // r2
  unsigned int v26; // r7
  int v28; // [sp+0h] [bp-40h]
  int v30; // [sp+8h] [bp-38h]
  int v31; // [sp+Ch] [bp-34h]
  unsigned int v32; // [sp+10h] [bp-30h]
  unsigned int v33; // [sp+14h] [bp-2Ch]
  int v34; // [sp+18h] [bp-28h]
  int v35; // [sp+1Ch] [bp-24h]

  v32 = a4;
  v11 = 0;
  v12 = a2;
  v30 = 0;
  *a9 = 0;
  v14 = *(_DWORD *)(a1 + 124);
  v15 = 0;
  v16 = a6;
  v31 = a3;
  v17 = 0;
  v33 = 0;
  v28 = a7;
  v18 = 1;
  if ( v14 > 1 )
  {
    while ( 2 )
    {
      v19 = *(_DWORD *)(a1 + 148) + 8 * v18;
      v20 = *(unsigned __int16 **)v19;
      v34 = *(_DWORD *)(v19 + 4);
      v35 = *(_DWORD *)v19;
      if ( a3 )
        return sub_7C5A5C((int)v20, v16, v12, v19, a5, a6, a7);
      v21 = 0;
      v22 = 0;
      if ( !v32 )
        JUMPOUT(0x7C5AE2);
      v23 = a5;
      do
      {
        if ( v21 )
          break;
        if ( RtlEqualSid(v20, *(unsigned __int16 **)v23) )
        {
          v21 = 1;
          ++v33;
          v25 = *(_DWORD *)(*(_DWORD *)(a1 + 148) + 8 * v18 + 4);
          if ( ((*(_DWORD *)(v23 + 4) ^ v25) & 4) != 0 )
          {
            if ( (v25 & 1) != 0 )
              return -1073741731;
            if ( (v25 & 0x10) != 0 )
              return -1073741133;
            v26 = (4 * *(unsigned __int8 *)(v35 + 1) + 11) & 0xFFFFFFFC;
            v30 += v26;
            if ( a2 )
            {
              if ( a6 )
              {
                *(_DWORD *)(a6 + 8 * *a9 + 8) = v34;
                *(_DWORD *)(a6 + 8 * *a9 + 4) = v28;
                RtlCopySid(v26, v28, v35);
                v28 += v26;
              }
              *(_DWORD *)(*(_DWORD *)(a1 + 148) + 8 * v18 + 4) &= ~(*(_DWORD *)(*(_DWORD *)(a1 + 148) + 8 * v18 + 4) & 4);
              *(_DWORD *)(*(_DWORD *)(a1 + 148) + 8 * v18 + 4) |= *(_DWORD *)(v23 + 4) & 4;
            }
            v21 = 1;
            ++*a9;
          }
        }
        ++v22;
        v20 = (unsigned __int16 *)v35;
        v23 += 8;
      }
      while ( v22 < v32 );
      a3 = v31;
      v12 = a2;
      ++v18;
      v16 = a6;
      v17 = v30;
      if ( v18 < *(_DWORD *)(a1 + 124) )
        continue;
      break;
    }
    a4 = v32;
    v15 = v33;
  }
  if ( v15 < a4 && !a3 )
    v11 = 262;
  v24 = v12 && *a9;
  *a10 = v24;
  if ( v16 )
    *a8 = v17 + 8 * *a9 + 4;
  return v11;
}
