// FsRtlGetNextExtraCreateParameter 
 
int __fastcall FsRtlGetNextExtraCreateParameter(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v7; // r3
  _DWORD *v8; // r2
  int v9; // r2
  int v10; // r6
  _DWORD *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3

  if ( a2 )
  {
    v9 = *(_DWORD *)(a2 - 44);
    if ( v9 == a1 + 8 )
      goto LABEL_13;
    v8 = (_DWORD *)(v9 - 8);
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 8);
    if ( v7 == a1 + 8 )
      goto LABEL_13;
    v8 = (_DWORD *)(v7 - 8);
  }
  if ( v8 )
  {
    v10 = 0;
    if ( a4 )
      *a4 = v8 + 13;
    if ( a5 )
      *a5 = v8[10] - 52;
    if ( a3 )
    {
      v11 = v8 + 4;
      v12 = v8[4];
      v13 = v8[5];
      v14 = v8[6];
      v15 = v11[3];
      *a3 = v12;
      a3[1] = v13;
      a3[2] = v14;
      a3[3] = v15;
    }
    return v10;
  }
LABEL_13:
  v10 = -1073741275;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  if ( a3 )
  {
    *a3 = 0;
    a3[1] = 0;
    a3[2] = 0;
    a3[3] = 0;
  }
  return v10;
}
