// SdbpReleaseSearchDBContext 
 
int __fastcall SdbpReleaseSearchDBContext(int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r0
  _DWORD *v3; // r3
  unsigned int v4; // r0
  unsigned int v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r3
  _DWORD *v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r0

  v1 = (_DWORD *)result;
  if ( result )
  {
    if ( *(_DWORD *)(result + 12) )
    {
      result = sub_7CD404();
    }
    else
    {
      v2 = *(_DWORD *)(result + 32);
      if ( v2 )
      {
        ExFreePoolWithTag(v2);
        v1[8] = 0;
      }
      v3 = (_DWORD *)v1[9];
      if ( v3 )
      {
        v7 = 0;
        if ( *v3 )
        {
          v8 = 0;
          do
          {
            v9 = v1[9] + v8;
            v10 = (_DWORD *)(v9 + 4);
            if ( v9 != -4 )
            {
              if ( *(_DWORD *)(v9 + 12) )
              {
                AslHashFree();
                v10[2] = 0;
              }
              if ( v10[3] )
              {
                AslHashFree();
                v10[3] = 0;
              }
              v11 = v10[5];
              if ( v11 )
              {
                ExFreePoolWithTag(v11);
                v10[4] = 0;
                v10[5] = 0;
              }
            }
            ++v7;
            v8 += 24;
          }
          while ( v7 < *(_DWORD *)v1[9] );
        }
        v12 = v1[9];
        if ( v12 )
          ExFreePoolWithTag(v12);
        v1[9] = 0;
      }
      v4 = v1[4];
      if ( v4 )
      {
        ExFreePoolWithTag(v4);
        v1[4] = 0;
      }
      v5 = v1[5];
      if ( v5 )
      {
        ExFreePoolWithTag(v5);
        v1[5] = 0;
      }
      v6 = v1[6];
      if ( v6 )
      {
        ExFreePoolWithTag(v6);
        v1[6] = 0;
      }
      result = v1[11];
      if ( result )
      {
        result = SdbpFreePackageAttributes();
        v1[11] = 0;
      }
    }
  }
  return result;
}
