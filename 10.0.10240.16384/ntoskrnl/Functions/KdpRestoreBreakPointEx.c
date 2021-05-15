// KdpRestoreBreakPointEx 
 
int __fastcall KdpRestoreBreakPointEx(int a1, unsigned __int16 *a2)
{
  int v4; // r1
  int v5; // r3
  unsigned int v6; // r5
  unsigned int *v7; // r8
  unsigned int v8; // t1
  int v10; // [sp+10h] [bp-A8h] BYREF
  __int16 v11; // [sp+18h] [bp-A0h]
  int v12; // [sp+1Ch] [bp-9Ch]
  char v13[152]; // [sp+20h] [bp-98h] BYREF

  v4 = *(_DWORD *)(a1 + 16);
  v11 = 56;
  v5 = *a2;
  v12 = a1;
  if ( v5 == 4 * v4
    && (v6 = 0,
        KdpCopyMemoryChunks(*((_DWORD *)a2 + 1), 0, (int)v13, 4 * v4, 0, 4, &v10),
        v10 == 4 * *(_DWORD *)(a1 + 16)) )
  {
    *(_DWORD *)(a1 + 8) = 0;
    v7 = (unsigned int *)v13;
    if ( *(_DWORD *)(a1 + 16) )
    {
      do
      {
        v8 = *v7++;
        if ( !KdpDeleteBreakpoint(v8) )
          *(_DWORD *)(a1 + 8) = -1073741823;
        ++v6;
      }
      while ( v6 < *(_DWORD *)(a1 + 16) );
    }
  }
  else
  {
    *(_DWORD *)(a1 + 8) = -1073741823;
  }
  return KdSendPacket_0();
}
