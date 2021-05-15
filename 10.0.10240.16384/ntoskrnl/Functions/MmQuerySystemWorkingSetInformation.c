// MmQuerySystemWorkingSetInformation 
 
int __fastcall MmQuerySystemWorkingSetInformation(int result, int *a2)
{
  int *v3; // r5
  int v4; // r8
  int v5; // r9
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int v10; // r3
  unsigned int v11; // r1

  a2[8] = 0;
  switch ( result )
  {
    case 2:
      v3 = &dword_634E00;
      break;
    case 3:
      v3 = &dword_634E80;
      break;
    case 4:
      v3 = &dword_634F00;
      break;
    default:
      return result;
  }
  v4 = result - 2;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_517300();
  v6 = *v3 & 0x7FFFFFFF;
  do
    v7 = __ldrex((unsigned int *)v3);
  while ( v7 == v6 && __strex(v6 + 1, (unsigned int *)v3) );
  __dmb(0xBu);
  if ( v7 != v6 )
    ExpWaitForSpinLockSharedAndAcquire(v3, v7);
  *a2 = v3[13];
  a2[1] = v3[21];
  a2[2] = v3[25];
  a2[3] = v3[12];
  a2[4] = v3[17];
  if ( (v3[28] & 0x80) == 128 )
    a2[8] |= 4u;
  if ( (v3[28] & 0x40) != 0 )
    a2[8] |= 1u;
  a2[6] = MiState[v4 + 1793];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)v3);
    while ( __strex(v8 & 0xBFFFFFFF, (unsigned int *)v3) );
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)v3);
    while ( __strex(v9 - 1, (unsigned int *)v3) );
  }
  KfLowerIrql(v5);
  a2[7] = MiGetStandbyRepurposed(MiSystemPartition, 1);
  result = *a2;
  v10 = a2[6];
  v11 = *a2 + dword_634680;
  a2[5] = v11;
  if ( v11 > v10 )
    a2[5] = v10;
  *a2 = result << 12;
  a2[1] <<= 12;
  return result;
}
