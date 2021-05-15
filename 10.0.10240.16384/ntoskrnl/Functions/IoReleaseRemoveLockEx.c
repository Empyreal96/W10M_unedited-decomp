// IoReleaseRemoveLockEx 
 
int __fastcall IoReleaseRemoveLockEx(int result, int a2, int a3)
{
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1

  if ( a3 == 88 )
    return sub_51EEA8();
  __dmb(0xBu);
  v3 = (unsigned int *)(result + 4);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 - 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  if ( !v5 )
    result = KeSetEvent(result + 8, 0, 0);
  return result;
}
