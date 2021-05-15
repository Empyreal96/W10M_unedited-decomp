// KiIpiProcessRequests 
 
int __fastcall KiIpiProcessRequests(int a1)
{
  int v1; // r4
  int v2; // r6
  int v3; // r10
  __int64 v4; // r0
  unsigned int v5; // r3
  unsigned int v6; // r9
  unsigned int *v7; // r2
  int v8; // r1
  int v9; // r7
  _DWORD *v10; // r5
  int v11; // r0
  int v12; // r8
  int v13; // r3
  int v14; // r3
  int v17; // [sp+8h] [bp-38h]
  char v18[48]; // [sp+10h] [bp-30h] BYREF

  v1 = a1;
  v2 = 0;
  v3 = 0;
  if ( (dword_682608 & 0x400000) != 0 )
  {
    HIDWORD(v4) = 1077936128;
    LODWORD(v4) = v18;
    v3 = 1;
    EtwGetKernelTraceTimestamp(v4);
  }
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = v5 + 1408;
  __dmb(0xBu);
  v7 = (unsigned int *)(v5 + 3084);
  v8 = 0;
  do
    v9 = __ldrex(v7);
  while ( __strex(0, v7) );
  __dmb(0xBu);
  if ( *(_DWORD *)(v5 + 3072) )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(v5 + 3072);
    do
      v10 = (_DWORD *)__ldrex(v7);
    while ( __strex(0, v7) );
    __dmb(0xBu);
    if ( v10 )
    {
      v2 = 1;
      while ( 1 )
      {
        v11 = (int)*(&KiProcessorBlock + ((int)((int)v10 - v6 - 18432) >> 5));
        v12 = (int)v10;
        v13 = v10[1];
        v10 = (_DWORD *)*v10;
        v17 = v11;
        if ( (v13 & 0xF) == 6 )
        {
          (*(void (**)(void))(v12 + 20))();
          v11 = v17;
        }
        KiIpiCompleteIpiRequest(v12, v11);
        if ( !v10 )
        {
          __dmb(0xBu);
          v8 = 0;
          v7 = (unsigned int *)(v6 + 1664);
          do
            v10 = (_DWORD *)__ldrex(v7);
          while ( __strex(0, v7) );
          __dmb(0xBu);
          if ( !v10 )
            break;
        }
      }
      v1 = a1;
    }
  }
  v14 = 0;
  if ( (v9 & 1) != 0 )
  {
    HalRequestSoftwareInterrupt(1);
    v14 = 1;
  }
  if ( (v9 & 2) != 0 )
  {
    HalRequestSoftwareInterrupt(2);
    v14 = 1;
  }
  if ( v14 )
    v2 = 1;
  if ( (*(_DWORD *)(v6 + 1672) & 0xF) == 5 )
  {
    KiFreezeCurrentProcessor(v1, v8, (int)v7, 5);
    v2 = 1;
  }
  if ( v3 )
    PerfInfoLogIpi((int)v18, v9);
  return v2;
}
