// IopLiveDumpProcessCorralStateChange 
 
int __fastcall IopLiveDumpProcessCorralStateChange(int result, int a2)
{
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  int v6; // r3
  char v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r1

  v3 = result;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v3 + 8);
    __dmb(0xBu);
    if ( v5 != *(_DWORD *)(a2 + 4) )
      break;
    __dmb(0xAu);
    __yield();
    v4 = *(_DWORD *)(a2 + 4);
    if ( v4 > 1 && v4 < 6 )
      result = ReadTimeStampCounter();
  }
  v6 = *(_DWORD *)(v3 + 8);
  *(_DWORD *)(a2 + 4) = v6;
  switch ( v6 )
  {
    case 2:
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v7 = 0;
      }
      else
      {
        __disable_irq();
        v7 = 1;
      }
      *(_BYTE *)(a2 + 8) = v7;
      break;
    case 3:
      result = KeSuspendClockTimerSafe();
      break;
    case 4:
      result = IopLiveDumpBufferDumpData(v3, (_DWORD *)a2);
      break;
    case 5:
      result = KeResumeClockTimerSafe();
      break;
    default:
      if ( v6 == 6 && *(_BYTE *)(a2 + 8) )
        __enable_irq();
      break;
  }
  __dmb(0xBu);
  v8 = (unsigned int *)(v3 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 + 1, v8) );
  __dmb(0xBu);
  return result;
}
