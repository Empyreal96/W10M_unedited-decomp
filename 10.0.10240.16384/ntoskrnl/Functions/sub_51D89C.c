// sub_51D89C 
 
void __fastcall sub_51D89C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, _BYTE *a15, unsigned int a16)
{
  char *v16; // r4
  char *v17; // r5
  int v18; // r8
  _DWORD *v19; // r10
  _BYTE *v20; // lr
  int v21; // r2
  unsigned int v22; // r1
  int v23; // r7
  int v24; // r3

  if ( !a16 )
  {
    v21 = *(_DWORD *)v16 & a4;
    if ( v21 != *(_DWORD *)v16 )
    {
      *v20 = 1;
      *(_DWORD *)v16 = v21;
      if ( (v18 & 0x2000000) != 0 )
      {
        if ( v21 )
        {
          *(_DWORD *)v17 = a2;
          if ( a15 )
            *a15 = 1;
        }
        else
        {
          *(_DWORD *)v17 = -1073741790;
          if ( a15 )
            *a15 = a2;
        }
      }
      else
      {
        *(_DWORD *)v17 = -1073741790;
        if ( a15 )
        {
          if ( *(_DWORD *)v16 )
            *a15 = 1;
          else
            *a15 = a2;
        }
      }
    }
LABEL_26:
    JUMPOUT(0x44B0CC);
  }
  v22 = 0;
  v23 = v17 - v16;
  while ( 1 )
  {
    v24 = *v19 & *(_DWORD *)v16;
    if ( v24 != *(_DWORD *)v16 )
    {
      *v20 = 1;
      *(_DWORD *)v16 = v24;
      if ( (v18 & 0x2000000) == 0 )
      {
        *(_DWORD *)&v16[v23] = -1073741790;
        if ( !a15 )
          goto LABEL_19;
        if ( *(_DWORD *)v16 )
          goto LABEL_25;
LABEL_18:
        a15[v22] = 0;
        goto LABEL_19;
      }
      if ( v24 )
      {
        *(_DWORD *)&v16[v23] = 0;
        if ( !a15 )
          goto LABEL_19;
LABEL_25:
        a15[v22] = 1;
        goto LABEL_19;
      }
      *(_DWORD *)&v16[v23] = -1073741790;
      if ( a15 )
        goto LABEL_18;
    }
LABEL_19:
    ++v22;
    v16 += 4;
    if ( v22 >= a16 )
      goto LABEL_26;
  }
}
