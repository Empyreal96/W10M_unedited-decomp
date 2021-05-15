// KeQueryInterruptTime 
 
int KeQueryInterruptTime()
{
  int v0; // r1
  int result; // r0

  v0 = MEMORY[0xFFFF900C];
  __dmb(0xBu);
  result = MEMORY[0xFFFF9008];
  __dmb(0xBu);
  if ( v0 != MEMORY[0xFFFF9010] )
    result = sub_50E304(result, v0, -28660);
  return result;
}
