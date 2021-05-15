// KeSaveStateForHibernate 
 
_DWORD *__fastcall KeSaveStateForHibernate(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  _DWORD *result; // r0
  unsigned int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]
  int v9; // [sp+Ch] [bp-4h]

  v7 = __get_CPSR() | 0x20;
  __disable_irq();
  RtlCaptureContext(a1 + 128);
  KiSaveProcessorControlState(a1);
  if ( (v7 & 0x80) == 0 )
    __enable_irq();
  result = a1;
  a1[140] = v8;
  a1[144] = v9;
  a1[142] = &a5;
  return result;
}
