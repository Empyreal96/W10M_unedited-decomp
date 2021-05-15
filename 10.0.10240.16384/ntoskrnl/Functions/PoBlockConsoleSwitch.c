// PoBlockConsoleSwitch 
 
int __fastcall PoBlockConsoleSwitch(int a1, int a2)
{
  int v3; // r3
  int v5[2]; // [sp+0h] [bp-20h] BYREF
  unsigned int v6[6]; // [sp+8h] [bp-18h] BYREF

  v5[0] = a1;
  v5[1] = a2;
  v6[0] = -100000;
  v6[1] = -1;
  while ( 1 )
  {
    v3 = MEMORY[0xFFFF92D8];
    __dmb(0xBu);
    v5[0] = v3;
    if ( v3 != -1 )
    {
      *(_DWORD *)(a1 + 16) = 0;
      if ( PopDispatchStateCallout(a1, v5) >= 0 )
        break;
    }
    KeDelayExecutionThread(0, 0, v6);
  }
  return sub_7EAC90();
}
