// MiLogPerfMemoryRangeEvent 
 
int *__fastcall MiLogPerfMemoryRangeEvent(int a1, int a2, unsigned int a3, int a4)
{
  int v5; // r4
  int v7; // r3
  int v8; // r0
  unsigned __int64 v9; // kr00_8
  unsigned int v11; // [sp+8h] [bp-30h] BYREF
  int v12; // [sp+Ch] [bp-2Ch]
  int v13; // [sp+10h] [bp-28h]
  int v14; // [sp+14h] [bp-24h]
  int var20[14]; // [sp+18h] [bp-20h] BYREF

  var20[10] = a1;
  var20[11] = a2;
  var20[13] = a4;
  v5 = 0;
  v12 = 0;
  var20[12] = a3;
  if ( (a3 & 1) != 0 )
    v7 = 632;
  else
    v7 = 633;
  v8 = (a3 >> 1) & 0xF;
  if ( v8 == 13 )
  {
    v9 = 16i64 * (unsigned int)a2;
    v12 = HIDWORD(v9);
    v5 = v9;
  }
  v11 = v5 & 0xFFFFFFF0 | v8;
  v14 = a4;
  var20[0] = (int)&v11;
  var20[1] = 0;
  var20[2] = 16;
  var20[3] = 0;
  v13 = a1;
  return EtwTraceKernelEvent(var20, 1, 0x20000001u, v7, 289413890);
}
