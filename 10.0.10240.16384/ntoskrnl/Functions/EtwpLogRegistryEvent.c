// EtwpLogRegistryEvent 
 
int __fastcall EtwpLogRegistryEvent(int a1, __int16 a2, int a3, int a4, int a5, int *a6, int a7)
{
  __int16 v8; // r0
  int v9; // r1
  int v10; // r1
  int v11; // r1
  int v12; // r3
  int *v13; // r2
  int v15[6]; // [sp+8h] [bp-58h] BYREF
  int v16[16]; // [sp+20h] [bp-40h] BYREF

  v15[2] = a3;
  v15[3] = a4;
  v15[4] = a5;
  v8 = a2 | 0x900;
  v9 = *a6;
  v16[0] = (int)v15;
  v15[0] = v9;
  v10 = a6[1];
  v16[1] = 0;
  v16[2] = 20;
  v15[1] = v10;
  v11 = 1;
  v16[3] = 0;
  if ( a7 )
  {
    v12 = *(_WORD *)a7 & 0xFFFE;
    if ( *(_DWORD *)(a7 + 4) )
    {
      if ( (*(_WORD *)a7 & 0xFFFE) != 0 )
      {
        v16[4] = *(_DWORD *)(a7 + 4);
        v16[6] = v12;
        v16[5] = 0;
        v16[7] = 0;
        v11 = 2;
      }
    }
  }
  v13 = &v16[4 * v11];
  *(_QWORD *)v13 = (unsigned int)&EtwpNull;
  *((_QWORD *)v13 + 1) = 2i64;
  return EtwpLogSystemEventUnsafe((int)v16, (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), a1, v11 + 1, v8, 5249282);
}
