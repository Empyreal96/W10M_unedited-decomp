// PopGetConsoleDisplayRequestCount 
 
int PopGetConsoleDisplayRequestCount()
{
  int result; // r0
  int v1; // [sp+0h] [bp-30h] BYREF
  int v2; // [sp+4h] [bp-2Ch] BYREF
  int v3; // [sp+8h] [bp-28h] BYREF
  int v4[8]; // [sp+10h] [bp-20h] BYREF

  result = 0;
  v1 = 0;
  if ( PsWin32CalloutsEstablished )
  {
    v3 = MEMORY[0xFFFF92D8];
    if ( MEMORY[0xFFFF92D8] == -1
      || (memset(v4, 0, 24),
          v2 = 0,
          v4[0] = 2,
          v4[2] = 4,
          v4[3] = (int)&v2,
          v4[4] = 4,
          v4[5] = (int)&v1,
          PsInvokeWin32Callout(5, v4, 1, &v3) >= 0) )
    {
      result = v1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
