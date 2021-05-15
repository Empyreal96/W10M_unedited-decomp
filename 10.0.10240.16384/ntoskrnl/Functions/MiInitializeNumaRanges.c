// MiInitializeNumaRanges 
 
int __fastcall MiInitializeNumaRanges(int a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // r8
  int v9; // r9
  unsigned int v10; // r1
  unsigned int v11; // r6
  int v12; // r5
  _DWORD *v13; // r1
  unsigned int v14; // r0
  int v15; // r0
  int v16; // r2
  _DWORD *v17; // [sp+0h] [bp-28h] BYREF
  _DWORD v18[9]; // [sp+4h] [bp-24h] BYREF

  v17 = a2;
  v18[0] = a3;
  v18[1] = a4;
  if ( MmPhysicalMemoryBlock )
  {
    v4 = v18;
    v5 = 0;
  }
  else
  {
    v4 = 0;
    v5 = 8;
  }
  v6 = 0;
  v7 = off_617B54(30, v5, &v17, v4);
  if ( v7 >= 0 )
  {
    if ( v4 )
    {
      if ( v5 != *v4 )
        return sub_54E870();
      if ( !v5 )
        v17 = 0;
    }
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      v11 = 271;
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632EBC);
    }
    else
    {
      do
        v10 = __ldrex((unsigned __int8 *)&dword_632EBC + 3);
      while ( __strex(v10 | 0x80, (unsigned __int8 *)&dword_632EBC + 3) );
      __dmb(0xBu);
      v11 = 0x10Fu;
      if ( v10 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632EBC);
      while ( 1 )
      {
        v12 = dword_632EBC;
        if ( (dword_632EBC & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632EBC & 0x40000000) == 0 )
        {
          do
            v14 = __ldrex((unsigned int *)&dword_632EBC);
          while ( v14 == v12 && __strex(v12 | 0x40000000, (unsigned int *)&dword_632EBC) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v6 = dword_6337F0;
    if ( dword_6337F0 && !byte_6337F4 )
    {
      byte_6337F4 = 1;
      v6 = 0;
    }
    v13 = v17;
    if ( v17 )
    {
      v15 = 0;
      if ( *v17 != -1 )
      {
        v16 = 0;
        do
        {
          if ( v13[v16 + 1] >= (unsigned int)(unsigned __int16)KeNumberNodes )
          {
            v13[v16 + 1] = 0;
            v13 = v17;
          }
          ++v15;
          v16 = 2 * v15;
        }
        while ( v13[2 * v15] != -1 );
      }
    }
    dword_6337F0 = (int)v13;
    dword_6337EC = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v11]);
    }
    else
    {
      __dmb(0xBu);
      MiState[v11] = 0;
    }
    KfLowerIrql(v9);
  }
  if ( v6 )
    ExFreePoolWithTag(v6, 0);
  return v7;
}
