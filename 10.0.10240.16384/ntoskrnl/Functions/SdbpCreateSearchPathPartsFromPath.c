// SdbpCreateSearchPathPartsFromPath 
 
int __fastcall SdbpCreateSearchPathPartsFromPath(unsigned __int16 *a1, _DWORD *a2, int a3, int a4)
{
  unsigned __int16 *v4; // r4
  int v5; // r5
  int v6; // r7
  _WORD *v9; // r0
  _BYTE *v10; // r6
  __int64 v11; // r2
  _BYTE *v12; // r1
  int v13; // r3

  v4 = a1;
  v5 = 0;
  v6 = 0;
  if ( !a1 )
  {
    AslLogCallPrintf(1, (int)"SdbpCreateSearchPathPartsFromPath", 997, "Invalid argument", a4);
    return 0;
  }
  if ( *a1 )
    v5 = 1;
  while ( 1 )
  {
    v9 = wcschr(a1, 59);
    if ( !v9 )
      break;
    ++v5;
    a1 = v9 + 1;
  }
  v10 = AslAlloc(0, 24 * (v5 - 1) + 28);
  if ( !v10 )
  {
    AslLogCallPrintf(1, (int)"SdbpCreateSearchPathPartsFromPath", 1026, "Failed to allocate search path parts", a4);
    return 0;
  }
  *(_DWORD *)v10 = v5;
  LODWORD(v11) = &v4[wcslen(v4)];
  if ( (unsigned int)v11 >= (unsigned int)v4 )
  {
    v12 = v10;
    do
    {
      v13 = *(unsigned __int16 *)v11;
      if ( v13 == 92 && !v6 )
        v6 = v11;
      if ( (v13 == 59 || v4 == (unsigned __int16 *)v11) && v6 )
      {
        if ( v13 == 59 )
          LODWORD(v11) = v11 + 2;
        HIDWORD(v11) = ((v6 - (int)v11) >> 1) + 1;
        *(_QWORD *)(v12 + 4) = v11;
        v12 += 24;
        v6 = 0;
      }
      LODWORD(v11) = v11 - 2;
    }
    while ( (unsigned int)v11 >= (unsigned int)v4 );
  }
  *a2 = v10;
  return 1;
}
