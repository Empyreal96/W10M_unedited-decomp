// MiAllocateVad 
 
_DWORD *__fastcall MiAllocateVad(unsigned int a1, unsigned int a2)
{
  _BYTE *v4; // r0
  _DWORD *v5; // r4
  int v6; // r2
  int v7; // r3

  v4 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 1399087446);
  v5 = v4;
  if ( !v4 )
    goto LABEL_4;
  memset(v4, 0, 40);
  v5[2] = -2;
  v5[3] = a1 >> 12;
  v6 = v5[8];
  v5[4] = a2 >> 12;
  v7 = v5[7];
  v5[8] = v6 & 0x80000000 | 0x7FFFF;
  v5[6] = 0;
  v5[7] = v7 & 0xFFFFFF0F | 0x8008;
  if ( !MiAddSecureEntry((int)v5, a1, a2, -2147483647, 0) )
  {
    ExFreePoolWithTag((unsigned int)v5);
LABEL_4:
    v5 = 0;
  }
  return v5;
}
