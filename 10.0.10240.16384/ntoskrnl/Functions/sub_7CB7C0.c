// sub_7CB7C0 
 
void __fastcall sub_7CB7C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int *a19, int a20, int a21, int a22)
{
  int v22; // r5
  unsigned __int16 *v23; // r8
  int v24; // r9
  int v25; // r5
  unsigned int v26; // r7
  int v27; // r10
  _WORD *v28; // r8
  int v29; // r2
  _WORD *v30; // r4

  if ( !v22 )
    JUMPOUT(0x76D996);
  a13 = 0;
  a14 = v22;
  v25 = *((_DWORD *)v23 + 1);
  v26 = 0;
  v27 = 1;
  v28 = (_WORD *)(*v23 + v25);
  while ( 1 )
  {
    if ( v26 > 1 )
      ZwClose();
    v29 = v24;
    v24 = (v24 - 1) & 1;
    *(&a13 + v24) = 0;
    v30 = (_WORD *)v25;
    if ( v25 < (unsigned int)v28 )
    {
      do
      {
        if ( *v30 == 92 )
          break;
        ++v30;
      }
      while ( v30 < v28 );
    }
    if ( v30 == (_WORD *)v25 )
      goto LABEL_12;
    HIWORD(a15) = (_WORD)v30 - v25;
    LOWORD(a15) = (_WORD)v30 - v25;
    a16 = v25;
    a17 = 24;
    a18 = *(&a13 + v29);
    a20 = 576;
    a19 = &a15;
    a21 = 0;
    a22 = 0;
    if ( ZwCreateKey() < 0 )
      goto LABEL_14;
    ++v26;
    if ( v30 == v28 || (v25 = (int)(v30 + 1), v30 + 1 == v28) )
LABEL_12:
      v27 = 0;
    if ( !v27 )
    {
LABEL_14:
      if ( v26 > 1 )
        ZwClose();
      JUMPOUT(0x76D986);
    }
  }
}
