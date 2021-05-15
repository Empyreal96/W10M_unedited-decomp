// PdcPoControlInput 
 
int __fastcall PdcPoControlInput(int result, int a2)
{
  int v2; // r3
  int v3; // [sp+0h] [bp-30h] BYREF
  int v4[9]; // [sp+8h] [bp-28h] BYREF
  int v5; // [sp+2Ch] [bp-4h] BYREF

  v4[8] = result;
  v5 = a2;
  if ( result )
  {
    if ( result == 1 )
    {
      v2 = 1;
    }
    else
    {
      if ( result != 2 )
        return result;
      v2 = 2;
    }
  }
  else
  {
    v2 = 0;
  }
  v3 = v2;
  memset(v4, 0, 24);
  v4[0] = 4;
  LOBYTE(v4[1]) = 0;
  v4[2] = 4;
  v4[3] = (int)&v3;
  v4[4] = 0;
  v4[5] = 0;
  return PsInvokeWin32Callout(5, v4, 1, &v5);
}
