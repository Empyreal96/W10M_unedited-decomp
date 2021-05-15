// PopLazySensorActiveInput 
 
int __fastcall PopLazySensorActiveInput(unsigned int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  int result; // r0
  int v7; // r2
  int v8; // r3
  int v9; // r7
  unsigned int v10; // r1
  int v11; // r1
  int v12; // r0
  unsigned int v13; // r5
  int v14; // r2
  int v15; // r3
  int v16; // [sp+0h] [bp-38h] BYREF
  int v17; // [sp+4h] [bp-34h]
  char v18[48]; // [sp+8h] [bp-30h] BYREF

  v3 = 0;
  byte_61DE12 = 1;
  v4 = 0;
  dword_61DE14 = 10;
  v16 = 0;
  v17 = 0;
  result = MmGetSessionById(a1, a2, a3, 10);
  v9 = result;
  if ( result )
  {
    if ( MmAttachSession(result, (int)v18, v7, v8) >= 0 )
    {
      v10 = MEMORY[0xFFFF9004];
      if ( MEMORY[0xFFFF9004] < 0x1000000u )
      {
        while ( 1 )
        {
          v12 = MEMORY[0xFFFF9324];
          __dmb(0xBu);
          v13 = MEMORY[0xFFFF9320];
          __dmb(0xBu);
          if ( v12 == MEMORY[0xFFFF9328] )
            break;
          __dmb(0xAu);
          __yield();
        }
        v11 = ((__int64)(v13 * (unsigned __int64)v10) >> 24) + (v12 << 8) * v10;
      }
      else
      {
        v11 = (__int64)(MEMORY[0xFFFF9320] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24;
      }
      PopConsoleSessionActiveInput(a1, v11, (int)&v16);
      MmDetachSession(v9, (int)v18, v14, v15);
      v3 = v16;
      v4 = v17;
    }
    result = ObfDereferenceObject(v9);
    dword_61DE0C = v4;
    byte_61DE11 = 1;
    dword_61DE08 = v3;
    byte_61DE10 = 1;
  }
  return result;
}
