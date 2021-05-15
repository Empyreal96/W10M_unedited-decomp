// ExpReleaseFastMutexContended 
 
unsigned int *__fastcall ExpReleaseFastMutexContended(unsigned int *result, unsigned int a2)
{
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r5
  int v5; // [sp+8h] [bp-18h] BYREF
  char v6[20]; // [sp+Ch] [bp-14h] BYREF

  while ( 1 )
  {
    v2 = 0;
    v3 = a2 + 1;
    if ( (a2 & 2) == 0 )
    {
      v3 = a2 - 1;
      v2 = 1;
    }
    __dmb(0xBu);
    do
      v4 = __ldrex(result);
    while ( v4 == a2 && __strex(v3, result) );
    __dmb(0xBu);
    if ( v4 == a2 )
      break;
    a2 = v4;
  }
  if ( v2 )
  {
    v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x7B);
    result = (unsigned int *)KeSetEventBoostPriorityEx(result + 3, v6, &v5, result, 1);
  }
  return result;
}
