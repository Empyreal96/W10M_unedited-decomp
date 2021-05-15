// InbvPortGetByte 
 
BOOL __fastcall InbvPortGetByte(int a1, int a2)
{
  return PortGetByte(&Port[3 * a1], a2, 1, 0) == 0;
}
