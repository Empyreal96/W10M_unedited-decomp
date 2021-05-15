// PpmHeteroComputeRelativePerformance 
 
void PpmHeteroComputeRelativePerformance()
{
  unsigned int v0; // r2
  unsigned int v1; // r1
  int *v2; // r4
  int v3; // r3
  unsigned __int64 v4; // kr08_8
  int v5; // r6
  unsigned int v6; // r9
  unsigned int v7; // r8
  unsigned int v8; // r0
  int v9; // r2
  unsigned __int64 v10; // r0
  unsigned int v11; // lr
  int v12; // r2
  int v13; // r3
  unsigned __int64 v14; // r2

  v0 = 0;
  v1 = 0;
  v2 = (int *)PpmPerfDomainHead;
  v3 = PpmPerfDomainHead;
  if ( (int *)PpmPerfDomainHead != &PpmPerfDomainHead )
  {
    do
    {
      v4 = *(_QWORD *)(v3 + 104);
      if ( __PAIR64__(v1, v0) <= v4 )
      {
        v1 = HIDWORD(v4);
        v0 = v4;
      }
      v3 = *(_DWORD *)v3;
    }
    while ( (int *)v3 != &PpmPerfDomainHead );
    if ( v0 | v1 )
    {
      v5 = -1;
      if ( v1 >= 0x7FFF && (v1 > 0x7FFF || v0 == -1) )
      {
        sub_81736C(v4);
      }
      else
      {
        v6 = v0;
        v7 = v1;
        if ( (int *)PpmPerfDomainHead != &PpmPerfDomainHead )
        {
          do
          {
            v8 = v2[26];
            v9 = v2[27];
            if ( v8 == v6 && v9 == v7 )
            {
              LODWORD(v10) = 0x10000;
            }
            else
            {
              v14 = __PAIR64__(HIWORD(v8) | (v9 << 16), (v7 << 31) | (v6 >> 1)) + __PAIR64__(v7 >> 1, v8 << 16);
              if ( !v6 && !v7 )
                __brkdiv0();
              LODWORD(v10) = _rt_udiv64(__SPAIR64__(v7, v6), v14);
              if ( v10 > 1 )
                goto LABEL_15;
              LODWORD(v10) = 1;
            }
            HIDWORD(v10) = 0;
LABEL_15:
            v11 = 0;
            if ( v2[6] )
            {
              v12 = 0;
              do
              {
                ++v11;
                v13 = *(_DWORD *)(v2[8] + v12);
                v12 += 80;
                *(_DWORD *)(v13 + 3236) = v10;
              }
              while ( v11 < v2[6] );
            }
            if ( (unsigned int)v5 >= v10 )
              v5 = v10;
            v2 = (int *)*v2;
          }
          while ( v2 != &PpmPerfDomainHead );
        }
        PpmHeteroMinRelativePerformance = v5;
      }
    }
  }
}
