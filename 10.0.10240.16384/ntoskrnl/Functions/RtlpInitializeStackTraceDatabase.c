// RtlpInitializeStackTraceDatabase 
 
int __fastcall RtlpInitializeStackTraceDatabase(int a1, int a2, unsigned int a3, int a4)
{
  int result; // r0
  int v5; // r3
  int v6; // r1
  int v7; // r2
  int v8; // [sp+0h] [bp-8h] BYREF

  v8 = a4;
  if ( RtlpStackTraceDatabase )
    return -1073741302;
  result = RtlStdInitializeStackDatabase(a1, a2, a3, &v8);
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v6 = v8;
    do
    {
      v7 = __ldrex((unsigned int *)&RtlpStackTraceDatabase);
      if ( v7 )
        break;
      v5 = __strex(v6, (unsigned int *)&RtlpStackTraceDatabase);
    }
    while ( v5 );
    __dmb(0xBu);
    if ( v7 )
    {
      RtlStdDeleteStackDatabase(v6, v6, v7, v5);
      return -1073741302;
    }
  }
  return result;
}
