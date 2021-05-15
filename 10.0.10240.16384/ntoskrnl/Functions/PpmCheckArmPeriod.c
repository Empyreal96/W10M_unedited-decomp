// PpmCheckArmPeriod 
 
__int64 *PpmCheckArmPeriod()
{
  unsigned int v0; // r5
  int v1; // r1
  __int64 *result; // r0
  int v3; // r2
  unsigned __int64 v4; // r2
  unsigned __int64 v5; // r2

  v0 = 0;
  v1 = 10000 * PpmCurrentProfile[44 * dword_61EC0C + 13];
  if ( (unsigned int)v1 <= (unsigned __int64)PpmCheckMinimumPeriod )
  {
    v0 = HIDWORD(PpmCheckMinimumPeriod);
    v1 = PpmCheckMinimumPeriod;
  }
  result = &PpmCheckPeriod;
  v3 = (unsigned __int8)PpmCheckArmed;
  if ( !PpmCheckArmed )
    goto LABEL_6;
  if ( __PAIR64__(v0, v1) != PpmCheckPeriod )
  {
    __dmb(0xBu);
    do
      v5 = __ldrexd((unsigned __int64 *)&PpmCheckLastExecutionTime);
    while ( __strexd(0i64, (unsigned __int64 *)&PpmCheckLastExecutionTime) );
    __dmb(0xBu);
    v3 = 0;
    PpmCheckArmed = 0;
  }
  if ( !v3 )
  {
LABEL_6:
    LODWORD(PpmCheckPeriod) = v1;
    HIDWORD(PpmCheckPeriod) = v0;
    PopExecuteOnTargetProcessors((int)&PpmCheckRegistered, (int)PpmCheckReset, 0, 0);
    __dmb(0xBu);
    result = 0;
    do
      v4 = __ldrexd((unsigned __int64 *)&PpmCheckLastExecutionTime);
    while ( __strexd(1ui64, (unsigned __int64 *)&PpmCheckLastExecutionTime) );
    __dmb(0xBu);
    PpmCheckArmed = 1;
  }
  return result;
}
