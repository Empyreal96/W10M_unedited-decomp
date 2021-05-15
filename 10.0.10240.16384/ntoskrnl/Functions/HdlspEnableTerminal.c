// HdlspEnableTerminal 
 
int __fastcall HdlspEnableTerminal(int a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r3
  int v4; // r4

  if ( a1 == 1 )
  {
    v1 = *(_DWORD *)(HeadlessGlobals + 24);
    if ( (v1 & 1) == 0 && (!*(_BYTE *)(HeadlessGlobals + 80) || (v1 & 2) == 0) )
    {
      v2 = *(_DWORD *)(HeadlessGlobals + 24) & 0xFFFFFFFE | InbvPortInitialize(
                                                              *(_DWORD *)(HeadlessGlobals + 28),
                                                              (v1 >> 9) & 7,
                                                              *(_DWORD *)(HeadlessGlobals + 36),
                                                              (_DWORD *)(HeadlessGlobals + 32),
                                                              *(_BYTE *)(HeadlessGlobals + 80),
                                                              *(_BYTE *)(HeadlessGlobals + 53),
                                                              *(_BYTE *)(HeadlessGlobals + 54)) & 1;
      *(_DWORD *)(HeadlessGlobals + 24) = v2;
      if ( (v2 & 1) == 0 )
        return -1073741823;
      HdlspSendStringAtBaud("\x1B[2J");
      HdlspSendStringAtBaud("\x1B[H");
      InbvPortEnableFifo(*(_DWORD *)(HeadlessGlobals + 32));
    }
  }
  else if ( !a1 )
  {
    v4 = HeadlessGlobals;
    InbvPortTerminate(*(_DWORD *)(HeadlessGlobals + 32));
    *(_DWORD *)(v4 + 32) = 0;
    *(_DWORD *)(v4 + 24) &= 0xFFFFFFFE;
  }
  return 0;
}
