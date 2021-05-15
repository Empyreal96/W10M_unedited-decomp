// IoAcquireRemoveLockEx 
 
int __fastcall IoAcquireRemoveLockEx(_BYTE *a1, int a2, int a3, int a4, int a5)
{
  unsigned int *v6; // r0
  unsigned int v7; // r5
  int result; // r0
  unsigned int v9; // r2
  unsigned int v10; // r2

  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 4);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  if ( *a1 )
  {
    __dmb(0xBu);
    do
    {
      v9 = __ldrex(v6);
      v10 = v9 - 1;
    }
    while ( __strex(v10, v6) );
    __dmb(0xBu);
    if ( !v10 )
      KeSetEvent((int)(a1 + 8), 0, 0);
    result = -1073741738;
  }
  else if ( a5 == 88 )
  {
    result = sub_50E204();
  }
  else
  {
    result = 0;
  }
  return result;
}
