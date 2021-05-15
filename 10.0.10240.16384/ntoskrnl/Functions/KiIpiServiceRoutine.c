// KiIpiServiceRoutine 
 
int __fastcall KiIpiServiceRoutine(int a1)
{
  int v1; // r9
  unsigned int v3; // r3
  unsigned int v4; // r6
  unsigned int *v5; // r2
  int v6; // r1
  unsigned int v7; // r5
  unsigned int *v8; // r2
  _DWORD *v9; // r10
  int v10; // r0
  _DWORD *v11; // r4
  int v12; // r3
  int v13; // [sp+0h] [bp-38h]

  v1 = *(_DWORD *)(a1 + 84);
  if ( (dword_682608 & 0x400000) != 0 )
    return sub_53FB54();
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v4 = v3 + 1408;
  __dmb(0xBu);
  v5 = (unsigned int *)(v3 + 3084);
  v6 = 0;
  do
    v7 = __ldrex(v5);
  while ( __strex(0, v5) );
  __dmb(0xBu);
  v8 = *(unsigned int **)(v3 + 3072);
  if ( v8 )
  {
    __dmb(0xBu);
    v8 = (unsigned int *)(v3 + 3072);
    v6 = 0;
    do
      v9 = (_DWORD *)__ldrex(v8);
    while ( __strex(0, v8) );
    __dmb(0xBu);
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = (int)*(&KiProcessorBlock + ((int)((int)v9 - v4 - 18432) >> 5));
        v11 = v9;
        v12 = v9[1];
        v9 = (_DWORD *)*v9;
        v13 = v10;
        if ( (v12 & 0xF) == 6 )
        {
          ((void (*)(void))v11[5])();
          v10 = v13;
        }
        KiIpiCompleteIpiRequest(v11, v10);
        if ( !v9 )
        {
          __dmb(0xBu);
          v8 = (unsigned int *)(v4 + 1664);
          v6 = 0;
          do
            v9 = (_DWORD *)__ldrex(v8);
          while ( __strex(0, v8) );
          __dmb(0xBu);
          if ( !v9 )
            break;
        }
      }
    }
  }
  if ( (v7 & 1) != 0 )
    HalRequestSoftwareInterrupt(1);
  if ( (v7 & 2) != 0 )
    HalRequestSoftwareInterrupt(2);
  if ( (*(_DWORD *)(v4 + 1672) & 0xF) == 5 )
    KiFreezeCurrentProcessor(v1, v6, (int)v8, 5);
  return 1;
}
