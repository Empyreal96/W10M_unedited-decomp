// EtwpProcessThreadImageRundown 
 
int __fastcall EtwpProcessThreadImageRundown(int a1, unsigned int a2, int a3)
{
  int v7[11]; // [sp+0h] [bp-38h] BYREF

  memset(v7, 0, sizeof(v7));
  v7[0] = a1;
  v7[4] = a2;
  LOBYTE(v7[9]) = a3;
  if ( !EtwpAcquireLoggerContextByLoggerId(a2, 0) )
    return -1073741162;
  if ( a3 )
    JUMPOUT(0x7D0198);
  return sub_7D0194();
}
