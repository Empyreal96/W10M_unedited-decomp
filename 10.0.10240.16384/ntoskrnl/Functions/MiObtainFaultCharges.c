// MiObtainFaultCharges 
 
int __fastcall MiObtainFaultCharges(__int16 *a1, unsigned int a2, char a3)
{
  unsigned int *v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r2
  int result; // r0
  unsigned int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r0

  while ( 1 )
  {
    if ( a1 == MiSystemPartition )
    {
      v6 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992);
      v7 = *v6;
      if ( a2 <= *v6 && v7 != -1 )
        break;
    }
    if ( MiChargePartitionResidentAvailable((int)a1, a2, 1024) )
      goto LABEL_8;
    a2 >>= 1;
    if ( !a2 )
      goto LABEL_22;
  }
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 - a2, v6) );
  if ( v8 != v7 )
    return sub_545648();
LABEL_8:
  if ( a2 )
    goto LABEL_9;
LABEL_22:
  if ( (a3 & 2) == 0 )
    return 0;
  a2 = 1;
  MiChargeResident(a1, 1, -1);
LABEL_9:
  if ( (a3 & 1) != 0 )
  {
    v10 = a2;
    while ( MiChargeCommit((int)a1, v10, 1) != 1 )
    {
      v10 >>= 1;
      if ( !v10 )
      {
        if ( (a3 & 2) != 0 )
        {
          v10 = 1;
          MiChargeCommit((int)a1, 1u, 4);
        }
        break;
      }
    }
    if ( a1 == MiSystemPartition )
    {
      do
        v11 = __ldrex(&dword_634A2C[76]);
      while ( __strex(v11 + v10, &dword_634A2C[76]) );
    }
    if ( v10 != a2 )
      MiReturnFaultCharges(a1, a2 - v10, 0);
    result = v10;
  }
  else
  {
    if ( a1 == MiSystemPartition )
    {
      do
        v12 = __ldrex(&dword_634A2C[76]);
      while ( __strex(v12 + a2, &dword_634A2C[76]) );
    }
    result = a2;
  }
  return result;
}
