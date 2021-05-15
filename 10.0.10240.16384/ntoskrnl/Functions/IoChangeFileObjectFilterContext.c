// IoChangeFileObjectFilterContext 
 
int __fastcall IoChangeFileObjectFilterContext(int a1, unsigned int a2, int a3)
{
  unsigned int v5; // r0
  bool v6; // zf
  unsigned int v7; // r1
  int result; // r0

  if ( !*(_DWORD *)(a1 + 124) )
    return -1073741811;
  IopGetFileObjectExtension();
  __dmb(0xBu);
  if ( a3 )
  {
    do
      v5 = __ldrex((unsigned int *)0x10);
    while ( !v5 && __strex(a2, (unsigned int *)0x10) );
    __dmb(0xBu);
    v6 = v5 == 0;
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)0x10);
    while ( v7 == a2 && __strex(0, (unsigned int *)0x10) );
    __dmb(0xBu);
    v6 = v7 == a2;
  }
  if ( v6 )
    result = 0;
  else
    result = -1073741791;
  return result;
}
