// PspTerminateProcess 
 
int __fastcall PspTerminateProcess(unsigned int *a1, int a2, int a3, int a4)
{
  unsigned int *v5; // r5
  unsigned int v6; // r10
  int v7; // r0
  int v8; // r4

  __dmb(0xBu);
  v5 = a1 + 48;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 8, v5) );
  __dmb(0xBu);
  if ( (v6 & 8) == 0 )
    return sub_7C2720((int)a1);
  if ( a1[195] && dword_61D9D4 )
    v7 = dword_61D9D4(a1, a3);
  else
    v7 = PspTerminateAllThreads(a1, a2, a3, a4 | 2);
  v8 = v7;
  if ( (v6 & 8) == 0 )
    KeForceResumeProcess(a1);
  return v8;
}
