// PopDispatchStateCallout 
 
int __fastcall PopDispatchStateCallout(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  int v5; // r4
  int v6; // [sp+8h] [bp-40h] BYREF
  int v7[14]; // [sp+10h] [bp-38h] BYREF

  if ( (dword_682610 & 0x8000) != 0 )
    return sub_7EAC98();
  if ( a2 )
  {
    v3 = a2;
    v4 = 1;
  }
  else
  {
    v3 = 0;
    v4 = 2;
  }
  v5 = PsInvokeWin32Callout(4, a1, v4, v3);
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v7[0] = (int)&v6;
    v7[1] = 0;
    v7[2] = 4;
    v7[3] = 0;
    v6 = v5;
    EtwTraceKernelEvent(v7, 1, 0x80008000, 4649, 4200450);
  }
  return v5;
}
