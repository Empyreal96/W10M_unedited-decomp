// KiStartDpcThread 
 
int __fastcall KiStartDpcThread(int a1)
{
  int v2; // r4
  int v4; // [sp+18h] [bp-20h] BYREF
  int v5; // [sp+20h] [bp-18h] BYREF
  int v6; // [sp+24h] [bp-14h]
  int v7; // [sp+28h] [bp-10h]

  v5 = 0;
  v6 = 0;
  v7 = 0;
  v6 = *(unsigned __int8 *)(a1 + 1052);
  v5 = *(_DWORD *)(a1 + 1048);
  v2 = PsCreateSystemThreadEx((int)&v4, 0x1FFFFF, 0, 0, 0, (int)KiExecuteDpc, a1, &v5, (int *)(a1 + 20));
  if ( v2 >= 0 )
  {
    ZwClose();
  }
  else if ( KeDpcWatchdogPeriod )
  {
    KeCancelTimer(a1 + 3320);
  }
  return v2;
}
