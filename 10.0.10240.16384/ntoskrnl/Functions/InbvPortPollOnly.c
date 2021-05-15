// InbvPortPollOnly 
 
BOOL __fastcall InbvPortPollOnly(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-8h] BYREF

  v5 = a4;
  return PortGetByte(&Port[3 * a1], &v5, 0, 1) == 0;
}
