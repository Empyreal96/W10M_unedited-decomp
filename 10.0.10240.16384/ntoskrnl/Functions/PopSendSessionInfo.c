// PopSendSessionInfo 
 
int __fastcall PopSendSessionInfo(int result, int a2, int a3, int a4)
{
  int v4; // [sp+0h] [bp-30h] BYREF
  char v5; // [sp+4h] [bp-2Ch]
  int v6; // [sp+8h] [bp-28h]
  int v7; // [sp+Ch] [bp-24h]
  int v8; // [sp+10h] [bp-20h]
  int v9; // [sp+14h] [bp-1Ch]
  int varg_r0[4]; // [sp+20h] [bp-10h] BYREF

  varg_r0[0] = result;
  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  if ( PsWin32CalloutsEstablished )
  {
    v4 = 0;
    v5 = 0;
    v7 = a4;
    v6 = 20;
    v8 = 0;
    v9 = 0;
    result = PsInvokeWin32Callout(5, (int)&v4, 1, varg_r0);
  }
  return result;
}
