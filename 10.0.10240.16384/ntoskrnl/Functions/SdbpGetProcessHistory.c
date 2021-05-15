// SdbpGetProcessHistory 
 
_BYTE *__fastcall SdbpGetProcessHistory(int a1, unsigned __int16 *a2, int a3)
{
  unsigned __int16 *v3; // r5
  int v4; // r4
  unsigned int v5; // r7
  unsigned int v6; // r8
  int v7; // r0
  int v8; // r9
  int v9; // r3
  int v10; // r6
  _BYTE *v11; // r0
  _BYTE *v12; // r5
  int v13; // r4
  _WORD *v14; // r4
  int v15; // r4

  v3 = (unsigned __int16 *)a3;
  v4 = a1;
  v5 = wcslen(a2);
  v6 = wcslen(v3);
  v7 = AslEnvVarQuery(v4, L"__PROCESS_HISTORY", 17);
  v8 = v7;
  if ( v7 == -1073741789 )
    v9 = v6 + v5 + 2;
  else
    v9 = v6 + v5 + 1;
  v10 = 2 * v9;
  v11 = AslAlloc(v7, 2 * v9);
  v12 = v11;
  v13 = (int)v11;
  if ( v11 )
  {
    *(_WORD *)v11 = 0;
    if ( v8 == -1073741789 && AslEnvVarQuery(a1, L"__PROCESS_HISTORY", 17) >= 0 )
    {
      v14 = &v12[2 * v10 - 2];
      if ( *v14 != 59 )
      {
        v14 = &v12[2 * v10];
        *v14 = 59;
      }
      v13 = (int)(v14 + 1);
    }
    memmove(v13, (int)a2, 2 * v5);
    v15 = v13 + 2 * v5;
    memmove(v15, a3, 2 * v6);
    *(_WORD *)(v15 + 2 * v6) = 0;
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpGetProcessHistory", 1471, "Unable to allocate process history buffer");
    v12 = 0;
  }
  return v12;
}
