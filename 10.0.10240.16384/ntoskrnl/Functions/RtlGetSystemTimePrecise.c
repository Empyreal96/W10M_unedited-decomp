// RtlGetSystemTimePrecise 
 
int RtlGetSystemTimePrecise()
{
  __int64 v0; // r0
  unsigned int v1; // r9
  int v2; // r4
  int v3; // r5
  unsigned int v4; // r10
  int v5; // r1
  int v6; // r6
  int v7; // r1
  unsigned int v8; // r0
  unsigned __int64 v10; // r4
  unsigned int v11; // [sp+0h] [bp-40h]
  unsigned int v12; // [sp+4h] [bp-3Ch]
  char v13; // [sp+8h] [bp-38h]
  int v14; // [sp+Ch] [bp-34h]
  _DWORD v15[11]; // [sp+14h] [bp-2Ch] BYREF

  while ( 1 )
  {
    v0 = RtlBeginReadTickLock(-27840);
    v1 = MEMORY[0xFFFF9348];
    v2 = HIDWORD(v0);
    v3 = v0;
    v12 = MEMORY[0xFFFF934C];
    v4 = MEMORY[0xFFFF935C];
    v11 = MEMORY[0xFFFF9358];
    v13 = MEMORY[0xFFFF9368];
    v14 = MEMORY[0xFFFF9014];
    KeQueryPerformanceCounter(&v15[1], 0);
    if ( RtlTryEndReadTickLock(-27840, v5, v3, v2) )
      break;
    __dmb(0xAu);
    __yield();
  }
  v6 = 0;
  if ( *(_QWORD *)&v15[1] > __PAIR64__(v12, v1) )
  {
    v7 = v15[1] - v1 - 1;
    v8 = ((*(_QWORD *)&v15[1] - __PAIR64__(v12, v1)) >> 32) + (v15[1] != v1) - 1;
    if ( v13 )
      return sub_50EBA4(v8, v7);
    v10 = v4 * (unsigned __int64)(unsigned int)v7;
    if ( v8 )
    {
      v6 = ((v11 * (unsigned __int64)v8 + v10) >> 32) + v8 * v4;
    }
    else
    {
      v6 = (v10 + ((v11 * (unsigned __int64)(unsigned int)v7) >> 32)) >> 32;
      v15[1] = (__PAIR64__(v4, v11) * (unsigned int)v7) >> 32;
    }
  }
  return v14 + v6;
}
