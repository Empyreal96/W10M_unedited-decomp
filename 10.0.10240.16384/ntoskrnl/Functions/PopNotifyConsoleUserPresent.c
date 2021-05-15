// PopNotifyConsoleUserPresent 
 
int __fastcall PopNotifyConsoleUserPresent(int result, int a2, int a3)
{
  int v3; // [sp+0h] [bp-30h] BYREF
  char v4[4]; // [sp+8h] [bp-28h] BYREF
  int v5; // [sp+Ch] [bp-24h]
  int v6; // [sp+10h] [bp-20h] BYREF
  char v7; // [sp+14h] [bp-1Ch]
  int v8; // [sp+18h] [bp-18h]
  char *v9; // [sp+1Ch] [bp-14h]
  int v10; // [sp+20h] [bp-10h]
  int v11; // [sp+24h] [bp-Ch]

  if ( PsWin32CalloutsEstablished )
  {
    v3 = MEMORY[0xFFFF92D8];
    if ( MEMORY[0xFFFF92D8] != -1 )
    {
      v4[1] = 0;
      v5 = a3;
      v6 = 1;
      v7 = 0;
      v8 = 8;
      v9 = v4;
      v10 = 0;
      v11 = 0;
      v4[0] = result;
      result = PsInvokeWin32Callout(5, &v6, 1, &v3);
    }
  }
  return result;
}
