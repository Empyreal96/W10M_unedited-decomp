// AslEnvExpandStrings 
 
int __fastcall AslEnvExpandStrings(int a1, unsigned __int16 *a2, int a3, _WORD *a4, unsigned int a5, _DWORD *a6)
{
  int v6; // r6
  int v8; // r5
  int v9; // r7
  __int16 v11; // lr
  int v12; // t1
  _WORD *v13; // r2
  unsigned int v14; // r0
  unsigned int v15; // r9
  int v16; // r0
  _WORD *v18; // [sp+8h] [bp-30h]
  unsigned int v19; // [sp+Ch] [bp-2Ch]
  unsigned __int16 *v21; // [sp+18h] [bp-20h]

  v6 = a3;
  v8 = 0;
  v9 = 0;
  if ( !a3 )
  {
LABEL_24:
    if ( a5 )
      *a4 = 0;
    else
      v8 = -1073741789;
    goto LABEL_27;
  }
  do
  {
    v12 = *a2++;
    v11 = v12;
    v21 = a2;
    if ( v12 != 37 )
      goto LABEL_17;
    v13 = a2;
    v14 = v6 - 1;
    v15 = 0;
    if ( v6 == 1 )
      goto LABEL_17;
    do
    {
      if ( *v13 == 37 )
        break;
      ++v15;
      ++v13;
    }
    while ( v15 < v14 );
    v18 = v13;
    if ( v15 && v15 < v14 )
    {
      v16 = AslEnvVarQuery(a1, a2, v15);
      if ( v16 == -1073741789 )
      {
        v9 = v19 + v9 - 1;
        a2 = v18 + 1;
        v6 = v6 - v15 - 2;
LABEL_10:
        v8 = -1073741789;
        continue;
      }
      if ( v16 >= 0 )
      {
        a2 = v18 + 1;
        v6 = v6 - v15 - 2;
        v9 += v19;
        if ( a5 <= v19 )
          goto LABEL_10;
        a5 -= v19;
        a4 += v19;
      }
      else
      {
        if ( v16 != -1073741568 )
          AslLogCallPrintf(1, (int)"AslEnvExpandStrings", 572, "AslEnvVarQuery failed [%x]", v16);
        --v6;
        a2 = v21;
        ++v9;
      }
    }
    else
    {
LABEL_17:
      if ( v8 != -1073741789 )
      {
        if ( a5 <= 1 )
        {
          v8 = -1073741789;
        }
        else
        {
          *a4++ = v11;
          --a5;
        }
      }
      ++v9;
      --v6;
    }
  }
  while ( v6 );
  if ( v8 != -1073741789 )
    goto LABEL_24;
LABEL_27:
  if ( a6 )
    *a6 = v9 + 1;
  return v8;
}
