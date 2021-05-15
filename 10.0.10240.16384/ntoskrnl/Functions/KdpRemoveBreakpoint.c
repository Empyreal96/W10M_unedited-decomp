// KdpRemoveBreakpoint 
 
int __fastcall KdpRemoveBreakpoint(int *a1, _BYTE *a2)
{
  int v3; // r4
  int v5; // r0
  int v7; // r3
  int v8; // r3

  v3 = *a1;
  KdpWriteInstructionBuffer(a2, *((_QWORD *)a1 + 2), *((_BYTE *)a1 + 28));
  v5 = KdpCopyCodeStream(v3 & ~*((unsigned __int8 *)a1 + 29), 0, (int)a2, *((unsigned __int8 *)a1 + 28), 5);
  if ( v5 < 0 )
    return 0;
  v7 = a1[6];
  if ( (v7 & 4) != 0 )
    v8 = v7 | 5;
  else
    v8 = 0;
  a1[6] = v8;
  if ( v5 == 259 )
    a1[6] |= 9u;
  return 1;
}
