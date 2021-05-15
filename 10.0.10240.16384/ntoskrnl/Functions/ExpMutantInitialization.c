// ExpMutantInitialization 
 
BOOL ExpMutantInitialization()
{
  _BYTE *v0; // r0
  int v2; // [sp+0h] [bp-68h] BYREF
  int v3[22]; // [sp+8h] [bp-60h] BYREF

  RtlInitUnicodeString((unsigned int)&v2, L"Mutant");
  memset(v3, 0, sizeof(v3));
  v0 = (_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 24);
  memset(v0, 0, KdDumpEnableOffset);
  LOWORD(v3[0]) = 88;
  v3[1] = 64;
  v3[2] = 256;
  v3[3] = 131073;
  v3[4] = 0x20000;
  v3[5] = 1179648;
  v3[6] = 2031617;
  v3[9] = 512;
  v3[11] = 32;
  v3[7] = 2031617;
  v3[15] = (int)ExpDeleteMutant;
  return ObCreateObjectType() >= 0;
}
