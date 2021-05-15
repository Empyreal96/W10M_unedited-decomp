// LdrpResGetResourceDirectory 
 
int __fastcall LdrpResGetResourceDirectory(unsigned int a1, int a2, int a3, unsigned int *a4, int *a5)
{
  unsigned int v5; // r5
  int v6; // r6
  int v7; // r8
  int v8; // r4
  int v9; // r10
  int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r6
  _DWORD *v13; // r0
  unsigned int v14; // r0
  int v15; // r2
  __int16 v18; // [sp+10h] [bp-128h]
  int v20; // [sp+1Ch] [bp-11Ch] BYREF
  unsigned __int16 v21; // [sp+20h] [bp-118h]
  __int16 v22; // [sp+22h] [bp-116h]
  unsigned int v23; // [sp+24h] [bp-114h] BYREF
  _DWORD _28[69]; // [sp+28h] [bp-110h] BYREF
  unsigned int varg_r0; // [sp+140h] [bp+8h]
  int varg_r1; // [sp+144h] [bp+Ch]
  int varg_r2; // [sp+148h] [bp+10h]
  unsigned int *varg_r3; // [sp+14Ch] [bp+14h]

  varg_r3 = a4;
  v18 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v5 = a1;
  varg_r0 = a1;
  v6 = 1;
  v7 = 1;
  if ( !a1 || !a4 || !a5 )
    return -1073741811;
  if ( (a1 & 3) != 0 )
  {
    if ( (a1 & 1) != 0 )
      v7 = 0;
    v5 = a1 & 0xFFFFFFFC;
    varg_r0 = a1 & 0xFFFFFFFC;
  }
  v8 = RtlImageNtHeaderEx((a3 & 0x1000) == 0, v5, (unsigned int)a2, &v20);
  if ( v8 >= 0 )
  {
    v9 = v20;
    v10 = *(unsigned __int16 *)(v20 + 24);
    if ( v10 == 267 )
    {
      memmove((int)_28, v20 + 24, 0xE0u);
    }
    else
    {
      if ( v10 != 523 )
        return -1073741701;
      memmove((int)_28, v20 + 24, 0xF0u);
      v6 = 0;
    }
    if ( v6 )
      v11 = _28[23];
    else
      v11 = _28[27];
    if ( v11 > 2 )
    {
      if ( v6 )
        v12 = _28[28];
      else
        v12 = _28[32];
      if ( v12 )
      {
        if ( v5 >= MmHighestUserAddress || v12 + v5 < MmHighestUserAddress )
        {
          if ( v7 || v12 < _28[15] )
          {
            if ( RtlUIntAdd(v5, v12, &v23) < 0 )
              return -1073741701;
            v14 = v23;
          }
          else
          {
            v13 = (_DWORD *)LdrpSectionTableFromVirtualAddress(v5, a2, v9);
            if ( !v13 )
              return -1073741701;
            if ( !v13[4] )
              return -1073741687;
            v14 = v13[5] - v13[3] + v12 + v5;
          }
          if ( !v14 )
            return -1073741687;
          if ( (v18 & 0x1000) == 0 )
            goto LABEL_46;
          if ( v14 > v5 && v14 + 16 <= (v5 & 0xFFFFFFFC) + a2 )
          {
            v21 = *(_WORD *)(v14 + 12);
            v15 = *(unsigned __int16 *)(v14 + 14);
            v22 = *(_WORD *)(v14 + 14);
            if ( !v21 && !v15 )
              return -1073741686;
            if ( v14 + 8 * (v21 + v15) <= (v5 & 0xFFFFFFFC) + a2 )
            {
LABEL_46:
              *a4 = v14;
              *a5 = v9;
              return 0;
            }
          }
          v8 = -1073741701;
        }
        else
        {
          v8 = -1073741701;
        }
      }
      else
      {
        v8 = -1073741687;
      }
    }
    else
    {
      v8 = -1073741687;
    }
  }
  return v8;
}
