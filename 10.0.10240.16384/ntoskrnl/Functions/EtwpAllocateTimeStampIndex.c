// EtwpAllocateTimeStampIndex 
 
unsigned int __fastcall EtwpAllocateTimeStampIndex(int a1)
{
  unsigned int result; // r0
  int v3; // r1
  char v4; // r3
  void *v5; // r1

  for ( result = 0; result < 2; result = (unsigned __int8)(result + 1) )
  {
    v3 = *((char *)&EtwpTimeStampStatus + 2 * result);
    if ( v3 > 0 && *((unsigned __int8 *)&EtwpTimeStampStatus + 2 * result + 1) == a1 )
    {
      v4 = v3 + 1;
LABEL_5:
      *((_BYTE *)&EtwpTimeStampStatus + 2 * result) = v4;
      return result;
    }
  }
  result = 0;
  if ( !EtwpTimeStampStatus )
  {
    if ( a1 == 2 )
    {
      v5 = EtwpGetSystemTime;
    }
    else if ( a1 == 3 )
    {
      v5 = EtwpGetCycleCount;
    }
    else
    {
      v5 = EtwpGetPerfCounter;
    }
    EtwpSystemTimeStamp = v5;
    byte_61A659 = a1;
    v4 = EtwpTimeStampStatus + 1;
    goto LABEL_5;
  }
  return sub_81B8DC(0);
}
