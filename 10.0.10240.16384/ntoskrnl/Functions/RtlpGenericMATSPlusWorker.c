// RtlpGenericMATSPlusWorker 
 
int __fastcall RtlpGenericMATSPlusWorker(int a1, int a2, int *a3)
{
  int *v6; // r2
  int v7; // t1

  RtlFillMemoryUlong(a3, 0x1000u, a1);
  KeInvalidateRangeAllCaches((int)a3, 4096);
  if ( RtlpTestAndFillMemoryUp(a1, a2, a3) )
  {
    KeInvalidateRangeAllCaches((int)a3, 4096);
    v6 = a3 + 1024;
    while ( 1 )
    {
      v7 = *--v6;
      if ( v7 != a2 )
        break;
      *v6 = a1;
      if ( v6 == a3 )
        return 1;
    }
  }
  return 0;
}
