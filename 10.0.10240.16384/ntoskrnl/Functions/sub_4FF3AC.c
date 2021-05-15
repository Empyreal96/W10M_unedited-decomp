// sub_4FF3AC 
 
int __fastcall sub_4FF3AC(char a1, int a2, unsigned __int16 *a3, _DWORD *a4, int *a5, int a6, int a7, unsigned int a8, _DWORD *a9)
{
  _WORD *v9; // r5
  _WORD *v11; // r9
  int v13; // r6
  int v14; // r0
  int v15; // r1
  unsigned int v16; // r8
  int v17; // r3
  unsigned int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  int v21; // r5
  int v22; // r3
  int v23; // r0
  _WORD *v24; // r3
  int v26; // [sp+4h] [bp-3Ch]
  int v27; // [sp+8h] [bp-38h]
  char v30[40]; // [sp+18h] [bp-28h] BYREF

  v9 = a3;
  v11 = (_WORD *)*a5;
  v13 = -1;
  if ( (a1 & 8) != 0 )
    v27 = -1;
  else
    v27 = 0;
  --*a4;
  v14 = *a3;
  if ( v14 != 0xFFFF )
    ungetwc_nolock(v14, a7);
  v15 = a1 & 0x10;
  v16 = a8;
  if ( (a1 & 0x10) == 0 )
    v16 = a8 - 1;
  v17 = a6;
  v26 = a6;
  while ( 1 )
  {
    if ( (a1 & 1) != 0 )
    {
      v26 = v17 - 1;
      if ( !v17 )
        break;
    }
    ++*a4;
    v18 = fgetwc_nolock(a7);
    v15 = a1 & 0x10;
    *v9 = v18;
    if ( v18 == 0xFFFF )
      goto LABEL_39;
    if ( (a1 & 0x10) == 0 && ((a1 & 0x20) == 0 || v18 >= 9 && v18 <= 0xD || v18 == 32) )
    {
      if ( (a1 & 0x40) == 0 )
        goto LABEL_39;
      v19 = (unsigned __int16)(v18 >> 3);
      if ( v18 < v19 )
      {
        v15 = a1 & 0x10;
LABEL_39:
        --*a4;
        v23 = (unsigned __int16)*v9;
        if ( v23 != 0xFFFF )
        {
          ungetwc_nolock(v23, a7);
          v15 = a1 & 0x10;
        }
        break;
      }
      v20 = *(char *)(v19 + a2) ^ v27;
      v15 = a1 & 0x10;
      if ( ((1 << (v18 & 7)) & v20) == 0 )
        goto LABEL_39;
    }
    if ( (a1 & 4) != 0 )
    {
      ++v11;
LABEL_34:
      v17 = v26;
    }
    else
    {
      if ( !v16 )
        goto LABEL_35;
      if ( (a1 & 2) != 0 )
      {
        --v16;
        *(_WORD *)*a5 = v18;
        *a5 += 2;
        goto LABEL_34;
      }
      v21 = (char)v18;
      if ( v16 < _mb_cur_max )
      {
        v30[0] = v18;
        if ( (char)v18 > 0 && (char)v18 > v16 || (unsigned int)(char)v18 > 5 )
        {
LABEL_35:
          if ( (a1 & 2) != 0 )
            *v11 = 0;
          else
            *(_BYTE *)v11 = 0;
          return v13;
        }
        memmove(*a5, (int)v30, (char)v18);
      }
      else
      {
        *(_BYTE *)*a5 = v18;
      }
      v15 = a1 & 0x10;
      v17 = v26;
      if ( v21 > 0 )
      {
        v16 -= v21;
        v22 = *a5 + v21;
        v9 = a3;
        *a5 = v22;
        goto LABEL_34;
      }
      v9 = a3;
    }
  }
  if ( v11 != (_WORD *)*a5 )
  {
    if ( (a1 & 4) == 0 )
    {
      ++*a9;
      if ( !v15 )
      {
        v24 = (_WORD *)*a5;
        if ( (a1 & 2) != 0 )
          *v24 = 0;
        else
          *(_BYTE *)v24 = 0;
      }
    }
    v13 = 0;
  }
  return v13;
}
