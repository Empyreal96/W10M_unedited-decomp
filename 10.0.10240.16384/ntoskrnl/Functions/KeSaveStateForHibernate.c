// KeSaveStateForHibernate 
 
_DWORD *__fastcall KeSaveStateForHibernate(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  int v5; // r1
  int v6; // r2
  int v7; // r3
  _DWORD *result; // r0
  unsigned int v10; // [sp+4h] [bp-Ch]
  int v11; // [sp+8h] [bp-8h]
  int v12; // [sp+Ch] [bp-4h]

  v10 = __get_CPSR() | 0x20;
  __disable_irq();
  RtlCaptureContext(a1 + 128, a2, a3, a4);
  KiSaveProcessorControlState(a1, v5, v6, v7);
  if ( (v10 & 0x80) == 0 )
    __enable_irq();
  result = a1;
  a1[140] = v11;
  a1[144] = v12;
  a1[142] = &a5;
  return result;
}
