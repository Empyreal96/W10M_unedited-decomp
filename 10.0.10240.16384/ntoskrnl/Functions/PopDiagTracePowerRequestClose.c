// PopDiagTracePowerRequestClose 
 
int __fastcall PopDiagTracePowerRequestClose(int result, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, char a13)
{
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_CLOSE_POWER_REQUEST);
    if ( result )
      result = sub_7BF17C(result, v13, v14, v15, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
  return result;
}
