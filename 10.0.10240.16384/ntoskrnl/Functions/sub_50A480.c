// sub_50A480 
 
void sub_50A480()
{
  int v0; // r4
  int v1; // r6
  int v2; // r0
  int v3; // r7
  int v4; // r0
  unsigned __int16 v5; // r5

  v1 = RtlpStackTraceDatabase;
  if ( RtlpStackTraceDatabase && (v2 = RtlStdLogStackTrace(RtlpStackTraceDatabase), (v3 = v2) != 0) )
  {
    v4 = RtlpStdGetRecordedStackTraceIndex(v1, v2);
    v5 = v4;
    if ( !v4 )
      RtlStdReleaseStackTrace(v1, v3);
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(v0 + 48) = v5;
  JUMPOUT(0x43A730);
}
