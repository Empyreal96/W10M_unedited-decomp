// CmpLogHiveLinkEvent 
 
int *__fastcall CmpLogHiveLinkEvent(int a1, unsigned __int16 *a2)
{
  int v2; // r0
  int *v3; // r2
  __int16 v5; // [sp+8h] [bp-50h] BYREF
  int v6[15]; // [sp+10h] [bp-48h] BYREF
  _DWORD v7[2]; // [sp+50h] [bp-8h] BYREF

  v7[0] = a1;
  v7[1] = a2;
  v5 = 0;
  v6[0] = (int)v7;
  v6[1] = 0;
  v6[2] = 4;
  v6[3] = 0;
  v2 = 1;
  if ( *((_DWORD *)a2 + 1) )
  {
    v6[4] = *((_DWORD *)a2 + 1);
    v6[5] = 0;
    v6[6] = *a2;
    v6[7] = 0;
    v2 = 2;
  }
  v3 = &v6[4 * v2];
  *v3 = (int)&v5;
  v3[2] = 2;
  v3[1] = 0;
  v3[3] = 0;
  return EtwTraceKernelEvent(v6, v2 + 1, 0x41000000u, 2342, 5249282);
}
