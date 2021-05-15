// EtwTraceJob 
 
int *__fastcall EtwTraceJob(int a1, int a2, int a3, int a4, unsigned __int16 a5)
{
  char v10[16]; // [sp+8h] [bp-48h] BYREF
  int v11; // [sp+18h] [bp-38h]
  int v12; // [sp+1Ch] [bp-34h]
  int v13; // [sp+20h] [bp-30h]
  int v14[10]; // [sp+28h] [bp-28h] BYREF

  EtwpCopyJobGuidSafe(v10, a1);
  v14[0] = (int)v10;
  v14[1] = 0;
  v11 = a2;
  v12 = a3;
  v14[2] = 28;
  v13 = a4;
  v14[3] = 0;
  if ( (dword_61AD40 & 0x80000) != 0 )
    EtwpPsProvTraceJob(a1, a2, a4, a5);
  return EtwTraceKernelEvent(v14, 1, 0x80000u, a5, (int)off_501904);
}
