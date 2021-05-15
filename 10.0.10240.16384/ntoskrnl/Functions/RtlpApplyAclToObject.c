// RtlpApplyAclToObject 
 
int __fastcall RtlpApplyAclToObject(int result, _DWORD *a2)
{
  unsigned int v2; // r5
  unsigned __int8 *i; // r4
  unsigned int v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r2
  int v8; // r2
  int v9; // r3
  int v10; // r2
  int v11; // r3

  if ( result )
  {
    v2 = 0;
    for ( i = (unsigned __int8 *)(result + 8); v2 < *(unsigned __int16 *)(result + 4); i += *((unsigned __int16 *)i + 1) )
    {
      v4 = *i;
      if ( (v4 <= 8 || v4 <= 0xA || v4 <= 0xE && v4 >= 0xD) && (i[1] & 8) == 0 )
      {
        v5 = *((_DWORD *)i + 1);
        if ( v5 < 0 )
          *((_DWORD *)i + 1) = *a2 | v5;
        v6 = *((_DWORD *)i + 1);
        if ( (v6 & 0x40000000) != 0 )
          *((_DWORD *)i + 1) = a2[1] | v6;
        v7 = *((_DWORD *)i + 1);
        if ( (v7 & 0x20000000) != 0 )
          *((_DWORD *)i + 1) = a2[2] | v7;
        v8 = *((_DWORD *)i + 1);
        if ( (v8 & 0x10000000) != 0 )
          *((_DWORD *)i + 1) = a2[3] | v8;
        *((_DWORD *)i + 1) &= 0xFFFFFFFu;
        v9 = *i;
        if ( !*i || v9 == 9 || v9 == 1 || v9 == 4 || v9 == 5 || v9 == 6 || v9 == 10 )
        {
          v10 = *((_DWORD *)i + 1);
          v11 = a2[3];
        }
        else
        {
          v10 = a2[3] | 0x1000000;
          v11 = *((_DWORD *)i + 1);
        }
        *((_DWORD *)i + 1) = v11 & v10;
      }
      ++v2;
    }
  }
  return result;
}
