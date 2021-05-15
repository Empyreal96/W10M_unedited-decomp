// CcPerfLogReadAhead 
 
int *__fastcall CcPerfLogReadAhead(int a1, __int64 *a2, unsigned int a3, unsigned int a4)
{
  __int64 v8; // kr00_8
  int v10[4]; // [sp+8h] [bp-48h] BYREF
  int v11; // [sp+18h] [bp-38h] BYREF
  __int64 v12[3]; // [sp+20h] [bp-30h] BYREF

  memset(v12, 0, sizeof(v12));
  LODWORD(v12[2]) = 0;
  v10[0] = (int)&v11;
  v10[1] = 0;
  v10[2] = 32;
  v8 = *a2;
  v10[3] = 0;
  v11 = a1;
  v12[0] = v8;
  v12[1] = __PAIR64__(a4, a3);
  return EtwTraceKernelEvent(v10, 1, 0x80020000, 5635, 4200706);
}
