// CmpQueryKeyDataFromNode 
 
int __fastcall CmpQueryKeyDataFromNode(int a1, int a2, int a3, _DWORD *a4, unsigned int a5, _DWORD *a6, int a7, int a8)
{
  int v12; // r8
  unsigned int v13; // r4
  int v14; // r10
  int v15; // r4
  int v16; // r10
  int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r10
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r0
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v29; // [sp+Ch] [bp-44h]
  int v30; // [sp+Ch] [bp-44h]
  int v31; // [sp+14h] [bp-3Ch] BYREF
  int v32; // [sp+18h] [bp-38h] BYREF
  int v33; // [sp+1Ch] [bp-34h] BYREF
  int v34; // [sp+20h] [bp-30h] BYREF
  int v35; // [sp+24h] [bp-2Ch] BYREF
  int v36; // [sp+28h] [bp-28h] BYREF
  int v37; // [sp+2Ch] [bp-24h]
  int varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  _DWORD *varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = a1;
  v12 = 0;
  v31 = -1;
  v13 = *(unsigned __int16 *)(a2 + 72);
  if ( (*(_WORD *)(a2 + 2) & 0x20) != 0 )
    v13 = (unsigned __int16)(2 * v13);
  CmGetKeyLastWriteTime(&v36, a7, a2, a8);
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v19 = v13 + 24;
      if ( !*(_WORD *)(a2 + 74)
        || (v19 = ((v13 + 27) & 0xFFFFFFFC) + *(unsigned __int16 *)(a2 + 74),
            (v12 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a2 + 48), &v31)) != 0) )
      {
        v30 = 0;
        *a6 = v19;
        if ( a5 >= 0x18 )
        {
          *a4 = v36;
          a4[1] = v37;
          a4[2] = 0;
          a4[4] = *(unsigned __int16 *)(a2 + 74);
          a4[5] = v13;
          v20 = v13;
          if ( a5 - 24 < v13 )
          {
            v20 = a5 - 24;
            v30 = -2147483643;
          }
          v21 = (int)(a4 + 6);
          if ( (*(_WORD *)(a2 + 2) & 0x20) != 0 )
            CmpCopyCompressedName(v21, a5 - 24, a2 + 76, *(unsigned __int16 *)(a2 + 72));
          else
            memmove(v21, a2 + 76, v20);
          if ( *(_WORD *)(a2 + 74) )
          {
            v22 = (v13 + 27) & 0xFFFFFFFC;
            a4[3] = v22;
            if ( a5 >= v22 )
              v23 = a5 - v22;
            else
              v23 = 0;
            v24 = *(unsigned __int16 *)(a2 + 74);
            if ( v23 < v24 )
            {
              v24 = v23;
              v30 = -2147483643;
            }
            memmove((int)a4 + v22, v12, v24);
          }
          else
          {
            a4[3] = -1;
          }
          v14 = v30;
        }
        else
        {
          v14 = -1073741789;
        }
LABEL_38:
        if ( v12 )
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
        return v14;
      }
    }
    else
    {
      if ( a3 != 2 )
        return -1073741811;
      v15 = *(unsigned __int16 *)(a2 + 74) + 44;
      if ( !*(_WORD *)(a2 + 74)
        || (v12 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a2 + 48), &v31)) != 0 )
      {
        v14 = CmGetVisibleMaxNameLenAndClassLen(a7, a2, a8, &v32, &v33);
        if ( v14 < 0 )
          return v14;
        v14 = CmGetVisibleMaxValueNameLenAndDataLen(a7, a2, a8, &v34, &v35);
        v29 = v14;
        if ( v14 < 0 )
          return v14;
        v16 = CmGetVisibleSubkeyCount(a7, a2, a8);
        v17 = CmGetVisibleValueCount(a7, a2, a8);
        *a6 = v15;
        if ( a5 >= 0x2C )
        {
          *a4 = v36;
          a4[1] = v37;
          a4[6] = v32;
          a4[7] = v33;
          a4[9] = v34;
          a4[10] = v35;
          a4[2] = 0;
          a4[4] = *(unsigned __int16 *)(a2 + 74);
          a4[5] = v16;
          a4[8] = v17;
          if ( *(_WORD *)(a2 + 74) )
          {
            a4[3] = 44;
            v18 = *(unsigned __int16 *)(a2 + 74);
            if ( a5 - 44 >= v18 )
            {
              v14 = v29;
            }
            else
            {
              v18 = a5 - 44;
              v14 = -2147483643;
            }
            memmove((int)(a4 + 11), v12, v18);
          }
          else
          {
            a4[3] = -1;
            v14 = v29;
          }
        }
        else
        {
          v14 = -1073741789;
        }
        goto LABEL_38;
      }
    }
    return -1073741670;
  }
  v14 = 0;
  *a6 = v13 + 16;
  if ( a5 < 0x10 )
    return -1073741789;
  *a4 = v36;
  a4[1] = v37;
  v25 = 0;
  a4[2] = 0;
  a4[3] = v13;
  v26 = a5 - 16;
  if ( a5 - 16 < v13 )
  {
    v13 = a5 - 16;
    v14 = -2147483643;
  }
  if ( (*(_WORD *)(a2 + 2) & 0x20) != 0 )
  {
    v27 = v26 >> 1;
    if ( v26 >> 1 >= *(unsigned __int16 *)(a2 + 72) )
      v27 = *(unsigned __int16 *)(a2 + 72);
    while ( v25 < v27 )
    {
      *((_WORD *)a4 + v25 + 8) = *(unsigned __int8 *)(v25 + a2 + 76);
      ++v25;
    }
  }
  else
  {
    memmove((int)(a4 + 4), a2 + 76, v13);
  }
  return v14;
}
