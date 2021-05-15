// EtwTraceJobRemoveProcess 
 
int *__fastcall EtwTraceJobRemoveProcess(int a1, int a2, int a3)
{
  int v4; // r1
  int v5; // r4
  char v8[16]; // [sp+8h] [bp-40h] BYREF
  int v9; // [sp+18h] [bp-30h]
  int v10; // [sp+1Ch] [bp-2Ch]
  int v11; // [sp+20h] [bp-28h]
  int v12[8]; // [sp+28h] [bp-20h] BYREF

  v4 = 0;
  v5 = 0;
  if ( a1 )
  {
    v4 = *(_DWORD *)(a1 + 288);
    __dmb(0xBu);
    v5 = *(_DWORD *)(a1 + 176);
  }
  EtwpCopyJobGuidSafe(v8, v4);
  v12[0] = (int)v8;
  v12[1] = 0;
  v12[2] = 28;
  v12[3] = 0;
  v9 = v5;
  v10 = a2;
  v11 = a3;
  return EtwTraceKernelEvent(v12, 1, 0x80000u, 1828, (int)off_501904);
}
