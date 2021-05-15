// MiReserveWorkingSetSwapSpace 
 
int __fastcall MiReserveWorkingSetSwapSpace(int a1, unsigned int *a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  unsigned int *v6; // r2
  unsigned int i; // r6
  unsigned int v10; // r5
  int v11; // r3

  v6 = *(unsigned int **)(a1 + 4 * a4 + 3600);
  for ( i = a4; ; i = a5 )
  {
    if ( i == a5 || a5 == 2 )
    {
      v11 = 1;
    }
    else
    {
      v10 = *v6;
      v11 = (v6[24] & 0x20) != 0 ? v10 >> 1 : v10 - (v10 >> 6);
    }
    if ( !MiReserveWorkingSetSwapSpaceRuns(a1, a6, i, v11) )
      break;
    MiFreeReservationRuns(a1, a2);
    memset(a2, 0, 40);
    if ( i == a5 || a5 >= 2 )
      return -1073741275;
    v6 = *(unsigned int **)(a1 + 4 * a5 + 3600);
  }
  return 0;
}
