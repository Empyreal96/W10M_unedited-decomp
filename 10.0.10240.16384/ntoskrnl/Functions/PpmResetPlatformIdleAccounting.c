// PpmResetPlatformIdleAccounting 
 
int __fastcall PpmResetPlatformIdleAccounting(__int64 *a1)
{
  __int64 v2; // kr00_8
  __int64 *v3; // r3
  int v4; // r1
  __int64 *v5; // r2
  int v6; // r0
  __int64 v7; // r0

  v2 = *a1;
  memset(a1, 0, 992 * *((_DWORD *)a1 + 1) + 24);
  if ( HIDWORD(v2) )
  {
    v3 = a1 + 3;
    v4 = HIDWORD(v2);
    do
    {
      *((_DWORD *)v3 + 6) = -1;
      *((_DWORD *)v3 + 7) = -1;
      v5 = v3;
      v6 = 26;
      do
      {
        *((_DWORD *)v5 + 42) = -1;
        *((_DWORD *)v5 + 43) = -1;
        v5 += 4;
        --v6;
      }
      while ( v6 );
      v3 += 124;
      --v4;
    }
    while ( v4 );
  }
  *(_DWORD *)a1 = v2 + 1;
  *((_DWORD *)a1 + 1) = HIDWORD(v2);
  LODWORD(v7) = KeQueryInterruptTime();
  *((_DWORD *)a1 + 2) = 0;
  a1[2] = v7;
  return v7;
}
