// SdbMakeIndexKeyFromStringEx 
 
int __fastcall SdbMakeIndexKeyFromStringEx(unsigned __int16 *a1, char a2)
{
  char *v4; // r5
  unsigned int v5; // r0
  char *v6; // r7
  unsigned __int16 *v7; // r1
  int result; // r0
  unsigned int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // t1
  unsigned int v12; // r3
  unsigned __int16 v13[2]; // [sp+4h] [bp-50h] BYREF
  char *v14; // [sp+8h] [bp-4Ch]
  unsigned __int16 v15[4]; // [sp+Ch] [bp-48h] BYREF
  int v16; // [sp+14h] [bp-40h] BYREF
  char *v17; // [sp+18h] [bp-3Ch] BYREF
  char v18[16]; // [sp+1Ch] [bp-38h] BYREF
  char v19; // [sp+2Ch] [bp-28h] BYREF

  v4 = (char *)&v17 + 3;
  v5 = wcslen(a1);
  v6 = v18;
  if ( (a2 & 2) != 0 && v5 > 8 )
    v7 = &a1[v5 - 8];
  else
    v7 = a1;
  RtlInitUnicodeString((unsigned int)v15, v7);
  v17 = &v19;
  HIWORD(v16) = 16;
  RtlCopyUnicodeString((unsigned __int16 *)&v16, v15);
  v14 = v18;
  v13[1] = 16;
  if ( RtlUpcaseUnicodeString(v13, (unsigned __int16 *)&v16, 0, 16) < 0 )
    return sub_7CCD08();
  v9 = v13[0] >> 1;
  if ( v9 > 8 )
    JUMPOUT(0x7CCD18);
  result = 0;
  v10 = 0;
  v16 = 0;
  v17 = 0;
  if ( v9 )
  {
    do
    {
      v11 = *(unsigned __int16 *)v6;
      v6 += 2;
      *v4-- = v11;
      v12 = v11 >> 8;
      if ( v11 >> 8 )
      {
        if ( v10 < 7 )
        {
          *v4-- = v12;
          ++v10;
        }
      }
      ++v10;
    }
    while ( v10 < v9 );
    result = v16;
  }
  return result;
}
