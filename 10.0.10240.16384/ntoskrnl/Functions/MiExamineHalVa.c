// MiExamineHalVa 
 
int MiExamineHalVa()
{
  int v0; // r2
  int v1; // r1
  char *v2; // r0
  _DWORD *v3; // t1
  int v4; // t1
  char v6; // [sp+4h] [bp-4h] BYREF

  v0 = -1070592004;
LABEL_2:
  v0 -= 4;
  v1 = 1;
  v2 = &v6;
  while ( 1 )
  {
    v3 = (_DWORD *)*((_DWORD *)v2 - 1);
    v2 -= 4;
    --v1;
    if ( (*v3 & 2) == 0 )
      return (v0 + 4) << 20;
    if ( !v1 )
    {
      while ( (v0 & 0xFFF) != 0 )
      {
        v4 = *(_DWORD *)(v0 - 4);
        v0 -= 4;
        if ( (v4 & 2) == 0 )
          return (v0 + 4) << 20;
      }
      goto LABEL_2;
    }
  }
}
