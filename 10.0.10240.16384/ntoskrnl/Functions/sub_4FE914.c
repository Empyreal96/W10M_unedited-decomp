// sub_4FE914 
 
int __fastcall sub_4FE914(char a1, int a2, int *a3, _DWORD *a4, _WORD **a5, int a6, int a7, int a8, _DWORD *a9)
{
  _WORD *v10; // r8
  int v12; // r4
  int v13; // r7
  int v14; // r1
  int v17; // r0
  int *v18; // lr
  _WORD *v19; // r3
  _WORD *v20; // r3
  int v22; // [sp+0h] [bp-30h] BYREF
  int v23; // [sp+4h] [bp-2Ch]
  int v24; // [sp+8h] [bp-28h]
  int *v25; // [sp+Ch] [bp-24h]
  int v26; // [sp+10h] [bp-20h]

  v10 = *a5;
  v25 = a3;
  v26 = a2;
  v12 = -1;
  if ( (a1 & 8) != 0 )
    v24 = -1;
  else
    v24 = 0;
  --*a4;
  if ( *a3 != -1 )
    ungetc_nolock(*a3, a7);
  v13 = a8;
  v14 = a1 & 0x10;
  v23 = v14;
  if ( (a1 & 0x10) == 0 )
    v13 = a8 - 1;
  while ( (a1 & 1) == 0 || a6-- != 0 )
  {
    ++*a4;
    v17 = sub_4FEB60(a7);
    v18 = v25;
    v14 = v23;
    *v25 = v17;
    if ( v17 == -1 )
      goto LABEL_31;
    if ( !v14 && ((a1 & 0x20) == 0 || v17 >= 9 && v17 <= 13 || v17 == 32) )
    {
      if ( (a1 & 0x40) == 0 || v17 < 0 )
        goto LABEL_31;
      if ( v17 < v17 >> 3 )
      {
        v14 = v23;
LABEL_31:
        --*a4;
        if ( *v18 != -1 )
        {
          ungetc_nolock(*v18, a7);
          v14 = v23;
        }
        break;
      }
      v14 = v23;
      if ( ((1 << (v17 & 7)) & (*(char *)((v17 >> 3) + v26) ^ v24)) == 0 )
        goto LABEL_31;
    }
    if ( (a1 & 4) != 0 )
    {
      v10 = (_WORD *)((char *)v10 + 1);
    }
    else
    {
      if ( !v13 )
      {
        if ( (a1 & 2) != 0 )
          *v10 = 0;
        else
          *(_BYTE *)v10 = 0;
        return v12;
      }
      v19 = *a5;
      if ( (a1 & 2) != 0 )
      {
        *v19 = (unsigned __int16)&v22;
        ++*a5;
      }
      else
      {
        *(_BYTE *)v19 = v17;
        *a5 = (_WORD *)((char *)*a5 + 1);
      }
      --v13;
    }
  }
  if ( v10 != *a5 )
  {
    if ( (a1 & 4) == 0 )
    {
      ++*a9;
      if ( !v14 )
      {
        v20 = *a5;
        if ( (a1 & 2) != 0 )
          *v20 = 0;
        else
          *(_BYTE *)v20 = 0;
      }
    }
    v12 = 0;
  }
  return v12;
}
