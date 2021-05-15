// RtlAssert 
 
BOOL __fastcall RtlAssert(int a1, int a2, int a3, int a4)
{
  char *v5; // r3
  BOOL result; // r0
  int v7[110]; // [sp+18h] [bp-1B8h] BYREF

  RtlCaptureContext(v7, a2, a3, a4);
  if ( a4 )
    v5 = (char *)a4;
  else
    v5 = &byte_5CB13F;
  DbgPrintEx(101, 0, (int)"\n*** Assertion failed: %s%s\n***   Source File: %s, line %ld\n\n", (int)v5);
  result = RtlIsAnyDebuggerPresent();
  if ( result )
    DbgPrompt((unsigned int)"Break repeatedly, break Once, Ignore, terminate Process, or terminate Thread (boipt)? ");
  return result;
}
