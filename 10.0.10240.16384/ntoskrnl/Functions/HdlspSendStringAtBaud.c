// HdlspSendStringAtBaud 
 
_BYTE *__fastcall HdlspSendStringAtBaud(_BYTE *result)
{
  _BYTE *v1; // r4

  v1 = result;
  if ( *result )
  {
    do
      result = (_BYTE *)InbvPortPutByte(*(_DWORD *)(HeadlessGlobals + 32));
    while ( *++v1 );
  }
  return result;
}
