// sub_7EB794 
 
void __fastcall sub_7EB794(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r0
  int v5; // r3
  _DWORD *v6; // r7

  v4 = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(a3 + 94), 0);
  v6 = (_DWORD *)v4;
  if ( v4 )
  {
    EtwpProviderArrivalCallback(v4, 1, v3, v5);
    EtwpReleaseLoggerContext(v6, 0);
  }
  JUMPOUT(0x7657DC);
}
