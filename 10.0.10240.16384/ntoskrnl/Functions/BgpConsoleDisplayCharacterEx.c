// BgpConsoleDisplayCharacterEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BgpConsoleDisplayCharacterEx(int a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  __int16 v6; // r5
  int v7; // r6
  int v8; // r8 OVERLAPPED
  int *v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r5
  int *v14; // r3
  int *v15; // r3
  int v17; // [sp+10h] [bp-30h]
  char v18[4]; // [sp+18h] [bp-28h] BYREF
  char v19[36]; // [sp+1Ch] [bp-24h] BYREF

  v6 = a1;
  if ( a2 > 0x50 || a3 > dword_61034C )
    return -1073741811;
  v7 = 0;
  switch ( a1 )
  {
    case 8:
      v10 = dword_610384;
      if ( !dword_610384 )
        goto LABEL_22;
      --dword_610384;
      v7 = BgpDisplayCharacterEx(
             32,
             (int *)dword_61036C,
             dword_61037C + dword_610370 * (v10 - 1),
             dword_610380 + dword_610374 * dword_610388,
             a5,
             a4,
             (int)v18,
             (int)v19,
             v17,
             0);
      if ( v7 >= 0 )
      {
        v15 = &dword_610390[75 * dword_610384 + 3 * dword_610388];
        *((_WORD *)v15 + 4) = 32;
        *v15 = a4;
        v15[1] = a5;
      }
      goto LABEL_21;
    case 9:
      v10 = dword_610384;
      v12 = 80 - dword_610384;
      if ( (unsigned int)(80 - dword_610384) < 5 )
      {
        if ( !v12 )
          goto LABEL_22;
      }
      else
      {
        v12 = 5;
      }
      do
      {
        v7 = BgpDisplayCharacterEx(
               32,
               (int *)dword_61036C,
               dword_61037C + dword_610370 * v10,
               dword_610380 + dword_610374 * dword_610388,
               a5,
               a4,
               (int)v18,
               (int)v19,
               v17,
               0);
        if ( v7 >= 0 )
        {
          v14 = &dword_610390[75 * dword_610384 + 3 * dword_610388];
          *((_WORD *)v14 + 4) = 32;
          *(_QWORD *)v14 = *(_QWORD *)&a4;
        }
        v10 = ++dword_610384;
        --v12;
      }
      while ( v12 );
LABEL_22:
      if ( v10 < 0x50 )
        goto LABEL_23;
LABEL_10:
      dword_610384 = 0;
      v11 = ++dword_610388;
      goto LABEL_24;
    case 10:
      goto LABEL_10;
  }
  if ( a1 != 13 )
  {
    v8 = a5;
    v7 = BgpDisplayCharacterEx(
           a1,
           (int *)dword_61036C,
           dword_61037C + dword_610370 * dword_610384,
           dword_610380 + dword_610374 * dword_610388,
           a5,
           a4,
           (int)v19,
           (int)v18,
           v17,
           0);
    if ( v7 >= 0 )
    {
      v9 = &dword_610390[75 * dword_610384 + 3 * dword_610388];
      *((_WORD *)v9 + 4) = v6;
      *(_QWORD *)v9 = *(_QWORD *)&a4;
      v10 = ++dword_610384;
      goto LABEL_22;
    }
LABEL_21:
    v10 = dword_610384;
    goto LABEL_22;
  }
  dword_610384 = 0;
LABEL_23:
  v11 = dword_610388;
LABEL_24:
  if ( v11 >= dword_61034C )
  {
    dword_610388 = v11 - 1;
    BgpConsoleScrollScreen();
  }
  return v7;
}
