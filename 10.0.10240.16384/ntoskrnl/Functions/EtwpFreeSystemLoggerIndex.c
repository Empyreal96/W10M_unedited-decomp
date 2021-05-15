// EtwpFreeSystemLoggerIndex 
 
int __fastcall EtwpFreeSystemLoggerIndex(int a1)
{
  int v2; // r1
  int result; // r0
  unsigned __int8 *v4; // r3
  unsigned int v5; // r2

  KeWaitForSingleObject((unsigned int)&EtwpStartTraceMutex, 0, 0, 0, 0);
  v2 = (unsigned __int16)EtwpSystemLogger[2 * a1 + 1];
  --*((_BYTE *)&EtwpTimeStampStatus + 2 * v2);
  result = KeReleaseMutex((int)&EtwpStartTraceMutex);
  __dmb(0xBu);
  v4 = (unsigned __int8 *)&EtwpActiveSystemLoggers + (a1 >> 3);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 & ~(unsigned __int8)(1 << (a1 & 7)), v4) );
  __dmb(0xBu);
  return result;
}
