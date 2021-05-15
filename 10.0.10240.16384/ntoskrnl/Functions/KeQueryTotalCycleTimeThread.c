// KeQueryTotalCycleTimeThread 
 
int __fastcall KeQueryTotalCycleTimeThread(int a1)
{
  int result; // r0

  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    result = KeUpdateTotalCyclesCurrentThread();
  else
    result = sub_5276A4();
  return result;
}
