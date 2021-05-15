// PdcPoBlockSessionSwitch 
 
int __fastcall PdcPoBlockSessionSwitch(int a1, int *a2)
{
  int result; // r0
  int v5; // [sp+0h] [bp-30h] BYREF
  int v6[10]; // [sp+8h] [bp-28h] BYREF

  memset(v6, 0, 24);
  LOBYTE(v6[0]) = 0;
  v6[1] = 0;
  v6[2] = 1;
  if ( a1 )
  {
    result = PoBlockConsoleSwitch(v6);
    *a2 = result;
  }
  else
  {
    v5 = *a2;
    v6[4] = 7;
    result = PopDispatchStateCallout(v6, &v5);
  }
  return result;
}
