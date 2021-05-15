// MiAllocateModWriterEntry 
 
int __fastcall MiAllocateModWriterEntry(__int16 *a1, int a2, int a3)
{
  int v5; // r4

  v5 = ExAllocatePoolWithTag(512, 4 * (a2 + 40), 1700228429);
  if ( !v5 )
    return 0;
  if ( !MiChargeForWriteInProgressPage(a1, a3 != 0) )
    return sub_53AE20();
  return v5;
}
