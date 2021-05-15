// BcpGetMaxResourceProfile 
 
int __fastcall BcpGetMaxResourceProfile(int a1, _DWORD *a2)
{
  int result; // r0
  unsigned int v4; // r5
  void **v5; // r4
  int *v6; // r2
  unsigned int v7; // r6
  unsigned int v8; // r8
  unsigned __int16 *v9; // r9
  int v10; // t1
  unsigned int v11; // [sp+0h] [bp-30h]
  void *v12; // [sp+8h] [bp-28h]

  result = 0;
  v4 = 0;
  v5 = &BcpStringsAndSizes;
  *a2 = 0;
  a2[1] = 0;
  v11 = 0;
  do
  {
    v6 = (int *)*v5;
    if ( *v5 != &dword_405C88 || (dword_619018 & 0x20000) == 0 )
    {
      result = 0;
      v7 = 0;
      v12 = v5[1];
      v8 = *(unsigned __int16 *)v6 >> 1;
      if ( v8 )
      {
        v9 = (unsigned __int16 *)v6[1];
        do
        {
          v10 = *v9++;
          result = BcpGetCharacterMaxResourceProfile(v10, v12, a1, a2);
          if ( result < 0 )
            break;
          ++v7;
        }
        while ( v7 < v8 );
        v4 = v11;
      }
      if ( result < 0 )
        break;
    }
    ++v4;
    v5 += 2;
    v11 = v4;
  }
  while ( v4 < 0x12 );
  return result;
}
