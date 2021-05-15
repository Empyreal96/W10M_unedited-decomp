// SepHasAllAppPackagesPresent 
 
int __fastcall SepHasAllAppPackagesPresent(unsigned __int8 *a1, bool *a2, bool *a3, bool *a4)
{
  char v7; // r8
  int v8; // r5
  int v9; // r6
  __int16 v10; // r2
  unsigned __int16 *v11; // r4
  unsigned int v12; // r6
  unsigned int v13; // r7
  unsigned __int16 *v14; // r9
  char v16[2]; // [sp+0h] [bp-28h] BYREF
  __int16 v17; // [sp+2h] [bp-26h] BYREF
  int v18; // [sp+4h] [bp-24h] BYREF
  bool *v19; // [sp+8h] [bp-20h]

  v18 = 0;
  v19 = a2;
  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  v7 = 16;
  v8 = 0;
  if ( RtlGetDaclSecurityDescriptor((int)a1, v16, &v18, (bool *)&v17) < 0 )
    return 0;
  if ( !v16[0] )
    return 0;
  v9 = v18;
  if ( !v18 || RtlGetControlSecurityDescriptor(a1, &v17, &v18) < 0 )
    return 0;
  v10 = v17;
  v11 = (unsigned __int16 *)(v9 + 8);
  v12 = *(unsigned __int16 *)(v9 + 4);
  *a3 = (v17 & 0x400) != 0;
  *a4 = (v10 & 0x1000) != 0;
  v13 = 0;
  if ( v12 )
  {
    v14 = (unsigned __int16 *)SeAllAppPackagesSid;
    do
    {
      if ( *(unsigned __int8 *)v11 <= 3u )
      {
        if ( RtlEqualSid(v11 + 4, v14) )
        {
          v8 = 1;
          v7 &= *((_BYTE *)v11 + 1);
          if ( (v7 & 0x10) == 0 )
            break;
        }
      }
      ++v13;
      v11 = (unsigned __int16 *)((char *)v11 + v11[1]);
    }
    while ( v13 < v12 );
  }
  *v19 = (v7 & 0x10) != 0;
  return v8;
}
