// XpressDecode 
 
int __fastcall XpressDecode(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v8; // r3
  int v9; // r6
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  __int64 v14; // r2

  v6 = a4;
  if ( !a1 || a1[14] != 903790814 )
    goto LABEL_18;
  if ( a3 != a6 )
  {
    if ( a3 < a6 || a6 < 0 || a3 <= 8 || a6 < 8 )
      goto LABEL_18;
    if ( a3 <= 0x10000 && a4 > 0 )
    {
      a1[1] = a2;
      a1[2] = a2;
      v8 = a2 + a3;
      v9 = a2 + v6;
      v10 = a5 + a6;
      *a1 = v8;
      a1[9] = a5 + a6 - 3;
      v11 = a5 + a6 - 1;
      a1[3] = v9;
      a1[5] = a5 + a6;
      a1[8] = v11;
      a1[10] = v11;
      if ( (unsigned int)(v9 - a2) > 0x108 )
        a1[2] = v9 - 264;
      v12 = a1[6];
      a1[7] = v12;
      if ( (unsigned int)(v10 - v12) > 0xE8 )
        a1[7] = v10 - 232;
      a1[12] = 0;
      a1[13] = 0;
      a1[6] = a5;
      v13 = sub_5CA29C();
      if ( !*(_DWORD *)(v13 + 48)
        || (v14 = *(_QWORD *)(v13 + 12), HIDWORD(v14) > (unsigned int)v14)
        || (_DWORD)v14 == *(_DWORD *)v13 && !*(_DWORD *)(v13 + 52) )
      {
LABEL_18:
        v6 = -1;
      }
    }
  }
  return v6;
}
