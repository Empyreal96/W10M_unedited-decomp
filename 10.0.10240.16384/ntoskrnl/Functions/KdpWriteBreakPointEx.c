// KdpWriteBreakPointEx 
 
int __fastcall KdpWriteBreakPointEx(_DWORD *a1, unsigned __int16 *a2)
{
  int v4; // r1
  int v5; // r3
  int v6; // r1
  char *v7; // r5
  unsigned int i; // r6
  unsigned int v9; // r0
  char *v10; // r5
  unsigned int j; // r6
  int v12; // r0
  int result; // r0
  int v14; // [sp+8h] [bp-238h]
  int v15; // [sp+Ch] [bp-234h]
  int v16[2]; // [sp+10h] [bp-230h] BYREF
  __int16 v17; // [sp+18h] [bp-228h]
  _DWORD *v18; // [sp+1Ch] [bp-224h]
  char v19[544]; // [sp+20h] [bp-220h] BYREF

  v4 = a1[4];
  v17 = 56;
  v5 = *a2;
  v18 = a1;
  if ( v5 == 16 * v4
    && (KdpCopyMemoryChunks(*((_DWORD *)a2 + 1), 0, (int)v19, 16 * v4, 0, 4, v16), v16[0] == 16 * a1[4]) )
  {
    a1[2] = 0;
    v7 = v19;
    for ( i = 0; i < a1[4]; v7 += 16 )
    {
      v9 = *((_DWORD *)v7 + 2);
      if ( v9 )
      {
        if ( !KdpDeleteBreakpoint(v9) )
          a1[2] = -1073741823;
        *((_DWORD *)v7 + 2) = 0;
      }
      ++i;
    }
    v10 = v19;
    for ( j = 0; j < a1[4]; v10 += 16 )
    {
      if ( *(_QWORD *)v10 )
      {
        v12 = KdpAddBreakpoint(*(_DWORD *)v10, v6, 57086, 0, 2, 1, v14, v15);
        *((_DWORD *)v10 + 2) = v12;
        if ( !v12 )
          a1[2] = -1073741823;
      }
      ++j;
    }
    KdpCopyMemoryChunks(*((_DWORD *)a2 + 1), 0, (int)v19, 16 * a1[4], 0, 5, v16);
    KdSendPacket_0();
    result = a1[5];
  }
  else
  {
    a1[2] = -1073741823;
    KdSendPacket_0();
    result = a1[2];
  }
  return result;
}
