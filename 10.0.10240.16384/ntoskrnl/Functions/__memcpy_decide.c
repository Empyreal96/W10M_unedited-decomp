// __memcpy_decide 
 
void __fastcall _memcpy_decide(int a1, __int64 *a2, unsigned int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r5
  unsigned int v6; // r4
  int v7; // r4

  if ( (((unsigned __int8)__get_CPSR() | 0x20) & 0xF) != 0 )
  {
    v4 = __mrc(15, 0, 0, 0, 0);
    v5 = HIBYTE(v4);
    v6 = v4 >> 4;
    if ( v5 == 65 && (v6 & 0xFFF) == 3081 )
      goto LABEL_6;
LABEL_7:
    v7 = 2;
    byte_60E000 = 2;
    goto LABEL_8;
  }
  if ( !MEMORY[0x7FFE028E] )
    goto LABEL_7;
LABEL_6:
  v7 = 1;
  byte_60E000 = 1;
LABEL_8:
  ((void (__fastcall *)(int, __int64 *, unsigned int, int))*(&off_4236E0 + 2 * v7))(a1, a2, a3, a4);
}
