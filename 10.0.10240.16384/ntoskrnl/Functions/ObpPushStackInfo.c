// ObpPushStackInfo 
 
unsigned int __fastcall ObpPushStackInfo(unsigned int result, int a2, unsigned __int16 a3, int a4)
{
  unsigned int v7; // r5
  int v8; // r0
  BOOL v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r4
  _BYTE v12[88]; // [sp+8h] [bp-58h] BYREF

  v7 = result;
  if ( (dword_682610 & 0x80) != 0 )
  {
    v8 = 4403;
    if ( a2 )
      v8 = 4402;
    result = EtwTraceObjectOperation(v8, v7, a3, a4);
  }
  if ( (ObpTraceFlags & 0x73) != 0 && (*(_BYTE *)(v7 + 13) & 1) != 0 )
  {
    v9 = KeAreInterruptsEnabled();
    result = v9 ? KeGetCurrentIrql(v9) : 15;
    if ( result <= 2 )
    {
      result = RtlCaptureStackBackTrace(1u, 0x10u, (int)v12, 0);
      if ( result )
      {
        if ( result < 0x10 )
          memset(&v12[4 * result], 0, 4 * (16 - result));
        __dmb(0xBu);
        do
        {
          v10 = __ldrex((unsigned int *)&ObpStackSequence);
          v11 = v10 + 1;
        }
        while ( __strex(v11, (unsigned int *)&ObpStackSequence) );
        __dmb(0xBu);
        if ( MmCanThreadFault() )
          result = ObpPushRefDerefInfo(v7, a2, a3, v11, v12, a4);
        else
          result = ObpDeferPushRefDerefInfo(v7, a2, a3, v11, v12, a4);
      }
    }
  }
  return result;
}
