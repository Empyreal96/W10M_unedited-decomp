// KdpInsertBreakpoint 
 
int __fastcall KdpInsertBreakpoint(int *a1, _BYTE *a2)
{
  int v3; // r5
  int v5; // r7
  int v6; // r0

  v3 = *a1;
  v5 = 0;
  KdpWriteInstructionBuffer(a2, *((_QWORD *)a1 + 1), *((_BYTE *)a1 + 28));
  v6 = KdpCopyCodeStream(v3 & ~*((unsigned __int8 *)a1 + 29), 0, (int)a2, *((unsigned __int8 *)a1 + 28), 5);
  if ( v6 < 0 )
    return 0;
  if ( v6 == 259 )
    v5 = 2;
  return v5 | 1;
}
