// PopIssueNextState 
 
int __fastcall PopIssueNextState(__int64 a1, unsigned int a2)
{
  int v2; // r6
  unsigned int *v3; // r7
  unsigned int v4; // r4
  unsigned int *v5; // r4
  unsigned int v6; // r5
  int result; // r0
  unsigned int v8; // r2

  v2 = a1;
  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 32);
  do
    v4 = __ldrex(v3);
  while ( __strex(0, v3) );
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 36);
  do
    v6 = __ldrex(v5);
  while ( __strex(a2, v5) );
  __dmb(0xBu);
  *(_DWORD *)HIDWORD(a1) = 0;
  result = PopHandleNextState(a1);
  while ( 1 )
  {
    v8 = *v3;
    __dmb(0xBu);
    if ( v8 == *(_DWORD *)(v2 + 28) )
      break;
    __dmb(0xAu);
    __yield();
  }
  return result;
}
