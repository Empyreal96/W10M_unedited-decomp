// PspTerminateThreadByPointer 
 
int __fastcall PspTerminateThreadByPointer(_DWORD *a1, int a2, int a3)
{
  int v3; // r6
  unsigned int *v7; // r2
  unsigned int v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1

  v3 = a1[84];
  if ( (a1[240] & 0x20) != 0 )
    return sub_7F79D0();
  if ( a3 && a1 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    __dmb(0xBu);
    v7 = a1 + 240;
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 1, v7) );
    __dmb(0xBu);
    PspExitThread(a2);
  }
  if ( (a1[19] & 0x400) != 0 )
    return -1073741790;
  if ( (*(_DWORD *)(v3 + 736) & 1) != 0 )
    return -1073741637;
  __dmb(0xBu);
  v9 = (unsigned __int8 *)(a1 + 240);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 1, v9) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    a1[246] = a2;
  KeRequestTerminationThread((int)a1);
  return 0;
}
