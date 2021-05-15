// RtlIsNameLegalDOS8Dot3 
 
int __fastcall RtlIsNameLegalDOS8Dot3(unsigned __int16 *a1, __int16 *a2, char *a3)
{
  int v3; // r8
  __int16 *v5; // r4
  char v6; // r9
  unsigned int v8; // r6
  int v9; // r5
  unsigned int v10; // r0
  unsigned __int8 *v11; // r4
  __int16 v12[2]; // [sp+0h] [bp-38h] BYREF
  char *v13; // [sp+4h] [bp-34h]
  char v14; // [sp+8h] [bp-30h] BYREF

  v3 = 0;
  v5 = a2;
  v6 = 0;
  if ( *a1 > 0x18u )
    return 0;
  if ( !a2 )
  {
    v13 = &v14;
    v12[0] = 0;
    v5 = v12;
    v12[1] = 12;
  }
  if ( RtlUpcaseUnicodeStringToCountedOemString(v5, a1, 0) < 0 )
    return 0;
  v8 = (unsigned __int16)*v5;
  if ( v8 == 1 )
    return sub_7DCF48();
  if ( v8 == 2 && **((_BYTE **)v5 + 1) == 46 )
    JUMPOUT(0x7DCF56);
  v9 = 0;
  v10 = 0;
  if ( *v5 )
  {
    v11 = (unsigned __int8 *)*((_DWORD *)v5 + 1);
    do
    {
      v9 = *v11;
      if ( NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[v9] )
      {
        if ( !v3 && v10 >= 7 || v10 == v8 - 1 )
          return 0;
        ++v10;
        ++v11;
      }
      else
      {
        if ( (unsigned int)v9 < 0x80 && ((1 << (v9 - 32 * (v9 >> 5))) & RtlFatIllegalTable[(unsigned int)v9 >> 5]) != 0 )
          return 0;
        if ( v9 == 32 )
          v6 = 1;
        if ( v9 == 46 )
        {
          if ( v3 || !v10 || *(v11 - 1) == 32 || v8 - v10 - 1 > 3 )
            return 0;
          v3 = 1;
        }
        if ( v10 >= 8 && !v3 )
          return 0;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < v8 );
  }
  if ( v9 == 32 || v9 == 46 )
    return 0;
  if ( a3 )
    *a3 = v6;
  return 1;
}
