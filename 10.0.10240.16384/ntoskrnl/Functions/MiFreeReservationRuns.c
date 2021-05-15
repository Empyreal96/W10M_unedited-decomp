// MiFreeReservationRuns 
 
int __fastcall MiFreeReservationRuns(int result, unsigned int *a2)
{
  unsigned int *v2; // r4
  int v3; // r6
  unsigned int v4; // r5

  v2 = a2;
  v3 = result;
  v4 = (unsigned int)(a2 + 10);
  while ( (unsigned int)v2 < v4 )
  {
    result = MiFreeReservationRun(v3, v2);
    v2 += 2;
  }
  return result;
}
