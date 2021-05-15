// EtwTraceCpuCacheFlush 
 
int __fastcall EtwTraceCpuCacheFlush(int a1, int a2, int a3, char a4, char a5, char a6)
{
  _DWORD v7[2]; // [sp+8h] [bp-18h] BYREF
  char v8; // [sp+10h] [bp-10h]
  char v9; // [sp+11h] [bp-Fh]
  char v10; // [sp+12h] [bp-Eh]
  char v11; // [sp+13h] [bp-Dh]
  int v12; // [sp+14h] [bp-Ch]

  v8 = a4;
  v7[0] = a2;
  v7[1] = a3;
  v9 = a5;
  v10 = a6;
  v11 = 0;
  v12 = 0;
  return EtwTraceTimedEvent(3939, 0x84000000, (int)v7, 16, 22026754, a1);
}
