// MiInsertUnusedSegment 
 
int __fastcall MiInsertUnusedSegment(_DWORD *a1, int a2)
{
  int v3; // r2
  int v4; // r8
  int v5; // r3
  unsigned int v7; // r1
  int v8; // r7
  int v9; // r3
  int *v10; // r1
  int **v11; // r6
  unsigned int v12; // r0
  _DWORD *v13; // r0
  void **v14; // r6

  v3 = a1[7];
  v4 = 0;
  if ( (v3 & 0x100) != 0 )
    return 0;
  if ( (v3 & 0x20) == 0 )
  {
    v5 = a1[8];
    if ( v5 )
    {
      if ( (v3 & 0x400) == 0 )
        v4 = MiConvertStaticSubsections(a1, a2, v3, v5);
    }
  }
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_520C04();
  do
    v7 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
  while ( 1 )
  {
    v8 = dword_632D80;
    if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_632D80 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex((unsigned int *)&dword_632D80);
      while ( v12 == v8 && __strex(v8 | 0x40000000, (unsigned int *)&dword_632D80) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v9 = a1[7] | 0x8000000;
  a1[7] = v9;
  if ( (v9 & 0x40000) != 0 )
  {
    v13 = a1 + 1;
    v14 = (void **)dword_63FA2C;
    *v13 = &unk_63FA28;
    v13[1] = v14;
    if ( *v14 != &unk_63FA28 )
      __fastfail(3u);
    *v14 = v13;
    dword_63FA2C = (int)v13;
    ++dword_63FA64;
    if ( !byte_63FA60 )
    {
      byte_63FA60 = 1;
      KiSetTimerEx(&unk_63FA30, MiSystemPartition, Mi10Milliseconds[0], Mi10Milliseconds[1], 0, 0, 0);
    }
  }
  else
  {
    v10 = a1 + 1;
    v11 = (int **)dword_63FA6C;
    *v10 = (int)&dword_63FA68;
    v10[1] = (int)v11;
    if ( *v11 != &dword_63FA68 )
      __fastfail(3u);
    *v11 = v10;
    dword_63FA6C = (int)v10;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  return v4;
}
