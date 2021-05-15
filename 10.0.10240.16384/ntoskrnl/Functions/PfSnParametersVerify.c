// PfSnParametersVerify 
 
int __fastcall PfSnParametersVerify(int *a1)
{
  int v1; // r7
  int *v2; // r4
  int v3; // r2
  int *i; // r1
  unsigned int v5; // r6
  int *v6; // r5
  int v7; // r1
  int *v8; // r5
  _DWORD *j; // r2
  int v10; // r3
  int v11; // t1
  __int64 v12; // kr00_8
  unsigned int v14; // r3

  v1 = -1073741811;
  v2 = a1;
  v3 = 0;
  for ( i = a1; *((_WORD *)i + 24); i = (int *)((char *)i + 2) )
  {
    if ( (unsigned int)++v3 >= 0x30 )
      return v1;
  }
  v5 = 0;
  v6 = a1;
  while ( *((_WORD *)v6 + 72) )
  {
    if ( towupper(*((unsigned __int16 *)v6 + 72)) == *((unsigned __int16 *)v6 + 72) )
    {
      ++v5;
      v6 = (int *)((char *)v6 + 2);
      if ( v5 < 0x80 )
        continue;
    }
    return v1;
  }
  v7 = 0;
  v8 = v2;
  for ( j = v2 + 2; ; j += 4 )
  {
    v11 = *v8++;
    v10 = v11;
    if ( v11 < 0 )
      break;
    if ( v10 >= 3 )
      break;
    if ( *j > 0x100000u )
      break;
    if ( j[1] > 0x4000u )
      break;
    v12 = *((_QWORD *)j + 1);
    if ( v12 < -6000000000i64 || SHIDWORD(v12) > 0 || v12 >= 0 )
      break;
    if ( ++v7 >= 2 )
    {
      if ( (unsigned int)v2[10] <= 0x1000 && (unsigned int)v2[11] <= 0x1000 && (v2[100] & 0xFFFFFFF0) == 0 )
      {
        v14 = v2[101];
        if ( v14 <= 0xA )
        {
          if ( v14 )
            v1 = 0;
        }
      }
      return v1;
    }
  }
  return v1;
}
