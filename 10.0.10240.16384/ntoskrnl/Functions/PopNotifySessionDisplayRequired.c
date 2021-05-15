// PopNotifySessionDisplayRequired 
 
int __fastcall PopNotifySessionDisplayRequired(int a1, int a2)
{
  int v2; // r3
  int v4; // [sp+0h] [bp-30h] BYREF
  int v5; // [sp+4h] [bp-2Ch] BYREF
  char v6; // [sp+8h] [bp-28h] BYREF
  int v7[8]; // [sp+10h] [bp-20h] BYREF

  if ( PsWin32CalloutsEstablished )
  {
    v2 = -1;
    if ( a1 )
      v2 = 1;
    v4 = v2;
    v5 = a2;
    memset(v7, 0, 24);
    v7[0] = 2;
    v7[2] = 4;
    v7[3] = (int)&v4;
    v7[4] = 4;
    v7[5] = (int)&v6;
    PsInvokeWin32Callout(5, (int)v7, 1, &v5);
  }
  return 0;
}
