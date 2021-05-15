// sub_7C3C60 
 
void __fastcall sub_7C3C60(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r0

  if ( a4 == 7 )
  {
    v5 = *(_DWORD *)(v4 + 20);
    if ( v5 )
      KeSetEvent(v5, 0, 0);
    if ( *(_BYTE *)(v4 + 16) )
      PfIoPowerEventNotify(*(_DWORD *)(v4 + 8));
  }
  else if ( (PoDebug & 2) != 0 )
  {
    DbgPrint("%s: Received an unrecognized message, type=%d\n", "PopUmpoProcessPowerMessage", *(_DWORD *)v4);
  }
  JUMPOUT(0x6B44FE);
}
