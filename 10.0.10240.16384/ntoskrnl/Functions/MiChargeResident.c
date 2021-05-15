// MiChargeResident 
 
int __fastcall MiChargeResident(__int16 *a1, unsigned int a2, int a3)
{
  unsigned int *v3; // r6
  unsigned int v4; // r5
  unsigned int v5; // r7
  int result; // r0

  if ( a1 != MiSystemPartition )
    return MiChargePartitionResidentAvailable((int)a1, a2, a3);
  v3 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992);
  v4 = *v3;
  if ( a2 > *v3 || v4 == -1 )
    return MiChargePartitionResidentAvailable((int)a1, a2, a3);
  do
    v5 = __ldrex(v3);
  while ( v5 == v4 && __strex(v4 - a2, v3) );
  if ( v5 == v4 )
    result = 1;
  else
    result = sub_50E6C4();
  return result;
}
