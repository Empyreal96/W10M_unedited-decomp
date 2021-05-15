// RtlIdnToUnicode 
 
int __fastcall RtlIdnToUnicode(int a1, unsigned __int16 *a2, int a3, int a4, int *a5)
{
  int v6; // r5
  int v7; // r4
  char v8; // r8
  int result; // r0
  signed int v10; // r4
  int v11; // r7
  int v12; // r1
  int v13; // r2
  int v14; // r6
  _BYTE *v15; // r0
  unsigned int v16; // r5
  int v17; // r1
  _WORD *v18; // r2
  unsigned int v19; // r3
  int v20; // r0
  int v21; // r1
  _WORD *v22; // r0
  char v23[4]; // [sp+10h] [bp-430h] BYREF
  unsigned int v24; // [sp+14h] [bp-42Ch] BYREF
  int v25; // [sp+18h] [bp-428h] BYREF
  int v26; // [sp+1Ch] [bp-424h]
  _WORD v27[528]; // [sp+20h] [bp-420h] BYREF

  v6 = 0;
  v26 = a4;
  v7 = a3;
  v8 = a1;
  if ( !a2 || !a5 || *a5 < 0 || a3 < -1 || *a5 > 0 && !a4 || (a1 & 0xFFFFFFF0) != 0 )
    return -1073741811;
  if ( a3 == -1 )
  {
    if ( RtlStringCchLengthW(a2, 0x203u, &v24) < 0 )
      return -1073740010;
    v7 = v24 + 1;
  }
  if ( !a2[v7 - 1] )
  {
    v6 = 1;
    --v7;
  }
  v24 = 511;
  result = punycode_decode((char *)a2, v7, (char *)v27, (int *)&v24, (v8 & 4) != 0, (v8 & 2) != 0, v23, &v25);
  if ( result >= 0 )
  {
    v10 = v24;
    if ( v6 )
    {
      if ( v24 >= 0x1FF )
        return -1073740010;
      v10 = v24 + 1;
      if ( 2 * v24 >= 0x3FE )
        _report_rangecheckfailure();
      v27[v24] = 0;
    }
    if ( (v8 & 8) == 0 && !v23[0] )
    {
      v11 = v25;
      if ( (v8 & 4) != 0 && (RtlIsNormalizedString(1, v27, (v25 - (int)v27) >> 1, v23) < 0 || !v23[0]) )
        return -1073740010;
      v12 = (v11 - (int)v27) >> 1;
      if ( v12 < v10 - (v6 != 0) )
      {
        if ( v6 )
          v13 = 2;
        else
          v13 = 1;
        v14 = v10 - v12 - v13;
        v15 = (_BYTE *)ExAllocatePoolWithTag(1, v14, 1164862537);
        v16 = (unsigned int)v15;
        if ( !v15 )
          return -1073741801;
        memset(v15, 0, v14);
        v17 = 0;
        if ( v14 > 0 )
        {
          v18 = (_WORD *)(v11 + 2);
          do
          {
            v19 = (unsigned __int16)*v18;
            if ( v19 >= 0x41 && v19 <= 0x5A )
            {
              *v18 = v19 + 32;
              *(_BYTE *)(v16 + v17) = 1;
            }
            ++v17;
            ++v18;
          }
          while ( v17 < v14 );
        }
        v20 = 269;
        if ( (v8 & 1) != 0 )
          v20 = 13;
        if ( RtlIsNormalizedString(v20, v11 + 2, v14, v23) < 0 || !v23[0] )
        {
          ExFreePoolWithTag(v16);
          return -1073740010;
        }
        v21 = 0;
        if ( v14 > 0 )
        {
          v22 = (_WORD *)(v11 + 2);
          do
          {
            if ( *(_BYTE *)(v16 + v21) == 1 )
              *v22 -= 32;
            ++v21;
            ++v22;
          }
          while ( v21 < v14 );
        }
        ExFreePoolWithTag(v16);
      }
    }
    if ( v26 && *a5 )
    {
      if ( v10 > *a5 )
        return -1073741789;
      memmove(v26, (int)v27, 2 * v10);
    }
    *a5 = v10;
    result = 0;
  }
  return result;
}
