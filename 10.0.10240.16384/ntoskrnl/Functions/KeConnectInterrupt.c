// KeConnectInterrupt 
 
int __fastcall KeConnectInterrupt(int a1, unsigned int a2, int a3, int a4)
{
  int v7; // r2
  int v8; // r7
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r0
  int v12; // r4
  int i; // [sp+0h] [bp-28h]
  int v15[9]; // [sp+4h] [bp-24h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v7 = KiIsInterruptTypeSecondary(a3);
  v8 = 0;
  v9 = 0;
  for ( i = v7; v9 < a2; v7 = i )
  {
    v10 = *(_DWORD *)(a1 + 4 * v9);
    *(_DWORD *)(v10 + 60) &= 0xFFFFFFFE;
    v11 = v7 ? KiConnectSecondaryInterrupt() : KiConnectInterruptInternal(v10, 0);
    v12 = v11;
    if ( v11 < 0 )
      goto LABEL_20;
    if ( v11 == 295 )
      v8 = 1;
    v9 = (unsigned __int8)(v9 + 1);
  }
  v12 = KiIntSteerConnect(a1, a2, a3 + 8);
  if ( v12 < 0 )
  {
LABEL_20:
    if ( v9 )
      KeDisconnectInterrupt(a1, v9, a3);
    return v12;
  }
  if ( !v8 )
  {
    v12 = HalEnableInterrupt(a3);
    if ( v12 < 0 )
      goto LABEL_20;
    KiIntSteerEnable(a1);
    goto LABEL_12;
  }
  if ( off_617B18(a3 + 8, v15) < 0 )
  {
LABEL_18:
    v12 = 295;
LABEL_12:
    if ( v12 >= 0 )
      return v12;
    goto LABEL_20;
  }
  if ( !i )
  {
    v12 = off_617A64(v15[0], 0);
    if ( v12 < 0 )
      goto LABEL_20;
    goto LABEL_18;
  }
  return sub_51F9E8();
}
