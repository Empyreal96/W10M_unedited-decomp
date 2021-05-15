// IoVerifierCheckForSettingsChange 
 
int __fastcall IoVerifierCheckForSettingsChange(char a1)
{
  unsigned int v1; // r1
  int result; // r0
  unsigned int v3; // r1
  unsigned int i; // r4
  unsigned int v5; // r1

  __dmb(0xBu);
  if ( (a1 & 0x10) != 0 )
  {
    do
      v1 = __ldrex((unsigned int *)&IovpEnabledInThePast);
    while ( __strex(1u, (unsigned int *)&IovpEnabledInThePast) );
    __dmb(0xBu);
    result = 0;
    do
      v3 = __ldrex((unsigned int *)&IovpDisabledWithoutReboot);
    while ( __strex(0, (unsigned int *)&IovpDisabledWithoutReboot) );
    __dmb(0xBu);
    if ( !IovIrpTraces && IovIrpTracesLength )
    {
      for ( i = 2; i < 0x100000; i *= 2 )
      {
        if ( i >= IovIrpTracesLength )
          break;
      }
      IovIrpTracesLength = i;
      result = ExAllocatePoolWithTagPriority(512, i << 6, 1414096470, 32);
      IovIrpTraces = result;
      if ( result )
        result = (int)memset((_BYTE *)result, 0, i << 6);
    }
  }
  else
  {
    result = 1;
    do
      v5 = __ldrex((unsigned int *)&IovpDisabledWithoutReboot);
    while ( __strex(1u, (unsigned int *)&IovpDisabledWithoutReboot) );
    __dmb(0xBu);
  }
  return result;
}
