// HdlspBugCheckProcessing 
 
int HdlspBugCheckProcessing()
{
  int result; // r0
  int v1; // r4
  const char *v2; // r0
  unsigned __int8 v3[88]; // [sp-4h] [bp-58h] BYREF

  result = HdlspGetLine(v3, 80);
  if ( result )
  {
    if ( !stricmp(v3, "?") || !stricmp(v3, "help") )
    {
      HdlspSendStringAtBaud("\r\n");
      HdlspSendStringAtBaud("d        Display all log entries, paging is on.\r\n");
      HdlspSendStringAtBaud("help     Display this list.\r\n");
      HdlspSendStringAtBaud("restart  Restart the system immediately.\r\n");
      HdlspSendStringAtBaud("?        Display this list.\r\n");
      v2 = "\r\n";
    }
    else
    {
      if ( !stricmp(v3, "d") )
      {
        HdlspProcessDumpCommand(1);
        return HdlspSendStringAtBaud("\n\r!SAC>");
      }
      if ( !stricmp(v3, "restart") )
      {
        v1 = 10;
        do
        {
          KeStallExecutionProcessor(100000);
          --v1;
        }
        while ( v1 );
        HalReturnToFirmware(3);
      }
      v2 = "Type ? or Help for a list of commands.\r\n";
    }
    HdlspSendStringAtBaud(v2);
    return HdlspSendStringAtBaud("\n\r!SAC>");
  }
  return result;
}
