// EtwpNetProvTraceNetwork 
 
int __fastcall EtwpNetProvTraceNetwork(int a1, int a2)
{
  int *v2; // r2
  int result; // r0

  if ( a2 > 2058 )
  {
    switch ( a2 )
    {
      case 2059:
        v2 = KNetEvt_RecvIPV4Udp;
        break;
      case 2065:
        v2 = KNetEvt_FailUdp;
        break;
      case 2074:
        v2 = KNetEvt_SendIPV6Udp;
        break;
      case 2075:
        v2 = KNetEvt_RecvIPV6Udp;
        break;
      default:
        return result;
    }
    return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
  }
  if ( a2 == 2058 )
  {
    v2 = KNetEvt_SendIPV4Udp;
    return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
  }
  switch ( a2 )
  {
    case 1546:
      v2 = KNetEvt_SendIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1547:
      v2 = KNetEvt_RecvIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1548:
      v2 = KNetEvt_ConnectIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1549:
      v2 = KNetEvt_DisconnectIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1550:
      v2 = KNetEvt_RetransmitIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1551:
      v2 = KNetEvt_AcceptIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1552:
      v2 = KNetEvt_ReconnectIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1553:
      v2 = KNetEvt_Fail;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1554:
      v2 = KNetEvt_TcpCopyIPV4;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1562:
      v2 = KNetEvt_SendIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1563:
      v2 = KNetEvt_RecvIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1564:
      v2 = KNetEvt_ConnectIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1565:
      v2 = KNetEvt_DisconnectIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1566:
      v2 = KNetEvt_RetransmitIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1567:
      v2 = KNetEvt_AcceptIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1568:
      v2 = KNetEvt_ReconnectIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    case 1570:
      v2 = KNetEvt_TcpCopyIPV6;
      return EtwWrite(EtwpNetProvRegHandle, unk_61A93C, (int)v2, 0);
    default:
      return result;
  }
  return result;
}
