// HdlspSendBlueScreenInfo 
 
int __fastcall HdlspSendBlueScreenInfo(int a1)
{
  int i; // r4
  _BYTE v4[168]; // [sp-4h] [bp-A8h] BYREF

  HdlspSendStringAtBaud("\a\a\a<?xml>\a<BP>");
  HdlspSendStringAtBaud("\r\n<INSTANCE CLASSNAME=\"BLUESCREEN\">");
  sprintf_s(
    (int)v4,
    160,
    (int)"\r\n<PROPERTY NAME=\"STOPCODE\" TYPE=\"string\"><VALUE>\"0x%0X\"</VALUE></PROPERTY>",
    a1);
  HdlspSendStringAtBaud(v4);
  for ( i = *(_DWORD *)(HeadlessGlobals + 20); i; i = *(_DWORD *)(i + 8) )
    HdlspSendStringAtBaud(*(_DWORD *)(i + 4));
  return HdlspSendStringAtBaud("\r\n</INSTANCE>\r\n</BP>\a");
}
