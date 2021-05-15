// PopBroadcastSessionInfo 
 
int __fastcall PopBroadcastSessionInfo(int a1, int a2, int a3)
{
  int result; // r0
  int v4; // [sp+0h] [bp-20h] BYREF
  char v5; // [sp+4h] [bp-1Ch]
  int v6; // [sp+8h] [bp-18h]
  int v7; // [sp+Ch] [bp-14h]
  int v8; // [sp+10h] [bp-10h]
  int v9; // [sp+14h] [bp-Ch]

  if ( PsWin32CalloutsEstablished )
  {
    v4 = 0;
    v5 = 0;
    v6 = 20;
    v7 = a3;
    v8 = 0;
    v9 = 0;
    result = PsInvokeWin32Callout(5, &v4, 2, 0);
  }
  return result;
}
