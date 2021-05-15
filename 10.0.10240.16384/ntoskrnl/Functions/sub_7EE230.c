// sub_7EE230 
 
void __fastcall sub_7EE230(int a1, int a2, int a3, int a4, int a5, char a6)
{
  int v6; // r4
  _WORD *v7; // r5

  if ( !v6 || v6 == 1 )
  {
    a5 = v6;
    a6 = 0;
    PsEnumProcesses((int (__fastcall *)(int *, int))EtwpUpdateProcessTracingCallback, (int)&a5);
  }
  *v7 = 0;
  JUMPOUT(0x77EEBC);
}
