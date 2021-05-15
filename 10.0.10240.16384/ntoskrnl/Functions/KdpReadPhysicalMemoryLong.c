// KdpReadPhysicalMemoryLong 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall KdpReadPhysicalMemoryLong(_DWORD *result, _WORD *a2)
{
  _DWORD *v3; // r8
  unsigned int v4; // r4
  unsigned int v5; // r6 OVERLAPPED
  unsigned int v6; // r5 OVERLAPPED
  int i; // r7
  unsigned int v8; // r2

  v3 = result;
  v4 = result[6];
  v5 = result[5];
  v6 = result[4];
  for ( i = result[7]; v4; v6 += v8 )
  {
    *((_QWORD *)v3 + 2) = *(_QWORD *)&v6;
    v3[6] = v4;
    v3[7] = i;
    *a2 = 0;
    v3[2] = 0;
    result = (_DWORD *)KdpReadPhysicalMemory(v3, (int)a2);
    v8 = v3[7];
    if ( (v8 & 0xC0000000) == 0x40000000 )
      v8 *= 4;
    if ( (int)v3[2] < 0 || !v8 )
      break;
    if ( v8 > v4 )
      v8 = v4;
    v4 -= v8;
    v5 = (__PAIR64__(v5, v6) + v8) >> 32;
  }
  return result;
}
