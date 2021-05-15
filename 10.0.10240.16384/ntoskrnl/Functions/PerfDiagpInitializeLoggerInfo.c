// PerfDiagpInitializeLoggerInfo 
 
unsigned int __fastcall PerfDiagpInitializeLoggerInfo(int a1, __int16 a2)
{
  unsigned int result; // r0

  memset(dword_61CB88, 0, 176);
  dword_61CBB4 = 0x20000;
  dword_61CBD0 = -2130771792;
  memmove((int)word_61CB48, (int)L"Circular Kernel Context Logger", 0x3Eu);
  result = RtlInitUnicodeString((unsigned int)&unk_61CC18, word_61CB48);
  dword_61CB88[0] = 180;
  word_61CC3A = 0;
  word_61CC38 = 1;
  if ( a1 )
  {
    word_61CC3E = 1;
    word_61CC3C = a2 + 1;
    word_61CC3A = 1;
    word_61CC38 = a2 + 2;
    dword_61CB88[0] = 4 * ((unsigned __int16)(a2 + 1) + 45);
  }
  return result;
}
